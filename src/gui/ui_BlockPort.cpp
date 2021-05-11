/*! VUT FIT ICP
 * @file ui_BlockPort.h
 * @brief Súbor pre GUI I/O portov
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

#include "ui_BlockManager.h"
#include "ui_BlockPort.h"

const int UIBlockPort::PortDrawSize = 10;
const int UIBlockPort::PortSize = 25;
const int UIBlockPort::PortMarginV = 30;
const int UIBlockPort::PortNamePadding = 15;
const QColor UIBlockPort::PortOutlineCol = QColor(0, 0, 0);
const QColor UIBlockPort::PortFreeCol = QColor(255, 255, 255);
const QColor UIBlockPort::PortHoverCol = QColor(175, 175, 175);

UIBlockPort::UIBlockPort(const std::string name, QWidget *parent)
	: QWidget(parent), p(parent), label(name.c_str(), parent){
    resize(UIBlockPort::PortSize + 2, UIBlockPort::PortSize + 2);

	show();
	label.show();

	setMouseTracking(true);
}

InPortUI::InPortUI(const InPortUI &other) : InPortUI(other, other.p){ }

InPortUI::InPortUI(const InPort &p, QWidget *parent)
    : UIBlockPort(p.name, parent), InPort(p){
	Move(0, 0);
}

void InPortUI::mouseMoveEvent(QMouseEvent *event){
	static_cast<UIBlockManager&>(this->block.graph).hoverConnectionUI(event->pos() + pos());
	UIBlockPort::mouseMoveEvent(event);
}

void InPortUI::mousePressEvent(QMouseEvent *event){
    setFocus();
    if(event->button() == Qt::LeftButton){
        UIBlockManager& g = dynamic_cast<UIBlockManager&>(block.graph);
        g.hideHoverConnectionUI();
        if(g.getConnectedOutPort(*this) == nullptr)
        {
            g.in_click = this;
            if (g.out_click != nullptr){
                g.addConnection(*g.out_click, *this);
            }
        }
        else{
            g.ConnectionRemoving(*this);
        }
    }
}

OutPortUI::OutPortUI(const OutPortUI &other) : OutPortUI(other, other.p){ }

OutPortUI::OutPortUI(const OutPort &p, QWidget *parent)
	: UIBlockPort(p.name, parent), OutPort(p) {
	Move(0, 0);
}

void OutPortUI::mouseMoveEvent(QMouseEvent *event){
	static_cast<UIBlockManager&>(this->block.graph).hoverConnectionUI(event->pos() + pos());
	UIBlockPort::mouseMoveEvent(event);
}

void OutPortUI::mousePressEvent(QMouseEvent *event){
	setFocus();
    if(event->button() == Qt::LeftButton){
        UIBlockManager& g = static_cast<UIBlockManager&>(block.graph);
        g.hideHoverConnectionUI();
        g.out_click = this;
        if (g.in_click != nullptr){
            g.addConnection(*this, *g.in_click);
        }
    }
}

int UIBlockPort::getWidth() const{
    return UIBlockPort::PortNamePadding * 2 + QApplication::fontMetrics().width(label.text());
}

void InPortUI::Move(int x, int y){
    move(x - UIBlockPort::PortSize/2 - 1, y - UIBlockPort::PortSize/2 - 1);
    label.move(x + UIBlockPort::PortNamePadding, y - label.height() / 2);

	UIBlockManager &g = static_cast<UIBlockManager&>(this->block.graph);
	g.updateConnectionUI(*this);
}

void OutPortUI::Move(int x, int y){
    move(x - UIBlockPort::PortSize/2 - 1, y - UIBlockPort::PortSize/2 - 1);
    label.move(x - UIBlockPort::PortNamePadding - label.width(), y - label.height() / 2);

	UIBlockManager &g = static_cast<UIBlockManager&>(this->block.graph);
	g.updateConnectionUI(*this);
}

void UIBlockPort::paintEvent(QPaintEvent *){
	QPainter painter(this);
    QRectF rectangle(9, 9, 8, 8);

    painter.setPen(UIBlockPort::PortOutlineCol);
	if(hover){
        painter.setBrush(UIBlockPort::PortHoverCol); //hover
	} else {
        painter.setBrush(UIBlockPort::PortFreeCol); //free
	}
    painter.drawRect(rectangle);
}

void UIBlockPort::mouseMoveEvent(QMouseEvent *event){
    QPoint diff = (event->pos() - QPoint(UIBlockPort::PortSize/2, UIBlockPort::PortSize/2));
    int dist = std::sqrt(diff.x()*diff.x() + diff.y()*diff.y());
    hover = (dist <= UIBlockPort::PortSize/2);
	update();
}

void UIBlockPort::leaveEvent(QEvent *){
	hover = false;
	update();
}

QPoint UIBlockPort::Pos(){
    return QPoint(pos().x() + UIBlockPort::PortSize/2 + 1, pos().y() + UIBlockPort::PortSize/2 + 1);
}
