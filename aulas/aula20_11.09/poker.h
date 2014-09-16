#ifndef RULES_H
#define RULES_H

#include "deck.h"

//http://www.thesocialpoker.com/howToPlayPokerRanking.do

//verifica se os elementos nas posicoes inicio ate fim
//possuem naipes iguais
bool naipes_iguais(vector<int> vet, int inicio, int fim);
//verifica se os elementos nas posicoes inicio ate fim
//formam sequencia
bool eh_sequencia(vector<int> vet, int inicio, int fim);
//verifica se os elementos nas posicoes inicio ate fim
//sao iguais
bool eh_igual(vector<int> vet, int inicio, int fim);
//conta quantos elementos desse valor existem
int  contar_valor(vector<int> vet, int valor);


int is_seq_real(vector<int> cartas);
int is_seq_naipe(vector<int> cartas);
int is_quadra(vector<int> cartas);
int is_trinca_par(vector<int> cartas);
int is_flush(vector<int> cartas);
int is_seq(vector<int> cartas);
int is_trinca(vector<int> cartas);
int is_dois_pares(vector<int> cartas);
int is_par(vector<int> cartas);
int is_carta_alta(vector<int> cartas);
#endif
