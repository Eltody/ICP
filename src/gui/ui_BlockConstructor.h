/*! VUT FIT ICP
 * @file EliteEditor.h
 * @brief Header súbor pre GUI vytváranie blokov
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

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
