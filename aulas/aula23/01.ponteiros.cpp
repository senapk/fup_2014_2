#include <iostream>
using namespace std;

int main ()
{
    //Momento da Criação
    //O & na hora da criacao do lado esquerdo
    int x = 9;
    int & num = x;
    num = 5;
    cout << x << endl; //imprime 5
    //se nao for na alocação(criação), & significa o endereco
    cout << &num << endl; //o endereco de num
    cout << &x << endl; //o endereco de x;

    //o asterisco depois do tipo define uma variável que quarda um
    //endereço de uma variavel daquele tipo
    int * ptr;
    //ptr = 5; //5 é o endereço de um inteiro?????
    //ptr = &5;//5 não é uma variavel
    ptr = &x;
    cout << ptr << endl;

    //o * na hora do uso significa pegue o valor do endereco
    cout << *ptr << endl;

    int z = 10;
    int * pz = &z;

    //* do lado esquerdo significa colocar o valor
    *pz = 9;
    *pz = 2 * *pz + 1;

    //cout << ptr << endl;

    ////ptr = &5;//o 5 não possui um endereço, não é uma variável, é um valor
    //int x = 5; //NORMALMENTE variáveis são alocadas em memoria continua
    //int y = 7;
    //ptr = &x;
    //cout << ptr << " " << &x << " " << &y << endl;
    //cout << *ptr << endl;
    //ptr++;
    //cout << *ptr << endl;
    //*ptr = 9;
    //cout << y << endl; //o novo valor de y eh 9

    return 0;
}
