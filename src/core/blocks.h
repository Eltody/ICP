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
	VECTOR_INPUT = 1,
    VECTOR3D_INPUT = 23,
	MAT2_INPUT = 2,
    MAT3_INPUT = 19,
	// Output
	VECTOR_OUTPUT = 4,
    VECTOR3D_OUTPUT = 24,
	MAT2_OUTPUT = 5,
    MAT3_OUTPUT = 20,
	
	// Vector
	VECTOR_ADD = 10,
    VECTOR_ADD3D = 25,
	VECTOR_SUB = 11,
    VECTOR_DOTPRODUCT = 12,
    // Matrix and Math
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
    MATH_DIV = 33,
    MAT_DETERMINANT = 34,
    MAT_DETERMINANT_INPUT = 35,
    MAT_DETERMINANT_OUTPUT = 36,
    MATH_SQRT = 37,
    MATH_ABS = 38,
    MATH_GT = 39,
    MATH_LT = 40
};

//! Maps human readable block names to BlockType
const std::map<BlockType, std::string> BLOCK_NAME = {
	// Input
    { VECTOR_INPUT, "Vektorový vstup" },
    { VECTOR3D_INPUT, "3D Vektorový vstup" },
    { MAT2_INPUT, "2x2 Maticový vstup" },
    { MAT3_INPUT, "3x3 Maticový vstup" },
	// Output
    { VECTOR_OUTPUT, "Vektorový výstup" },
    { VECTOR3D_OUTPUT, "3D Vektorový výstup" },
    { MAT2_OUTPUT, "2x2 Maticový výstup" },
    { MAT3_OUTPUT, "3x3 Maticový výstup" },

	// Vector
    { VECTOR_ADD, "Vektorové sčítanie"},
    { VECTOR_ADD3D, "3D Vektorové sčítanie"},
    { VECTOR_SUB,  "Vektorové odčítanie"},
    { VECTOR_DOTPRODUCT, "Skalárny súčin" },

	// Matrix
    { MAT_ADD, "2x2 Maticové sčítanie"},
    { MAT3_ADD, "3x3 Maticové sčítanie"},
    { MAT_MUL,  "2x2 Maticové násobenie"},
    { MAT3_MUL,  "3x3 Maticové násobenie"},
    { MAT_MUL_VEC,  "Násobenie matice a vektoru"},
    { MAT_SUB, "2x2 Maticové odčítanie"},
    { MAT3_SUB, "3x3 Maticové odčítanie"},
    { MAT_DETERMINANT, "2x2 Výpočet determinantu matice"},
    { MAT_DETERMINANT_OUTPUT, "Maticový determinant výstup" },
    { MAT_DETERMINANT_INPUT, "2x2 Maticový vstup (pre determinant)" },

    // Math
    { MATH_INPUT, "Číselný vstup" },
    { MATH_OUTPUT, "Číselný výstup" },
    { MATH_ADD, "Sčítanie dvoch čísel"},
    { MATH_SUB, "Odčítanie dvoch čísel"},
    { MATH_MUL, "Násobenie dvoch čísel"},
    { MATH_DIV, "Delenie dvoch čísel"},
    { MATH_SQRT, "Druhá odmocnina čísla"},
    { MATH_ABS, "Absolútna hodnota čísla"},
    { MATH_GT, "Porovnanie čísel - väčšie ako"},
    { MATH_LT, "Porovnanie čísel - menšie ako"},
};

#endif // BLOCKS_H
