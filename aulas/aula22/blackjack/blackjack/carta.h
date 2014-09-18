#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;

enum Naipe {COPAS,PAUS,OUROS,ESPADAS};

struct Carta {
    int valor;
    Naipe naipe;

};

string to_string(Carta carta);

#endif // CARTA_H
