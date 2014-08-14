#include <iostream>
using namespace std;

int main ()
{
    int horas = 0, minutos = 0, segundos = 0;
    cout << "horas minutos segundos\n";
    cin >> horas >> minutos >> segundos;

    cout << (horas * 3600 + minutos * 60 + segundos) << " segundos";
    return 0;
}
