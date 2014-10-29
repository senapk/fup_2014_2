TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \ 
    bola.cpp

LIBS += -L/usr/lib -lsfml-graphics -lsfml-window -lsfml-system
INCLUDEPATH += /usr/lib/

CONFIG += c++11

HEADERS += 
