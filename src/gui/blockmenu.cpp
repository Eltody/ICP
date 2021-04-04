#include "blockmenu.h"
#include <QCursor>
#include "../core/blocks.h"
#include "block_ui.h"

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
