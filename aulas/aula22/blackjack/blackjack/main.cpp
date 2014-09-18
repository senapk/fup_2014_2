#include <iostream>
#include <vector>
#include "deck.h"
#include "blackjack.h"
#include "input.h"
using namespace std;

enum Estado{Jogando, Vitoria, Derrota, Parou};
int main()
{
    vector<Carta> baralho = get_baralho();
    embaralhar(baralho);
    vector<Carta> mao;
    vector<Carta> mesa;
    dar_carta(baralho, mao);
    dar_carta(baralho, mao);
    dar_carta(baralho, mesa);

    Estado estado = Jogando;
    while(estado == Jogando){
        mostrar_placar(mao, mesa);
        if(calcular_pontos(mao) > 21){
            estado = Derrota;
            break;
        }
        if(calcular_pontos(mao) == 21){
            estado = Vitoria;
            break;
        }
        int opcao = pegar_opcao("Digite 1 para pedir carta e 2 para parar", 1, 2);
        if(opcao == 2){
            estado = Parou;
            break;
        }
        dar_carta(baralho, mao);
    }
    if(estado == Parou){
        while(calcular_pontos(mesa) < calcular_pontos(mao)){
            dar_carta(baralho, mesa);
            mostrar_placar(mao, mesa);
        }
        int pontos = calcular_pontos(mesa);
        if(pontos <= 21 and pontos > calcular_pontos(mao) )
            estado = Derrota;
        else
            estado = Vitoria;
    }

    if(estado == Vitoria)
        cout << "Ganhou \n";
    else
        cout << "Perdeu \n";


    return 0;
}

