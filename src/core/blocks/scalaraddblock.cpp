/** ICP Project 2017/2018: BlockEditor
 * @file scalaraddblock.cpp
 * @brief Scalar addition block's operation and ports definition
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#include "scalaraddblock.h"
#include "../types/types.h"
#include "../blocks.h"

ScalarAddBlock::ScalarAddBlock(Graph &g)
	: BlockBase(g, SCALAR_ADD, BLOCK_NAME.at(SCALAR_ADD),
    {
        InPort(*this, scal(), "Skalár A"),
        InPort(*this, scal(), "Skalár B")
    },
    {
        OutPort(*this, scal(), "Výstup")
    }
    ){}

void ScalarAddBlock::Compute(){
    this->Output(0)["val"] = this->Input(0)["val"] + this->Input(1)["val"];
}
