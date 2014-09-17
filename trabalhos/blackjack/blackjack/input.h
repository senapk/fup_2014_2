#ifndef INPUT_H
#define INPUT_H

#include <iostream>
using namespace std;

int pegar_opcao(string texto, int min, int max)
{
    int opcao;
    while(true){
        cout << texto << endl;
        cin >> opcao;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }else{
            if(opcao < min or opcao > max){
                cin.ignore(1000, '\n');
                continue;
            }
            break;
        }
    }
    return opcao;
}

#endif
