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
#include <motor.h>
//#define motor cout
using namespace std;


//Joaozinho olhou o relógio e quis saber quantos segundos se passaram desde que o dia iniciou.
//Faça uma função que converte de Tempo para segundos e outra que converte de segundos para tempo.

struct Tempo{
    int hora;
    int minuto;
    int segundo;
};

//@begin

int tempo2segundos(Tempo tempo){
    return 0;
}

Tempo segundos2tempo(int segundos){
    return Tempo();
}
//@end

void tests() {
    motor << "converte PRATA IF STRUCT" << endl;
    motor << (tempo2segundos(Tempo{2, 2, 2}) == 7322);

    Tempo tempo;
    tempo = segundos2tempo(7322);
    motor << (tempo.hora == 2 && tempo.minuto == 2 && tempo.segundo ==2);
    tempo = segundos2tempo(7323);
    motor << (tempo.hora == 2 && tempo.minuto == 2 && tempo.segundo ==3);


}

int main(){
    tests();
    motor << "fim";
    return(0);
}