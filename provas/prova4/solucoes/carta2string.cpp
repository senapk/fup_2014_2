#include <iostream>
#include <motor.h>
using namespace std;

enum Naipe {COPAS,PAUS,OUROS,ESPADAS};

struct Carta {
    int valor;
    Naipe naipe;

};
#include <sstream>
//Faca uma funcao que retorne uma string correspondente a
//carta passada. Se o valor for 1 ou 14 ela vale As.
//11, 12, e 13 são J, Q e K respectivamente.
//Para os naipes use O, E, C, P para ouro, espadas, copas e paus.
string carta2string(Carta carta){
    stringstream ss;
    if(carta.valor == 1)
        ss << "A ";
    if(carta.valor == 11)
        ss << "J ";
    if(carta.valor == 12)
        ss << "Q ";
    if(carta.valor == 13)
        ss << "K ";
    if(carta.valor > 1 and carta.valor < 11)
        ss << carta.valor << " ";
    ss << "de ";
    if(carta.naipe == ESPADAS)
        ss << "Espadas";
    if(carta.naipe == COPAS)
        ss << "Copas";
    if(carta.naipe == PAUS)
        ss << "Paus";
    if(carta.naipe == OUROS)
        ss << "Ouros";
    cout << ss.str();
    return ss.str();
}


int main(){
    cout << "#open carta2string ";
    cout << (carta2string(Carta{2, PAUS})  == "2 de Paus");
    cout << (carta2string(Carta{1, PAUS})  == "A de Paus");
    cout << (carta2string(Carta{13, COPAS}) == "K de Copas");
    cout << (carta2string(Carta{10, OUROS}) == "10 de Ouros");
    cout << (carta2string(Carta{11, ESPADAS}) == "J de Espadas");

    cout << "#end";
    return 0;
}
