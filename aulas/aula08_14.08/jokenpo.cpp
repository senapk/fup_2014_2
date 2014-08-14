#include <iostream>
using namespace std;

enum Opcao {PEDRA, PAPEL, TESOURA};
enum Resultado {EMPATE, JOGADOR1, JOGADOR2};

//retorne 1 se o jogador 1 ganhou e 2 se o jogador 2 ganhou e 0 se empate
Resultado quem_ganhou( Opcao jog1, Opcao jog2){
    if(jog1 == jog2)
        return EMPATE;
    if(jog1 == PEDRA && jog2 == TESOURA)
        return JOGADOR1;
    if(jog1 == TESOURA && jog2 == PAPEL)
        return JOGADOR1;
    if(jog1 == PAPEL && jog2 == PEDRA)
        return JOGADOR1;
    return JOGADOR2;
}


int main ()
{
    string nome = "pedra";
    Opcao escolha = PEDRA;

    cout << (quem_ganhou(PEDRA, PEDRA) == EMPATE);
    cout << (quem_ganhou(PEDRA, TESOURA) == JOGADOR1);
    cout << (quem_ganhou(PAPEL, TESOURA) == JOGADOR2);

    return 0;
}
