/*! VUT FIT ICP
 * @file graph.cpp
 * @brief
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#include "graph.h"
#include <utility>
#include <sstream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <algorithm>

Graph::Graph() : bf(*this), needToBeComputed(), blocks_iterator(needToBeComputed.begin()), computedAsLast(nullptr) { }

std::string Graph::GetSchemeName() const{
	return this->name;
}

void Graph::SetSchemeName(const std::string name){
	this->name = name;
	if (graphChanged) {
		graphChanged();
	}
}

void Graph::onGraphChange(std::function<void ()> callback){
	this->graphChanged = callback;
}

int Graph::getIDofBlock(const BlockBase &block) const{
	int idx = 0;
	for (BlockBase *b : blocks) {
		if (b == &block){
			return idx;
		}
		idx++;
	}
	return -1;
}

void Graph::GraphClearing(){
	for (BlockBase *b : blocks){
		GetBlockFactory().FreeBlock(b);
	}
	blocks.clear();
	connections.clear();
	name.clear();
	if (graphChanged) {
		graphChanged();
	}
}

bool Graph::GraphLoading(std::stringstream &graph, bool overlap){
    if(!overlap){
        GraphClearing();
	}
	// block id offset
	int b_id_off = static_cast<int>(blocks.size());

	std::string tmp;
    try{
		// Blocks
		graph >> std::ws; // skip whitespaces
        std::getline(graph, tmp,'(');
        if (tmp != "blocks"){
			return false;
		}
        std::getline(graph, tmp, ')');
		std::stringstream block_stream(tmp);
        while(std::getline(block_stream, tmp, ';')){
			BlockType t = static_cast<BlockType>(std::stoi(tmp));
			addBlock(t);
		}

		// Connections
		graph >> std::ws; // skip whitespaces
        std::getline(graph, tmp,'(');
        if (tmp != "paths") {
			return false;
		}
        std::getline(graph, tmp, ')');
		std::stringstream conn_stream(tmp);
        while (std::getline(conn_stream, tmp, ';')){
			std::stringstream conn(tmp);
			std::getline(conn, tmp, '-');
			std::stringstream out(tmp);
			std::getline(conn, tmp, '-');
			std::stringstream in(tmp);
			std::string in_b, in_p, out_b, out_p;
			std::getline(out, out_b, '|');
			std::getline(out, out_p, '|');
			std::getline(in, in_b, '|');
			std::getline(in, in_p, '|');
			auto out_block = this->blocks.begin();
			auto in_block = this->blocks.begin();
			std::advance(out_block, std::stoi(out_b) + b_id_off);
			std::advance(in_block, std::stoi(in_b) + b_id_off);
			OutPort &a = (*out_block)->Output(std::stoi(out_p));
			InPort &b = (*in_block)->Input(std::stoi(in_p));
			addConnection(a, b);
		}
	}
    catch (const std::invalid_argument &){
		return false;
	}
	return true;
}

std::stringstream Graph::GraphSaving(){
	std::stringstream ss;
	// Blocks
    ss << "blocks(";
	bool first = true;
	for (BlockBase *b : blocks) {
		if(first) {
			first = false;
		} else {
            ss << ";";
		}
		ss << static_cast<int>(b->type);
	}
    ss << ")";

	// Connections
	ss << '\n';
    ss << "paths(";
	first = true;
    for (std::pair<InPort *, OutPort *> p : connections){
		if(first) {
			first = false;
        } else{
            ss << ";";
		}
		ss << p.second->block.getID() << "|";
		ss << p.second->getID() << "-";
		ss << p.first->block.getID() << "|";
		ss << p.first->getID();
	}
    ss << ")";

	return std::move(ss);
}

BlockFactory &Graph::GetBlockFactory(){
	return bf;
}

BlockBase *Graph::addBlock(BlockType t){
	BlockBase *b = GetBlockFactory().AllocBlock(t);
    if (b != nullptr){
		this->blocks.push_back(b);
		computeReset();
        if (graphChanged){
			graphChanged();
		}
	}
	return b;
}

void Graph::BlockRemoving(BlockBase *b){
	this->blocks.remove(b);
	for(std::size_t i = 0; i < b->InputCount(); i++){
        ConnectionRemoving(b->Input(i));
	}
	for(std::size_t i = 0; i < b->OutputCount(); i++){
        ConnectionRemoving(b->Output(i));
	}
	GetBlockFactory().FreeBlock(b);
	computeReset();
    if (graphChanged){
		graphChanged();
	}
}

OutPort *Graph::getConnectedOutPort(InPort &p){
	if (connections.find(&p) != connections.end()){
		return connections.at(&p);
	} else {
		return nullptr;
	}
}

bool Graph::addConnection(OutPort &a, InPort &b){
    if (!a.Value().type_of(b.Value())){
		return false;
	}
    if (!AcyclicBlocks(a, b)){
		return false;
	}
	connections.insert(std::pair<InPort *, OutPort *>(&b, &a));
	a.eventConnectionChange();
	b.eventConnectionChange();
	computeReset();
    if (graphChanged){
		graphChanged();
	}
	return true;
}

void Graph::ConnectionRemoving(InPort &p){
	OutPort *op = getConnectedOutPort(p);
	if (op != nullptr){
		op->eventConnectionChange();
	}
	connections.erase(&p);
	computeReset();
    if (graphChanged){
		graphChanged();
	}
}

void Graph::ConnectionRemoving(OutPort &p){
	for(auto it = connections.begin(); it != connections.end();){
        if ((*it).second == &p){
			(*it).first->eventConnectionChange();
			(*it).second->eventConnectionChange();
			it = connections.erase(it);
        } else{
			it++;
		}
	}
	computeReset();
    if (graphChanged){
		graphChanged();
	}
}

bool Graph::allInputsConnected(){
    for(const auto b : needToBeComputed){
        if(b->Computable() && !b->InputsAreConnected()){
            return false;
        }
    }
	return true;
}

void Graph::computeReset(){
	for (BlockBase *b : blocks){
        if(b->Computable()){
            b->Reset();
        }
	}
    needToBeComputed = blocks;
    blocks_iterator = needToBeComputed.begin();
}

bool Graph::computeStep(){
    computedAsLast = nullptr;

    if (!allInputsConnected()){
		return false;
	}
    while (needToBeComputed.size() > 0){
        if ((*blocks_iterator)->Computable()){
            if ((*blocks_iterator)->HasAllValues()){
                (*blocks_iterator)->Compute();
                computedAsLast = *blocks_iterator;
                needToBeComputed.erase(blocks_iterator++);
				break; // block is computed, continue
            } else{
                blocks_iterator++;
			}
		}
        else{
			// remove non-computable block
            needToBeComputed.erase(blocks_iterator++);
		}
		// cyclic iteration
        if(blocks_iterator == needToBeComputed.end()){
            blocks_iterator = needToBeComputed.begin();
		}
	}

	// cyclic iteration
    if(blocks_iterator == needToBeComputed.end()){
        blocks_iterator = needToBeComputed.begin();
	}
	return true;
}

bool Graph::computeAll(){
	computeReset();
	while(!computeFinished()){
		if(!computeStep()){
			return false;
		}
	}
	return true;
}

bool Graph::computeFinished(){
    return (needToBeComputed.size() == 0);
}

/**
 * Directed Acyclic Graph Check
 * Reference: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
 */
bool Graph::AcyclicBlocks(OutPort &a, InPort &b){
	// std::map<output, inputs> edges
	std::map<const BlockBase*, std::set<const BlockBase*>> dag;

	dag[&(a.block)].insert(&(b.block));
    for(auto &c : connections){
		dag[&(c.second->block)].insert(&(c.first->block));
	}

	const BlockBase *curr;
	std::list<const BlockBase*> visited;
	std::list<const BlockBase*> stack;

	auto not_visited = [&visited](auto x){
		return std::find(visited.begin(), visited.end(), x) == visited.end();
	};
	auto in_stack = [&stack](auto x){
		return std::find(stack.begin(), stack.end(), x) != stack.end();
	};
    for (auto &c : dag){
		curr = c.first;
        if (not_visited(curr)){
			visited.push_back(curr);
			stack.push_back(curr);
		}
        while (stack.size() > 0){
			curr = stack.back();
			bool move_next = false;
            if (dag.find(curr) != dag.end()){
				// if current has any connections, loop trough them
                for (auto &next : dag.at(curr)){
					if(in_stack(next)){
						// graph is not acyclic if next is already in stack
						return false;
					}
					if(not_visited(next)){
						// move to next if not visited
						move_next = true;
						visited.push_back(next);
						stack.push_back(next);
						break;
					}
				}
			}
			if (!move_next){
				stack.pop_back();
			}
		}
	}
	return true;
}
