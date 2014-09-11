#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <algorithm> //random_shuffle
#include <vector>
#include <iomanip> //setw
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum Naipe {COPAS,PAUS,OUROS,ESPADAS};

struct Carta {
	int valor;
	Naipe naipe;
};


//PROTOTIPOS

//retorna um vetor de cartas
vector<Carta> get_baralho();

//retorna o simbolo que corresponde ao valor da carta
string value2Symbol(int value);

//retorna o simbolo UTF8 que corresponde ao naipe da carta
string naipe2symbol(Naipe naipe);

//retorna a string correpondente a carta
string to_string(Carta carta);

//retorna a string correspondente ao vetor de cartas
//voce pode passar de quantas em quantas cartas
//havera quebra de linha ou nao passar nada
string to_string(vector<Carta> cartas, int quebra = 13);

//ordena as cartas por valor
void ordenar_valor(vector<Carta> & cartas);

//ordena as cartas por naipe
void ordenar_naipe(vector<Carta> & cartas);

//embaralha as cartas
void embaralhar(vector<Carta> & cartas);

//puxa e retorna uma carta do grupo de cartas
//se o grupo de cartas tiver tamanho 0
//ele retornará uma carta de valor 0, naipe 0
Carta puxar_carta(vector<Carta> & cartas);


//IMPLEMENTACOES

vector<Carta> get_baralho() {
    vector<Carta> baralho;
    Carta carta;
    for(int i=0;i<4;i++){
        carta.naipe = (Naipe) i;
        for(int j=1;j<14;j++) {
            carta.valor = j;
            baralho.push_back(carta);
        }
    }
    return baralho;
}

string value2Symbol(int value){
    if(value == 14)
        return " A";
    if(value == 1)
        return " A";
    if(value == 11)
        return " J";
    if(value == 12)
        return " Q";
    if(value == 13)
        return " K";
    if(value == 10)
        return "10";
    return  " " + to_string(value);
}

string naipe2symbol(Naipe naipe){
    switch(naipe){
        case COPAS : return "\xe2\x99\xa5" ;
        case OUROS : return "\xe2\x99\xa6" ;
        case PAUS : return "\xe2\x99\xa3" ;
        case ESPADAS : return "\xe2\x99\xa0" ;
    }
    return  "";
}

string to_string(Carta carta){
    return (value2Symbol(carta.valor) + naipe2symbol(carta.naipe));
}

string to_string(vector<Carta> cartas, int quebra){
    stringstream saida;
    if (quebra < 2 )
        quebra = 10;
    saida << "[";
    for(int i = 0; i < (int) cartas.size() - 1; i++){
        if(i != 0 and i % quebra == 0)
            saida << endl << " ";
        saida << to_string(cartas[i]) << ",";
    }
    saida << to_string(cartas.back()) << " ]" << endl;
    return saida.str();
}

void ordenar_valor(vector<Carta> & cartas){
    sort(begin(cartas), end(cartas), [](Carta c1, Carta c2){
        return c1.valor < c2.valor;
    });
}
void ordenar_naipe(vector<Carta> & cartas){
    sort(begin(cartas), end(cartas), [](Carta c1, Carta c2){
        if(c1.naipe == c2.naipe)
            return (c1.valor < c2.valor);
        return c1.naipe < c2.naipe;
    });
}

void embaralhar(vector<Carta> & cartas){
    static int init = 0;
    if(init == 0){
        init = 1;
        srand(time(NULL));
    }
    random_shuffle(begin(cartas), end(cartas));
}

//Se cartas vazio, retorna carta invalida
Carta puxar_carta(vector<Carta> & cartas){
    if(cartas.size() == 0)
        return Carta{0,(Naipe)0};

    Carta carta;
    carta = cartas.back();
    cartas.pop_back();
    return carta;
}

#endif
