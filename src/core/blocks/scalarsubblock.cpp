/** ICP Project 2017/2018: BlockEditor
 * @file scalarsubblock.cpp
 * @brief Scalar subtraction block's operation and ports definition
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#include "scalarsubblock.h"
#include "../types/types.h"
#include "../blocks.h"

ScalarSubBlock::ScalarSubBlock(Graph &g)
	: BlockBase(g, SCALAR_SUB, BLOCK_NAME.at(SCALAR_SUB),
    {
        InPort(*this, scal(), "Skalár A"),
        InPort(*this, scal(), "Skalár B")
    },
    {
        OutPort(*this, scal(), "Výstup")
    }
    ){}

void ScalarSubBlock::Compute(){
    this->Output(0)["val"] = this->Input(0)["val"] - this->Input(1)["val"];
}

