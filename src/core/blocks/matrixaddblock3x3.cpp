/** ICP Project 2017/2018: BlockEditor
 * @file matrixaddblock.cpp
 * @brief Matrix addition block's operation and ports definition
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#include "matrixaddblock3x3.h"
#include "../types/types.h"
#include "../blocks.h"

Matrix3x3AddBlock::Matrix3x3AddBlock(Graph &g)
    : BlockBase(g, MAT3_ADD, BLOCK_NAME.at(MAT3_ADD),
    {
        InPort(*this, mat3(), "Matica A"),
        InPort(*this, mat3(), "Matica B")
    },
    {
        OutPort(*this, mat3(), "Výstup")
    }
    ){}

void Matrix3x3AddBlock::Compute(){
    this->Output(0)["m11"] = this->Input(0)["m11"] + this->Input(1)["m11"];
    this->Output(0)["m12"] = this->Input(0)["m12"] + this->Input(1)["m12"];
    this->Output(0)["m13"] = this->Input(0)["m13"] + this->Input(1)["m13"];
    this->Output(0)["m21"] = this->Input(0)["m21"] + this->Input(1)["m21"];
    this->Output(0)["m22"] = this->Input(0)["m22"] + this->Input(1)["m22"];
    this->Output(0)["m23"] = this->Input(0)["m23"] + this->Input(1)["m23"];
    this->Output(0)["m31"] = this->Input(0)["m31"] + this->Input(1)["m31"];
    this->Output(0)["m32"] = this->Input(0)["m32"] + this->Input(1)["m32"];
    this->Output(0)["m33"] = this->Input(0)["m33"] + this->Input(1)["m33"];
}
