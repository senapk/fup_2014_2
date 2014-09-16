#include <iostream>
#include <vector>
using namespace std;

//38E, 41D, 39E, 39D, 40E, 41D, 42E, 41D, 38D
struct Sapato{
    int numero;
    char pe;
};

Sapato o_contrario(Sapato sapato){
    if(sapato.pe == 'D')
        sapato.pe = 'E';
    else {
        sapato.pe = 'D';
    }
    return sapato;
}

int procurar(vector<Sapato> vet, int inicio,
        vector<bool> marcados, Sapato sapato){
    for(int i = inicio; i < (int) vet.size(); i++){
        if((vet[i].numero == sapato.numero) and
               (vet[i].pe == sapato.pe) and
               marcados[i] == false)
            return i;
    }
    return -1;
}

vector<Sapato> procurar_pares(vector<Sapato> sapatos){
    vector<Sapato> pares;
    vector<bool> marcados(sapatos.size(), false);
    for(size_t i = 0; i < sapatos.size(); ++i){
        if(marcados[i] == true)
            continue;
        int pos = procurar(sapatos, i + 1, marcados, o_contrario(sapatos[i]));
        if(pos == -1)
            continue;
        marcados[pos] = true;
        pares.push_back(sapatos[i]);
        pares.push_back(sapatos[pos]);
    }
    return pares;
}

int main ()
{
    vector<Sapato> loja = {{38,'D'}, {39, 'E'}, {40, 'D'}, {39, 'E'}, {40, 'E'},
                           {38,'E'}, {39, 'D'}, {40, 'D'}, {39, 'E'}, {40, 'E'}};
    //saida esperada
    //38d 38e 39e 39d 40d 40e 40d 40e
    auto pares = procurar_pares(loja);
    for(Sapato sapato : pares){
        cout << sapato.numero << " " << sapato.pe << ",";
    }
    return 0;
}
