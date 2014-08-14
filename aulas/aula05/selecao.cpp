#include <iostream>
using namespace std;

int main ()
{
    float salario;
    salario = 724.0;

    if (salario > 200)
    {
        if(salario > 500)
            cout << "muito rico! \n";
        if(salario < 400)
        {
            cout << "medio rico! \n";
        }
        else
        {
            cout << "rico! \n";
        }
    }
    else
        cout << "pobre! \n";

    return 0;
}
