#include <iostream>
using namespace std;

int main ()
{
    bool vivo = false;
    int opcao = 0;
    cout << "Se voce for zumbi digite 1\n";

    //enquanto ! (der certo)
    while(!(cin >> opcao)){
        cin.clear(); //limpe
        cin.ignore(500, '\n'); //ignore 500 ou até o \n
        cout << "Se voce for zumbi digite 1\n"; //envie msg de erro
    }

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
