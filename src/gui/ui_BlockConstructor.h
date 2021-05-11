
#pragma once
#include <QWidget>
#include <list>
#include "../core/BlockConstructor.h"

class UIBlockManager;

/**
 * @brief GUI vytváranie blokov
 */
class UIBlockConstructor : public BlockConstructor
{
private:
	QWidget *block_parent;
public:
    //! GUI Konštruktor bloku
    //! @param t BlockType bloku pre vytvorenie
	BlockBase* AllocBlock(BlockType t) override;

    UIBlockConstructor(UIBlockManager &g);
};
