
#pragma once
#include <QWidget>
#include <string>

//! Tooltips shown when hovering over connections
class Tooltip : public QWidget{
private:
    //! Label used in the tooltip
    std::string text;
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
    /**
     * @brief Tooltip constructor
     * @param parent The top-most widget (GraphUI)
     */
    explicit Tooltip(QWidget *parent = nullptr);
    /**
     * @brief Text of the tooltip
     * @param text Inner text
     */
    void Text(std::string text);
    /**
     * @brief Places the tooltip at the specified coordinates
     * @param x X-axis coordinate
     * @param y Y-axis coordinate
     */
    void Move(int x, int y);
protected:
    //! Rendering the tooltip
    void paintEvent(QPaintEvent *) override;
};
