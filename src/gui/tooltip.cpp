/*! VUT FIT ICP
 * @file tooltip.cpp
 * @brief
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

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
