#include <QPainterPath>
#include <QPainter>
#include <QPen>
#include <algorithm>

#include "connection_ui.h"

const int ConnectionUI::ConnectionHoverSize = 15;
const QColor ConnectionUI::ConnectionCol = QColor(255, 255, 255);

ConnectionUI::ConnectionUI(InPortUI *in, OutPortUI *out, QWidget *parent)
    : QWidget(parent), p(parent), t(parent), in(in), out(out){
    show();
    setAttribute(Qt::WA_TransparentForMouseEvents);
}

ConnectionUI::ConnectionUI(const ConnectionUI &other)
    : QWidget(other.p), p(other.p), t(other.p), in(other.in), out(other.out){ }

bool ConnectionUI::operator==(const InPort &p){
	return this->in == &p;
}

bool ConnectionUI::operator==(const OutPort &p){
	return this->out == &p;
}

bool ConnectionUI::operator==(const Port &p){
	return (this->in == &p || this->out == &p);
}

bool operator==(const ConnectionUI &a, const ConnectionUI &b){
	return a.in == b.in;
}

QPainterPath ConnectionUI::computePath(){
    QPoint left = getLeft();
    QPoint right = getRight();

    QPainterPath path;
    path.moveTo(left);
    path.lineTo(right);

	return path;
}

void ConnectionUI::showValue(){
	t.move(mapFromGlobal(QCursor::pos()));
	t.Text(out->Value());
	t.show();
	t.raise();
}

void ConnectionUI::hideValue(){
	t.hide();
}

void ConnectionUI::paintEvent(QPaintEvent *){
	resize(parentWidget()->size());
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
    QPen p(ConnectionUI::ConnectionCol);
	if(hover){
		p.setWidth(2);
		showValue();
    } else{
		hideValue();
	}
	painter.setPen(p);
	painter.drawPath(computePath());
}

QPoint ConnectionUI::getLeft(){
    return this->out->Pos();
}

QPoint ConnectionUI::getRight(){
    return this->in->Pos();
}

bool ConnectionUI::mouseHover(QPoint mouse){
    QPoint off = QPoint(ConnectionUI::ConnectionHoverSize / 2, ConnectionUI::ConnectionHoverSize / 2);
	hover = computePath().intersects(QRectF(mouse - off, mouse + off));
	update();
	return hover;
}

bool ConnectionUI::mouseHover(bool hover){
	this->hover = hover;
	update();
	return this->hover;
}

TempConnectionUI::TempConnectionUI(InPort **in, OutPort **out, QWidget *parent)
	: ConnectionUI(static_cast<InPortUI*>(*in), static_cast<OutPortUI*>(*out), parent),
	  in_c(in), out_c(out) {
	hover = false;
	t.hide();
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
	ConnectionUI::paintEvent(event);
}
