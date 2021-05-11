/*! VUT FIT ICP
 * @file graph_ui.cpp
 * @brief
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#include <QMessageBox>
#include <QCursor>

#include "graph_ui.h"
#include "block_ui.h"

BlockConstructor &GraphUI::GetBlockFactory(){
	return bf;
}

GraphUI::GraphUI() : in_click(nullptr), out_click(nullptr),
    tc(&in_click, &out_click, this), bf(*this), block_context_menu(*this){
	setMouseTracking(true);
}

QPoint GraphUI::getOffset() const{
	return pos_offset;
}

void GraphUI::JEEclear(){
	Manager::JEEclear();
	for(ConnectionUI *c : ui_connections){
		delete c;
	}
	ui_connections.clear();
	in_click = nullptr;
	out_click = nullptr;
	computedAsLast = nullptr;
}

bool GraphUI::JEEload(std::stringstream &graph, bool overlap){
	// block id offset
	int b_id_off = static_cast<int>(blocks.size());

    int x_off = 5, y_off = 5;
	bool first_ = true;
    if (overlap){
        for (BlockBase *b : blocks){
			auto block = static_cast<BlockUI<BlockBase>*>(b);
			if(first_){
				x_off = block->Pos().x();
				y_off = block->Pos().y() + block->height();
				first_ = false;
			}
			x_off = std::min(x_off, block->Pos().x());
			y_off = std::max(y_off, block->Pos().y() + block->height());
		}
        y_off += 5;
    } else{
		pos_offset = QPoint(0, 0); // reset drag offset
	}

	if (!Manager::JEEload(graph, overlap)){
		return false;
	}

	std::string tmp;
    try{
		// Block Positions
		graph >> std::ws; // skip whitespaces
        std::getline(graph, tmp,'(');
        if (tmp != "position"){
			return false;
		}
        std::getline(graph, tmp, ')');
		std::stringstream pos_stream(tmp);

		auto it = blocks.begin();
		if (overlap) {
			std::advance(it, b_id_off);
		}

        while(std::getline(pos_stream, tmp, ';')){
			std::stringstream xy(tmp);
			std::string xs, ys;
			std::getline(xy, xs, ':');
			std::getline(xy, ys, ':');
			int x = std::stoi(xs) + x_off;
			int y = std::stoi(ys) + y_off;
			static_cast<BlockUI<BlockBase>*>(*it)->Move(x, y);
			it++;
		}
	}
    catch (const std::invalid_argument &){
		return false;
	}
	return true;
}

std::stringstream GraphUI::JEEsave(){
	std::stringstream ss = Manager::JEEsave();

	// get offset
	int x_off = 0, y_off = 0;
	bool first_ = true;
    for (BlockBase *b : blocks){
		auto p = static_cast<BlockUI<BlockBase>*>(b)->Pos();
		if (first_) {
			x_off = p.x(); y_off = p.y();
			first_ = false;
		} else {
			x_off = std::min(x_off, p.x());
			y_off = std::min(y_off, p.y());
		}
	}

	// Block Positions
	ss << '\n';
    ss << "position(";
	bool first = true;
    for (BlockBase *b : blocks){
		if(first) {
			first = false;
		} else {
            ss << ";";
		}
		BlockUI<BlockBase> *b_ui = static_cast<BlockUI<BlockBase>*>(b);
		ss << b_ui->Pos().x() - x_off << ":" << b_ui->Pos().y() - y_off;
	}
    ss << ")";

	return std::move(ss);
}

void GraphUI::blockContextMenu(BlockBase *b){
	block_context_menu.ShowMenu(b);
}

BlockBase *GraphUI::addBlock(BlockType t){
	BlockBase *b = Manager::addBlock(t);
	static_cast<BlockUI<BlockBase>*>(b)->updateOffset(pos_offset);
	return b;
}

void GraphUI::BlockRemoving(BlockBase *b){
	Manager::BlockRemoving(b);
	this->in_click = nullptr;
	this->out_click = nullptr;
}

bool GraphUI::addConnection(OutPort &a, InPort &b){
    if(Manager::addConnection(a, b)){
		// remove previous connection
		for(ConnectionUI *c : ui_connections){
			if((*c) == b){
				ui_connections.remove(c);
				delete c;
			}
		}
		// create new connection
		ui_connections.push_back(new ConnectionUI(static_cast<InPortUI*>(&b), static_cast<OutPortUI*>(&a), this));

		this->in_click = nullptr;
		this->out_click = nullptr;
		return true;
	}
    else{
		if(!a.Value().type_of(b.Value())){
            GraphUI::ErrorAlert("Hodnoty týchto konektorov nie sú kompatibilné!");
		}
        else{
            GraphUI::ErrorAlert("Toto prepojenie by vytvorilo cyklus!");
		}

		this->in_click = nullptr;
		this->out_click = nullptr;
		return false;
	}
}

void GraphUI::ConnectionRemoving(InPort &p){
	OutPort *conn_p = getConnectedOutPort(p);
	if(conn_p != nullptr){
		this->out_click = conn_p;

		Manager::ConnectionRemoving(p);

        for (auto it = ui_connections.cbegin(); it != ui_connections.cend();){
            if (*(*it) == p){
				delete (*it);
				it = ui_connections.erase(it);
			}
            else{
				it++;
			}
		}
	}
}

void GraphUI::ConnectionRemoving(OutPort &p){
	Manager::ConnectionRemoving(p);

    for (auto it = ui_connections.cbegin(); it != ui_connections.cend();){
        if (*(*it) == p){
			delete (*it);
			it = ui_connections.erase(it);
		}
        else{
			it++;
		}
	}
}

void GraphUI::updateConnectionUI(Ports &p){
	for(ConnectionUI *c : ui_connections){
		if((*c) == p){
            c->raise();
            c->update();
		}
	}
}

GraphUI::~GraphUI(){
	for(ConnectionUI *c : ui_connections){
		delete c;
	}
}

void GraphUI::hoverConnectionUI(QPoint mouse){
	for(ConnectionUI *c : ui_connections){
		c->mouseHover(mouse);
	}
    tc.raise();
    tc.update();
}

void GraphUI::mouseMoveEvent(QMouseEvent *event){
	hoverConnectionUI(event->pos());
    tc.raise();
    tc.update();
	if(drag){
		pos_offset += event->pos() - drag_p;
		drag_p = event->pos();
		for (auto b : blocks) {
			static_cast<BlockUI<BlockBase>*>(b)->updateOffset(pos_offset);
		}
	}
}

void GraphUI::hideHoverConnectionUI(){
	for(ConnectionUI *c : ui_connections){
		c->mouseHover(false);
	}
    tc.raise();
    tc.update();
}

bool GraphUI::allInputsConnected(){
    if(!Manager::allInputsConnected()){
        GraphUI::ErrorAlert("Nie všetky vstupy sú pripojené!");
        return false;
    }
	return true;
}

void GraphUI::computeReset(){
	if(computedAsLast != nullptr){
		static_cast<BlockUI<BlockBase>*>(computedAsLast)->Highlight(false);
	}
	Manager::computeReset();
}

bool GraphUI::computeStep(){
	if(computedAsLast != nullptr){
		static_cast<BlockUI<BlockBase>*>(computedAsLast)->Highlight(false);
	}
	bool ret = Manager::computeStep();
	if(computedAsLast != nullptr){
		static_cast<BlockUI<BlockBase>*>(computedAsLast)->Highlight(true);
	}
	return ret;
}

bool GraphUI::computeAll(){
    if (Manager::computeAll()){
		return computeStep();
    } else{
		return false;
	}
}

void GraphUI::leaveEvent(QEvent *){
	hideHoverConnectionUI();
}

void GraphUI::mousePressEvent(QMouseEvent *event){
	setFocus();
	in_click = nullptr;
	out_click = nullptr;
    tc.raise();
    tc.update();

    if(event->button() == Qt::LeftButton){
		drag = true;
		drag_p = event->pos();
	}
}

void GraphUI::mouseReleaseEvent(QMouseEvent *){
	drag = false;
}

void GraphUI::ErrorAlert(std::string message){
    QMessageBox alert;
    alert.setWindowTitle("Chyba");
    alert.setText(message.c_str());
    alert.show();
    alert.exec();
}



BlockDelete::BlockDelete(GraphUI &g) : graph(g){
    menu.addAction(QIcon(":/icons/delete.png"), "Vymazať");
}

void BlockDelete::ShowMenu(BlockBase *block){
    menu.move(QCursor::pos());
    if (menu.exec() != nullptr){
        graph.BlockRemoving(block);
    }
}
