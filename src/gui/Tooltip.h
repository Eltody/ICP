#pragma once
#include <QWidget>
#include <string>

//! Tooltips shown when hovering over connections
class Tooltip : public QWidget{
public:
    //! Function that renders labels in a tooltip
    static std::vector<std::string> TextLines(const std::string &text, int &width, int &height);
};
