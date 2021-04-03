/** ICP Project 2017/2018: BlockEditor
 * @file matrix_io.cpp
 * @brief Matrix IO block's operation and ports definition
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#include "matrix3x3_io.h"
#include "../types/types.h"

Matrix3x3Input::Matrix3x3Input(Graph &g)
    : BlockBase(g, MAT3_INPUT, "Vstup",
{}, {OutPort(*this, mat3(), "")}) { }

void Matrix3x3Input::Compute() { }

Matrix3x3Output::Matrix3x3Output(Graph &g)
    : BlockBase(g, MAT3_OUTPUT, "Výstup",
    {InPort(*this, mat3(), "")}, {}) { }

void Matrix3x3Output::Compute() { }
