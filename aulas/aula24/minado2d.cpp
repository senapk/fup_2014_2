
//#include <motor.h>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

//@begin

//O objetivo desse jogo é determinar, para cada célula do tabuleiro,
//o número de minas explosivas nos arredores da mesma (que são a própria
//célula e as células imediatamente vizinhas à direita e à esquerda, caso
//essas existam). Por exemplo, a figura abaixo ilustra uma possível
//configuração de um tabuleiro com 6 células. E o vetor de proximidade que
//eh gerado pela soma da celula atual com as vizinhas
//
// [0 1 0 0 0 1 1 1 0] -> minas
// [1 1 1 0 1 2 3 2 1] -> proximidade
//
//Escrever um programa, dado um tabuleiro, informe o número de minas na
//vizinhança de cada posição. Retorne esse vetor de proximidade

vector<int> minado(vector<int> vet){
    vector<int> proximos(vet.size(), 0);

    int tam = vet.size();
    for (int i = 1; i < (tam - 1); i++){
        proximos[i] = vet[i - 1] + vet[i] + vet[i + 1];
    }

    if (tam == 1)
        proximos[0] = vet[0];
    else
    {
        proximos[0] = vet[0] + vet[1];
        proximos[tam - 1] = vet[tam - 1] + vet[tam - 2];
    }


    return proximos;
}

//@end

void tests(){
    cerr << "#open minado PRATA VECTOR FOR" << endl;
    cerr << (minado({0, 1, 0, 0, 0, 1, 1, 1, 0}) ==
        vector<int>({1, 1, 1, 0, 1, 2, 3, 2, 1}));
    cerr << (minado({0, 0, 1, 1, 0, 1}) ==
        vector<int>({0, 1, 2, 2, 2, 1}));
    cerr << (minado({0, 0, 1, 1, 1, 0}) ==
            vector<int>({0, 1, 2, 3, 2, 1}));
}

int main(){
    tests();
    cerr << endl << "#end";
    return(0);
}
