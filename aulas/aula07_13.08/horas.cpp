#include <iostream>
using namespace std;

int main ()
{
    int horas = 0, minutos = 0, segundos = 0;
    int total;
    cout << "segundos\n";
    cin >> total;

    horas = total / 3600;
    total = total % 3600;

    minutos = total / 60;

    segundos = total % 60;

    cout << horas << " " << minutos << " " << segundos << endl;

    return 0;
}
