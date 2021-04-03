/** VUT FIT ICP
 * Predmet: Seminár C++ 2020/2021
 *
 * Názov súboru: vector.cpp
 * Popis súboru: súbor obsahuje funkcie pre prácu s vektormi a matematické operácie nad nimi
 *
 * Dátum: 3.4.2021
 * Autori:
 *        Zaťko Tomáš  - xzatko02
 *        Martin Rakús - xrakus04
 */

#include "../types/types.h"
#include "../blocks.h"
#include "vector.h"
#include "math.h"
#include <cmath>


// blok pre načítanie vstupu 2D vektoru
VectorInput::VectorInput(Graph &g)
    : BlockBase(g, VECTOR_INPUT, "Vstup",
{}, {OutPort(*this, vec2(), "")}) { }


// blok pre načítanie vstupu 3D vektoru
Vector3DInput::Vector3DInput(Graph &g)
    : BlockBase(g, VECTOR3D_INPUT, "Vstup",
{}, {OutPort(*this, vec3(), "")}) { }


void VectorInput::Compute() { }
void VectorOutput::Compute() { }


void Vector3DInput::Compute() { }
void Vector3DOutput::Compute() { }


// blok pre výstup 2D vektoru
VectorOutput::VectorOutput(Graph &g)
    : BlockBase(g, VECTOR_OUTPUT, "Výstup",
	{InPort(*this, vec2(), "")}, {}) { }


// blok pre výstup 3D vektoru
Vector3DOutput::Vector3DOutput(Graph &g)
    : BlockBase(g, VECTOR3D_OUTPUT, "Výstup",
    {InPort(*this, vec3(), "")}, {}) { }


// blok pre sčítanie dvoch 2D vektorov
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


// výpočet sčítania dvoch 2D vektorov
void VectorAddBlock::Compute(){
    this->Output(0)["x"] = this->Input(0)["x"] + this->Input(1)["x"];
    this->Output(0)["y"] = this->Input(0)["y"] + this->Input(1)["y"];
}


// blok pre sčítanie dvoch 3D vektorov
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


// výpočet sčítania dvoch 3D vektorov
void VectorAddBlock3D::Compute(){
    this->Output(0)["x"] = this->Input(0)["x"] + this->Input(1)["x"];
    this->Output(0)["y"] = this->Input(0)["y"] + this->Input(1)["y"];
    this->Output(0)["z"] = this->Input(0)["z"] + this->Input(1)["z"];
}


// blok pre vektorový súčin dvoch 2D vektorov
VectorDotProductBlock2D::VectorDotProductBlock2D(Graph &g)
    : BlockBase(g, VECTOR_DOTPRODUCT, BLOCK_NAME.at(VECTOR_DOTPRODUCT),
    {
        InPort(*this, vec2(), "Vektor A"),
        InPort(*this, vec2(), "Vektor B")
    },
    {
        OutPort(*this, math(), "Výstup")
    }
    ){}


// výpočet vektorového súčinu dvoch 2D vektorov
void VectorDotProductBlock2D::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["x"] * this->Input(1)["x"] + this->Input(0)["y"] * this->Input(1)["y"];
}


// blok pre výstup 2D skalárneho súčinu
VectorDotOutput::VectorDotOutput(Graph &g)
    : BlockBase(g, VECTOR_DOT_OUTPUT, "Výstup",
    {InPort(*this, math(), "")}, {}) { }


void VectorDotOutput::Compute() { }
