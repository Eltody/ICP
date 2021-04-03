/** ICP Project 2017/2018: BlockEditor
 * @file blocks.h
 * @brief Block types definition and helper structures
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#ifndef BLOCKS_H
#define BLOCKS_H

#include <string>
#include <map>

//! BlockTypes used for adding blocks, block factories, etc. with assigned numbers for file saves
enum BlockType {
	// Input
	SCAL_INPUT = 0,
	VECTOR_INPUT = 1,
    VECTOR3D_INPUT = 23,
	MAT2_INPUT = 2,
    MAT3_INPUT = 19,
	// Output
	SCAL_OUTPUT = 3,
	VECTOR_OUTPUT = 4,
    VECTOR3D_OUTPUT = 24,
	MAT2_OUTPUT = 5,
    MAT3_OUTPUT = 20,
	
	// Vector
	VECTOR_ADD = 10,
    VECTOR_ADD3D = 25,
	VECTOR_SUB = 11,
    VECTOR_DOTPRODUCT = 12,
	// Scalar
    SCALAR_ADD = 13,
    SCALAR_SUB = 14,
    SCALAR_MUL = 15,
	// Matrix
	MAT_ADD = 16,
	MAT_MUL = 17,
    MAT3_ADD = 21,
    MAT3_MUL = 22,
    MAT_MUL_VEC = 18,
    MAT_SUB = 26,
    MAT3_SUB = 27,
    MATH_ADD = 28,
    MATH_INPUT = 29,
    MATH_OUTPUT = 30,
    MATH_SUB = 31,
    MATH_MUL = 32,
    MATH_DIV = 33
};

//! Maps human readable block names to BlockType
const std::map<BlockType, std::string> BLOCK_NAME = {
	// Input
    { SCAL_INPUT, "Skalárny vstup" },
    { VECTOR_INPUT, "Vektorový vstup" },
    { VECTOR3D_INPUT, "3D Vektorový vstup" },
    { MAT2_INPUT, "Maticový vstup" },
    { MAT3_INPUT, "3x3 Maticový vstup" },
	// Output
    { SCAL_OUTPUT, "Skalárny výstup" },
    { VECTOR_OUTPUT, "Vektorový výstup" },
    { VECTOR3D_OUTPUT, "3D Vektorový výstup" },
    { MAT2_OUTPUT, "Maticový výstup" },
    { MAT3_OUTPUT, "3x3 Maticový výstup" },

	// Vector
    { VECTOR_ADD, "Vektorové sčítanie"},
    { VECTOR_ADD3D, "3D Vektorové sčítanie"},
    { VECTOR_SUB,  "Vektorové odčítanie"},
    { VECTOR_DOTPRODUCT, "Skalárny súčin" },
	// Scalar
    { SCALAR_ADD, "Skalárne sčítanie"},
    { SCALAR_SUB, "Skalárne odčítanie"},
    { SCALAR_MUL,  "Skalárne násobenie"},
	// Matrix
    { MAT_ADD, "Maticové sčítanie"},
    { MAT3_ADD, "3x3 Maticové sčítanie"},
    { MAT_MUL,  "Maticové násobenie"},
    { MAT3_MUL,  "3x3 Maticové násobenie"},
    { MAT_MUL_VEC,  "Násobenie matice a vektoru"},
    { MAT_SUB, "Maticové odčítanie"},
    { MAT3_SUB, "3x3 Maticové odčítanie"},
    // Math
    { MATH_INPUT, "Číselný vstup" },
    { MATH_OUTPUT, "Číselný výstup" },
    { MATH_ADD, "Matematické sčítanie"},
    { MATH_SUB, "Matematické odčítanie"},
    { MATH_MUL, "Matematické násobenie"},
    { MATH_DIV, "Matematické delenie"},
};

#endif // BLOCKS_H
