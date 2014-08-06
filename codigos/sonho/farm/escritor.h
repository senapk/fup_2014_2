#ifndef ESCRITOR_H
#define ESCRITOR_H

#include <SFML/Graphics.hpp>
#include <string>
#include "constantes.h"
#include "interface.h"

using namespace std;
using namespace sf;

class Escritor {
    int x, y;
    float tamanho;
    string s;
    Color cor;
    Text texto;
    Font fonte;

public:
    Escritor();
    void setPosicao(int x, int y);
    void setTamanho(int tamanho);
    void setCor(Color cor);
    void Reset();
    void escrever(string texto);
    void escrever(string texto, Color cor);
    void escrever(string texto, int x, int y);
    void escrever(string texto, int x, int y, Color cor);
    void escreverAnimacao(string texto);
};

#endif // ESCRITOR_H
