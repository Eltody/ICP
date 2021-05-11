
#pragma once
#include <QWidget>
#include <list>
#include "../core/BlockConstructor.h"

class GraphUI;

/**
 * @brief Abstract factory for creating GUI blocks
 *
 * Blocks are created using abstract factory design patern.
 */
class BlockFactoryUI : public BlockConstructor
{
private:
	//! Widged used as parent for constructed blocks
	QWidget *block_parent;
public:
	//! GUI Block constructor
	//! @param t BlockType of block to construct
	BlockBase* AllocBlock(BlockType t) override;

	//! Factory constructor
	//! @param g Parent scheme object
	BlockFactoryUI(GraphUI &g);
};
