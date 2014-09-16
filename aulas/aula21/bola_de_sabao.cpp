#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vet_i;

void print(vet_i vet){
    for(int elem : vet)
        cout << elem << " ";
    cout << endl;
}

vet_i pegar_posicoes(vet_i elementos, int valor){
    vet_i posicoes;
    for(size_t i = 0; i < elementos.size(); ++i)
        if(elementos[i] == valor)
            posicoes.push_back(i);
    return posicoes;
}

void apagar(vet_i & elementos, vet_i posicoes){
    //print(posicoes);
    for(int i = (posicoes.size() - 1); i >= 0; --i){
        int pos = posicoes[i];
        elementos.erase(begin(elementos) + pos);
        //print(elementos);
    }
    //print(elementos);
}

void somar_bolhas(vet_i & vet){
    size_t pos = 0;
    while(pos < vet.size()){
        print(vet);
        vet_i posicoes = pegar_posicoes(vet, vet[pos]);
        //cout << "oi" << endl;
        if(posicoes.size() > 1){
            vet.push_back(vet[pos] * posicoes.size());
            apagar(vet, posicoes);
            //cout << "oi2" << endl;
            pos = 0;
        }else{
            pos++;
        }
    }
}

int main ()
{
    vector<int> vet = {1, 2, 8, 4, 2, 1, 7, 8, 9, 16};
    somar_bolhas(vet);
    for(int elem : vet)
        cout << elem << " ";


    return 0;
}
