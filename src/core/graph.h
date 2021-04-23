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
    //! Zoznam všetkých prepojení
	std::map<InPort *, OutPort *> connections;

    //! Konštruktor
	Graph();

    //! Vráti názov schémy
    std::string GetSchemeName() const;
	
    //! @brief Nastaví nový názov pre schému
    //! @param name Nový názov schémy
    void SetSchemeName(const std::string name);

	//! Sets callback called on graph change
	void onGraphChange(std::function<void(void)> callback);

    //! Vracia ID bloku, zo zoznamu blokov
    int getIDofBlock(const BlockBase &block) const;

    //! Vymaže všetky bloky a spojenia
    virtual void GraphClearing();
	/**
     * @brief Načíta GPH súbor ako schému
     * @param graph Reference to parent scheme object
	 * @param merge Flag that indicates merge mode
	 * (if true, loaded scheme will be overlapped through the existing one)
     * @return Vracia true pre úspešné vykonanie
	 */
    virtual bool GraphLoading(std::stringstream &graph, bool merge = false);
	/**
     * @brief Generuje súbor, ktorý bude uložený inou funkciou
     * @return Vracia string stream objekt s GPH reprezentáciou schémy
	 */
    virtual std::stringstream GraphSaving();

    //! Pridá nový blok do schémy špecifikovaný BlockTypom
	virtual BlockBase *addBlock(BlockType);
	/**
     * @brief Odstráni blok zo schémy
     * @param blockToRemove Referencia bloku na odstránenie
	 */
    virtual void BlockRemoving(BlockBase *blockToRemove);
	/**
     * @brief Získa port na druhej strane prepojenia
     * @param port Vstupný port prepojenia
     * @return Vracia výstupný port prepojenia
	 */
    OutPort * getConnectedOutPort(InPort &port);
	/**
     * @brief Pridá prepojenie medzi dva bloky
     * @param startingPointConnection Výstupný port, odkiaľ prichádza prepojenie
     * @param endingPointConnection Vstupný port, kde prepojenie končí
     * @return Vracia true, pokiaľ sedia dátové typy a prepojenie nevytvorilo cyklus
	 */
    virtual bool addConnection(OutPort &startingPointConnection, InPort &endingPointConnection);
	/**
     * @brief Zruší prepojenie vstupného portu
     * @param port Vstupný port
	 */
    virtual void ConnectionRemoving(InPort &port);
	/**
     * @brief Zruší pripojenie výstupného portu
     * @param port Výstupný port
	 */
    virtual void ConnectionRemoving(OutPort &port);
	/**
     * @brief Skontroluje, či sú všetky vstupné a výstupné porty blokov pripojené
     * @return Vracia true, pokiaľ sú všetky porty pripojené
	 */
	virtual bool allInputsConnected();
	/**
     * @brief Zruší vykonávanie akcií
	 */
	virtual void computeReset();
    /**
     * @brief Vykoná jednu akciu, ktorá čaká na vykonanie
     * @return Vracia true pri úspešnom vykonaní
	 */
	virtual bool computeStep();
	/**
     * @brief Vykoná všetky akcie, ktoré čakajú na vykonanie
     * @return Vracia true pri úspešnom vykonaní
	 */
	virtual bool computeAll();
	/**
	 * @brief Informs that computation is finished
     * @return Vracia true, pokiaľ sa vykonali všetky bloky
	 */
	bool computeFinished();
	/**
	 * @brief Checks that attempted connection doesn't forme a cycle
	 * @param a Output port where the connection starts
	 * @param b Input port where the connection ends
	 * @return True when connection doesn't form a cycle, false otherwise
	 */
    bool isAcyclic(OutPort &startingPointConnection, InPort &endingPointConnection);
};
