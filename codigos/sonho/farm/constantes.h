#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>
#include <vector>
#include <map>

#define RED     cout << "\033[1;31m";
#define GREEN   cout << "\033[1;32m";
#define BLUE    cout << "\033[1;36m";
#define YELLOW  cout << "\033[1;33m";
#define WHITE   cout << "\033[1;37m";
#define RESET   cout << "\033[0m";
#define CLEAR   cout << "\033[2J";

#define showL(m, color) color cout << m << endl; RESET;
#define show(m, color) color cout << m; RESET;
#define LINE cout << endl;

using namespace std;

enum Estado {PARADO, ANDANDO, OLHANDO};
enum Direcao{NORTE = 0, LESTE = 1, SUL = 2, OESTE = 3};
enum Rotacao{DIREITA = 1, ESQUERDA = -1, FRENTE = 0};

enum Objeto {PERSONAGEM, OBSTACULO, INIMIGO, PREMIO, CAMINHO};

#define TAM_BLOCO 60
#define TAM_PASSO 15
#define FRAME_RATE 60
#define SLEEP_MOVIMENTO 20 //milisegundos
#define SLEEP_INICIAL 2000
#define FONTE "farm/fonte/UbuntuMono-B.ttf"

#define TEXTO_PATH "farm/texto/path.txt"
#define TEXTO_CAMPO "cenario.txt"
#define IMAGENS_PASTA "farm/imagens/"

#endif // CONSTANTES_H
