/*! VUT FIT ICP
 * @file BlockManager.h
 * @brief Header súbor pre prácu so schémou a uchovanie informácií o schéme
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
#include "BlockPort.h"
#include "BlockBase.h"
#include "BlockConstructor.h"

/**
 * @brief Trieda - udržuje všetky informácie o schéme
 */
class Manager{
private:
    //! Funkcia, ktorá sa volá pri každej zmene grafu
	std::function<void(void)> graphChanged;
	BlockConstructor bf;
protected:
    //! Názov schémy
    std::string name;
	//! Get block abstract factory
	virtual BlockConstructor & GetBlockFactory();
    //! Zoznam všetkých nevykonaných blokov pre computeStep()
    std::list<BlockBase*> needToBeComputed;
    //! Iterátor pre vykonávanie blokov
    std::list<BlockBase*>::iterator blocks_iterator;
    //! Referencia k poslednému vykonanému bloku
    BlockBase *computedAsLast;
public:
    //! Zoznam všetkých blokov
	std::list<BlockBase*> blocks;
    //! Zoznam všetkých prepojení
	std::map<InPort *, OutPort *> connections;

    //! Konštruktor
    Manager();

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
    virtual void JEEclear();
	/**
     * @brief Načíta GPH súbor ako schému
     * @param graph Reference to parent scheme object
     * @param overlap Príznak, pokiaľ true, načítaná schéma prekryje existujúcu schému
     * @return Vracia true pre úspešné vykonanie
	 */
    virtual bool JEEload(std::stringstream &graph, bool overlap = false);
	/**
     * @brief Generuje súbor, ktorý bude uložený inou funkciou
     * @return Vracia string stream objekt s GPH reprezentáciou schémy
	 */
    virtual std::stringstream JEEsave();

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
     * @param startPointConnection Výstupný port, kde prepojenie začína
     * @param endPointConnection Vstupný port, kde prepojenie končí
     * @return Vracia true, pokiaľ sedia dátové typy a prepojenie nevytvorilo cyklus
	 */
    virtual bool addConnection(OutPort &startPointConnection, InPort &endPointConnection);
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
     * @brief Informuje o dokončení vykonávania akcie
     * @return Vracia true, pokiaľ sa vykonali všetky bloky
	 */
	bool computeFinished();
	/**
     * @brief Kontroluje či by prepojenie nevytvorilo cyklus
     * @param startPointConnection Výstupný port, kde prepojenie začína
     * @param endPointConnection Vstupný port, kde prepojenie končí
     * @return Vracia true, pokiaľ prepojenie nevytvorilo cyklus
	 */
    bool AcyclicBlocks(OutPort &startPointConnection, InPort &endPointConnection);
};
