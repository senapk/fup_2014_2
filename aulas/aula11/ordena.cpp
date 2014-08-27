#include <iostream>
using namespace std;

enum Ordenacao {Crescente, Decrescente, SemOrdem};

Ordenacao verifica_ordem( int A, int B, int C){
    if( A < B && B < C)
        return Crescente;
    if( A > B and B > C)
        return Decrescente;
    return SemOrdem;
}


int main ()
{
    cout <<( verifica_ordem( 1, 2, 0) == SemOrdem);
    return 0;
}
