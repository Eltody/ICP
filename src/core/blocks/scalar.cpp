/** VUT FIT ICP
 * Predmet: Seminár C++ 2020/2021
 *
 * Názov súboru: scalar.cpp
 * Popis súboru: súbor obsahuje funkcie pre prácu s skalármi a matematické operácie nad nimi
 *
 * Dátum: 3.4.2021
 * Autori:
 *        Zaťko Tomáš  - xzatko02
 *        Martin Rakús - xrakus04
 */

#include "../types/types.h"
#include "../blocks.h"
#include "scalar.h"
#include "math.h"

// blok pre načítanie vstupu skaláru
ScalarInput::ScalarInput(Graph &g)
    : BlockBase(g, SCAL_INPUT, "Vstup",
{}, {OutPort(*this, scal(), "")}) { }


// blok pre výstup skaláru
ScalarOutput::ScalarOutput(Graph &g)
    : BlockBase(g, SCAL_OUTPUT, "Výstup",
    {InPort(*this, scal(), "")}, {}) { }


void ScalarInput::Compute() { }
void ScalarOutput::Compute() { }


// blok pre sčítanie dvoch skalárov
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


// výpočet sčítania dvoch skalárov
void ScalarAddBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] + this->Input(1)["Hodnota"];
}


// blok pre odčítanie dvoch skalárov
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


// výpočet odčítania dvoch skalárov
void ScalarSubBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] - this->Input(1)["Hodnota"];
}


// blok pre násobenie dvoch skalárov
ScalarMulBlock::ScalarMulBlock(Graph &g)
    : BlockBase(g, SCALAR_MUL, BLOCK_NAME.at(SCALAR_MUL),
    {
        InPort(*this, scal(), "Skalár A"),
        InPort(*this, scal(), "Skalár B")
    },
    {
        OutPort(*this, scal(), "Výstup")
    }
    ){}


// výpočet násobenia dvoch skalárov
void ScalarMulBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] * this->Input(1)["Hodnota"];
}


//*******************************************************//


// blok pre načítanie vstupu skaláru
MathInput::MathInput(Graph &g)
    : BlockBase(g, MATH_INPUT, "Vstup",
{}, {OutPort(*this, math(), "")}) { }


// blok pre výstup skaláru
MathOutput::MathOutput(Graph &g)
    : BlockBase(g, MATH_OUTPUT, "Výstup",
    {InPort(*this, math(), "")}, {}) { }


void MathInput::Compute() { }
void MathOutput::Compute() { }


// blok pre sčítanie dvoch čísel
MathAddBlock::MathAddBlock(Graph &g)
    : BlockBase(g, MATH_ADD, BLOCK_NAME.at(MATH_ADD),
    {
        InPort(*this, math(), "Číslo A"),
        InPort(*this, math(), "Číslo B")
    },
    {
        OutPort(*this, math(), "Výstup")
    }
    ){}


// výpočet sčítania dvoch čísel
void MathAddBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] + this->Input(1)["Hodnota"];
}


// blok pre odčítanie dvoch čísel
MathSubBlock::MathSubBlock(Graph &g)
    : BlockBase(g, MATH_SUB, BLOCK_NAME.at(MATH_SUB),
    {
        InPort(*this, math(), "Číslo A"),
        InPort(*this, math(), "Číslo B")
    },
    {
        OutPort(*this, math(), "Výstup")
    }
    ){}


// výpočet odčítania dvoch čísel
void MathSubBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] - this->Input(1)["Hodnota"];
}


// blok pre násobenie dvoch čísel
MathMulBlock::MathMulBlock(Graph &g)
    : BlockBase(g, MATH_MUL, BLOCK_NAME.at(MATH_MUL),
    {
        InPort(*this, math(), "Číslo A"),
        InPort(*this, math(), "Číslo B")
    },
    {
        OutPort(*this, math(), "Výstup")
    }
    ){}


// výpočet násobenia dvoch čísel
void MathMulBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] * this->Input(1)["Hodnota"];
}


// blok pre delenie dvoch čísel
MathDivBlock::MathDivBlock(Graph &g)
    : BlockBase(g, MATH_DIV, BLOCK_NAME.at(MATH_DIV),
    {
        InPort(*this, math(), "Číslo A"),
        InPort(*this, math(), "Číslo B")
    },
    {
        OutPort(*this, math(), "Výstup")
    }
    ){}


// výpočet delenia dvoch čísel
void MathDivBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] / this->Input(1)["Hodnota"];
}


// blok pre druhú odmocninu čísla
MathSqrtBlock::MathSqrtBlock(Graph &g)
    : BlockBase(g, MATH_SQRT, BLOCK_NAME.at(MATH_SQRT),
    {
        InPort(*this, math(), "Číslo A")
    },
    {
        OutPort(*this, math(), "Výstup")
    }
    ){}


// výpočet druhej odmocniny čisla
void MathSqrtBlock::Compute(){
    this->Output(0)["Hodnota"] = sqrt(this->Input(0)["Hodnota"]);
}
