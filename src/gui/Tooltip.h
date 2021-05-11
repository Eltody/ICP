#pragma once
#include <QWidget>
#include <string>

//! Zobrazené tooltipy pri umiestnení kurzoru nad blokmi
class Tooltip : public QWidget{
public:
    //! Funkcia vykreslujuca štítky v tooltipe
    static std::vector<std::string> TextLines(const std::string &text, int &width, int &height);
};
