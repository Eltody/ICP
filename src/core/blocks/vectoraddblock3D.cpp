/** ICP Project 2017/2018: BlockEditor
 * @file vectoraddblock.cpp
 * @brief Vector addition block's operation and ports definition
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#include "vectoraddblock3D.h"
#include "../types/types.h"
#include "../blocks.h"

VectorAddBlock3D::VectorAddBlock3D(Graph &g)
    : BlockBase(g, VECTOR_ADD3D, BLOCK_NAME.at(VECTOR_ADD3D),
	{
        InPort(*this, vec3(), "Vektor A"),
        InPort(*this, vec3(), "Vektor B")
	},
	{
        OutPort(*this, vec3(), "Výstup")
	}
	){}

void VectorAddBlock3D::Compute(){
    this->Output(0)["x"] = this->Input(0)["x"] + this->Input(1)["x"];
    this->Output(0)["y"] = this->Input(0)["y"] + this->Input(1)["y"];
    this->Output(0)["z"] = this->Input(0)["z"] + this->Input(1)["z"];
}
