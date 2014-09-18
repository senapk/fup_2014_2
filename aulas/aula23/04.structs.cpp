#include <iostream>
using namespace std;

struct Pessoa{
    string nome;
    int idade;
};

int main ()
{
    Pessoa bruce{"Bruce Wayne", 35};
    Pessoa *ptr = &bruce;

    //tres formas de usar
    cout << ptr[0].nome << " " << ptr[0].idade << endl;
    cout << (*ptr).nome << " " << (*ptr).idade << endl;
    cout << ptr->nome << " " << ptr->idade << endl;

    return 0;
}
