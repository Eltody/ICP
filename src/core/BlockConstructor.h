/*! VUT FIT ICP
 * @file blockbase.h
 * @brief Header súbor pre kontrolu a prácu s portami
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#pragma once
#include "Blocks.h"
#include <list>

class Manager;
class BlockBase;

/**
 * @brief Vytváranie blokov
 */
class BlockConstructor{
protected:
    //! Schéma
	Manager &g;
    //! Zoznam všetkých blokov
	std::list<BlockBase*> blocks;
public:
    //! @brief Konštruktor bloku
    //! @param t Typ bloku pre vytvorenie
	virtual BlockBase* AllocBlock(BlockType t);
    //! @brief Deštruktor bloku
    //! @param b Adresa bloku na vymazanie
	virtual void FreeBlock(BlockBase *b);

    BlockConstructor(Manager &g); // konštruktor
    virtual ~BlockConstructor(); // deštruktor
};
