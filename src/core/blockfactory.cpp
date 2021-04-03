/** VUT FIT ICP
 * Predmet: Seminár C++ 2020/2021
 *
 * Názov súboru: blockfactory.cpp
 * Popis súboru: alokácia a dealokácia blokov
 *
 * Dátum: 3.4.2021
 * Autori:
 *        Zaťko Tomáš  - xzatko02
 *        Martin Rakús - xrakus04
 */


#include "blockfactory.h"

#include "blocks/scalar.h"
#include "blocks/vector.h"
#include "blocks/matrix.h"


// alokácia blokov
BlockBase *BlockFactory::AllocBlock(BlockType t){
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
    case MAT_SUB:
        b = new MatrixSubBlock(g);
        break;
    case MAT3_SUB:
        b = new Matrix3x3SubBlock(g);
        break;
	default:
		return nullptr;
	}
	blocks.push_back(b);
	return b;
}


BlockFactory::BlockFactory(Graph &g) : g(g) { }


// uvoľnenie bloku
void BlockFactory::FreeBlock(BlockBase *b){
	blocks.remove(b);
	delete b;
}


// uvoľnenie všetkých blokov
BlockFactory::~BlockFactory(){
	for(BlockBase *b : blocks){
		delete b;
	}
}
