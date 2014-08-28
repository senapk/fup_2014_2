#include <iostream>
using namespace std;

enum Banana{Verde, Amarela, Preta};

int main ()
{
    Banana sacola[] = {Verde, Amarela, Preta, Verde, Verde, Amarela, Amarela};

    int qtd = 0;
    for(int ind = 0; ind < 7; ++ind){
        if(sacola[ind] == Verde)
            qtd++;
    }
    cout << "Mamae, existem " << qtd << " bananas verdes" << endl;

    return 0;
}
