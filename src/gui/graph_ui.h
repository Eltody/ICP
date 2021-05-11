
#pragma once
#include <QMouseEvent>
#include <QPaintEvent>
#include <QWidget>
#include <QMenu>
#include <list>

#include "../core/BlockBase.h"
#include "../core/BlockManager.h"
#include "blockfactory_ui.h"
#include "connection_ui.h"


class BlockDelete{
private:
    //! Parent widget
    GraphUI &graph;
    //! Objekt zobrazujúceho sa menu
    QMenu menu;
public:
    //! Konštruktor
    BlockDelete(GraphUI &g);
    //! Function for showing the menu after right-clicking a block Funkcia pre zobrazenie menu po kliknutí pravého tlačidla
    void ShowMenu(BlockBase *block);
};


class ConnectionUI;

/**
 * @brief Parent QWidget to all other widgets used in scheme
 */
class GraphUI : public QWidget, public Manager{
public:
    //! Current offset of graph against main window
    QPoint pos_offset;
    //! List of graphical connections in GUI
    std::list<ConnectionUI*> ui_connections;
    GraphUI();
    //! Get offset of graph against main window
    QPoint getOffset() const;
    //! Delete the current scheme, get ready for a new scheme
    void JEEclear() override;
    /**
     * @brief Load scheme from a file
     * @param graph Scheme's parent widget
     * @param overlap Merge flag - file will overlap into existing scheme if true
     * @return True when file was loaded successfully, else false
     */
    bool JEEload(std::stringstream &graph, bool overlap = false) override;
    /**
     * @brief Prepare scheme for saving - generate stringstream GPH represaentation
     * @return GPH stringstream representation
     */
    std::stringstream JEEsave() override;
    //! Block's context menu
    void blockContextMenu(BlockBase *b);

    BlockBase *addBlock(BlockType t) override;
    //! Removes a block from the scheme
    void BlockRemoving(BlockBase *b) override;
    /**
     * @brief Adds a connection to the scheme if all conditions are met
     * @param a Output port where the connection starts
     * @param b Input port where the connection ends
     * @return True if connection was added, else false
     */
    bool addConnection(OutPort &a, InPort &b) override;
    /**
     * @brief Remove connection from the scheme
     *
     * @param p Input port
     */
    void ConnectionRemoving(InPort &p) override;
    /**
     * @brief Remove connection from the scheme
     *
     * @param p Output port
     */
    void ConnectionRemoving(OutPort &p) override;
    /**
     * @brief Replace detached side of the connection
     * @param p Ports, where the connection was detached
     */
    void updateConnectionUI(Ports &p);
    /**
     * @brief Show tooltip when connection is hovered while other connection is being attached to the second port
     * @param mouse QPoint coordinates
     */
    void hoverConnectionUI(QPoint mouse);
    //! Hides all connection tooltips
    void hideHoverConnectionUI();
    //! Checks that all inputs in the scheme are connected
    bool allInputsConnected() override;
    //! Sets the first block as next in compute queue
    void computeReset() override;
    //! Computes one next block in compute queue
    bool computeStep() override;
    //! Computes the whole scheme
    bool computeAll() override;
    //! Manager GUI destructor
    ~GraphUI();
    //! Temporary value used while creating a connection - port's address after one click
	InPort *in_click;
	//! Temporary value used while creating a connection - port's address after one click
	OutPort *out_click;
private:
	//! Temporary connection held between mouse and the first port while connecting to the other port
	TempConnectionUI tc;
	//! GUI Block factory
	BlockFactoryUI bf;
	//! Getting block factory (core)
	BlockConstructor & GetBlockFactory() override;
	//! Dragging state
	bool drag = false;
	//! Current dragging coordinates
	QPoint drag_p;
	//! Right click dropdown menu for block options
	BlockDelete block_context_menu;
    //! Warning/Error message
    void ErrorAlert(std::string message);
protected:
	//! Invokes actions triggered by mouse movement
	void mouseMoveEvent(QMouseEvent *event) override;
	//! Invokes actions triggered by mouse clicks
	void mousePressEvent(QMouseEvent *event) override;
	//! Invokes actions triggered by releasing the mouse button
	void mouseReleaseEvent(QMouseEvent *) override;
	//! Invokes actions triggered by mouse leaving a connection
	void leaveEvent(QEvent *) override;
};
