/*! VUT FIT ICP
 * @file blockfactory_ui.cpp
 * @brief
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */

#include "ui_BlockConstructor.h"
#include "ui_BlockPort.h"
#include "ui_BlockManager.h"
#include "ui_Block.h"

#include "../core/Operations.h"


BlockBase *UIBlockConstructor::AllocBlock(BlockType option){
	UIBlockManager *gp = static_cast<UIBlockManager*>(&g);
    BlockBase *block;

    if(option == VECTOR_INPUT){
        block = new InputBlockUI<VectorInput>(UIBlock<VectorInput>(VectorInput(g), gp), gp);
    }
    else if(option == VECTOR3D_INPUT){
        block = new InputBlockUI<Vector3DInput>(UIBlock<Vector3DInput>(Vector3DInput(g), gp), gp);
    }
    else if(option == VECTOR_OUTPUT){
        block = new OutputBlockUI<VectorOutput>(UIBlock<VectorOutput>(VectorOutput(g), gp), gp);
    }
    else if(option == VECTOR_DOT_OUTPUT){
        block = new OutputBlockUI<VectorDotOutput>(UIBlock<VectorDotOutput>(VectorDotOutput(g), gp), gp);
    }
    else if(option == VECTOR3D_OUTPUT){
        block = new OutputBlockUI<Vector3DOutput>(UIBlock<Vector3DOutput>(Vector3DOutput(g), gp), gp);
    }
    else if(option == MAT2_INPUT){
        block = new InputBlockUI<MatrixInput>(UIBlock<MatrixInput>(MatrixInput(g), gp), gp);
    }
    else if(option == MAT2_OUTPUT){
        block = new OutputBlockUI<MatrixOutput>(UIBlock<MatrixOutput>(MatrixOutput(g), gp), gp);
    }
    else if(option == MAT3_INPUT){
        block = new InputBlockUI<Matrix3x3Input>(UIBlock<Matrix3x3Input>(Matrix3x3Input(g), gp), gp);
    }
    else if(option == MAT3_OUTPUT){
        block = new OutputBlockUI<Matrix3x3Output>(UIBlock<Matrix3x3Output>(Matrix3x3Output(g), gp), gp);
    }
    else if(option == MATH_INPUT){
        block = new InputBlockUI<MathInput>(UIBlock<MathInput>(MathInput(g), gp), gp);
    }
    else if(option == MATH_OUTPUT){
        block = new OutputBlockUI<MathOutput>(UIBlock<MathOutput>(MathOutput(g), gp), gp);
    }
    else if(option == VECTOR_ADD){
        block = new UIBlock<VectorAddBlock>(VectorAddBlock(g), gp);
    }
    else if(option == VECTOR_SUB){
        block = new UIBlock<VectorSubBlock>(VectorSubBlock(g), gp);
    }
    else if(option == VECTOR_ADD3D){
        block = new UIBlock<VectorAddBlock3D>(VectorAddBlock3D(g), gp);
    }
    else if(option == VECTOR_SUB3D){
        block = new UIBlock<VectorSubBlock3D>(VectorSubBlock3D(g), gp);
    }
    else if(option == VECTOR_DOTPRODUCT){
        block = new UIBlock<VectorDotProductBlock2D>(VectorDotProductBlock2D(g), gp);
    }
    else if(option == VECTOR_MUL_CONST){
        block = new UIBlock<VectorMulConstBlock>(VectorMulConstBlock(g), gp);
    }
    else if(option == VECTOR_MUL_CONST3D){
        block = new UIBlock<VectorMulConstBlock3D>(VectorMulConstBlock3D(g), gp);
    }
    else if(option == MAT_ADD){
        block = new UIBlock<MatrixAddBlock>(MatrixAddBlock(g), gp);
    }
    else if(option == MAT3_ADD){
        block = new UIBlock<Matrix3x3AddBlock>(Matrix3x3AddBlock(g), gp);
    }
    else if(option == MAT_MUL){
        block = new UIBlock<MatrixMulBlock>(MatrixMulBlock(g), gp);
    }
    else if(option == MAT3_MUL){
        block = new UIBlock<Matrix3x3MulBlock>(Matrix3x3MulBlock(g), gp);
    }
    else if(option == MAT_MUL_VEC){
        block = new UIBlock<MatMulVecBlock>(MatMulVecBlock(g), gp);
    }
    else if(option == MAT_SUB){
        block = new UIBlock<MatrixSubBlock>(MatrixSubBlock(g), gp);
    }
    else if(option == MAT3_SUB){
        block = new UIBlock<Matrix3x3SubBlock>(Matrix3x3SubBlock(g), gp);
    }
    else if(option == MATH_ADD){
        block = new UIBlock<MathAddBlock>(MathAddBlock(g), gp);
    }
    else if(option == MATH_SUB){
        block = new UIBlock<MathSubBlock>(MathSubBlock(g), gp);
    }
    else if(option == MATH_MUL){
        block = new UIBlock<MathMulBlock>(MathMulBlock(g), gp);
    }
    else if(option == MATH_DIV){
        block = new UIBlock<MathDivBlock>(MathDivBlock(g), gp);
    }
    else if(option == MATH_SQRT){
        block = new UIBlock<MathSqrtBlock>(MathSqrtBlock(g), gp);
    }
    else if(option == MATH_ABS){
        block = new UIBlock<MathAbsBlock>(MathAbsBlock(g), gp);
    }
    else if(option == MATH_GT){
        block = new UIBlock<MathGTBlock>(MathGTBlock(g), gp);
    }
    else if(option == MATH_LT){
        block = new UIBlock<MathLTBlock>(MathLTBlock(g), gp);
    }
    else if(option == MATH_SIN){
        block = new UIBlock<MathSinBlock>(MathSinBlock(g), gp);
    }
    else if(option == MATH_COS){
        block = new UIBlock<MathCosBlock>(MathCosBlock(g), gp);
    }
    else if(option == MATH_INC){
        block = new UIBlock<MathIncBlock>(MathIncBlock(g), gp);
    }
    else if(option == MATH_DEC){
        block = new UIBlock<MathDecBlock>(MathDecBlock(g), gp);
    }
    else if(option == MAT_DETERMINANT){
        block = new UIBlock<MatrixDeterminantBlock>(MatrixDeterminantBlock(g), gp);
    }
    else if(option == MAT_DETERMINANT_INPUT){
        block = new InputBlockUI<MatrixDeterminantInput>(UIBlock<MatrixDeterminantInput>(MatrixDeterminantInput(g), gp), gp);
    }
    else if(option == MAT_DETERMINANT_OUTPUT){
        block = new OutputBlockUI<MatrixDeterminantOutput>(UIBlock<MatrixDeterminantOutput>(MatrixDeterminantOutput(g), gp), gp);
    }
    else{
		return nullptr;
    }
    blocks.push_back(block);
    return block;
}

UIBlockConstructor::UIBlockConstructor(UIBlockManager &g)
	: BlockConstructor(g), block_parent(&g) { }
