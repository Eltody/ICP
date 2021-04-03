/** ICP Project 2017/2018: BlockEditor
 * @file Mat3x3MulVecBlock.cpp
 * @brief Matrix and vector multiplication block's operation and ports definition
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#include "matmulvecblock3x3.h"
#include "../types/types.h"
#include "../blocks.h"

Mat3x3MulVecBlock::Mat3x3MulVecBlock(Graph &g)
    : BlockBase(g, MAT_MUL_VEC, BLOCK_NAME.at(MAT_MUL_VEC),
    {
        InPort(*this, mat3(), "Mat"),
        InPort(*this, vec2(), "Vec")
    },
    {
        OutPort(*this, vec2(), "Out")
    }
    ){}

void Mat3x3MulVecBlock::Compute(){
    this->Output(0)["x"] = (this->Input(0)["m11"] * this->Input(1)["x"]) + (this->Input(0)["m12"] * this->Input(1)["y"]) + (this->Input(0)["m13"] * this->Input(1)["z"]);
    this->Output(0)["y"] = (this->Input(0)["m21"] * this->Input(1)["x"]) + (this->Input(0)["m22"] * this->Input(1)["y"]) + (this->Input(0)["m23"] * this->Input(1)["z"]);
    this->Output(0)["z"] = (this->Input(0)["m21"] * this->Input(1)["x"]) + (this->Input(0)["m22"] * this->Input(1)["y"]) + (this->Input(0)["m33"] * this->Input(1)["z"]);
}
