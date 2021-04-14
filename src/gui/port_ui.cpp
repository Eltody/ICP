/*! VUT FIT ICP
 * @file port_ui.cpp
 * @brief
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#include <QPainterPath>
#include <QApplication>
#include <QPainter>
#include <QCursor>
#include <QColor>
#include <QRectF>
#include <cmath>

#include "graph_ui.h"
#include "port_ui.h"

const int PortBaseUI::PortDrawSize = 10;
const int PortBaseUI::PortSize = 25;
const int PortBaseUI::PortMarginV = 30;
const int PortBaseUI::PortNamePadding = 15;
const QColor PortBaseUI::PortOutlineCol = QColor(0, 0, 0);
const QColor PortBaseUI::PortFreeCol = QColor(255, 255, 255);
const QColor PortBaseUI::PortHoverCol = QColor(175, 175, 175);

PortBaseUI::PortBaseUI(const std::string name, QWidget *parent)
	: QWidget(parent), p(parent), label(name.c_str(), parent){
    resize(PortBaseUI::PortSize + 2, PortBaseUI::PortSize + 2);

	show();
	label.show();

	setMouseTracking(true);
}

InPortUI::InPortUI(const InPortUI &other) : InPortUI(other, other.p){ }

InPortUI::InPortUI(const InPort &p, QWidget *parent)
    : PortBaseUI(p.name, parent), InPort(p){
	Move(0, 0);
}

void InPortUI::mouseMoveEvent(QMouseEvent *event){
	static_cast<GraphUI&>(this->block.graph).hoverConnectionUI(event->pos() + pos());
	PortBaseUI::mouseMoveEvent(event);
}

void InPortUI::mousePressEvent(QMouseEvent *event){
    setFocus();
    if(event->button() == Qt::LeftButton){
        GraphUI& g = dynamic_cast<GraphUI&>(block.graph);
        g.hideHoverConnectionUI();
        if(g.getConnectedOutPort(*this) == nullptr)
        {
            g.in_click = this;
            if (g.out_click != nullptr){
                g.addConnection(*g.out_click, *this);
            }
        }
        else{
            g.removeConnection(*this);
        }
    }
}

OutPortUI::OutPortUI(const OutPortUI &other) : OutPortUI(other, other.p){ }

OutPortUI::OutPortUI(const OutPort &p, QWidget *parent)
	: PortBaseUI(p.name, parent), OutPort(p) {
	Move(0, 0);
}

void OutPortUI::mouseMoveEvent(QMouseEvent *event){
	static_cast<GraphUI&>(this->block.graph).hoverConnectionUI(event->pos() + pos());
	PortBaseUI::mouseMoveEvent(event);
}

void OutPortUI::mousePressEvent(QMouseEvent *event){
	setFocus();
    if(event->button() == Qt::LeftButton){
        GraphUI& g = static_cast<GraphUI&>(block.graph);
        g.hideHoverConnectionUI();
        g.out_click = this;
        if (g.in_click != nullptr){
            g.addConnection(*this, *g.in_click);
        }
    }
}

int PortBaseUI::getWidth() const{
    return PortBaseUI::PortNamePadding * 2 + QApplication::fontMetrics().width(label.text());
}

void InPortUI::Move(int x, int y){
    move(x - PortBaseUI::PortSize/2 - 1, y - PortBaseUI::PortSize/2 - 1);
    label.move(x + PortBaseUI::PortNamePadding, y - label.height() / 2);

	GraphUI &g = static_cast<GraphUI&>(this->block.graph);
	g.updateConnectionUI(*this);
}

void OutPortUI::Move(int x, int y){
    move(x - PortBaseUI::PortSize/2 - 1, y - PortBaseUI::PortSize/2 - 1);
    label.move(x - PortBaseUI::PortNamePadding - label.width(), y - label.height() / 2);

	GraphUI &g = static_cast<GraphUI&>(this->block.graph);
	g.updateConnectionUI(*this);
}

void PortBaseUI::paintEvent(QPaintEvent *){
	QPainter painter(this);
    QRectF rectangle(9, 9, 8, 8);

    painter.setPen(PortBaseUI::PortOutlineCol);
	if(hover){
        painter.setBrush(PortBaseUI::PortHoverCol); //hover
	} else {
        painter.setBrush(PortBaseUI::PortFreeCol); //free
	}
    painter.drawRect(rectangle);
}

void PortBaseUI::mouseMoveEvent(QMouseEvent *event){
    QPoint diff = (event->pos() - QPoint(PortBaseUI::PortSize/2, PortBaseUI::PortSize/2));
    int dist = std::sqrt(diff.x()*diff.x() + diff.y()*diff.y());
    hover = (dist <= PortBaseUI::PortSize/2);
	update();
}

void PortBaseUI::leaveEvent(QEvent *){
	hover = false;
	update();
}

QPoint PortBaseUI::Pos(){
    return QPoint(pos().x() + PortBaseUI::PortSize/2 + 1, pos().y() + PortBaseUI::PortSize/2 + 1);
}
