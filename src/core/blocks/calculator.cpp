/** VUT FIT ICP
 * Predmet: Seminár C++ 2020/2021
 *
 * Názov súboru: calculator.cpp
 * Popis súboru: súbor obsahuje funkcie pre prácu s skalármi a matematické operácie nad nimi
 *
 * Dátum: 3.4.2021
 * Autori:
 *        Zaťko Tomáš  - xzatko02
 *        Martin Rakús - xrakus04
 */

#include "../types/types.h"
#include "../blocks.h"
#include "calculator.h"
#include "math.h"
#include <cmath>


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


// blok pre výpočet absolútnej hodnoty čísla
MathAbsBlock::MathAbsBlock(Graph &g)
    : BlockBase(g, MATH_ABS, BLOCK_NAME.at(MATH_ABS),
    {
        InPort(*this, math(), "Číslo A")
    },
    {
        OutPort(*this, math(), "Výstup")
    }
    ){}


// výpočet druhej odmocniny čisla
void MathAbsBlock::Compute(){
    this->Output(0)["Hodnota"] = abs(this->Input(0)["Hodnota"]);
}


// blok pre vyhodnotenie väčšieho čísla z dvoch - GT - greater than
MathGTBlock::MathGTBlock(Graph &g)
    : BlockBase(g, MATH_GT, BLOCK_NAME.at(MATH_GT),
    {
        InPort(*this, math(), "Číslo A"),
        InPort(*this, math(), "Číslo B")
    },
    {
        OutPort(*this, math(), "Výstup")
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
MathLTBlock::MathLTBlock(Graph &g)
    : BlockBase(g, MATH_LT, BLOCK_NAME.at(MATH_LT),
    {
        InPort(*this, math(), "Číslo A"),
        InPort(*this, math(), "Číslo B")
    },
    {
        OutPort(*this, math(), "Výstup")
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
MathSinBlock::MathSinBlock(Graph &g)
    : BlockBase(g, MATH_SIN, BLOCK_NAME.at(MATH_SIN),
    {
        InPort(*this, math(), "Číslo A")
    },
    {
        OutPort(*this, math(), "Výstup")
    }
    ){}


// výpočet sinusu
void MathSinBlock::Compute(){
        this->Output(0)["Hodnota"] = sin(this->Input(0)["Hodnota"]);
}


// blok pre výpočet cosinusu
MathCosBlock::MathCosBlock(Graph &g)
    : BlockBase(g, MATH_COS, BLOCK_NAME.at(MATH_COS),
    {
        InPort(*this, math(), "Číslo A")
    },
    {
        OutPort(*this, math(), "Výstup")
    }
    ){}


// výpočet cosinusu
void MathCosBlock::Compute(){
        this->Output(0)["Hodnota"] = cos(this->Input(0)["Hodnota"]);
}


// blok pre inkrement
MathIncBlock::MathIncBlock(Graph &g)
    : BlockBase(g, MATH_INC, BLOCK_NAME.at(MATH_INC),
    {
        InPort(*this, math(), "Číslo A")
    },
    {
        OutPort(*this, math(), "Výstup")
    }
    ){}


// vykonanie inkrementu
void MathIncBlock::Compute(){
        this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] + 1;
}
