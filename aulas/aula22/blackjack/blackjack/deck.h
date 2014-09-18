#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <algorithm> //random_shuffle
#include <vector>
#include <iomanip> //setw
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "carta.h"
using namespace std;


//PROTOTIPOS

//retorna um vetor de cartas
vector<Carta> get_baralho();

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


#endif
