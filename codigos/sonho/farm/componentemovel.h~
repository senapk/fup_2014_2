#ifndef COMPONENTEMOVEL_H
#define COMPONENTEMOVEL_H

#include <SFML/Graphics.hpp>
#include "componente.h"
#include <vector>

using namespace std;
using namespace sf;

class ComponenteMovel : public Componente {
private:
    int xAnt, yAnt;
    int frameOlhar;
    Estado estado;
    Direcao direcao;
    Rotacao ladoOlhando;

public:
    ComponenteMovel(int x, int y, int largura, int altura, Objeto tipo);
    void carregarSprite();

    void paint(RenderWindow* j);
    void paintOlhar(RenderWindow* j);
    ComponenteMovel* getVizinho(Rotacao lado);

    void andar(int distancia);
    Objeto verificar();

    void setEstado(Estado e);
    void setDirecao(Direcao d);
    void setLadoOlhando(Rotacao lado);
    void setFrameOlhando(int frame);
    Rotacao getLadoOlhando();
    Direcao getDirecao();
};

#endif // COMPONENTEMOVEL_H
