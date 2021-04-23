#pragma once
#include "blocks.h"
#include <list>

class Graph;
class BlockBase;

/**
 * @brief Abstract factory for creating blocks
 *
 * Blocks are created using abstract factory design patern.
 */
class BlockFactory {
protected:
	//! Main widget that contains the scheme
	Graph &g;
	//! List of all blocks
	std::list<BlockBase*> blocks;
public:
	//! @brief Block constructor
	//! @param t Type of block to construct
	virtual BlockBase* AllocBlock(BlockType t);
	//! @brief Block destructor
	//! @param b Address of the block to destruct
	virtual void FreeBlock(BlockBase *b);
	//! @brief Factory constructor
	//! @param g Parent scheme object
	BlockFactory(Graph &g);
	
    virtual ~BlockFactory(); // destruktor
};
