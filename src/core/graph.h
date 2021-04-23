/*! VUT FIT ICP
 * @file graph.h
 * @brief Header súbor pre prácu a operáciami nad schémou
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <map>
#include <initializer_list>
#include <functional>
#include "port.h"
#include "blockbase.h"
#include "blockfactory.h"

/**
 * @brief Trieda - udržuje všetky informácie o schéme
 */
class Graph
{
private:
    //! Funkcia, ktorá sa volá pri každej zmene grafu
	std::function<void(void)> graphChanged;
	//! Block abstract factory
	BlockFactory bf;
protected:
    //! Názov schémy
    std::string name;
	//! Get block abstract factory
	virtual BlockFactory & GetBlockFactory();
    //! Zoznam všetkých nevykonaných blokov pre computeStep()
	std::list<BlockBase*> to_compute;
    //! Iterátor pre vykonávanie blokov
	std::list<BlockBase*>::iterator c_it;
    //! Referencia k poslednému vykonanému bloku
	BlockBase *last_computed;
public:
    //! Zoznam všetkých blokov
	std::list<BlockBase*> blocks;
    //! Zoznam všetkých pripojení
	std::map<InPort *, OutPort *> connections;

    //! Konštruktor
	Graph();

    //! Vráti názov schémy
    std::string GetName() const;
	
    //! @brief Nastaví nový názov pre schému
    //! @param name Nový názov schémy
    void SetName(const std::string name);

	//! Sets callback called on graph change
	void onGraphChange(std::function<void(void)> callback);

	//! Returns ID of a block in graph's block list
	int getBlockID(const BlockBase &block) const;

	//! Delete all blocks and connections - clear the scheme
	virtual void clearGraph();
	/**
	 * @brief Loads scheme from a GPH file.
	 * @param graph Reference to parent scheme object
	 * @param merge Flag that indicates merge mode
	 * (if true, loaded scheme will be overlapped through the existing one)
	 * @return True on success, else false
	 */
	virtual bool loadGraph(std::stringstream &graph, bool merge = false);
	/**
	 * @brief Generates the file that needs to be saved to a disk by another function.
	 * @return String stream object with GPH representation of a scheme
	 */
	virtual std::stringstream saveGraph();

	//! Adds new block specified by BlockType
	virtual BlockBase *addBlock(BlockType);
	/**
	 * @brief Removes a block form the scheme
	 * @param b Reference to a block to remove
	 */
	virtual void removeBlock(BlockBase *b);
	/**
	 * @brief Gets port on the other side of a connection
	 * @param p Input port of the connection
	 * @return Output port of the connection
	 */
	OutPort * getConnectedOutPort(InPort &p);
	/**
	 * @brief Add a connection between the blocks
	 * @param a Output port where the connection starts
	 * @param b Input port where the connection ends
	 * @return True if data type matched and connection didn't form a cycle, false otherwise
	 */
	virtual bool addConnection(OutPort &a, InPort &b);
	/**
	 * @brief Remove a connection
	 * @param p Input port
	 */
	virtual void removeConnection(InPort &p);
	/**
	 * @brief Remove a connection
	 * @param p Output port
	 */
	virtual void removeConnection(OutPort &p);
	/**
	 * @brief Checks if all inputs of all blocks are connected
	 * @return True when all inputs are connected, else false
	 */
	virtual bool allInputsConnected();
	/**
	 * @brief Resets the copution
	 */
	virtual void computeReset();
	/**
	 * @brief Computes one block in compute queue
	 * @return False when failed, else true
	 */
	virtual bool computeStep();
	/**
	 * @brief Computes the whole compute queue
	 * @return False when failed, else true
	 */
	virtual bool computeAll();
	/**
	 * @brief Informs that computation is finished
	 * @return True when all blocks were computed, else false
	 */
	bool computeFinished();
	/**
	 * @brief Checks that attempted connection doesn't forme a cycle
	 * @param a Output port where the connection starts
	 * @param b Input port where the connection ends
	 * @return True when connection doesn't form a cycle, false otherwise
	 */
	bool isAcyclic(OutPort &a, InPort &b);
};
