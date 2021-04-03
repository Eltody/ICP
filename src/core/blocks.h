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
	MAT_MUL_VEC = 18
};

//! Maps human readable block names to BlockType
const std::map<BlockType, std::string> BLOCK_NAME = {
	// Input
	{ SCAL_INPUT, "Scalar Input" },
	{ VECTOR_INPUT, "Vector Input" },
    { VECTOR3D_INPUT, "Vector 3D Input" },
    { MAT2_INPUT, "Matrix 2x2 Input" },
    { MAT3_INPUT, "Matrix 3x3 Input" },
	// Output
	{ SCAL_OUTPUT, "Scalar Output" },
	{ VECTOR_OUTPUT, "Vector Output" },
    { VECTOR3D_OUTPUT, "Vector 3D Output" },
    { MAT2_OUTPUT, "Matrix 2x2 Output" },
    { MAT3_OUTPUT, "Matrix 3x3 Output" },

	// Vector
	{ VECTOR_ADD, "Vector Add"},
    { VECTOR_ADD3D, "Vector 3D Add"},
	/*{ VECTOR_SUB,  "Vector Sub"},*/
	{ VECTOR_DOTPRODUCT, "Vector Dot Product" },
	// Scalar
	{ SCALAR_ADD, "Scalar Add"},
	{ SCALAR_SUB, "Scalar Sub"},
	{ SCALAR_MUL,  "Scalar Multiply"},
	// Matrix
	{ MAT_ADD, "Matrix Add"},
    { MAT3_ADD, "Matrix 3x3 Add"},
	{ MAT_MUL,  "Matrix Multiply"},
    { MAT3_MUL,  "Matrix 3x3 Multiply"},
	{ MAT_MUL_VEC,  "Matrix Vector Product"}
};

#endif // BLOCKS_H
