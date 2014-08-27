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
//#include <motor.h>
#define motor cout
using namespace std;


//Escreva uma função que retorne o nome da carta passada por parâmetro.
//O nome deve ser da forma:
//"7 de Paus" para valores entre 2 e 10.
//"As de Copas" para As, Valetes, Damas e Reis.
//Verifique os testes para mais informações.
//
enum Valor {AS = 1, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, DEZ,
            VALETES, DAMAS, REIS};
enum Naipe {OUROS, ESPADAS, COPAS, PAUS};

struct Carta{
    Valor valor;
    Naipe naipe;
};

//@begin

string gerar_nome(Carta carta){
    return "";
}
//@end

void tests() {
    motor << "fname BRONZE IF ENUM STRUCT" << endl;
    motor << (gerar_nome(Carta{AS, ESPADAS}) == "As de Espadas");
    motor << (gerar_nome(Carta{DAMAS, PAUS}) == "Damas de Paus");
    motor << (gerar_nome(Carta{REIS, OUROS}) == "Reis de Ouros");
    motor << (gerar_nome(Carta{VALETES, COPAS}) == "Valetes de Copas");
    motor << (gerar_nome(Carta{SETE, COPAS}) == "7 de Copas");
    motor << (gerar_nome(Carta{SETE, COPAS}) == "7 de Copas");
    motor << (gerar_nome(Carta{CINCO, COPAS}) == "5 de Copas");
}

int main(){
    tests();
    motor << "fim";
    return(0);
}