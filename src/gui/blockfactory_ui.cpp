/** ICP Project 2017/2018: BlockEditor
 * @file blockfactory_ui.cpp
 * @brief Block type specific creation
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */


#include "blockfactory_ui.h"
#include "port_ui.h"
#include "graph_ui.h"
#include "block_ui.h"

#include "../core/blocks/calculator.h"
#include "../core/blocks/vector.h"
#include "../core/blocks/matrix.h"

BlockBase *BlockFactoryUI::AllocBlock(BlockType t){
	GraphUI *gp = static_cast<GraphUI*>(&g);
	BlockBase *b;
	switch (t) {
	case VECTOR_INPUT:
		b = new InputBlockUI<VectorInput>(BlockUI<VectorInput>(VectorInput(g), gp), gp);
		break;
    case VECTOR3D_INPUT:
        b = new InputBlockUI<Vector3DInput>(BlockUI<Vector3DInput>(Vector3DInput(g), gp), gp);
        break;
    case VECTOR_OUTPUT:
        b = new OutputBlockUI<VectorOutput>(BlockUI<VectorOutput>(VectorOutput(g), gp), gp);
        break;
    case VECTOR_DOT_OUTPUT:
        b = new OutputBlockUI<VectorDotOutput>(BlockUI<VectorDotOutput>(VectorDotOutput(g), gp), gp);
        break;
    case VECTOR3D_OUTPUT:
        b = new OutputBlockUI<Vector3DOutput>(BlockUI<Vector3DOutput>(Vector3DOutput(g), gp), gp);
		break;
	case MAT2_INPUT:
		b = new InputBlockUI<MatrixInput>(BlockUI<MatrixInput>(MatrixInput(g), gp), gp);
		break;
	case MAT2_OUTPUT:
		b = new OutputBlockUI<MatrixOutput>(BlockUI<MatrixOutput>(MatrixOutput(g), gp), gp);
		break;
    case MAT3_INPUT:
        b = new InputBlockUI<Matrix3x3Input>(BlockUI<Matrix3x3Input>(Matrix3x3Input(g), gp), gp);
        break;
    case MAT3_OUTPUT:
        b = new OutputBlockUI<Matrix3x3Output>(BlockUI<Matrix3x3Output>(Matrix3x3Output(g), gp), gp);
        break;
    case MATH_INPUT:
        b = new InputBlockUI<MathInput>(BlockUI<MathInput>(MathInput(g), gp), gp);
        break;
    case MATH_OUTPUT:
        b = new OutputBlockUI<MathOutput>(BlockUI<MathOutput>(MathOutput(g), gp), gp);
        break;
	case VECTOR_ADD:
		b = new BlockUI<VectorAddBlock>(VectorAddBlock(g), gp);
		break;
    case VECTOR_SUB:
        b = new BlockUI<VectorSubBlock>(VectorSubBlock(g), gp);
        break;
    case VECTOR_ADD3D:
        b = new BlockUI<VectorAddBlock3D>(VectorAddBlock3D(g), gp);
        break;
    case VECTOR_DOTPRODUCT:
        b = new BlockUI<VectorDotProductBlock2D>(VectorDotProductBlock2D(g), gp);
        break;
    case MAT_ADD:
		b = new BlockUI<MatrixAddBlock>(MatrixAddBlock(g), gp);
        break;
    case MAT3_ADD:
        b = new BlockUI<Matrix3x3AddBlock>(Matrix3x3AddBlock(g), gp);
        break;
    case MAT_MUL:
		b = new BlockUI<MatrixMulBlock>(MatrixMulBlock(g), gp);
        break;
    case MAT3_MUL:
        b = new BlockUI<Matrix3x3MulBlock>(Matrix3x3MulBlock(g), gp);
        break;
	case MAT_MUL_VEC:
		b = new BlockUI<MatMulVecBlock>(MatMulVecBlock(g), gp);
		break;
    case MAT_SUB:
        b = new BlockUI<MatrixSubBlock>(MatrixSubBlock(g), gp);
        break;
    case MAT3_SUB:
        b = new BlockUI<Matrix3x3SubBlock>(Matrix3x3SubBlock(g), gp);
        break;
    case MATH_ADD:
        b = new BlockUI<MathAddBlock>(MathAddBlock(g), gp);
        break;
    case MATH_SUB:
        b = new BlockUI<MathSubBlock>(MathSubBlock(g), gp);
        break;
    case MATH_MUL:
        b = new BlockUI<MathMulBlock>(MathMulBlock(g), gp);
        break;
    case MATH_DIV:
        b = new BlockUI<MathDivBlock>(MathDivBlock(g), gp);
        break;
    case MATH_SQRT:
        b = new BlockUI<MathSqrtBlock>(MathSqrtBlock(g), gp);
        break;
    case MATH_ABS:
        b = new BlockUI<MathAbsBlock>(MathAbsBlock(g), gp);
        break;
    case MATH_GT:
        b = new BlockUI<MathGTBlock>(MathGTBlock(g), gp);
        break;
    case MATH_LT:
        b = new BlockUI<MathLTBlock>(MathLTBlock(g), gp);
        break;
    case MATH_SIN:
        b = new BlockUI<MathSinBlock>(MathSinBlock(g), gp);
        break;
    case MATH_COS:
        b = new BlockUI<MathCosBlock>(MathCosBlock(g), gp);
        break;
    case MATH_INC:
        b = new BlockUI<MathIncBlock>(MathIncBlock(g), gp);
        break;
    case MATH_DEC:
        b = new BlockUI<MathDecBlock>(MathDecBlock(g), gp);
        break;
    case MAT_DETERMINANT:
        b = new BlockUI<MatrixDeterminantBlock>(MatrixDeterminantBlock(g), gp);
        break;
    case MAT_DETERMINANT_INPUT:
        b = new InputBlockUI<MatrixDeterminantInput>(BlockUI<MatrixDeterminantInput>(MatrixDeterminantInput(g), gp), gp);
        break;
    case MAT_DETERMINANT_OUTPUT:
        b = new OutputBlockUI<MatrixDeterminantOutput>(BlockUI<MatrixDeterminantOutput>(MatrixDeterminantOutput(g), gp), gp);
        break;
	default:
		return nullptr;
	}
	blocks.push_back(b);
	return b;
}

BlockFactoryUI::BlockFactoryUI(GraphUI &g)
	: BlockFactory(g), block_parent(&g) { }
