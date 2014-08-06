#ifndef COMPONENTE_H
#define COMPONENTE_H

#include <iostream>
#include "constantes.h"
#include "imagemanager.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Componente {
protected:
    int x, y;
    int altura, largura;
    int frame;
    Objeto tipo;
    int variacaoDeTipo;
    Sprite sprite;


public:
    Componente(int x, int y, int largura, int altura, Objeto tipo);
    void carregarSprite();

    void paint(RenderWindow* j);

    int getX();
    int getY();
    Objeto getTipo();
    Sprite* getSprite();
    void setX(int x);
    void setY(int y);
    void setPosicao(int x, int y);
    void setSize(int altura, int largura);
    void setVariacao(int variacao);

    bool colide(Componente* c);
};

#endif // COMPONENTE_H
