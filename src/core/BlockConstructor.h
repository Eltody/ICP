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
 * @brief Abstract factory for creating blocks
 *
 * Blocks are created using abstract factory design patern.
 */
class BlockConstructor{
protected:
	//! Main widget that contains the scheme
	Manager &g;
	//! List of all blocks
	std::list<BlockBase*> blocks;
public:
	//! @brief Block constructor
	//! @param t BlockType of block to construct
	virtual BlockBase* AllocBlock(BlockType t);
	//! @brief Block destructor
	//! @param b Address of the block to destruct
	virtual void FreeBlock(BlockBase *b);
	//! @brief Factory constructor
	//! @param g Parent scheme object
    BlockConstructor(Manager &g);
	
    virtual ~BlockConstructor(); // destruktor
};
