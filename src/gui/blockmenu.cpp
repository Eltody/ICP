/** ICP Project 2017/2018: BlockEditor
 * @file blockmenu.cpp
 * @brief Class for block type selection drop-down and block actions drop-down
 * @details Class contains methods for drop-down menus that call creation of new blocks
 * and menus created when right-clicking blocks
 * @author Tomáš Pazdiora (xpazdi02)
 * @author Michal Pospíšil (xpospi95)
 */


#include "blockmenu.h"
#include <QCursor>
#include "../core/blocks.h"
#include "block_ui.h"

BlockMenu::BlockMenu(GraphUI &g) : graph(g) {
    auto matrix = menu.addMenu("Matica 2x2");
    auto matrix3 = menu.addMenu("Matica 3x3");
    auto vector = menu.addMenu("Vektor");
    auto calculator = menu.addMenu("Kalkulačka");


    matrix->addAction(new BlockMenuAction(MAT2_INPUT, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT2_OUTPUT, QIcon()));

    matrix->addAction(new BlockMenuAction(MAT_DETERMINANT_INPUT, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT_DETERMINANT_OUTPUT, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT_ADD, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT_SUB, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT_MUL, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT_MUL_VEC, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT_DETERMINANT, QIcon()));


    matrix3->addAction(new BlockMenuAction(MAT3_INPUT, QIcon()));
    matrix3->addAction(new BlockMenuAction(MAT3_OUTPUT, QIcon()));
    matrix3->addAction(new BlockMenuAction(MAT3_ADD, QIcon()));
    matrix3->addAction(new BlockMenuAction(MAT3_SUB, QIcon()));
    matrix3->addAction(new BlockMenuAction(MAT3_MUL, QIcon()));


	vector->addAction(new BlockMenuAction(VECTOR_INPUT, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR3D_INPUT, QIcon()));
	vector->addAction(new BlockMenuAction(VECTOR_OUTPUT, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR3D_OUTPUT, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR_DOT_OUTPUT, QIcon()));
	vector->addAction(new BlockMenuAction(VECTOR_ADD, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR_SUB, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR_ADD3D, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR_SUB3D, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR_DOTPRODUCT, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR_MUL_CONST, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR_MUL_CONST3D, QIcon()));


    calculator->addAction(new BlockMenuAction(MATH_INPUT, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_OUTPUT, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_ADD, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_SUB, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_MUL, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_DIV, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_SQRT, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_ABS, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_GT, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_LT, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_SIN, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_COS, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_INC, QIcon()));
    calculator->addAction(new BlockMenuAction(MATH_DEC, QIcon()));
}


void BlockMenu::ShowMenu() {
	auto point = QCursor::pos();
	menu.move(point);
	auto selected = menu.exec();
	if (selected != nullptr) {
        BlockBase *b = graph.addBlock(static_cast<BlockMenuAction&>(*selected));;
		auto block = static_cast<BlockUI<BlockBase>*>(b);
		if(block != nullptr){
			auto p = graph.mapFromGlobal(point) - graph.getOffset();
			block->Move(p.x(), p.y());
		}
	}
}


BlockMenuAction::BlockMenuAction(BlockType t, const QIcon &icon)
	: QAction(icon, QString(BLOCK_NAME.at(t).c_str()), nullptr), t(t) { }


BlockMenuAction::operator BlockType() {
	return t;
}


BlockDelete::BlockDelete(GraphUI &g) : graph(g) {
    menu.addAction(QIcon(":/icons/delete.png"), "Vymazať");
}


void BlockDelete::ShowMenu(BlockBase *block) {
	menu.move(QCursor::pos());
	if (menu.exec() != nullptr) {
		graph.removeBlock(block);
	}
}
