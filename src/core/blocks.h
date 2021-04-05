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
enum BlockType{
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
    VECTOR_MUL_CONST3D = 40,

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
    { VECTOR_INPUT, "Vektorový vstup (2D)" },
    { VECTOR3D_INPUT, "Vektorový vstup (3D)" },
    { VECTOR_OUTPUT, "Vektorový výstup (2D)" },
    { VECTOR3D_OUTPUT, "Vektorový výstup (3D)" },
    { VECTOR_DOT_OUTPUT, "Výstup skalárneho súčinu" },
    { VECTOR_ADD, "Vektorové sčítanie (2D)"},
    { VECTOR_ADD3D, "Vektorové sčítanie (3D)"},
    { VECTOR_SUB3D, "Vektorové odčítanie (3D)"},
    { VECTOR_SUB,  "Vektorové odčítanie  (2D)"},
    { VECTOR_DOTPRODUCT, "Skalárny súčin" },
    { VECTOR_MUL_CONST, "Vektorové násobenie číslom (2D)"},
    { VECTOR_MUL_CONST3D, "Vektorové násobenie číslom (3D)"},

    // Matrix
    { MAT2_INPUT, "Maticový vstup" },
    { MAT3_INPUT, "Maticový vstup" },
    { MAT_DETERMINANT_INPUT, "Vstup pre determinant" },
    { MAT2_OUTPUT, "Maticový výstup" },
    { MAT3_OUTPUT, "Maticový výstup" },
    { MAT_DETERMINANT_OUTPUT, "Výstup pre determinantu" },
    { MAT_ADD, "Maticové sčítanie"},
    { MAT3_ADD, "Maticové sčítanie"},
    { MAT_MUL,  "Maticové násobenie"},
    { MAT3_MUL,  "Maticové násobenie"},
    { MAT_SUB, "Maticové odčítanie"},
    { MAT3_SUB, "Maticové odčítanie"},
    { MAT_DETERMINANT, "Výpočet determinantu"},
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
    { MATH_GT, "Porovnanie čísel A>B"},
    { MATH_LT, "Porovnanie čísel A<B"},
    { MATH_SIN, "Sínus čísla"},
    { MATH_COS, "Cosínus čísla"},
    { MATH_INC, "Inkrement čísla o 1"},
    { MATH_DEC, "Dekrement čísla o 1"},
};

#endif // BLOCKS_H
