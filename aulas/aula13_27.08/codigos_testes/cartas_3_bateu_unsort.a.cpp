//////////////////////////////////////////////////////////////////////////////
// Template Questões Individuais - Fundamentos de Programação - UFC
// __________ David Sena Oliveira, sena.ufc@gmail.com
//
// template : @version - 3.0
// motor.h : @version - 5.0
// _______ : download - http:tinyurl.com/fup-motor-h
// _______ : instalar - /usr/local/include/motor.h
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#include <motor.h>
//#define motor cout


//Escreva uma função que verifica se o trio de cartas passadas por parametro forma
//uma sequencia que vence o jogo. O jogo é vencido de duas formas:
//1- As tres cartas possuem o mesmo valor.
//2- As tres cartas possuem o mesmo naipe e valores em sequencia.
//
//As cartas já são passadas ordenadas para a função.
//Ou seja, a carta um é sempre a menor, a carta dois
//a do meio e a carta tres é a maior.
//
enum Valor {AS = 1, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, DEZ,
            VALETES, DAMAS, REIS};
enum Naipe {OUROS, ESPADAS, COPAS, PAUS};

struct Carta{
    Valor valor;
    Naipe naipe;
};

//@begin

bool bateu_ordenado(Carta um, Carta dois, Carta tres){
    return false;
}

//@end

void tests() {
    //motor << "bateu_ordenado BRONZE IF ENUM STRUCT FOR" << endl;
    motor << "bateu_ordenado OURO IF" << endl;
    motor << (bateu_ordenado(Carta{DOIS, PAUS}, Carta{TRES, OUROS}, Carta{QUATRO, ESPADAS}) == false);
    motor << (bateu_ordenado(Carta{DOIS, OUROS}, Carta{TRES, OUROS}, Carta{QUATRO, OUROS}) == true);
    motor << (bateu_ordenado(Carta{DOIS, OUROS}, Carta{DOIS, OUROS}, Carta{DOIS, ESPADAS}) == true);
}

int main(){
    tests();
    motor << "fim";
    return(0);
}