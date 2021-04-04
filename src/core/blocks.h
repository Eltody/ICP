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
    // Vector
	VECTOR_INPUT = 1,
    VECTOR3D_INPUT = 2,
    VECTOR_OUTPUT = 3,
    VECTOR3D_OUTPUT = 4,
    VECTOR_DOT_OUTPUT = 37,
    VECTOR_ADD = 5,
    VECTOR_ADD3D = 6,
    VECTOR_SUB = 7,
    VECTOR_SUB3D = 38,
    VECTOR_DOTPRODUCT = 8,
    VECTOR_MUL_CONST = 39,

    // Matrix
    MAT2_INPUT = 9,
    MAT3_INPUT = 10,
    MAT_DETERMINANT_INPUT = 11,
    MAT2_OUTPUT = 12,
    MAT3_OUTPUT = 13,
    MAT_DETERMINANT_OUTPUT = 14,
    MAT_ADD = 15,
    MAT3_ADD = 16,
    MAT_MUL = 17,
    MAT3_MUL = 18,
    MAT_SUB = 19,
    MAT3_SUB = 20,
    MAT_MUL_VEC = 21,
    MAT_DETERMINANT = 22,

    // Calculator
    MATH_INPUT = 23,
    MATH_OUTPUT = 24,
    MATH_ADD = 25,
    MATH_SUB = 26,
    MATH_MUL = 27,
    MATH_DIV = 28,
    MATH_SQRT = 29,
    MATH_ABS = 30,
    MATH_GT = 31,
    MATH_LT = 32,
    MATH_SIN = 33,
    MATH_COS = 34,
    MATH_INC = 35,
    MATH_DEC = 36
};

//! Maps human readable block names to BlockType
const std::map<BlockType, std::string> BLOCK_NAME = {
    // Vector
    { VECTOR_INPUT, "Vektorový vstup" },
    { VECTOR3D_INPUT, "3D Vektorový vstup" },
    { VECTOR_OUTPUT, "Vektorový výstup" },
    { VECTOR3D_OUTPUT, "3D Vektorový výstup" },
    { VECTOR_DOT_OUTPUT, "Vektorový výstup (pre skalárny súčin)" },
    { VECTOR_ADD, "Vektorové sčítanie"},
    { VECTOR_ADD3D, "3D Vektorové sčítanie"},
    { VECTOR_SUB3D, "3D Vektorové odčítanie"},
    { VECTOR_SUB,  "Vektorové odčítanie"},
    { VECTOR_DOTPRODUCT, "Skalárny súčin" },
    { VECTOR_MUL_CONST, "Vektorové násobenie konštantou"},

    // Matrix
    { MAT2_INPUT, "2x2 Maticový vstup" },
    { MAT3_INPUT, "3x3 Maticový vstup" },
    { MAT_DETERMINANT_INPUT, "2x2 Maticový vstup (pre determinant)" },
    { MAT2_OUTPUT, "2x2 Maticový výstup" },
    { MAT3_OUTPUT, "3x3 Maticový výstup" },
    { MAT_DETERMINANT_OUTPUT, "Maticový determinant výstup" },
    { MAT_ADD, "2x2 Maticové sčítanie"},
    { MAT3_ADD, "3x3 Maticové sčítanie"},
    { MAT_MUL,  "2x2 Maticové násobenie"},
    { MAT3_MUL,  "3x3 Maticové násobenie"},
    { MAT_SUB, "2x2 Maticové odčítanie"},
    { MAT3_SUB, "3x3 Maticové odčítanie"},
    { MAT_DETERMINANT, "2x2 Výpočet determinantu matice"},
    { MAT_MUL_VEC,  "Násobenie matice a vektoru"},

    // Calculator
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
    { MATH_SIN, "Sínus čísla"},
    { MATH_COS, "Cosínus čísla"},
    { MATH_INC, "Inkrement čísla o 1"},
    { MATH_DEC, "Dekrement čísla o 1"},
};

#endif // BLOCKS_H
