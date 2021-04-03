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

#include "blocks/calculator.h"
#include "blocks/vector.h"
#include "blocks/matrix.h"


// alokácia blokov
BlockBase *BlockFactory::AllocBlock(BlockType t){
	BlockBase *b;
	switch (t) {
	case VECTOR_INPUT:
		b = new VectorInput(g);
		break;
    case VECTOR3D_INPUT:
        b = new Vector3DInput(g);
        break;
	case VECTOR_OUTPUT:
		b = new VectorOutput(g);
		break;
    case VECTOR_DOT_OUTPUT:
        b = new VectorDotOutput(g);
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
    case MAT_DETERMINANT_INPUT:
        b = new MatrixDeterminantInput(g);
        break;
    case MAT_DETERMINANT_OUTPUT:
        b = new MatrixDeterminantOutput(g);
        break;
    case MAT3_INPUT:
        b = new Matrix3x3Input(g);
        break;
    case MAT3_OUTPUT:
        b = new Matrix3x3Output(g);
        break;
    case MATH_INPUT:
        b = new MathInput(g);
        break;
    case MATH_OUTPUT:
        b = new MathOutput(g);
        break;
	case VECTOR_ADD:
		b = new VectorAddBlock(g);
		break;
    case VECTOR_SUB:
        b = new VectorSubBlock(g);
        break;
    case VECTOR_ADD3D:
        b = new VectorAddBlock3D(g);
        break;
    case VECTOR_DOTPRODUCT:
        b = new VectorDotProductBlock2D(g);
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
    case MAT_DETERMINANT:
        b = new MatrixDeterminantBlock(g);
        break;
    case MATH_ADD:
        b = new MathAddBlock(g);
        break;
    case MATH_SUB:
        b = new MathSubBlock(g);
        break;
    case MATH_MUL:
        b = new MathMulBlock(g);
        break;
    case MATH_DIV:
        b = new MathDivBlock(g);
        break;
    case MATH_SQRT:
        b = new MathSqrtBlock(g);
        break;
    case MATH_ABS:
        b = new MathAbsBlock(g);
        break;
    case MATH_GT:
        b = new MathGTBlock(g);
        break;
    case MATH_LT:
        b = new MathLTBlock(g);
        break;
    case MATH_SIN:
        b = new MathSinBlock(g);
        break;
    case MATH_COS:
        b = new MathCosBlock(g);
        break;
    case MATH_INC:
        b = new MathIncBlock(g);
        break;
    case MATH_DEC:
        b = new MathDecBlock(g);
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
