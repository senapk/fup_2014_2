/////////////////////////////////////////////
// Fundamentos de Programação - UFC Quixada
// Baixe o motor.h ou comente o include
// motor.h: https://github.com/senapk/arcade
/////////////////////////////////////////////

#include <iostream>
#include <motor.h>
using namespace std;
//@begin

//Joaozinho olhou o relógio e quis saber quanto tempo se passou desde a hora que ele almoçou.
//Faça uma função que mostre quanto tempo se passou entre dois tempos.
//Considere que o segundo tempo sempre será maior que o primeiro

struct Tempo{
    int hora;
    int minuto;
    int segundo;
};

Tempo diferenca(Tempo inicio, Tempo fim){
    return Tempo{0, 0, 0};
}

//@end

//@tests
bool igual(Tempo one, Tempo two){
    if(one.hora == two.hora)
        if(one.minuto == two.minuto)
            if(one.segundo == two.segundo)
                return true;
    return false;
}

void tests(){
    cout << "#open diferenca_tempo" << endl;
    cout << "#set PRATA IF STRUCT" << endl;
    cout << (igual(diferenca(Tempo{0, 0, 0}, Tempo{0, 0, 1}), Tempo{0, 0, 1}));
    cout << (igual(diferenca(Tempo{1, 0, 0}, Tempo{2, 3, 1}), Tempo{1, 3, 1}));
    cout << (igual(diferenca(Tempo{1, 50, 0}, Tempo{2, 0, 0}), Tempo{0, 10, 0}));

}

int main(){
    tests();
    cout << endl << "#end";
    return(0);
}
//@tips
//As linhas estão invertidas para você não ler sem querer :)
//O resultado da subtração, converta de volta para tempo.
//Subtraia os segundos
//Converta os dois tempos para segundos.
//Faça uma função que converte de tempo para segundos.

