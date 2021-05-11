/*! VUT FIT ICP
 * @file port.h
 * @brief Porty pre bloky a vytvorenie menu pri right click-u na blok
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */


#include "BlockPort.h"
#include "blockbase.h"


Ports::Ports(const Ports &other) : data(other.data, this),
	connUpdate(other.connUpdate), valUpdate(other.valUpdate),
	block(other.block), name(other.name) { }


Ports::Ports(const BlockBase &b, const Type &t, std::string name)
	: data(t, this), block(b), name(name) { }


void Ports::eventValueChange(){
    if (valUpdate)
		valUpdate(*this);
}


void Ports::eventConnectionChange(){
    if (connUpdate)
        connUpdate(*this);
}


void Ports::onConnectionChange(std::function<void (Ports &)> callback){
	this->connUpdate = callback;
}


void Ports::onValueChange(std::function<void (Ports &)> callback){
	this->valUpdate = callback;
}


TypeValue &Ports::operator[](const std::string &s){
	return Value()[s];
}


int InPort::getID() const{
	return this->block.getPortID(*this);
}


InPort::InPort(const InPort &other, const BlockBase &b) : InPort(b, other.data, other.name){ }


InPort::InPort(const BlockBase &b, const Type &t, std::string name) : Ports(b, t, name){ }


Type &InPort::Value(){
	const auto &conn = this->block.graph.connections;
    if (conn.find(this) != conn.end()){
		OutPort *port = this->block.graph.connections.at(this);
        if(port != nullptr)
			return port->Value(); // return value from connected port
	}
	return this->data;
}


void OutPort::eventValueChange(){
    Ports::eventValueChange();
    for (auto &c : this->block.graph.connections){
        if (this == c.second)
			c.first->eventValueChange();
	}
}


int OutPort::getID() const{
	return this->block.getPortID(*this);
}


OutPort::OutPort(const OutPort &other, const BlockBase &b) : OutPort(b, other.data, other.name){ }


OutPort::OutPort(const BlockBase &b, const Type &t, std::string name) : Ports(b, t, name){ }


Type &OutPort::Value(){
	return this->data;
}
