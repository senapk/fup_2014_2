#include <iostream>
using namespace std;

int main ()
{
    bool vivo = false;
    int opcao = 0;
    cout << "Se voce for zumbi digite 1\n";
    bool erro_entrada = true;
    do{
        cin >> opcao;
        if (cin.fail())
        {
            erro_entrada = true;
            cin.clear();
            cin.ignore(500, '\n');
            cout << "Se voce for zumbi digite 1\n";
        }
        else {
            erro_entrada = false;
        }

    }
    while(erro_entrada);


    if(opcao == 1){
        vivo = false;
    }else{
        vivo = true;
    }

    cout << "parabens, voce estah ";
    if(!vivo)
        cout << " morto-";
    cout << "vivo";

    return 0;
}
