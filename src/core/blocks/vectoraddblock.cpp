/** ICP Project 2017/2018: BlockEditor
 * @file vectoraddblock.cpp
 * @brief Vector addition block's operation and ports definition
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#include "vectoraddblock.h"
#include "../types/types.h"
#include "../blocks.h"

VectorAddBlock::VectorAddBlock(Graph &g)
	: BlockBase(g, VECTOR_ADD, BLOCK_NAME.at(VECTOR_ADD),
	{
        InPort(*this, vec2(), "Vektor A"),
        InPort(*this, vec2(), "Vektor B")
	},
	{
        OutPort(*this, vec2(), "Výstup")
	}
	){}

void VectorAddBlock::Compute(){
	this->Output(0)["x"] = this->Input(0)["x"] + this->Input(1)["x"];
	this->Output(0)["y"] = this->Input(0)["y"] + this->Input(1)["y"];
}
