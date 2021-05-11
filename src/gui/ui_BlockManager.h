/*! VUT FIT ICP
 * @file EliteEditor.h
 * @brief Header súbor pre prácu s blokmi - vymazanie
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#pragma once
#include <QMouseEvent>
#include <QPaintEvent>
#include <QWidget>
#include <QMenu>
#include <list>

#include "../core/BlockBase.h"
#include "../core/BlockManager.h"
#include "ui_BlockConstructor.h"
#include "ui_BlockConnections.h"


class BlockDelete{
private:
    //! Parent widget
    UIBlockManager &graph;
    //! Objekt zobrazujúceho sa menu
    QMenu menu;
public:
    //! Konštruktor
    BlockDelete(UIBlockManager &g);
    //! Funkcia pre zobrazenie menu po kliknutí pravého tlačidla
    void ShowMenu(BlockBase *block);
};


class UIConnections;

/**
 * @brief Parent QWidget pre všetky widgets v schéme
 */
class UIBlockManager : public QWidget, public Manager{
public:
    //! Aktuálny offset
    QPoint pos_offset;
    //! GUI Zoznam prepojení
    std::list<UIConnections*> ui_connections;
    UIBlockManager();

    QPoint getOffset() const;
    //! Zmazanie aktualnej schémy
    void JEEclear() override;
    /**
     * @brief Načítanie schémy zo súboru
     * @param graph Parent widget schémy
     * @param overlap Merge pri existujucej schéme
     * @return True Vracia true pri správnom načítaní súboru
     */
    bool JEEload(std::stringstream &graph, bool overlap = false) override;

    std::stringstream JEEsave() override;

    void blockContextMenu(BlockBase *b);

    BlockBase *addBlock(BlockType t) override;
    //! Vymazanie bloku zo schemy
    void BlockRemoving(BlockBase *b) override;

    bool addConnection(OutPort &a, InPort &b) override;

    void ConnectionRemoving(InPort &p) override;

    void ConnectionRemoving(OutPort &p) override;

    void updateConnectionUI(Ports &p);
    void hoverConnectionUI(QPoint mouse);
    void hideHoverConnectionUI();
    bool allInputsConnected() override;

    void computeReset() override;
    bool computeStep() override;
    bool computeAll() override;
    ~UIBlockManager();

	InPort *in_click;
	OutPort *out_click;
private:
    //! Dočasné prepojenie pri prvom kliknutí myši a vyberanie portu
	TempConnectionUI tc;
	UIBlockConstructor bf;
	BlockConstructor & GetBlockFactory() override;
	bool drag = false;
	QPoint drag_p;

	BlockDelete block_context_menu;
    //! Error správa
    void ErrorAlert(std::string message);
protected:
    //! vyvolanie akcií myši
	void mouseMoveEvent(QMouseEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *) override;
	void leaveEvent(QEvent *) override;
};
