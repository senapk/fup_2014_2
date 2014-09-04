#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> vet){
    cout << "[ ";
    for(int elem : vet){
        cout << elem << " ";
    }
    cout << ']' << endl;
}

int main ()
{
    cout << std::min(8, 5) << endl;
    int v1 = 12;
    int v2 = 15;
    int v3 = max(v1, v2);
    cout << v3 << endl;;
    std::swap(v1, v2);
    cout << v2 << endl; //12

    string nome = "David Sena Oliveira";
    cout << nome[0] << " " << nome[4] << endl;
    swap(nome[0], nome[4]);
    cout << nome << endl; //daviD

    for(char c : nome){
        cout << c << " ";
    }
    cout << endl;
    for(int i = 0; i <(int) nome.length(); i++){
        cout << nome[i] << " ";
    }
    cout << endl;

    vector<int> notas = {9, 8, 7, 6, 7, 8, 0, 7};
    print(notas);
    sort(notas.begin(), notas.end());
    print(notas);

    sort(nome.begin(), nome.end());
    cout << nome << endl;

    random_shuffle(notas.begin(), notas.end());
    print(notas);
    random_shuffle(notas.begin(), notas.end());
    print(notas);
    reverse(notas.begin() + 1, notas.end());
    print(notas);

    cout << count(notas.begin(), notas.end(), 7) << endl;

    auto posicao = find(notas.begin(), notas.end(), 12);
    if(posicao == notas.end())
        cout << "nao existe" << endl;
    else
        *posicao = 10;
    print(notas);

    posicao = find(notas.begin(), notas.end(), 0);
    if(posicao == notas.end())
        cout << "nao existe" << endl;
    else
        *posicao = 10;
    print(notas);

    posicao = min_element(notas.begin(), notas.end());
    cout << *posicao << endl;
    posicao = max_element(notas.begin(), notas.end());
    cout << *posicao << endl;




    return 0;
}
