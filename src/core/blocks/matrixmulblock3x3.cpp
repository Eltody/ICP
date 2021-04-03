/** ICP Project 2017/2018: BlockEditor
 * @file matrixmulblock.cpp
 * @brief Matrix multiplication block's operation and ports definition
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#include "matrixmulblock3x3.h"
#include "../types/types.h"
#include "../blocks.h"

Matrix3x3MulBlock::Matrix3x3MulBlock(Graph &g)
    : BlockBase(g, MAT3_MUL, BLOCK_NAME.at(MAT3_MUL),
    {
        InPort(*this, mat3(), "A"),
        InPort(*this, mat3(), "B")
    },
    {
        OutPort(*this, mat3(), "Out")
    }
    ){}

void Matrix3x3MulBlock::Compute(){
    this->Output(0)["m11"] = (this->Input(0)["m11"] * this->Input(1)["m11"]) + (this->Input(0)["m12"] * this->Input(1)["m21"]) + (this->Input(0)["m13"] * this->Input(1)["m31"]);
    this->Output(0)["m12"] = (this->Input(0)["m11"] * this->Input(1)["m12"]) + (this->Input(0)["m12"] * this->Input(1)["m22"]) + (this->Input(0)["m13"] * this->Input(1)["m32"]);
    this->Output(0)["m13"] = (this->Input(0)["m11"] * this->Input(1)["m13"]) + (this->Input(0)["m12"] * this->Input(1)["m23"]) + (this->Input(0)["m13"] * this->Input(1)["m33"]);
    this->Output(0)["m21"] = (this->Input(0)["m21"] * this->Input(1)["m11"]) + (this->Input(0)["m22"] * this->Input(1)["m21"]) + (this->Input(0)["m23"] * this->Input(1)["m31"]);
    this->Output(0)["m22"] = (this->Input(0)["m21"] * this->Input(1)["m12"]) + (this->Input(0)["m22"] * this->Input(1)["m22"]) + (this->Input(0)["m23"] * this->Input(1)["m32"]);
    this->Output(0)["m23"] = (this->Input(0)["m21"] * this->Input(1)["m13"]) + (this->Input(0)["m22"] * this->Input(1)["m23"]) + (this->Input(0)["m23"] * this->Input(1)["m33"]);
    this->Output(0)["m31"] = (this->Input(0)["m31"] * this->Input(1)["m11"]) + (this->Input(0)["m32"] * this->Input(1)["m21"]) + (this->Input(0)["m33"] * this->Input(1)["m31"]);
    this->Output(0)["m32"] = (this->Input(0)["m31"] * this->Input(1)["m12"]) + (this->Input(0)["m32"] * this->Input(1)["m22"]) + (this->Input(0)["m33"] * this->Input(1)["m32"]);
    this->Output(0)["m33"] = (this->Input(0)["m31"] * this->Input(1)["m13"]) + (this->Input(0)["m32"] * this->Input(1)["m23"]) + (this->Input(0)["m33"] * this->Input(1)["m33"]);
}
