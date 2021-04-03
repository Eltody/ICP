#include "../types/types.h"
#include "../blocks.h"
#include "vector.h"

VectorInput::VectorInput(Graph &g)
    : BlockBase(g, VECTOR_INPUT, "Vstup",
{}, {OutPort(*this, vec2(), "")}) { }

void VectorInput::Compute() { }

VectorOutput::VectorOutput(Graph &g)
    : BlockBase(g, VECTOR_OUTPUT, "Výstup",
	{InPort(*this, vec2(), "")}, {}) { }

void VectorOutput::Compute() { }



Vector3DInput::Vector3DInput(Graph &g)
    : BlockBase(g, VECTOR3D_INPUT, "Vstup",
{}, {OutPort(*this, vec3(), "")}) { }

void Vector3DInput::Compute() { }

Vector3DOutput::Vector3DOutput(Graph &g)
    : BlockBase(g, VECTOR3D_OUTPUT, "Výstup",
    {InPort(*this, vec3(), "")}, {}) { }

void Vector3DOutput::Compute() { }


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


VectorDotProductBlock::VectorDotProductBlock(Graph &g)
    : BlockBase(g, VECTOR_DOTPRODUCT, BLOCK_NAME.at(VECTOR_DOTPRODUCT),
    {
        InPort(*this, vec2(), "Vektor A"),
        InPort(*this, vec2(), "Vektor B")
    },
    {
        OutPort(*this, scal(), "Výstup")
    }
    ){}

void VectorDotProductBlock::Compute(){
    this->Output(0)["val"] = this->Input(0)["x"] * this->Input(1)["x"] + this->Input(0)["y"] * this->Input(1)["y"];
}
