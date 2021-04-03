/** ICP Project 2017/2018: BlockEditor
 * @file blockfactory.cpp
 * @brief (De)Allocation of blocks
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */

#include "blockfactory.h"

#include "blocks/scalar_io.h"
#include "blocks/vector_io.h"
#include "blocks/vector3D_io.h"
#include "blocks/matrix_io.h"
#include "blocks/matrix3x3_io.h"
#include "blocks/vectoraddblock.h"
#include "blocks/vectoraddblock3D.h"
#include "blocks/vectordotproductblock.h"
#include "blocks/scalaraddblock.h"
#include "blocks/scalarsubblock.h"
#include "blocks/scalarmulblock.h"
#include "blocks/matrixaddblock.h"
#include "blocks/matrixaddblock3x3.h"
#include "blocks/matrixmulblock.h"
#include "blocks/matrixmulblock3x3.h"
#include "blocks/matmulvecblock.h"

BlockBase *BlockFactory::AllocBlock(BlockType t)
{
	BlockBase *b;
	switch (t) {
	case SCAL_INPUT:
		b = new ScalarInput(g);
		break;
	case SCAL_OUTPUT:
		b = new ScalarOutput(g);
		break;
	case VECTOR_INPUT:
		b = new VectorInput(g);
		break;
    case VECTOR3D_INPUT:
        b = new Vector3DInput(g);
        break;
	case VECTOR_OUTPUT:
		b = new VectorOutput(g);
		break;
    case VECTOR3D_OUTPUT:
        b = new Vector3DOutput(g);
        break;
	case MAT2_INPUT:
		b = new MatrixInput(g);
		break;
	case MAT2_OUTPUT:
		b = new MatrixOutput(g);
		break;
    case MAT3_INPUT:
        b = new Matrix3x3Input(g);
        break;
    case MAT3_OUTPUT:
        b = new Matrix3x3Output(g);
        break;
	case VECTOR_ADD:
		b = new VectorAddBlock(g);
		break;
    case VECTOR_ADD3D:
        b = new VectorAddBlock3D(g);
        break;
    case VECTOR_DOTPRODUCT:
        b = new VectorDotProductBlock(g);
        break;
    case SCALAR_ADD:
        b = new ScalarAddBlock(g);
        break;
    case SCALAR_SUB:
        b = new ScalarSubBlock(g);
        break;
    case SCALAR_MUL:
        b = new ScalarMulBlock(g);
        break;
    case MAT_ADD:
        b = new MatrixAddBlock(g);
        break;
    case MAT_MUL:
        b = new MatrixMulBlock(g);
        break;
    case MAT3_ADD:
        b = new Matrix3x3AddBlock(g);
        break;
    case MAT3_MUL:
        b = new Matrix3x3MulBlock(g);
        break;
	case MAT_MUL_VEC:
		b = new MatMulVecBlock(g);
		break;
	default:
		return nullptr;
	}
	blocks.push_back(b);
	return b;
}

void BlockFactory::FreeBlock(BlockBase *b)
{
	blocks.remove(b);
	delete b;
}

BlockFactory::BlockFactory(Graph &g) : g(g) { }

BlockFactory::~BlockFactory()
{
	for(BlockBase *b : blocks){
		delete b;
	}
}
