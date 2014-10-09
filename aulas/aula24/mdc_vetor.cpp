
/////////////////////////////////////////////
// Fundamentos de Programação - UFC Quixada
// Baixe o motor.h ou comente o include
// motor.h: https://github.com/senapk/arcade
/////////////////////////////////////////////

#include <motor.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//@begin

//Chiquinho estava simplificando umas equações.
//x/a + x/b + x/c
//
//O professor disse que Chiquinho precisaria calcular o máximo divisor comum
//entre a, b e c.
//
//Como você é amigo de Chiquinho, ele pediu logo pra você fazer um programa
//que calcular o MDC de qualquer número de elementos.
//
//Faça uma função que recebe um vetor de inteiros e retorna o mdc deles.
int mdc(vector<int> vet){
    return 0;
}

//@end

void tests(){
    cerr << "#open mdc_arrays BRONZE IF FOR" << endl;
    cerr << (mdc({2, 4}) == 2);
    cerr << (mdc({3, 5}) == 1);
    cerr << (mdc({15, 21}) == 3);
    cerr << (mdc({15, 45}) == 15);
    cerr << (mdc({15, 45, 10}) == 5);
    cerr << (mdc({15, 45, 150}) == 15);
}

int main(){
    tests();
    cerr << endl << "#end";
    return(0);
}
