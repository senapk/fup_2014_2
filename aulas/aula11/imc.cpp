#include <iostream>
using namespace std;

enum NivelObesidade{Abaixo, Normal, Acima};

NivelObesidade calcula_obesidade(float altura, float peso){
    float imc = peso / (altura * altura);

    if (imc < 17)
        return Abaixo;
    if (imc < 20)
        return Normal;
    return Acima;
}

int main ()
{
    cout << (calcula_obesidade(1.70, 80) == Normal);
    return 0;
}
