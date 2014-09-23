#include <motor.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//O dono do zoologico quer a lista de todas as especies de animais
//que existem no zoologico. Para isso ele te deu uma lista de todos
//os animais. Ele quer que você faça um programa que retorne uma
//nova lista contendo apenas um animal de cada especie.
//Considere que um número representa uma especie.
//Devolva um novo vetor, sem números repetidos e ordenado.
//Voce pode usar o sort da std para ordenar.

vector<int> pegar_exemplares(vector<int> vet){
    return vector<int>();
}

int main ()
{
    cout << "#open pegar_exemplares PRATA IF FOR ";
    vector<int> in, out;
    cout << (pegar_exemplares({1, 1}) == vector<int>({1}));
    cout << (pegar_exemplares({1, 0, 1}) == vector<int>({0, 1}));
    cout << (pegar_exemplares({1, 1, 2, 0}) == vector<int>({0, 1, 2}));
    in = {1, 3, 1, 2, 5, 7, 2};
    out = {1, 2, 3, 5, 7};
    cout << (pegar_exemplares(in) == out);
    in = {1, 2, 3, 2, 5, 7, 2, 9, 0};
    out = {0, 1, 2, 3, 5, 7, 9};
    cout << (pegar_exemplares(in) == out);

    cout << endl;
    cout << "#end";
    return 0;
}
