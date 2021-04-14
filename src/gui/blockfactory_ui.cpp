#include "blockfactory_ui.h"
#include "port_ui.h"
#include "graph_ui.h"
#include "block_ui.h"

#include "../core/blocks/operations.h"


BlockBase *BlockFactoryUI::AllocBlock(BlockType option){
	GraphUI *gp = static_cast<GraphUI*>(&g);
    BlockBase *block;

    if(option == VECTOR_INPUT){
        block = new InputBlockUI<VectorInput>(BlockUI<VectorInput>(VectorInput(g), gp), gp);
    }
    else if(option == VECTOR3D_INPUT){
        block = new InputBlockUI<Vector3DInput>(BlockUI<Vector3DInput>(Vector3DInput(g), gp), gp);
    }
    else if(option == VECTOR_OUTPUT){
        block = new OutputBlockUI<VectorOutput>(BlockUI<VectorOutput>(VectorOutput(g), gp), gp);
    }
    else if(option == VECTOR_DOT_OUTPUT){
        block = new OutputBlockUI<VectorDotOutput>(BlockUI<VectorDotOutput>(VectorDotOutput(g), gp), gp);
    }
    else if(option == VECTOR3D_OUTPUT){
        block = new OutputBlockUI<Vector3DOutput>(BlockUI<Vector3DOutput>(Vector3DOutput(g), gp), gp);
    }
    else if(option == MAT2_INPUT){
        block = new InputBlockUI<MatrixInput>(BlockUI<MatrixInput>(MatrixInput(g), gp), gp);
    }
    else if(option == MAT2_OUTPUT){
        block = new OutputBlockUI<MatrixOutput>(BlockUI<MatrixOutput>(MatrixOutput(g), gp), gp);
    }
    else if(option == MAT3_INPUT){
        block = new InputBlockUI<Matrix3x3Input>(BlockUI<Matrix3x3Input>(Matrix3x3Input(g), gp), gp);
    }
    else if(option == MAT3_OUTPUT){
        block = new OutputBlockUI<Matrix3x3Output>(BlockUI<Matrix3x3Output>(Matrix3x3Output(g), gp), gp);
    }
    else if(option == MATH_INPUT){
        block = new InputBlockUI<MathInput>(BlockUI<MathInput>(MathInput(g), gp), gp);
    }
    else if(option == MATH_OUTPUT){
        block = new OutputBlockUI<MathOutput>(BlockUI<MathOutput>(MathOutput(g), gp), gp);
    }
    else if(option == VECTOR_ADD){
        block = new BlockUI<VectorAddBlock>(VectorAddBlock(g), gp);
    }
    else if(option == VECTOR_SUB){
        block = new BlockUI<VectorSubBlock>(VectorSubBlock(g), gp);
    }
    else if(option == VECTOR_ADD3D){
        block = new BlockUI<VectorAddBlock3D>(VectorAddBlock3D(g), gp);
    }
    else if(option == VECTOR_SUB3D){
        block = new BlockUI<VectorSubBlock3D>(VectorSubBlock3D(g), gp);
    }
    else if(option == VECTOR_DOTPRODUCT){
        block = new BlockUI<VectorDotProductBlock2D>(VectorDotProductBlock2D(g), gp);
    }
    else if(option == VECTOR_MUL_CONST){
        block = new BlockUI<VectorMulConstBlock>(VectorMulConstBlock(g), gp);
    }
    else if(option == VECTOR_MUL_CONST3D){
        block = new BlockUI<VectorMulConstBlock3D>(VectorMulConstBlock3D(g), gp);
    }
    else if(option == MAT_ADD){
        block = new BlockUI<MatrixAddBlock>(MatrixAddBlock(g), gp);
    }
    else if(option == MAT3_ADD){
        block = new BlockUI<Matrix3x3AddBlock>(Matrix3x3AddBlock(g), gp);
    }
    else if(option == MAT_MUL){
        block = new BlockUI<MatrixMulBlock>(MatrixMulBlock(g), gp);
    }
    else if(option == MAT3_MUL){
        block = new BlockUI<Matrix3x3MulBlock>(Matrix3x3MulBlock(g), gp);
    }
    else if(option == MAT_MUL_VEC){
        block = new BlockUI<MatMulVecBlock>(MatMulVecBlock(g), gp);
    }
    else if(option == MAT_SUB){
        block = new BlockUI<MatrixSubBlock>(MatrixSubBlock(g), gp);
    }
    else if(option == MAT3_SUB){
        block = new BlockUI<Matrix3x3SubBlock>(Matrix3x3SubBlock(g), gp);
    }
    else if(option == MATH_ADD){
        block = new BlockUI<MathAddBlock>(MathAddBlock(g), gp);
    }
    else if(option == MATH_SUB){
        block = new BlockUI<MathSubBlock>(MathSubBlock(g), gp);
    }
    else if(option == MATH_MUL){
        block = new BlockUI<MathMulBlock>(MathMulBlock(g), gp);
    }
    else if(option == MATH_DIV){
        block = new BlockUI<MathDivBlock>(MathDivBlock(g), gp);
    }
    else if(option == MATH_SQRT){
        block = new BlockUI<MathSqrtBlock>(MathSqrtBlock(g), gp);
    }
    else if(option == MATH_ABS){
        block = new BlockUI<MathAbsBlock>(MathAbsBlock(g), gp);
    }
    else if(option == MATH_GT){
        block = new BlockUI<MathGTBlock>(MathGTBlock(g), gp);
    }
    else if(option == MATH_LT){
        block = new BlockUI<MathLTBlock>(MathLTBlock(g), gp);
    }
    else if(option == MATH_SIN){
        block = new BlockUI<MathSinBlock>(MathSinBlock(g), gp);
    }
    else if(option == MATH_COS){
        block = new BlockUI<MathCosBlock>(MathCosBlock(g), gp);
    }
    else if(option == MATH_INC){
        block = new BlockUI<MathIncBlock>(MathIncBlock(g), gp);
    }
    else if(option == MATH_DEC){
        block = new BlockUI<MathDecBlock>(MathDecBlock(g), gp);
    }
    else if(option == MAT_DETERMINANT){
        block = new BlockUI<MatrixDeterminantBlock>(MatrixDeterminantBlock(g), gp);
    }
    else if(option == MAT_DETERMINANT_INPUT){
        block = new InputBlockUI<MatrixDeterminantInput>(BlockUI<MatrixDeterminantInput>(MatrixDeterminantInput(g), gp), gp);
    }
    else if(option == MAT_DETERMINANT_OUTPUT){
        block = new OutputBlockUI<MatrixDeterminantOutput>(BlockUI<MatrixDeterminantOutput>(MatrixDeterminantOutput(g), gp), gp);
    }
    else{
		return nullptr;
    }
    blocks.push_back(block);
    return block;
}

BlockFactoryUI::BlockFactoryUI(GraphUI &g)
	: BlockFactory(g), block_parent(&g) { }
