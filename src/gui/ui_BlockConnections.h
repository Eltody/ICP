
#pragma once
#include <QPoint>
#include <QWidget>
#include <QPaintEvent>

#include "Tooltip.h"
#include "ui_BlockPort.h"

//! Widget for connection graphical representation
class UIConnections : public QWidget{
protected:
	//! Parent widget
	QWidget *p;
	//! Connection terminates here
	InPortUI *in;
	//! Connection starts here
	OutPortUI *out;
	//! Adjusts the line shape and position
	QPainterPath computePath();
	//! Mouse hover state
    bool hover = false;
    //! Provides start point for path compution
    virtual QPoint getLeft();
    //! Provides end point for path compution
    virtual QPoint getRight();
public:
	/**
	 * @brief Connection constructor
	 * @param in Input port
	 * @param out Output port
	 * @param parent Parent widget containing the scheme
	 */
    explicit UIConnections(InPortUI *in, OutPortUI *out, QWidget *parent = nullptr);
	//! Connection constructor
    UIConnections(const UIConnections &other);
	//! Overloading operator == for input port comparison
	bool operator==(const InPort &p);
	//! Overloading operator == for output port comparison
	bool operator==(const OutPort &p);
	//! Overloading operator == for any port comparison
	bool operator==(const Ports &p);
	//! Overloading operator == for connection comparison (based on input ports)
    friend bool operator==(const UIConnections &a, const UIConnections &b);
	//! Activating hover state by mouse
	bool mouseHover(QPoint mouse);
	//! Activating hover state by function call
	bool mouseHover(bool hover);
    //! Connection line width when hovered
    static const int ConnectionHoverSize;
    //! Connection line color
    static const QColor ConnectionCol;
protected:
	void paintEvent(QPaintEvent *event) override;
};

//! Temporary connection for visualising unfinished connection
class TempConnectionUI : public UIConnections{
private:
	//! Input port
	InPort **in_c;
	//! Output port
	OutPort **out_c;
protected:
    //! Get starting coordinates
    QPoint getLeft() override;
    //! Get end coordinates
    QPoint getRight() override;
	//! Actual rendering of the connection
	void paintEvent(QPaintEvent *) override;
public:
	/**
	 * @brief Temp connection constructor
	 * @param in Input port
	 * @param out Output port
	 * @param parent Parent widget where the whole scheme is stored
	 */
	TempConnectionUI(InPort **in, OutPort **out, QWidget *parent = nullptr);
};
