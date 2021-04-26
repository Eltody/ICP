
#pragma once
#include <QWidget>
#include <string>

//! Tooltips shown when hovering over connections
class Tooltip : public QWidget{
public:
    //! Tooltip corner rounding size
    static const int TooltipRoundSize;
    //! Tooltip padding
    static const int TooltipPadding;
    //! Tooltip horizontal padding
    static const int TooltipHPadding;
    //! Tooltip outline color
    static const QColor TooltipOutlineCol;
    //! Tooltip background color
    static const QColor TooltipBackgroundCol;
    //! Tooltip text color
    static const QColor TooltipTextCol;

    //! Function that renders labels in a tooltip
    static std::vector<std::string> TextLines(const std::string &text, int &width, int &height);
};
