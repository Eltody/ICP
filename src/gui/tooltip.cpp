#include "blockeditor.h"
#include "tooltip.h"

#include <QFontMetricsF>
#include <QPainterPath>
#include <QApplication>
#include <QPainter>
#include <QFont>
#include <vector>

std::vector<std::string> Tooltip::TextLines(const std::string &text, int &width, int &height){
    QFont SegoeUI("Segoe UI", 10);
    QFontMetrics fm(SegoeUI);
    int w = 0;
	std::vector<std::string> lines;
	std::string tmp;
	for(auto const &c : text){
		if(c == '\n'){
            int width = fm.horizontalAdvance(tmp.c_str());
			w = width > w ? width : w;
			lines.push_back(tmp);
			tmp.clear();
		} else {
			tmp += c;
		}
	}
    int h = fm.height();
	height = h;
	width = w;
	return lines;
}

Tooltip::Tooltip(QWidget *parent) : QWidget(parent) {
	setAttribute(Qt::WA_TransparentForMouseEvents);
}

void Tooltip::Move(int x, int y){
	move(x - width() / 2, y - height() / 2);
}

void Tooltip::Text(std::string text){
	this->text = text;
}

void Tooltip::paintEvent(QPaintEvent *)
{
	int w, h;
	auto lines = TextLines(text,w , h);

	resize(w + 2 * Style::TooltipHPadding,
		   h * static_cast<int>(lines.size()) + 2 * Style::TooltipPadding);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	painter.setPen(Style::TooltipOutlineCol);
	painter.setBrush(Style::TooltipBackgroundCol);

	QPainterPath path;
	path.addRoundedRect(QRectF(.5, .5, width() - 1, height() - 1), Style::TooltipRoundSize, Style::TooltipRoundSize);

	painter.drawPath(path);

	painter.setPen(Style::TooltipTextCol);
	int offset = h - 3;
	for(const std::string &line : lines){
		painter.drawText(Style::TooltipHPadding, offset + Style::TooltipPadding, line.c_str());
		offset += h;
	}
}
