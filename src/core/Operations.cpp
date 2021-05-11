/** VUT FIT ICP 2020/2021
 * @file operations.cpp
 * @brief Súbor obsahuje funkcie pre prácu so základnými matematickými operáciami
 * @date 3.4.2021
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#include "Types.h"
#include "Blocks.h"
#include "Operations.h"
#include "math.h"
#include <cmath>


// blok pre načítanie vstupu čísla
MathInput::MathInput(Manager &g)
    : BlockBase(g, MATH_INPUT, "Vstup",
{}, {OutPort(*this, one_number(), "")}) { }


// blok pre výstup čísla
MathOutput::MathOutput(Manager &g)
    : BlockBase(g, MATH_OUTPUT, "Výstup",
    {InPort(*this, one_number(), "")}, {}) { }


void MathInput::Compute() { }
void MathOutput::Compute() { }


// blok pre sčítanie dvoch čísel
MathAddBlock::MathAddBlock(Manager &g)
    : BlockBase(g, MATH_ADD, BLOCK_NAME.at(MATH_ADD),
    {
        InPort(*this, one_number(), "Číslo A"),
        InPort(*this, one_number(), "Číslo B")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// výpočet sčítania dvoch čísel
void MathAddBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] + this->Input(1)["Hodnota"];
}


// blok pre odčítanie dvoch čísel
MathSubBlock::MathSubBlock(Manager &g)
    : BlockBase(g, MATH_SUB, BLOCK_NAME.at(MATH_SUB),
    {
        InPort(*this, one_number(), "Číslo A"),
        InPort(*this, one_number(), "Číslo B")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// výpočet odčítania dvoch čísel
void MathSubBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] - this->Input(1)["Hodnota"];
}


// blok pre násobenie dvoch čísel
MathMulBlock::MathMulBlock(Manager &g)
    : BlockBase(g, MATH_MUL, BLOCK_NAME.at(MATH_MUL),
    {
        InPort(*this, one_number(), "Číslo A"),
        InPort(*this, one_number(), "Číslo B")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// výpočet násobenia dvoch čísel
void MathMulBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] * this->Input(1)["Hodnota"];
}


// blok pre delenie dvoch čísel
MathDivBlock::MathDivBlock(Manager &g)
    : BlockBase(g, MATH_DIV, BLOCK_NAME.at(MATH_DIV),
    {
        InPort(*this, one_number(), "Číslo A"),
        InPort(*this, one_number(), "Číslo B")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// výpočet delenia dvoch čísel
void MathDivBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] / this->Input(1)["Hodnota"];
}


// blok pre druhú odmocninu čísla
MathSqrtBlock::MathSqrtBlock(Manager &g)
    : BlockBase(g, MATH_SQRT, BLOCK_NAME.at(MATH_SQRT),
    {
        InPort(*this, one_number(), "Číslo A")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// výpočet druhej odmocniny čisla
void MathSqrtBlock::Compute(){
    this->Output(0)["Hodnota"] = sqrt(this->Input(0)["Hodnota"]);
}


// blok pre výpočet absolútnej hodnoty čísla
MathAbsBlock::MathAbsBlock(Manager &g)
    : BlockBase(g, MATH_ABS, BLOCK_NAME.at(MATH_ABS),
    {
        InPort(*this, one_number(), "Číslo A")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// výpočet druhej odmocniny čisla
void MathAbsBlock::Compute(){
    this->Output(0)["Hodnota"] = abs(this->Input(0)["Hodnota"]);
}


// blok pre vyhodnotenie väčšieho čísla z dvoch - GT - greater than
MathGTBlock::MathGTBlock(Manager &g)
    : BlockBase(g, MATH_GT, BLOCK_NAME.at(MATH_GT),
    {
        InPort(*this, one_number(), "Číslo A"),
        InPort(*this, one_number(), "Číslo B")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// vyhodnotenie väčšieho čísla z dvoch - GT - greater than
void MathGTBlock::Compute(){
    if (this->Input(0)["Hodnota"] > this->Input(1)["Hodnota"]){
        this->Output(0)["Hodnota"] = -this->Input(0)["Hodnota"];
        this->Output(0)["Hodnota"] = -this->Output(0)["Hodnota"];
    }
    else{
        this->Output(0)["Hodnota"] = -this->Input(1)["Hodnota"];
        this->Output(0)["Hodnota"] = -this->Output(0)["Hodnota"];
    }
}


// blok pre vyhodnotenie menšieho čísla z dvoch - LT - less than
MathLTBlock::MathLTBlock(Manager &g)
    : BlockBase(g, MATH_LT, BLOCK_NAME.at(MATH_LT),
    {
        InPort(*this, one_number(), "Číslo A"),
        InPort(*this, one_number(), "Číslo B")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// vyhodnotenie menšieho čísla z dvoch - LT - less than
void MathLTBlock::Compute(){
    if (this->Input(0)["Hodnota"] < this->Input(1)["Hodnota"]){
        this->Output(0)["Hodnota"] = -this->Input(0)["Hodnota"];
        this->Output(0)["Hodnota"] = -this->Output(0)["Hodnota"];
    }
    else{
        this->Output(0)["Hodnota"] = -this->Input(1)["Hodnota"];
        this->Output(0)["Hodnota"] = -this->Output(0)["Hodnota"];
    }
}


// blok pre výpočet sinusu
MathSinBlock::MathSinBlock(Manager &g)
    : BlockBase(g, MATH_SIN, BLOCK_NAME.at(MATH_SIN),
    {
        InPort(*this, one_number(), "Číslo A")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// výpočet sinusu
void MathSinBlock::Compute(){
        this->Output(0)["Hodnota"] = sin(this->Input(0)["Hodnota"]);
}


// blok pre výpočet cosinusu
MathCosBlock::MathCosBlock(Manager &g)
    : BlockBase(g, MATH_COS, BLOCK_NAME.at(MATH_COS),
    {
        InPort(*this, one_number(), "Číslo A")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// výpočet cosinusu
void MathCosBlock::Compute(){
        this->Output(0)["Hodnota"] = cos(this->Input(0)["Hodnota"]);
}


// blok pre inkrement
MathIncBlock::MathIncBlock(Manager &g)
    : BlockBase(g, MATH_INC, BLOCK_NAME.at(MATH_INC),
    {
        InPort(*this, one_number(), "Číslo A")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// vykonanie inkrementu
void MathIncBlock::Compute(){
        this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] + 1;
}


// blok pre dekrement
MathDecBlock::MathDecBlock(Manager &g)
    : BlockBase(g, MATH_DEC, BLOCK_NAME.at(MATH_DEC),
    {
        InPort(*this, one_number(), "Číslo A")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// vykonanie inkrementu
void MathDecBlock::Compute(){
        this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] - 1;
}



//----------MATICE----------



// blok pre načítanie vstupu matice 2x2
MatrixInput::MatrixInput(Manager &g)
    : BlockBase(g, MAT2_INPUT, "Vstup",
{}, {OutPort(*this, matrix2x2_out(), "")}) { }


// blok pre načítanie vstupu matice 3x3
Matrix3x3Input::Matrix3x3Input(Manager &g)
    : BlockBase(g, MAT3_INPUT, "Vstup",
{}, {OutPort(*this, matrix3x3_out(), "")}) { }


void MatrixInput::Compute() { }
void Matrix3x3Input::Compute() { }


void MatrixOutput::Compute() { }
void Matrix3x3Output::Compute() { }


// blok pre výstup matice 2x2
MatrixOutput::MatrixOutput(Manager &g)
    : BlockBase(g, MAT2_OUTPUT, "Výstup",
    {InPort(*this, matrix2x2_out(), "")}, {}) { }


// blok pre výstup matice 3x3
Matrix3x3Output::Matrix3x3Output(Manager &g)
    : BlockBase(g, MAT3_OUTPUT, "Výstup",
    {InPort(*this, matrix3x3_out(), "")}, {}) { }


// blok pre sčítanie matíc 2x2
MatrixAddBlock::MatrixAddBlock(Manager &g)
    : BlockBase(g, MAT_ADD, BLOCK_NAME.at(MAT_ADD),
    {
        InPort(*this, matrix2x2_out(), "Matica A"),
        InPort(*this, matrix2x2_out(), "Matica B")
    },
    {
        OutPort(*this, matrix2x2_out(), "Výstup")
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
Matrix3x3AddBlock::Matrix3x3AddBlock(Manager &g)
    : BlockBase(g, MAT3_ADD, BLOCK_NAME.at(MAT3_ADD),
    {
        InPort(*this, matrix3x3_out(), "Matica A"),
        InPort(*this, matrix3x3_out(), "Matica B")
    },
    {
        OutPort(*this, matrix3x3_out(), "Výstup")
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
MatMulVecBlock::MatMulVecBlock(Manager &g)
    : BlockBase(g, MAT_MUL_VEC, BLOCK_NAME.at(MAT_MUL_VEC),
    {
        InPort(*this, matrix2x2_out(), "Matica"),
        InPort(*this, vector2D_out(), "Vektor")
    },
    {
        OutPort(*this, vector2D_out(), "Výstup")
    }
    ){}


// výpočet násobenia matice 2x2 a 2D vektoru
void MatMulVecBlock::Compute(){
    this->Output(0)["x"] = (this->Input(0)["m11"] * this->Input(1)["x"]) + (this->Input(0)["m12"] * this->Input(1)["y"]);
    this->Output(0)["y"] = (this->Input(0)["m21"] * this->Input(1)["x"]) + (this->Input(0)["m22"] * this->Input(1)["y"]);
}


// blok pre násobenie matice 3x3 a 3D vektoru
Mat3x3MulVecBlock::Mat3x3MulVecBlock(Manager &g)
    : BlockBase(g, MAT_MUL_VEC, BLOCK_NAME.at(MAT_MUL_VEC),
    {
        InPort(*this, matrix3x3_out(), "Matica"),
        InPort(*this, vector2D_out(), "Vektor")
    },
    {
        OutPort(*this, vector2D_out(), "Výstup")
    }
    ){}


// výpočet násobenia matice 3x3 a 3D vektoru
void Mat3x3MulVecBlock::Compute(){
    this->Output(0)["x"] = (this->Input(0)["m11"] * this->Input(1)["x"]) + (this->Input(0)["m12"] * this->Input(1)["y"]) + (this->Input(0)["m13"] * this->Input(1)["z"]);
    this->Output(0)["y"] = (this->Input(0)["m21"] * this->Input(1)["x"]) + (this->Input(0)["m22"] * this->Input(1)["y"]) + (this->Input(0)["m23"] * this->Input(1)["z"]);
    this->Output(0)["z"] = (this->Input(0)["m21"] * this->Input(1)["x"]) + (this->Input(0)["m22"] * this->Input(1)["y"]) + (this->Input(0)["m33"] * this->Input(1)["z"]);
}


// blok pre sčítanie matíc 2x2
MatrixMulBlock::MatrixMulBlock(Manager &g)
    : BlockBase(g, MAT_MUL, BLOCK_NAME.at(MAT_MUL),
    {
        InPort(*this, matrix2x2_out(), "Matica A"),
        InPort(*this, matrix2x2_out(), "Matica B")
    },
    {
        OutPort(*this, matrix2x2_out(), "Výstup")
    }
    ){}


// výpočet násobenia matíc 2x2
void MatrixMulBlock::Compute(){
    this->Output(0)["m11"] = (this->Input(0)["m11"] * this->Input(1)["m11"]) + (this->Input(0)["m12"] * this->Input(1)["m21"]);
    this->Output(0)["m12"] = (this->Input(0)["m11"] * this->Input(1)["m12"]) + (this->Input(0)["m12"] * this->Input(1)["m22"]);
    this->Output(0)["m21"] = (this->Input(0)["m21"] * this->Input(1)["m11"]) + (this->Input(0)["m22"] * this->Input(1)["m21"]);
    this->Output(0)["m22"] = (this->Input(0)["m21"] * this->Input(1)["m12"]) + (this->Input(0)["m22"] * this->Input(1)["m22"]);
}


// blok pre násobenie matíc 3x3
Matrix3x3MulBlock::Matrix3x3MulBlock(Manager &g)
    : BlockBase(g, MAT3_MUL, BLOCK_NAME.at(MAT3_MUL),
    {
        InPort(*this, matrix3x3_out(), "Matica A"),
        InPort(*this, matrix3x3_out(), "Matica B")
    },
    {
        OutPort(*this, matrix3x3_out(), "Výstup")
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



// blok pre odčítanie matíc 2x2
MatrixSubBlock::MatrixSubBlock(Manager &g)
    : BlockBase(g, MAT_SUB, BLOCK_NAME.at(MAT_SUB),
    {
        InPort(*this, matrix2x2_out(), "Matica A"),
        InPort(*this, matrix2x2_out(), "Matica B")
    },
    {
        OutPort(*this, matrix2x2_out(), "Výstup")
    }
    ){}


// výpočet odčítania matíc 2x2
void MatrixSubBlock::Compute(){
    this->Output(0)["m11"] = this->Input(0)["m11"] - this->Input(1)["m11"];
    this->Output(0)["m12"] = this->Input(0)["m12"] - this->Input(1)["m12"];
    this->Output(0)["m21"] = this->Input(0)["m21"] - this->Input(1)["m21"];
    this->Output(0)["m22"] = this->Input(0)["m22"] - this->Input(1)["m22"];
}


// blok pre odčítanie matíc 3x3
Matrix3x3SubBlock::Matrix3x3SubBlock(Manager &g)
    : BlockBase(g, MAT3_SUB, BLOCK_NAME.at(MAT3_SUB),
    {
        InPort(*this, matrix3x3_out(), "Matica A"),
        InPort(*this, matrix3x3_out(), "Matica B")
    },
    {
        OutPort(*this, matrix3x3_out(), "Výstup")
    }
    ){}


// výpočet odčítania matíc 3x3
void Matrix3x3SubBlock::Compute(){
    this->Output(0)["m11"] = this->Input(0)["m11"] - this->Input(1)["m11"];
    this->Output(0)["m12"] = this->Input(0)["m12"] - this->Input(1)["m12"];
    this->Output(0)["m13"] = this->Input(0)["m13"] - this->Input(1)["m13"];
    this->Output(0)["m21"] = this->Input(0)["m21"] - this->Input(1)["m21"];
    this->Output(0)["m22"] = this->Input(0)["m22"] - this->Input(1)["m22"];
    this->Output(0)["m23"] = this->Input(0)["m23"] - this->Input(1)["m23"];
    this->Output(0)["m31"] = this->Input(0)["m31"] - this->Input(1)["m31"];
    this->Output(0)["m32"] = this->Input(0)["m32"] - this->Input(1)["m32"];
    this->Output(0)["m33"] = this->Input(0)["m33"] - this->Input(1)["m33"];
}


// blok pre výpočet determinantu matice 2x2
MatrixDeterminantBlock::MatrixDeterminantBlock(Manager &g)
    : BlockBase(g, MAT_DETERMINANT, BLOCK_NAME.at(MAT_DETERMINANT),
    {
        InPort(*this, matrix2x2_out(), "Matica A")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// výpočet determinantu matice 2x2
void MatrixDeterminantBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["m11"] * this->Input(0)["m22"] - this->Input(0)["m12"] * this->Input(0)["m21"];
}

// blok pre načítanie vstupu matice 2x2 pre výpočet determinantu
MatrixDeterminantInput::MatrixDeterminantInput(Manager &g)
    : BlockBase(g, MAT_DETERMINANT_INPUT, "Vstup",
{}, {OutPort(*this, matrix2x2_out(), "")}) { }

void MatrixDeterminantInput::Compute() { }

// blok pre výstup determinant matice 2x2
MatrixDeterminantOutput::MatrixDeterminantOutput(Manager &g)
    : BlockBase(g, MAT_DETERMINANT_OUTPUT, "Výstup",
    {InPort(*this, one_number(), "")}, {}) { }

void MatrixDeterminantOutput::Compute() { }



//----------VEKTORY----------



// blok pre načítanie vstupu 2D vektoru
VectorInput::VectorInput(Manager &g)
    : BlockBase(g, VECTOR_INPUT, "Vstup",
{}, {OutPort(*this, vector2D_out(), "")}) { }


// blok pre načítanie vstupu 3D vektoru
Vector3DInput::Vector3DInput(Manager &g)
    : BlockBase(g, VECTOR3D_INPUT, "Vstup",
{}, {OutPort(*this, vector3D_out(), "")}) { }


void VectorInput::Compute() { }
void VectorOutput::Compute() { }


void Vector3DInput::Compute() { }
void Vector3DOutput::Compute() { }


// blok pre výstup 2D vektoru
VectorOutput::VectorOutput(Manager &g)
    : BlockBase(g, VECTOR_OUTPUT, "Výstup",
    {InPort(*this, vector2D_out(), "")}, {}) { }


// blok pre výstup 3D vektoru
Vector3DOutput::Vector3DOutput(Manager &g)
    : BlockBase(g, VECTOR3D_OUTPUT, "Výstup",
    {InPort(*this, vector3D_out(), "")}, {}) { }


// blok pre sčítanie dvoch 2D vektorov
VectorAddBlock::VectorAddBlock(Manager &g)
    : BlockBase(g, VECTOR_ADD, BLOCK_NAME.at(VECTOR_ADD),
    {
        InPort(*this, vector2D_out(), "Vektor A"),
        InPort(*this, vector2D_out(), "Vektor B")
    },
    {
        OutPort(*this, vector2D_out(), "Výstup")
    }
    ){}


// výpočet sčítania dvoch 2D vektorov
void VectorAddBlock::Compute(){
    this->Output(0)["x"] = this->Input(0)["x"] + this->Input(1)["x"];
    this->Output(0)["y"] = this->Input(0)["y"] + this->Input(1)["y"];
}


// blok pre odčítanie dvoch 2D vektorov
VectorSubBlock::VectorSubBlock(Manager &g)
    : BlockBase(g, VECTOR_SUB, BLOCK_NAME.at(VECTOR_SUB),
    {
        InPort(*this, vector2D_out(), "Vektor A"),
        InPort(*this, vector2D_out(), "Vektor B")
    },
    {
        OutPort(*this, vector2D_out(), "Výstup")
    }
    ){}


// výpočet očítania dvoch 2D vektorov
void VectorSubBlock::Compute(){
    this->Output(0)["x"] = this->Input(0)["x"] - this->Input(1)["x"];
    this->Output(0)["y"] = this->Input(0)["y"] - this->Input(1)["y"];
}


// blok pre sčítanie dvoch 3D vektorov
VectorAddBlock3D::VectorAddBlock3D(Manager &g)
    : BlockBase(g, VECTOR_ADD3D, BLOCK_NAME.at(VECTOR_ADD3D),
    {
        InPort(*this, vector3D_out(), "Vektor A"),
        InPort(*this, vector3D_out(), "Vektor B")
    },
    {
        OutPort(*this, vector3D_out(), "Výstup")
    }
    ){}


// výpočet sčítania dvoch 3D vektorov
void VectorAddBlock3D::Compute(){
    this->Output(0)["x"] = this->Input(0)["x"] + this->Input(1)["x"];
    this->Output(0)["y"] = this->Input(0)["y"] + this->Input(1)["y"];
    this->Output(0)["z"] = this->Input(0)["z"] + this->Input(1)["z"];
}


// blok pre odčítanie dvoch 3D vektorov
VectorSubBlock3D::VectorSubBlock3D(Manager &g)
    : BlockBase(g, VECTOR_SUB3D, BLOCK_NAME.at(VECTOR_SUB3D),
    {
        InPort(*this, vector3D_out(), "Vektor A"),
        InPort(*this, vector3D_out(), "Vektor B")
    },
    {
        OutPort(*this, vector3D_out(), "Výstup")
    }
    ){}


// výpočet odčítania dvoch 3D vektorov
void VectorSubBlock3D::Compute(){
    this->Output(0)["x"] = this->Input(0)["x"] - this->Input(1)["x"];
    this->Output(0)["y"] = this->Input(0)["y"] - this->Input(1)["y"];
    this->Output(0)["z"] = this->Input(0)["z"] - this->Input(1)["z"];
}


// blok pre vektorový súčin dvoch 2D vektorov
VectorDotProductBlock2D::VectorDotProductBlock2D(Manager &g)
    : BlockBase(g, VECTOR_DOTPRODUCT, BLOCK_NAME.at(VECTOR_DOTPRODUCT),
    {
        InPort(*this, vector2D_out(), "Vektor A"),
        InPort(*this, vector2D_out(), "Vektor B")
    },
    {
        OutPort(*this, one_number(), "Výstup")
    }
    ){}


// výpočet vektorového súčinu dvoch 2D vektorov
void VectorDotProductBlock2D::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["x"] * this->Input(1)["x"] + this->Input(0)["y"] * this->Input(1)["y"];
}


// blok pre výstup 2D skalárneho súčinu
VectorDotOutput::VectorDotOutput(Manager &g)
    : BlockBase(g, VECTOR_DOT_OUTPUT, "Výstup",
    {InPort(*this, one_number(), "")}, {}) { }


void VectorDotOutput::Compute() { }


// blok pre vynásobenie 2D vektora konštantou
VectorMulConstBlock::VectorMulConstBlock(Manager &g)
    : BlockBase(g, VECTOR_MUL_CONST, BLOCK_NAME.at(VECTOR_MUL_CONST),
    {
        InPort(*this, vector2D_out(), "Vektor"),
        InPort(*this, one_number(), "Konštanta")
    },
    {
        OutPort(*this, vector2D_out(), "Výstup")
    }
    ){}


// výpočet vynásobenia 2D vektora konštantou
void VectorMulConstBlock::Compute(){
    this->Output(0)["x"] = this->Input(0)["x"] * this->Input(1)["Hodnota"];
    this->Output(0)["y"] = this->Input(0)["y"] * this->Input(1)["Hodnota"];
}


// blok pre vynásobenie 3D vektora konštantou
VectorMulConstBlock3D::VectorMulConstBlock3D(Manager &g)
    : BlockBase(g, VECTOR_MUL_CONST3D, BLOCK_NAME.at(VECTOR_MUL_CONST3D),
    {
        InPort(*this, vector3D_out(), "Vektor"),
        InPort(*this, one_number(), "Konštanta")
    },
    {
        OutPort(*this, vector3D_out(), "Výstup")
    }
    ){}


// výpočet vynásobenia 3D vektora konštantou
void VectorMulConstBlock3D::Compute(){
    this->Output(0)["x"] = this->Input(0)["x"] * this->Input(1)["Hodnota"];
    this->Output(0)["y"] = this->Input(0)["y"] * this->Input(1)["Hodnota"];
    this->Output(0)["z"] = this->Input(0)["z"] * this->Input(1)["Hodnota"];
}
