/*! VUT FIT ICP
 * @file main.cpp
 * @brief Main súbor programu
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */


#include "gui/EliteEditor.h"
#include <QApplication>
#include "gui/ui_BlockManager.h"


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
    UIBlockManager scheme;
    ELITEEDITOR win(scheme);
	return app.exec();
}
