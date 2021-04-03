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
    auto matrix = menu.addMenu("Matica");
    auto scalar = menu.addMenu("Skalár");
    auto vector = menu.addMenu("Vektor");


    matrix->addAction(new BlockMenuAction(MAT2_INPUT, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT2_OUTPUT, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT3_INPUT, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT3_OUTPUT, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT_ADD, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT_SUB, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT3_ADD, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT_MUL, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT3_MUL, QIcon()));
    matrix->addAction(new BlockMenuAction(MAT_MUL_VEC, QIcon()));


	scalar->addAction(new BlockMenuAction(SCAL_INPUT, QIcon()));
	scalar->addAction(new BlockMenuAction(SCAL_OUTPUT, QIcon()));
	scalar->addAction(new BlockMenuAction(SCALAR_ADD, QIcon()));
	scalar->addAction(new BlockMenuAction(SCALAR_SUB, QIcon()));
	scalar->addAction(new BlockMenuAction(SCALAR_MUL, QIcon()));


	vector->addAction(new BlockMenuAction(VECTOR_INPUT, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR3D_INPUT, QIcon()));
	vector->addAction(new BlockMenuAction(VECTOR_OUTPUT, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR3D_OUTPUT, QIcon()));
	vector->addAction(new BlockMenuAction(VECTOR_ADD, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR_ADD3D, QIcon()));
    vector->addAction(new BlockMenuAction(VECTOR_DOTPRODUCT, QIcon()));
}


void BlockMenu::ShowMenu() {
	auto point = QCursor::pos();
	menu.move(point);
	auto selected = menu.exec();
	if (selected != nullptr) {
		BlockBase *b = graph.addBlock(static_cast<BlockMenuAction&>(*selected));
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
