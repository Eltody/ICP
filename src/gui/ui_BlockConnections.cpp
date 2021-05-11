/*! VUT FIT ICP
 * @file ui_BlockConnections.h
 * @brief Súbor pre vytvárenie prepojení blokov
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#include <QPainterPath>
#include <QPainter>
#include <QPen>
#include <algorithm>

#include "ui_BlockConnections.h"

const int UIConnections::ConnectionHoverSize = 15;
const QColor UIConnections::ConnectionCol = QColor(255, 255, 255);

UIConnections::UIConnections(InPortUI *in, OutPortUI *out, QWidget *parent)
    : QWidget(parent), p(parent), in(in), out(out){
    show();
    setAttribute(Qt::WA_TransparentForMouseEvents);
}

UIConnections::UIConnections(const UIConnections &other)
    : QWidget(other.p), p(other.p), in(other.in), out(other.out){ }

bool UIConnections::operator==(const InPort &p){
	return this->in == &p;
}

bool UIConnections::operator==(const OutPort &p){
	return this->out == &p;
}

bool UIConnections::operator==(const Ports &p){
	return (this->in == &p || this->out == &p);
}

bool operator==(const UIConnections &a, const UIConnections &b){
	return a.in == b.in;
}

QPainterPath UIConnections::computePath(){
    QPoint left = getLeft();
    QPoint right = getRight();

    QPainterPath path;
    path.moveTo(left);
    path.lineTo(right);

	return path;
}

void UIConnections::paintEvent(QPaintEvent *){
	resize(parentWidget()->size());
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
    QPen p(UIConnections::ConnectionCol);
	if(hover){
		p.setWidth(2);
    }
	painter.setPen(p);
	painter.drawPath(computePath());
}

QPoint UIConnections::getLeft(){
    return this->out->Pos();
}

QPoint UIConnections::getRight(){
    return this->in->Pos();
}

bool UIConnections::mouseHover(QPoint mouse){
    QPoint off = QPoint(UIConnections::ConnectionHoverSize / 2, UIConnections::ConnectionHoverSize / 2);
	hover = computePath().intersects(QRectF(mouse - off, mouse + off));
	update();
	return hover;
}

bool UIConnections::mouseHover(bool hover){
	this->hover = hover;
	update();
	return this->hover;
}

TempConnectionUI::TempConnectionUI(InPort **in, OutPort **out, QWidget *parent)
	: UIConnections(static_cast<InPortUI*>(*in), static_cast<OutPortUI*>(*out), parent),
	  in_c(in), out_c(out) {
	hover = false;
}

QPoint TempConnectionUI::getLeft(){
	if (*in_c == nullptr && *out_c == nullptr){
		//hide();
		return QPoint(0, 0);
	} else {
		//show();
		if (*out_c == nullptr){
			return mapFromGlobal(cursor().pos());
		} else {
			return (*static_cast<OutPortUI*>(*out_c)).Pos();
		}
	}
}

QPoint TempConnectionUI::getRight(){
	if (*in_c == nullptr && *out_c == nullptr){
		//hide();
		return QPoint(0, 0);
	} else {
		//show();
		if (*in_c == nullptr){
			return mapFromGlobal(cursor().pos());
		} else {
			return (*static_cast<InPortUI*>(*in_c)).Pos();
		}
	}
}

void TempConnectionUI::paintEvent(QPaintEvent *event){
	hover = false;
	UIConnections::paintEvent(event);
}
