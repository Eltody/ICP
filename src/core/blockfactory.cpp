/** VUT FIT ICP
 * @file blockfactory.cpp
 * @brief Alokácia a dealokácia blokov
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#include "blockfactory.h"

#include "blocks/calculator.h"
#include "blocks/vector.h"
#include "blocks/matrix.h"


// alokácia blokov
BlockBase *BlockFactory::AllocBlock(BlockType option){
    BlockBase *block;
    if(option == VECTOR_INPUT){
        block = new VectorInput(g);
    }
    else if( option == VECTOR3D_INPUT){
        block = new Vector3DInput(g);
    }
    else if( option == VECTOR_OUTPUT){
        block = new VectorOutput(g);
    }
    else if( option == VECTOR_DOT_OUTPUT){
        block = new VectorDotOutput(g);
    }
    else if( option == VECTOR3D_OUTPUT){
        block = new Vector3DOutput(g);
    }
    else if( option == MAT2_INPUT){
        block = new MatrixInput(g);
    }
    else if( option == MAT2_OUTPUT){
        block = new MatrixOutput(g);
    }
    else if( option == MAT_DETERMINANT_INPUT){
        block = new MatrixDeterminantInput(g);
    }
    else if( option == MAT_DETERMINANT_OUTPUT){
        block = new MatrixDeterminantOutput(g);
    }
    else if( option == MAT3_INPUT){
        block = new Matrix3x3Input(g);
    }
    else if( option == MAT3_OUTPUT){
        block = new Matrix3x3Output(g);
    }
    else if( option == MATH_INPUT){
        block = new MathInput(g);
    }
    else if( option == MATH_OUTPUT){
        block = new MathOutput(g);
    }
    else if( option == VECTOR_ADD){
        block = new VectorAddBlock(g);
    }
    else if( option == VECTOR_SUB){
        block = new VectorSubBlock(g);
    }
    else if( option == VECTOR_ADD3D){
        block = new VectorAddBlock3D(g);
    }
    else if( option == VECTOR_SUB3D){
        block = new VectorSubBlock3D(g);
    }
    else if( option == VECTOR_DOTPRODUCT){
        block = new VectorDotProductBlock2D(g);
    }
    else if( option == VECTOR_MUL_CONST){
        block = new VectorMulConstBlock(g);
    }
    else if( option == VECTOR_MUL_CONST3D){
        block = new VectorMulConstBlock3D(g);
    }
    else if( option == MAT_ADD){
        block = new MatrixAddBlock(g);
    }
    else if( option == MAT_MUL){
        block = new MatrixMulBlock(g);
    }
    else if( option == MAT3_ADD){
        block = new Matrix3x3AddBlock(g);
    }
    else if( option == MAT3_MUL){
        block = new Matrix3x3MulBlock(g);
    }
    else if( option == MAT_MUL_VEC){
        block = new MatMulVecBlock(g);
    }
    else if( option == MAT_SUB){
        block = new MatrixSubBlock(g);
    }
    else if( option == MAT3_SUB){
        block = new Matrix3x3SubBlock(g);
    }
    else if( option == MAT_DETERMINANT){
        block = new MatrixDeterminantBlock(g);
    }
    else if( option == MATH_ADD){
        block = new MathAddBlock(g);
    }
    else if( option == MATH_SUB){
        block = new MathSubBlock(g);
    }
    else if( option == MATH_MUL){
        block = new MathMulBlock(g);
    }
    else if( option == MATH_DIV){
        block = new MathDivBlock(g);
    }
    else if( option == MATH_SQRT){
        block = new MathSqrtBlock(g);
    }
    else if( option == MATH_ABS){
        block = new MathAbsBlock(g);
    }
    else if( option == MATH_GT){
        block = new MathGTBlock(g);
    }
    else if( option == MATH_LT){
        block = new MathLTBlock(g);
    }
    else if( option == MATH_SIN){
        block = new MathSinBlock(g);
    }
    else if( option == MATH_COS){
        block = new MathCosBlock(g);
    }
    else if( option == MATH_INC){
        block = new MathIncBlock(g);
    }
    else if( option == MATH_DEC){
        block = new MathDecBlock(g);
    }
    else{
        return nullptr;
    }
    blocks.push_back(block);
    return block;
}


BlockFactory::BlockFactory(Graph &g) : g(g) { }


// uvoľnenie bloku
void BlockFactory::FreeBlock(BlockBase *block){
    blocks.remove(block);
    delete block;
}


// uvoľnenie všetkých blokov
BlockFactory::~BlockFactory(){
    for(BlockBase *block : blocks){
        delete block;
	}
}
