#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <vector>
#include "deck.h"

typedef vector<Carta> vec_c;

int calcular_pontos(vector<Carta> mao);

void dar_carta(vector<Carta> &pilha, vector<Carta> & mao);

void mostrar_placar(vec_c jogador, vec_c mesa);

#endif // BLACKJACK_H
