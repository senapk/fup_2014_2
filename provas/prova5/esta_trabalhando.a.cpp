/////////////////////////////////////////////
// Fundamentos de Programação - UFC Quixada
// Baixe o motor.h ou comente o include
// motor.h: https://github.com/senapk/arcade
/////////////////////////////////////////////

#include <motor.h>
#include <iostream>
using namespace std;
//@begin

//Um funcionário trabalha de segunda a sexta, de 8 até 12 e de 14 até 18.
//No sabado ele trabalho de 8 até 12.
//Faça uma função que retorna true se o funcionário está trabalhando.

enum Dia{SEG, TER, QUA, QUI, SEX, SAB, DOM};

bool esta_trabalhando(Dia dia, int hora){
    return false;
}

//@end

//@tests
void tests(){
    cout << "#open esta_trabalhando BRONZE IF ENUM" << endl;
    cout << (esta_trabalhando(DOM, 13) == false);
    cout << (esta_trabalhando(SAB, 11) == true);
    cout << (esta_trabalhando(SEG, 12) == false);
    cout << (esta_trabalhando(TER, 5) == false);
    cout << (esta_trabalhando(QUA, 15) == true);
}

int main(){
    tests();
    cout << endl << "#end";
    return(0);
}