/*! VUT FIT ICP
 * @file main.cpp
 * @brief Main súbor programu
 * @author Tomáš Zaťko  - xzatko02
 * @author Martin Rakús - xrakus04
 */


#include "gui/EliteEditor.h"
#include <QApplication>
#include "gui/graph_ui.h"


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
    GraphUI scheme;
    ELITEEDITOR win(scheme);
	return app.exec();
}
