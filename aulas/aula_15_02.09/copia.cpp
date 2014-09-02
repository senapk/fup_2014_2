#include <iostream>
using namespace std;

int somar(int& num){
    num = num + 5;
    cout << num << endl;
    return num;

}



int main ()
{
    int valor = 4;
    somar(valor);
    cout << valor << endl;
    return 0;
}
