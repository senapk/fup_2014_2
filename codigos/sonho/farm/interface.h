#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "componente.h"
#include "componentemovel.h"
#include "escritor.h"
#include "personagemfactory.h"

#define INICIAR Interface::init();
#define FIM Interface::espera();
#define VELOCIDADE(speed) Interface::setSpeed(speed);

using namespace std;
using namespace sf;

class Interface {
private:
    static RenderWindow janela;
    static vector<Componente*> componentes;
    static ComponenteMovel* personagem;

public:
    static void create(string nome);
    static void create(int largura, int altura, string nome);
    static void carregarCampo(string campo, int &largura, int &altura);
    static void espera();
    static void espera(string s);
    static void espera(int sleep);
    static RenderWindow* getJanela();
    static ComponenteMovel* getPersonagem();
    static vector<Componente*> getComponentes();
    static void verificarEventos();
    //graficos
    static void mostrarComponente(Componente* c);
    static void mostrarComponentes();
    static void mostrarComponentesSemDisplay();

    static void tratarColisao();

    static void init();
    static void setSpeed(int speed);
    static int SLEEP_MOV;
};

#endif // INTERFACE_H
