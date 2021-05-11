
#pragma once
#include <QPoint>
#include <QWidget>
#include <QPaintEvent>

#include "Tooltip.h"
#include "ui_BlockPort.h"

//! Grafické prepojenie
class UIConnections : public QWidget{
protected:
    QWidget *p;
    InPortUI *in;
    OutPortUI *out;
    QPainterPath computePath();
    bool hover = false;
    virtual QPoint getLeft();
    virtual QPoint getRight();

public:
    /**
     * @brief Konštruktor prepojenia
     * @param in Vstupný port
     * @param out Výstupný port
     * @param parent Parent widget obsahujuci schemu
     */
    explicit UIConnections(InPortUI *in, OutPortUI *out, QWidget *parent = nullptr);
    //! Konštruktor prepojenia
    UIConnections(const UIConnections &other);
    //! Pre porovnanie vstupného portu
    bool operator==(const InPort &p);
    //! Pre porovnanie výstupného portu
    bool operator==(const OutPort &p);
    //! Pre porovnanie akéhokoľvek portu
    bool operator==(const Ports &p);
    friend bool operator==(const UIConnections &a, const UIConnections &b);
    bool mouseHover(QPoint mouse);
    bool mouseHover(bool hover);
    static const int ConnectionHoverSize;
    //! farba prepojenia
    static const QColor ConnectionCol;
protected:
    void paintEvent(QPaintEvent *event) override;
};

//! Dočasné prepojenie zobrazujuce nedokončoné prepojenie
class TempConnectionUI : public UIConnections{
private:
    //! Vstupný port
    InPort **in_c;
    //! Výstupný port
    OutPort **out_c;
protected:
    //! Súradnice začiatku
    QPoint getLeft() override;
    //! Súradnice konca
    QPoint getRight() override;
    //! Vykreslovanie prepojenia
    void paintEvent(QPaintEvent *) override;
public:
    /**
     * @brief Konštruktor dočasného prepojenia
     * @param in Vstupný port
     * @param out Výstupný port
     * @param parent Parent widget kde bude schéma uložené
     */
    TempConnectionUI(InPort **in, OutPort **out, QWidget *parent = nullptr);
};
