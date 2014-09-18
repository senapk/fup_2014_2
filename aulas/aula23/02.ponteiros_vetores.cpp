#include <iostream>
using namespace std;

int main ()
{
    int x = 6;
    int * p = &x;
    cout << p[0] << endl; //6
    cout << *p   << endl; //6

    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int * pv = vet; //o nome do vetor eh o endereco do primeiro elemento
    cout << pv[0] << endl; //1
    pv = vet + 3; //pulou pro terceira posicao
    cout << *pv << endl; //4
    pv = pv + 1;
    cout << *pv << endl; //5
    cout << *(pv + 2) << endl; //7
    cout << pv[2] << endl; //7
    pv[3] = 0; //o 8 passa a ser 0
    pv = &vet[9];



    //*vet eh erro pq vet não é ponteiro
    //vet++; //erro pq vet eh constante

    //o elemento 0 de pv pode ser acessado com
    cout << *pv << " ou " << pv[0] << endl;

    //o elemento 4 pode ser acessado como
    cout << *(pv + 4) << " ou " << pv[4] << endl;

    //andando num vetor utilizando ponteiros
    for(int * p = vet; p < (vet + 10); p++){
        cout << *p << endl;
    }

    return 0;
}
