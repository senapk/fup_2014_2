#include <iostream>
using namespace std;

enum Opcao {PEDRA, PAPEL, TESOURA};
enum Resultado {EMPATE, JOGADOR1, JOGADOR2};

//Retorne o resultado
Resultado quem_ganhou( Opcao jog1, Opcao jog2){
