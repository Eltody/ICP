/*! VUT FIT ICP
 * @file ui_BlockPort.h
 * @brief Header súbor pre GUI I/O portov
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

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
 * @brief GUI reprezentácia vstupných portov
 */
class InPortUI : public UIBlockPort, public InPort{
public:
	InPortUI(const InPortUI &other);
	explicit InPortUI(const InPort &p, QWidget *parent = nullptr);
    //! Presuň na súradnice
	void Move(int x, int y) override;
protected:
    //! Vyvolá akcie pri pohybe myšou
	void mouseMoveEvent(QMouseEvent *event) override;
    //! Vyvolá akcie pri kliknutí myšou
	void mousePressEvent(QMouseEvent *) override;
};

/**
 * @brief GUI reprezentácia výstupných portov
 */
class OutPortUI : public UIBlockPort, public OutPort{
public:
    //! Konštruktor
	OutPortUI(const OutPortUI &other);
	explicit OutPortUI(const OutPort &p, QWidget *parent = nullptr);
    //! Presuň na súradnice
	void Move(int x, int y) override;
protected:
    //! Vyvolá akcie pri pohybe myšou
	void mouseMoveEvent(QMouseEvent *event) override;
    //! Vyvolá akcie pri kliknutí myšou
	void mousePressEvent(QMouseEvent *) override;
};
