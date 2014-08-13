#include <iostream>
using namespace std;

int main ()
{
    float sal_joao = 0.0;
    float sal_maria = 0.0;
    float gastos = 0.0;

    cout << "joao maria gastos" << endl;
    cin >> sal_joao >> sal_maria >> gastos;

    cout << "O gasto de joao eh"
         << (gastos * sal_joao/(sal_joao + sal_maria)) << endl;
    cout << "O gasto de maria eh"
         << (gastos * sal_maria/(sal_joao + sal_maria)) << endl;
    return 0;
}
