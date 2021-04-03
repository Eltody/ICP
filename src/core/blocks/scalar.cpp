#include "../types/types.h"
#include "../blocks.h"
#include "scalar.h"

ScalarInput::ScalarInput(Graph &g)
    : BlockBase(g, SCAL_INPUT, "Vstup",
{}, {OutPort(*this, scal(), "")}) { }

void ScalarInput::Compute() { }

ScalarOutput::ScalarOutput(Graph &g)
    : BlockBase(g, SCAL_OUTPUT, "Výstup",
	{InPort(*this, scal(), "")}, {}) { }

void ScalarOutput::Compute() { }



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

void ScalarAddBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] + this->Input(1)["Hodnota"];
}



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

void ScalarMulBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] * this->Input(1)["Hodnota"];
}



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

void ScalarSubBlock::Compute(){
    this->Output(0)["Hodnota"] = this->Input(0)["Hodnota"] - this->Input(1)["Hodnota"];
}
