/** VUT FIT ICP
 * Predmet: Seminár C++ 2020/2021
 *
 * Názov súboru: alert.cpp
 * Popis súboru: vytvorenie výstražného okna
 *
 * Dátum: 3.4.2021
 * Autori:
 *        Zaťko Tomáš  - xzatko02
 *        Martin Rakús - xrakus04
 */


#include "alert.h"
#include "QMessageBox"


void ErrorAlert(std::string message) {
	QMessageBox alert;
    alert.setWindowTitle("Chyba");
	alert.setText(message.c_str());
	alert.show();
	alert.exec();
}
