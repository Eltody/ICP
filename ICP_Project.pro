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
    src/core/BlockConstructor.cpp \
    src/core/BlockManager.cpp \
    src/core/BlockPort.cpp \
    src/core/BlockType.cpp \
    src/core/blocks/operations.cpp \
    src/gui/EliteEditor.cpp \
    src/gui/tooltip.cpp \
    src/main.cpp \
    src/core/blockbase.cpp \
    src/gui/connection_ui.cpp \
    src/gui/port_ui.cpp \
    src/core/types/types.cpp \
    src/gui/blockfactory_ui.cpp \
    src/gui/graph_ui.cpp

HEADERS += \
    src/core/BlockConstructor.h \
    src/core/BlockManager.h \
    src/core/BlockPort.h \
    src/core/BlockType.h \
    src/core/Blocks.h \
    src/core/blocks/operations.h \
    src/gui/EliteEditor.h \
    src/gui/tooltip.h \
    src/core/blockbase.h \
    src/gui/connection_ui.h \
    src/gui/block_ui.h \
    src/gui/port_ui.h \
    src/core/types/types.h \
    src/gui/blockfactory_ui.h \
    src/gui/graph_ui.h \

FORMS += \
    src/gui/EliteEditor.ui

RESOURCES += res/icons.qrc

CONFIG += c++14
