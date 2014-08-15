#include <iostream>
using namespace std;

/*
A fórmula de Heron, utilizada para calcular a área de um triângulo, tem forma,
onde S é a área, a, b e c são os lados e sp o semiperímetro dado por,

S = sqrt(p * (p - a) * (p - b) * (p - c))
sp = (a + b + c) / 2

Determine a area do triangulo dados os lados a, b e c.
*/

float area_triangulo(float a, float b, float c){

    return 0.0;
}


/*
    Lembra que eu falei que não se pode comparar dois floats??
    Pra isso estou te dando pronta uma função que testa se dois floats
    são iguais. Olhe o exemplo na mais pra ver como funciona.
*/
#include <cmath>
bool compara_float(float float1, float float2){
    if(fabs(float1 - float2) < 0.001)
        return true;
    return false;
}


int main ()
{

    //por incrivel que pareça, essa soma dá falso
    cout << ( 0.1 + 0.1 + 0.1 == 0.3);
    //mas usando a função ela dá verdadeiro
    cout << (compara_float( 0.1 + 0.1 + 0.1, 0.3));

    //escreva seus testes aqui
    //use a calculadora pra testar o que deve sair e escreva
    //seus testes aqui com pelo menos 3 casas decimais
    return 0;
}

