/////////////////////////////////////////////
// Fundamentos de Programação - UFC Quixada
// Baixe o motor.h ou comente o include
// motor.h: https://github.com/senapk/arcade
/////////////////////////////////////////////

#include <iostream>
#include <motor.h>
#include <vector>
#include <algorithm>

using namespace std;
//@begin

//O dono do zoologico quer a lista de todos os animais do zoologico
//que possuiem apenas um exemplar de cada especie.
//Para isso ele te deu uma lista de todos os animais.
//Ele quer que você faça um programa que retorne uma
//nova lista contendo apenas as especies que contem apenas um exemplar.
//Considere que um número representa uma especie.
//Devolva um novo vetor ordenado das especies que só tem um exemplar.
//Voce pode usar o sort da std para ordenar.

vector<int> pegar_sozinhos(vector<int> vet){
    return vector<int>();
}

//@end

void tests ()
{
    cout << "#open sozinho PRATA IF FOR VECTOR ";
    vector<int> in, out;
    in = {1, 1};
    out = {};
    cout << (pegar_sozinhos(in) == out) << endl;

    in = {2, 1, 1};
    out = {2};
    cout << (pegar_sozinhos(in) == out) << endl;

    in = {2, 3, 1, 2, 5, 7, 2};
    out = {1, 3, 5, 7};
    cout << (pegar_sozinhos(in) == out) << endl;
}

int main(){
    tests();
    cout << endl << "#end";
    return(0);
}