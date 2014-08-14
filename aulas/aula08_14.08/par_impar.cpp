#include <iostream>
using namespace std;

enum Opcao {PAR, IMPAR};
enum Resultado {JOGADOR1, JOGADOR2};

Resultado quem_ganhou( Opcao jog1, int valor_jog1, int valor_jog2){

}


int main ()
{
    cout << (quem_ganhou(PAR, 1, 1) == JOGADOR1);
    cout << (quem_ganhou(PAR, 1, 0) == JOGADOR2);
    cout << (quem_ganhou(IMPAR, 1, 0) == JOGADOR1);
    cout << (quem_ganhou(IMPAR, 1, 5) == JOGADOR2);

    return 0;
}
