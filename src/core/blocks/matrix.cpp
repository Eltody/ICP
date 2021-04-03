/** VUT FIT ICP
 * Predmet: Seminár C++ 2020/2021
 *
 * Názov súboru: matrix.cpp
 * Popis súboru: súbor obsahuje funkcie pre prácu s maticami 2x2 a 3x3 a matematické operácie nad nimi
 *
 * Dátum: 3.4.2021
 * Autori:
 *        Zaťko Tomáš  - xzatko02
 *        Martin Rakús - xrakus04
 */


#include "../types/types.h"
#include "../blocks.h"
#include "matrix.h"

// blok pre načítanie vstupu matice 2x2
MatrixInput::MatrixInput(Graph &g)
    : BlockBase(g, MAT2_INPUT, "Vstup",
{}, {OutPort(*this, mat2(), "")}) { }


// blok pre načítanie vstupu matice 3x3
Matrix3x3Input::Matrix3x3Input(Graph &g)
    : BlockBase(g, MAT3_INPUT, "Vstup",
{}, {OutPort(*this, mat3(), "")}) { }


void MatrixInput::Compute() { }
void Matrix3x3Input::Compute() { }


void MatrixOutput::Compute() { }
void Matrix3x3Output::Compute() { }


// blok pre výstup matice 2x2
MatrixOutput::MatrixOutput(Graph &g)
    : BlockBase(g, MAT2_OUTPUT, "Výstup",
    {InPort(*this, mat2(), "")}, {}) { }


// blok pre výstup matice 3x3
Matrix3x3Output::Matrix3x3Output(Graph &g)
    : BlockBase(g, MAT3_OUTPUT, "Výstup",
    {InPort(*this, mat3(), "")}, {}) { }


// blok pre sčítanie matíc 2x2
MatrixAddBlock::MatrixAddBlock(Graph &g)
    : BlockBase(g, MAT_ADD, BLOCK_NAME.at(MAT_ADD),
    {
        InPort(*this, mat2(), "Matica A"),
        InPort(*this, mat2(), "Matica B")
    },
    {
        OutPort(*this, mat2(), "Výstup")
    }
    ){}


// výpočet sčítania matíc 2x2
void MatrixAddBlock::Compute(){
    this->Output(0)["m11"] = this->Input(0)["m11"] + this->Input(1)["m11"];
    this->Output(0)["m12"] = this->Input(0)["m12"] + this->Input(1)["m12"];
    this->Output(0)["m21"] = this->Input(0)["m21"] + this->Input(1)["m21"];
    this->Output(0)["m22"] = this->Input(0)["m22"] + this->Input(1)["m22"];
}


// blok pre sčítanie matíc 3x3
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


// výpočet sčítania matíc 3x3
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


// blok pre násobenie matice 2x2 a 2D vektoru
MatMulVecBlock::MatMulVecBlock(Graph &g)
    : BlockBase(g, MAT_MUL_VEC, BLOCK_NAME.at(MAT_MUL_VEC),
    {
        InPort(*this, mat2(), "Matica"),
        InPort(*this, vec2(), "Vektor")
    },
    {
        OutPort(*this, vec2(), "Výstup")
    }
    ){}


// výpočet násobenia matice 2x2 a 2D vektoru
void MatMulVecBlock::Compute(){
    this->Output(0)["x"] = (this->Input(0)["m11"] * this->Input(1)["x"]) + (this->Input(0)["m12"] * this->Input(1)["y"]);
    this->Output(0)["y"] = (this->Input(0)["m21"] * this->Input(1)["x"]) + (this->Input(0)["m22"] * this->Input(1)["y"]);
}


// blok pre násobenie matice 3x3 a 3D vektoru
Mat3x3MulVecBlock::Mat3x3MulVecBlock(Graph &g)
    : BlockBase(g, MAT_MUL_VEC, BLOCK_NAME.at(MAT_MUL_VEC),
    {
        InPort(*this, mat3(), "Matica"),
        InPort(*this, vec2(), "Vektor")
    },
    {
        OutPort(*this, vec2(), "Výstup")
    }
    ){}


// výpočet násobenia matice 3x3 a 3D vektoru
void Mat3x3MulVecBlock::Compute(){
    this->Output(0)["x"] = (this->Input(0)["m11"] * this->Input(1)["x"]) + (this->Input(0)["m12"] * this->Input(1)["y"]) + (this->Input(0)["m13"] * this->Input(1)["z"]);
    this->Output(0)["y"] = (this->Input(0)["m21"] * this->Input(1)["x"]) + (this->Input(0)["m22"] * this->Input(1)["y"]) + (this->Input(0)["m23"] * this->Input(1)["z"]);
    this->Output(0)["z"] = (this->Input(0)["m21"] * this->Input(1)["x"]) + (this->Input(0)["m22"] * this->Input(1)["y"]) + (this->Input(0)["m33"] * this->Input(1)["z"]);
}


// blok pre sčítanie matíc 2x2
MatrixMulBlock::MatrixMulBlock(Graph &g)
    : BlockBase(g, MAT_MUL, BLOCK_NAME.at(MAT_MUL),
    {
        InPort(*this, mat2(), "Matica A"),
        InPort(*this, mat2(), "Matica B")
    },
    {
        OutPort(*this, mat2(), "Výstup")
    }
    ){}


// výpočet násobenia matíc 2x2
void MatrixMulBlock::Compute(){
    this->Output(0)["m11"] = (this->Input(0)["m11"] * this->Input(1)["m11"]) + (this->Input(0)["m12"] * this->Input(1)["m21"]);
    this->Output(0)["m12"] = (this->Input(0)["m11"] * this->Input(1)["m12"]) + (this->Input(0)["m12"] * this->Input(1)["m22"]);
    this->Output(0)["m21"] = (this->Input(0)["m21"] * this->Input(1)["m11"]) + (this->Input(0)["m22"] * this->Input(1)["m21"]);
    this->Output(0)["m22"] = (this->Input(0)["m21"] * this->Input(1)["m12"]) + (this->Input(0)["m22"] * this->Input(1)["m22"]);
}


// blok pre sčítanie matíc 3x3
Matrix3x3MulBlock::Matrix3x3MulBlock(Graph &g)
    : BlockBase(g, MAT3_MUL, BLOCK_NAME.at(MAT3_MUL),
    {
        InPort(*this, mat3(), "Matica A"),
        InPort(*this, mat3(), "Matica B")
    },
    {
        OutPort(*this, mat3(), "Výstup")
    }
    ){}


// výpočet násobenia matíc 3x3
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




//*****************************************************************************//

// blok pre sčítanie matíc 2x2
MatrixSubBlock::MatrixSubBlock(Graph &g)
    : BlockBase(g, MAT_SUB, BLOCK_NAME.at(MAT_SUB),
    {
        InPort(*this, mat2(), "Matica A"),
        InPort(*this, mat2(), "Matica B")
    },
    {
        OutPort(*this, mat2(), "Výstup")
    }
    ){}


// výpočet sčítania matíc 2x2
void MatrixSubBlock::Compute(){
    this->Output(0)["m11"] = this->Input(0)["m11"] - this->Input(1)["m11"];
    this->Output(0)["m12"] = this->Input(0)["m12"] - this->Input(1)["m12"];
    this->Output(0)["m21"] = this->Input(0)["m21"] - this->Input(1)["m21"];
    this->Output(0)["m22"] = this->Input(0)["m22"] - this->Input(1)["m22"];
}

