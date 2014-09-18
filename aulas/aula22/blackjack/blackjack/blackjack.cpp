#include "blackjack.h"
int calcular_pontos(vector<Carta> mao){
    int total = 0;
    int num_as = 0;
    for(Carta carta : mao){
        if(carta.valor > 9){
            total += 10;
            continue;
        }
        if(carta.valor > 1){
            total += carta.valor;
            continue;
        }
        total += 11;
        num_as++;
    }
    while(total > 21 and num_as > 0){
        num_as--;
        total -= 10;
    }
    return total;
}


void dar_carta(vector<Carta> &pilha, vector<Carta> &mao){
    mao.push_back(puxar_carta(pilha));
}


void mostrar_placar(vec_c jogador, vec_c mesa){
    cout << "Jogador : "
         << calcular_pontos(jogador) << " "
         << to_string(jogador);
    cout << "Mesa : "
         << calcular_pontos(mesa) << " "
         << to_string(mesa) << endl;
}
