#include <iostream>
#include "deck.h"
using namespace std;
#include <ctime>
#include <cstdlib>

int main(){
    srand(time(NULL));
    vector<Carta> baralho = get_baralho();
    cout << "baralho criado" << endl << to_string(baralho) << endl;
    ordenar_valor(baralho);
    cout << "ordenado por valor" << endl << to_string(baralho) << endl;
    ordenar_naipe(baralho);
    cout << "ordenado por naipe" << endl << to_string(baralho) << endl;
    random_shuffle(begin(baralho), end(baralho));
    cout << "embaralhado" << endl << to_string(baralho) << endl;

    vector<Carta> mao;
    mao.push_back(puxar_carta(baralho));
    mao.push_back(puxar_carta(baralho));
    mao.push_back(puxar_carta(baralho));
    mao.push_back(puxar_carta(baralho));
    mao.push_back(puxar_carta(baralho));
    cout << "mao puxada" << endl << to_string(mao) << endl;
    cout << "baralho que sobrou" << endl << to_string(baralho) << endl;

    return 0;
}

