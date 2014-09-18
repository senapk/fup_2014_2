#include <iostream>
using namespace std;

struct Pessoa{
    string nome;
    int idade;
};

int main ()
{
    Pessoa *ptr = new Pessoa{"Mario", 68}; //{} c++11 only

    //tres formas de usar
    cout << ptr[0].nome << " " << ptr[0].idade << endl;
    cout << (*ptr).nome << " " << (*ptr).idade << endl;
    cout << ptr->nome << " " << ptr->idade << endl;

    int *x = new int; //x recebe um endereco de um int cout << *x << endl;

    int *y = new int(8); //y aponta para um inteiro inicializado com 8
    cout << *y << endl;

    int *z = new int[8]; //z eh a cabeça de um vetor de 8 inteiros
    cout << *z << endl;

    //devolvendo a memoria
    delete [] z;
    delete x;
    delete y;
    delete ptr;

    return 0;
}
