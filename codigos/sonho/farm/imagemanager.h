#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include "constantes.h"

using namespace sf;
using namespace std;

//conjunto de sprites para as diferentes direções
typedef struct {
    vector<Texture> norte;
    vector<Texture> sul;
    vector<Texture> leste;
    vector<Texture> oeste;
}SpriteComponenteMovel;

class ImageManager {

public:
    //{PERSONAGEM, OBSTACULO, INIMIGO, PREMIO, CAMINHO}
    static map<int, vector<Texture> > texturasObstaculo;
    static map<int, vector<Texture> > texturasInimigo;
    static map<int, vector<Texture> > texturasPremio;
    static map<int, vector<Texture> > texturasCaminho;

    static SpriteComponenteMovel texturasMoveis; //para o personagem
    static SpriteComponenteMovel texturasMoveisOlhar; //para o personagem

public:
    static void init();
    static void carregarTextura(Objeto tipo, string end, int variacao);
    static void carregarTextura(string endN, string endS, string endL, string endO);
    static void carregarTexturaOlhar(string endN, string endS, string endL, string endO);
    static Texture* getTexture(Objeto tipo, int variacao, int frame);
    static Texture* getTexture(int frame, Direcao direcao);
    static Texture* getTextureOlhar(int frame, Direcao direcao);
    static int getAnimacaoSize(Objeto tipo, int variacao);
    static int getAnimacaoSize();
    static int getAnimacaoSizeOlhar();
};

#endif // IMAGEMANAGER_H
