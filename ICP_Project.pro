#-------------------------------------------------
#
# Project created by QtCreator 2018-04-26T10:21:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EliteEditor
TEMPLATE = app

RC_ICONS = icon.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    src/core/BlockBase.cpp \
    src/core/BlockConstructor.cpp \
    src/core/BlockManager.cpp \
    src/core/BlockPort.cpp \
    src/core/BlockType.cpp \
    src/core/Operations.cpp \
    src/core/Types.cpp \
    src/gui/EliteEditor.cpp \
    src/gui/tooltip.cpp \
    src/gui/ui_BlockConnections.cpp \
    src/gui/ui_BlockConstructor.cpp \
    src/gui/ui_BlockManager.cpp \
    src/gui/ui_BlockPort.cpp \
    src/main.cpp

HEADERS += \
    src/core/BlockBase.h \
    src/core/BlockConstructor.h \
    src/core/BlockManager.h \
    src/core/BlockPort.h \
    src/core/BlockType.h \
    src/core/Blocks.h \
    src/core/Operations.h \
    src/core/Types.h \
    src/gui/EliteEditor.h \
    src/gui/tooltip.h \
    src/gui/ui_Block.h \
    src/gui/ui_BlockConnections.h \
    src/gui/ui_BlockConstructor.h \
    src/gui/ui_BlockManager.h \
    src/gui/ui_BlockPort.h

FORMS += \
    src/gui/EliteEditor.ui

RESOURCES += res/icons.qrc

CONFIG += c++14
