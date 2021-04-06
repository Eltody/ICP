#include <QPainterPath>
#include <QApplication>
#include <QPainter>
#include <vector>

#include "tooltip.h"

const int Tooltip::TooltipRoundSize = 10;
const int Tooltip::TooltipPadding = 10;
const int Tooltip::TooltipHPadding = 18;
const QColor Tooltip::TooltipOutlineCol = QColor(0, 0, 0, 0);
const QColor Tooltip::TooltipBackgroundCol = QColor(76, 76, 76);
const QColor Tooltip::TooltipTextCol = QColor(255, 255, 255);

std::vector<std::string> Tooltip::TextLines(const std::string &text, int &width, int &height){
    int w = 0;
	std::vector<std::string> lines;
	std::string tmp;
	for(auto const &c : text){
		if(c == '\n'){
            int width = QApplication::fontMetrics().width(tmp.c_str());
			w = width > w ? width : w;
			lines.push_back(tmp);
			tmp.clear();
		} else {
			tmp += c;
		}
	}
    int h = QApplication::fontMetrics().height();
	height = h;
	width = w;
	return lines;
}

Tooltip::Tooltip(QWidget *parent) : QWidget(parent){
	setAttribute(Qt::WA_TransparentForMouseEvents);
}

void Tooltip::Move(int x, int y){
	move(x - width() / 2, y - height() / 2);
}

void Tooltip::Text(std::string text){
	this->text = text;
}

void Tooltip::paintEvent(QPaintEvent *){
	int w, h;
	auto lines = TextLines(text,w , h);

    resize(w + 2 * Tooltip::TooltipHPadding,
           h * static_cast<int>(lines.size()) + 2 * Tooltip::TooltipPadding);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(Tooltip::TooltipOutlineCol);
    painter.setBrush(Tooltip::TooltipBackgroundCol);

	QPainterPath path;
    path.addRoundedRect(QRectF(.5, .5, width() - 1, height() - 1), Tooltip::TooltipRoundSize, Tooltip::TooltipRoundSize);

	painter.drawPath(path);

    painter.setPen(Tooltip::TooltipTextCol);
	int offset = h - 3;
	for(const std::string &line : lines){
        painter.drawText(Tooltip::TooltipHPadding, offset + Tooltip::TooltipPadding, line.c_str());
		offset += h;
	}
}
