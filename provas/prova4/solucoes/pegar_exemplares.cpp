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

//int pos_primeiro(vector<int> vet, int elem){
    //for(int i = 0; i < (int)vet.size(); i++){
        //if(vet[i] == elem)
            //return i;
    //}
    //return -1;
//}

//#include <algorithm>
//vector<int> pegar_exemplares(vector<int> vet){
    //vector<int> exemplares;
    //for(int i = 0; i < (int)vet.size(); i++){
        //if(pos_primeiro(vet, vet[i]) == i)
            //exemplares.push_back(vet[i]);
    //}
    //sort(begin(exemplares), end(exemplares));
    //return exemplares;
//}

bool tem_igual(vector<int> vet, int pos, int elem){
    for(int i = 0; i < pos; i++)
        if(vet[i] == elem)
            return true;
    return false;
}

vector<int> pegar_exemplares(vector<int> vet){
    vector<int> exemplares;
    for(int i = 0; i < (int)vet.size(); i++)
        if(!tem_igual(vet, i, vet[i]))
            exemplares.push_back(vet[i]);

    sort(begin(exemplares), end(exemplares));
    return exemplares;
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
