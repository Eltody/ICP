#-------------------------------------------------
#
# Project created by QtCreator 2018-04-26T10:21:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = blockeditor
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
    src/core/blocks/calculator.cpp \
    src/gui/tooltip.cpp \
    src/main.cpp \
    src/core/type.cpp \
    src/core/port.cpp \
    src/core/blockbase.cpp \
    src/gui/connection_ui.cpp \
    src/gui/port_ui.cpp \
    src/gui/blockeditor.cpp \
    src/core/graph.cpp \
    src/core/types/types.cpp \
    src/core/blockfactory.cpp \
    src/gui/blockfactory_ui.cpp \
    src/gui/graph_ui.cpp

HEADERS += \
    src/core/blocks/calculator.h \
    src/gui/tooltip.h \
    src/core/type.h \
    src/core/port.h \
    src/core/blockbase.h \
    src/gui/connection_ui.h \
    src/gui/block_ui.h \
    src/gui/port_ui.h \
    src/gui/blockeditor.h \
    src/core/graph.h \
    src/core/types/types.h \
    src/core/blockfactory.h \
    src/core/blocks.h \
    src/gui/blockfactory_ui.h \
    src/gui/graph_ui.h \

FORMS += \
    src/gui/blockeditor.ui

RESOURCES += res/icons.qrc

CONFIG += c++14
