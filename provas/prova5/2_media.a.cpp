/////////////////////////////////////////////
// Fundamentos de Programação - UFC Quixada
// Baixe o motor.h ou comente o include
// motor.h: https://github.com/senapk/arcade
/////////////////////////////////////////////

#include <iostream>
#include <motor.h>
using namespace std;
//@begin

/*
   O seu professor de FUP está curioso para saber a média das notas da sua turma.
   Para isso, ele armazenou as notas em um vetor e agora pede sua ajuda para
   implementar uma função que retorna a media aritimética dos valores contidos em
   um vetor.
   */

float media(vector<float> vet) {
    return 0.0;
}

//@end

//@tests
auto feq = [](float a, float b){return (max(a,b) - min(a, b) < 0.1);};
void tests(){

    cout << "#open media BRONZE ";
    vector<float> v1 = {1.0};
    vector<float> v2 = {1.0, 2.0, 3.0};
    vector<float> v3 = {2.0, 2.0, 2.0, 2.0};

    cout << (feq(media(v1), 1.0));
    cout << (feq(media(v2), 2.0));
    cout << (feq(media(v3), 2.0));
}

int main(){
    tests();
    cout << endl << "#end";
    return(0);
}
//@tips
//As linhas estão invertidas para você não ler sem querer :)
// Depois divida pela media
// recolhendo todos os valores do vetor.
// Para calcular a soma você precisa usar um acumulador para ir
// elementos.
// A média é a soma de todos os elementos dividida pela quantidade de

