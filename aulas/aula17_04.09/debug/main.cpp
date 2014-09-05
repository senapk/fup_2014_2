#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int achar_menor(vector<int> vet){
    int menor = vet[0];
    for(int elem : vet){
        if (elem < menor)
            menor = elem;
    }
    return menor;
}
int achar_maior(vector<int> vet){
    int maior = vet[0];
    for(int elem : vet){
        if (elem > maior)
            maior = elem;
    }
    return maior;
}

int somar(vector<int> vet){
    int soma = 0;
    for(int elem : vet)
        soma += elem;
    return soma;
}

float calcular_media(vector<int> vet){
    float soma = 0;
    for(int elem : vet)
        soma += elem;
    float media = (soma / vet.size());
    return media;
}

int contar_menores(vector<int> vet){
    float media = calcular_media(vet);
    int cont = 0;
    for(int elem : vet)
        if(elem < media)
            cont = cont + 1;
    return cont;
}

void imprimir(vector<int> vet){
    for(int elem: vet)
        cout << elem << " ";
    cout << endl;
}
/*
string get_texto(vector<int> vet){
    string saida = "[";
    for(int elem: vet)
        saida += to_string(elem) + " ";
    saida += "]\n";
    return saida;
}
*/

#include <sstream>
string get_texto(vector<int> vet){
    stringstream saida;
    saida << "[";
    for(int elem: vet)
        saida << elem << " ";
    saida << "]\n";
    return saida.str();
}

vector<int> pegar_impares(vector<int> vet){
    vector<int> vetimpar;
    for(int elem : vet)
        if(elem % 2 == 1)
            vetimpar.push_back(elem);
    return vetimpar;
}

bool existe(vector<int> vet, int elem){
    for(int criatura : vet)
        if(criatura == elem)
            return true;
    return false;
}

vector<int> intercessao(vector<int> um, vector<int> dois){
    vector<int> saida;
    for(int elem : um)
        if(existe(dois, elem))
            saida.push_back(elem);
    return saida;
}

int main()
{
    vector<int> vet = {4, 3, 1, 2, 7, 9};
    cout << "Menor " << achar_menor(vet) << endl;
    cout << "Maior " << achar_maior(vet) << endl;
    cout << "Soma " << somar(vet) << endl;
    cout << "Media " << calcular_media(vet) << endl;
    cout << "Menores " << contar_menores(vet) << endl;
    cout << get_texto(vet);
    vector<int> impares = pegar_impares(vet);
    //cout << get_texto(impares);
    sort(impares.begin(), impares.end());
    imprimir(impares);


    return 0;
}












