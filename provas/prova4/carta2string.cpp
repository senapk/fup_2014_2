#include <iostream>
#include <motor.h>
using namespace std;

enum Naipe {COPAS,PAUS,OUROS,ESPADAS};

struct Carta {
    int valor;
    Naipe naipe;

};

//Faca uma funcao que retorne uma string correspondente a
//carta passada. Se o valor for 1 ou 14 ela vale As.
//11, 12, e 13 são J, Q e K respectivamente.
//Para os naipes use O, E, C, P para ouro, espadas, copas e paus.
string carta_to_string(Carta carta){
    return "";
}


int main(){
    cout << "#open carta2string ";
    cout << (carta2string(Carta{2, Paus})  == "2 de Paus");
    cout << (carta2string(Carta{1, Paus})  == "A de Paus");
    cout << (carta2string(Carta{K, Copas}) == "K de Paus");
    cout << (carta2string(Carta{10, Ouros}) == "10 de Ouros");
    cout << (carta2string(Carta{J, Espadas}) == "J de Espadas");

    cout << endl
    cout << "#end";
    return 0;
}
