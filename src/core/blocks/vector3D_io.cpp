/** ICP Project 2017/2018: BlockEditor
 * @file vector_io.cpp
 * @brief Vector IO block's operation and ports definition
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#include "vector3D_io.h"
#include "../types/types.h"

Vector3DInput::Vector3DInput(Graph &g)
    : BlockBase(g, VECTOR3D_INPUT, "Vstup",
{}, {OutPort(*this, vec3(), "")}) { }

void Vector3DInput::Compute() { }

Vector3DOutput::Vector3DOutput(Graph &g)
    : BlockBase(g, VECTOR3D_OUTPUT, "Výstup",
    {InPort(*this, vec3(), "")}, {}) { }

void Vector3DOutput::Compute() { }
