#include <iostream>
#include <vector>
#include <motor.h>
using namespace std;

//Faca uma funcao que conte o valor de uma mão de blackjack.
//Ela recebe um vetor de cartas e calcula usando as seguntes
//regras. K, Q e J valem 10 pontos. AS vale 11 pontos. As
//outras cartas valem seu proprio valor.
//Se a soma de pontos for maior que 21, o As passa a valer
//1 ponto, diminuindo a soma total para o valor tentar
//baixar para menos de 21.
//
//No vetor de inteiros mao, o valor 1, 11, 12 e 13
//sao o A, J, Q, K

int blackjack(vector<int> mao){
    return 0;
}

int main(){
    cout << "#open blackjack ";
    cout << (blackjack({1, 13}) == 21);
    cout << (blackjack({11, 13}) == 20);
    cout << (blackjack({1, 1, 1}) == 13);
    cout << (blackjack({1, 1, 2, 3, 12}) == 17);
    cout << (blackjack({1, 1, 2, 13, 12}) == 24);
    //@--
    cout << (blackjack({1, 1, 2, 3, 1}) == 18);
    cout << endl;
    cout << "#end";
}
