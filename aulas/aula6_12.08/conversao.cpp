#include <iostream>
using namespace std;


float celsius2f(float valor){
    return valor * 1.8 + 32;
}
float f2celsius(float valor){
    return (valor - 32) / 1.8;
}
float k2celsius(float valor){
    return valor + 273;
}
float celsius2k(float valor){
    return valor - 273;
}

int main ()
{
    float valor = 0.0;
    char tipo1 = 0;
    char tipo2 = 0;
    float convertido = 0.0;

    cout << "Diga valor tipo1 tipo2";
    cin >> valor >> tipo1 >> tipo2;

    if(tipo1 == tipo2)
        convertido = valor;
    if(tipo1 == 'k' and tipo2 == 'c')
        convertido = k2celsius(valor);
    if(tipo1 == 'f' and tipo2 == 'k'){
        //float celsius = f2celsius(valor);
        //float kelvin = celsius2k(celsius);
        //convertido = kelvin;
        convertido = celsius2k(f2celsius(valor));

    }


    return 0;
}
