TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    blackjack.cpp \
    deck.cpp \
    carta.cpp

HEADERS += \
    deck.h \
    input.h \
    blackjack.h \
    carta.h

CONFIG += c++11
