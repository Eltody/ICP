
#pragma once
#include <QPaintEvent>
#include <QMouseEvent>
#include <QWidget>
#include <QLabel>
#include <QPoint>
#include <string>
#include "../core/BlockPort.h"

/**
 * @brief Abstract class pre GUI reprezentáciu
 */
class UIBlockPort : public QWidget{
protected:
	QWidget *p;
	bool hover = false;
	QLabel label;
    UIBlockPort(const std::string name, QWidget *parent = nullptr);

	void paintEvent(QPaintEvent *) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void leaveEvent(QEvent *) override;
public:
    //! Súradnice bloku
	QPoint Pos();
    //! Prenos na súradnice
	virtual void Move(int x, int y) = 0;
	int getWidth() const;
    static const int PortSize;
    static const int PortDrawSize;
    static const int PortMarginV;
    static const int PortNamePadding;
    static const QColor PortOutlineCol;
    static const QColor PortFreeCol;
    static const QColor PortHoverCol;
};

/**
 * @brief Input ports GUI representation
 */
class InPortUI : public UIBlockPort, public InPort{
public:
	//! Copy constructor
	InPortUI(const InPortUI &other);
	//! Input port constructor (decorator pattern)
	explicit InPortUI(const InPort &p, QWidget *parent = nullptr);
	//! Move to coordinates
	void Move(int x, int y) override;
protected:
	//! Event that invokes actions triggered by mouse movement
	void mouseMoveEvent(QMouseEvent *event) override;
	//! Event that invokes actions triggered by mouse clicks
	void mousePressEvent(QMouseEvent *) override;
};

/**
 * @brief Output ports GUI representation
 */
class OutPortUI : public UIBlockPort, public OutPort{
public:
	//! Copy constructor
	OutPortUI(const OutPortUI &other);
	//! Output port constructor (decorator pattern)
	explicit OutPortUI(const OutPort &p, QWidget *parent = nullptr);
	//! Move to coordinates
	void Move(int x, int y) override;
protected:
	//! Event that invokes actions triggered by mouse movement
	void mouseMoveEvent(QMouseEvent *event) override;
	//! Event that invokes actions triggered by mouse clicks
	void mousePressEvent(QMouseEvent *) override;
};
