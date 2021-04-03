/** VUT FIT ICP
 * Predmet: Seminár C++ 2020/2021
 *
 * Názov súboru: main.cpp
 * Popis súboru: main aplikácie
 *
 * Dátum: 3.4.2021
 * Autori:
 *        Zaťko Tomáš  - xzatko02
 *        Martin Rakús - xrakus04
 */


#include "gui/blockeditor.h"
#include <QApplication>
#include "gui/graph_ui.h"


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	GraphUI schema;
	BLOCKEDITOR win(schema);
	return app.exec();
}
