#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int contar_qtd(vector<int> vet, int val){
    int cont = 0;
    for(int elem : vet)
        if(elem == val)
            cont++;
    return cont;
}

int contar_unicos(vector<int> vet){
    int cont = 0;
    for(int elem : vet){
        if(contar_qtd(vet, elem) == 1)
            cont++;
    }
    return cont;
}

int contar_sozinhos(vector<int> vet){
    int cont = 0;
    for(int i = 0; i < (int)vet.size(); i++){
        int qtd = 0;
        for(int j = 0; j < (int) vet.size(); j++){
            if(vet[i] == vet[j])
                qtd++;
        }
        if(qtd == 1)
            cont++;
    }
    return cont;
}

int contar_21(vector<int> mao){
    int total = 0;
    int n_as = 0;
    for(int carta : mao){
        if(carta > 10){
            total += 10;
        }else if(carta > 1){
            total += carta;
        }else{
            total += 11;
            n_as++;
        }
    }
    while(total > 21 and n_as > 0){
        total -= 10;
        n_as--;
    }
    return total;
}

vector<int> pegar_baralho(){
    vector<int> baralho;
    for(int i = 1; i < 14; i++)
        for(int j = 0; j < 4; j++)
            baralho.push_back(i);
    return baralho;
}

void embaralhar(vector<int> & baralho){
    random_shuffle(begin(baralho), end(baralho));
}
void ordenar(vector<int> & baralho){
    sort(begin(baralho), end(baralho));
}

void print(vector<int> baralho){
    cout << "[";

    for(int elem : baralho){
        cout << elem << " ";
    }
    cout << "]\n";
}

int pedir_carta(vector<int> & baralho){
    if(baralho.size() == 0)
        return -1;
    int valor = baralho[baralho.size() - 1];
    baralho.pop_back();
    return valor;
}

int main()
{
    vector<int> baralho = pegar_baralho();
    print(baralho);

    embaralhar(baralho);
    print(baralho);

    vector<int> mao;
    mao.push_back(pedir_carta(baralho));
    mao.push_back(pedir_carta(baralho));
    mao.push_back(pedir_carta(baralho));
    mao.push_back(pedir_carta(baralho));
    print(mao);

    mao.clear();
    mao.push_back(pedir_carta(baralho));
    mao.push_back(pedir_carta(baralho));
    mao.push_back(pedir_carta(baralho));
    mao.push_back(pedir_carta(baralho));

    print(mao);
    cout << contar_21(mao);


    return 0;

}
