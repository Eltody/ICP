/*! VUT FIT ICP
 * @file graph_ui.cpp
 * @brief
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#include <QMessageBox>
#include <QCursor>

#include "ui_BlockManager.h"
#include "ui_Block.h"

BlockConstructor &UIBlockManager::GetBlockFactory(){
	return bf;
}

UIBlockManager::UIBlockManager() : in_click(nullptr), out_click(nullptr),
    tc(&in_click, &out_click, this), bf(*this), block_context_menu(*this){
	setMouseTracking(true);
}

QPoint UIBlockManager::getOffset() const{
	return pos_offset;
}

void UIBlockManager::JEEclear(){
	Manager::JEEclear();
	for(UIConnections *c : ui_connections){
		delete c;
	}
	ui_connections.clear();
	in_click = nullptr;
	out_click = nullptr;
	computedAsLast = nullptr;
}

bool UIBlockManager::JEEload(std::stringstream &graph, bool overlap){
	// block id offset
	int b_id_off = static_cast<int>(blocks.size());

    int x_off = 5, y_off = 5;
	bool first_ = true;
    if (overlap){
        for (BlockBase *b : blocks){
			auto block = static_cast<UIBlock<BlockBase>*>(b);
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
			static_cast<UIBlock<BlockBase>*>(*it)->Move(x, y);
			it++;
		}
	}
    catch (const std::invalid_argument &){
		return false;
	}
	return true;
}

std::stringstream UIBlockManager::JEEsave(){
	std::stringstream ss = Manager::JEEsave();

	// get offset
	int x_off = 0, y_off = 0;
	bool first_ = true;
    for (BlockBase *b : blocks){
		auto p = static_cast<UIBlock<BlockBase>*>(b)->Pos();
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
		UIBlock<BlockBase> *b_ui = static_cast<UIBlock<BlockBase>*>(b);
		ss << b_ui->Pos().x() - x_off << ":" << b_ui->Pos().y() - y_off;
	}
    ss << ")";

	return std::move(ss);
}

void UIBlockManager::blockContextMenu(BlockBase *b){
	block_context_menu.ShowMenu(b);
}

BlockBase *UIBlockManager::addBlock(BlockType t){
	BlockBase *b = Manager::addBlock(t);
	static_cast<UIBlock<BlockBase>*>(b)->updateOffset(pos_offset);
	return b;
}

void UIBlockManager::BlockRemoving(BlockBase *b){
	Manager::BlockRemoving(b);
	this->in_click = nullptr;
	this->out_click = nullptr;
}

bool UIBlockManager::addConnection(OutPort &a, InPort &b){
    if(Manager::addConnection(a, b)){
		// remove previous connection
		for(UIConnections *c : ui_connections){
			if((*c) == b){
				ui_connections.remove(c);
				delete c;
			}
		}
		// create new connection
		ui_connections.push_back(new UIConnections(static_cast<InPortUI*>(&b), static_cast<OutPortUI*>(&a), this));

		this->in_click = nullptr;
		this->out_click = nullptr;
		return true;
	}
    else{
		if(!a.Value().type_of(b.Value())){
            UIBlockManager::ErrorAlert("Hodnoty týchto konektorov nie sú kompatibilné!");
		}
        else{
            UIBlockManager::ErrorAlert("Toto prepojenie by vytvorilo cyklus!");
		}

		this->in_click = nullptr;
		this->out_click = nullptr;
		return false;
	}
}

void UIBlockManager::ConnectionRemoving(InPort &p){
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

void UIBlockManager::ConnectionRemoving(OutPort &p){
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

void UIBlockManager::updateConnectionUI(Ports &p){
	for(UIConnections *c : ui_connections){
		if((*c) == p){
            c->raise();
            c->update();
		}
	}
}

UIBlockManager::~UIBlockManager(){
	for(UIConnections *c : ui_connections){
		delete c;
	}
}

void UIBlockManager::hoverConnectionUI(QPoint mouse){
	for(UIConnections *c : ui_connections){
		c->mouseHover(mouse);
	}
    tc.raise();
    tc.update();
}

void UIBlockManager::mouseMoveEvent(QMouseEvent *event){
	hoverConnectionUI(event->pos());
    tc.raise();
    tc.update();
	if(drag){
		pos_offset += event->pos() - drag_p;
		drag_p = event->pos();
		for (auto b : blocks) {
			static_cast<UIBlock<BlockBase>*>(b)->updateOffset(pos_offset);
		}
	}
}

void UIBlockManager::hideHoverConnectionUI(){
	for(UIConnections *c : ui_connections){
		c->mouseHover(false);
	}
    tc.raise();
    tc.update();
}

bool UIBlockManager::allInputsConnected(){
    if(!Manager::allInputsConnected()){
        UIBlockManager::ErrorAlert("Nie všetky vstupy sú pripojené!");
        return false;
    }
	return true;
}

void UIBlockManager::computeReset(){
	if(computedAsLast != nullptr){
		static_cast<UIBlock<BlockBase>*>(computedAsLast)->Highlight(false);
	}
	Manager::computeReset();
}

bool UIBlockManager::computeStep(){
	if(computedAsLast != nullptr){
		static_cast<UIBlock<BlockBase>*>(computedAsLast)->Highlight(false);
	}
	bool ret = Manager::computeStep();
	if(computedAsLast != nullptr){
		static_cast<UIBlock<BlockBase>*>(computedAsLast)->Highlight(true);
	}
	return ret;
}

bool UIBlockManager::computeAll(){
    if (Manager::computeAll()){
		return computeStep();
    } else{
		return false;
	}
}

void UIBlockManager::leaveEvent(QEvent *){
	hideHoverConnectionUI();
}

void UIBlockManager::mousePressEvent(QMouseEvent *event){
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

void UIBlockManager::mouseReleaseEvent(QMouseEvent *){
	drag = false;
}

void UIBlockManager::ErrorAlert(std::string message){
    QMessageBox alert;
    alert.setWindowTitle("Chyba");
    alert.setText(message.c_str());
    alert.show();
    alert.exec();
}



BlockDelete::BlockDelete(UIBlockManager &g) : graph(g){
    menu.addAction(QIcon(":/icons/delete.png"), "Vymazať");
}

void BlockDelete::ShowMenu(BlockBase *block){
    menu.move(QCursor::pos());
    if (menu.exec() != nullptr){
        graph.BlockRemoving(block);
    }
}
