#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string print(vector<int> baralho){
    stringstream ss;
    ss << "[ ";

    for(int elem : baralho){
        ss << elem << " ";
    }
    ss << "]";
    return ss.str();
}

//retornar os animais que estão sozinhos
//[1 2 3 2 4 6 1 8 7]
//[3 4 6 8 7]
vector<int> pegar_sozinhos(vector<int> vet){
    vector<int> sozinhos;
    for(int referencia : vet){
        int cont = 0;
        for(int analisado : vet){
            if(analisado == referencia)
                cont++;
        }
        if(cont == 1)
            sozinhos.push_back(referencia);
    }
    return sozinhos;
}

//[1 2 3 2 4 6 1 8 1 3 2 7 6 7]
//[1 2 4 8]
//retornar os animais que não tem par
vector<int> pegar_sem_par(vector<int> vet){
    vector<int> sozinhos;
    int tam = vet.size();
    for(int i = 0; i < tam; i++){
        int cont = 0;
        int primeiro = 0;
        for(int j = 0; j < tam; j++){
            if(vet[i] == vet[j]){
                if(cont == 0)
                    primeiro = j;
                cont++;
            }
        }
        if(cont % 2 == 1 and primeiro == i){
            sozinhos.push_back(vet[i]);
        }
    }
    return sozinhos;
}

auto primeiro = [] (vector<int> vet, int elem)->int{
    for(int i = 0; i < (int)vet.size(); i++)
        if( vet[i] == elem)
            return i;
    return -1;
};

auto contar = [] (vector<int> vet, int elem)->int{
    int cont = 0;
    for(int x : vet)
        if( x == elem)
            cont++;
    return cont;
};

vector<int> pegar_sem_par2(vector<int> vet){
    vector<int> sozinhos;
    int tam = vet.size();
    for(int i = 0; i < tam; i++){
        if(contar(vet, vet[i]) % 2 == 1)
            if(primeiro(vet, vet[i]) == i)
                sozinhos.push_back(vet[i]);
    }
    return sozinhos;
}

//retornar um exemplar de cada animal
//[1 1 2 3 4 5 6 7 3 2 1 9]
//[1 2 3 4 5 6 7 9]
vector<int> um_exemplar(vector<int> vet){
    vector<int> exemplares;
    for(int i = 0; i < (int) vet.size(); i++){
        if(i == primeiro(vet, vet[i]))
            exemplares.push_back(vet[i]);
    }
    return exemplares;
}

int primeiro_nao_marcado (vector<int> vet, vector<bool> marc, int elem){
    for(int i = 0; i < (int)vet.size(); i++)
        if(vet[i] == elem and marc[i] == false)
            return i;
    return -1;
};

//pares homens e mulheres
//fazer os pares de homens(valores positivos) e mulheres(negativos)
//[1 2 -1 1 4 3 -3 3 -2 2]
//[1 4 3 2]
//
vector<int> achar_sozinhos_hm(vector<int> vet){
    vector<int> sozinhos;
    vector<bool> marcacao(vet.size(), false);
    for(int i = 0; i < (int)vet.size(); i++){
        if(marcacao[i] == false){
            marcacao[i] == true;
            int pos = primeiro_nao_marcado(vet, marcacao, -vet[i]);
                if(pos == -1)
                    sozinhos.push_back(vet[i]);
        }
    }

}

//contar quantos pares de bilas joaozinho tem


int main ()
{
    cout << print(pegar_sozinhos({1, 2, 3, 2, 4, 6, 1, 8, 7})) << endl;;
    cout << print(pegar_sem_par({1, 2, 3, 2, 4, 6, 1, 8, 7})) << endl;;
    return 0;
}
