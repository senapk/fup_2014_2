#include <iostream>
using namespace std;

//tenta ler a idade e retorna se conseguiu
bool diga_sua_idade(){
    int idade;
    cout << "Diga sua idade:";
    if(!(cin >> idade)){
        cout << "Deu problema" << endl;
        cin.clear();
        return false;
    }
    return true;
}

int main ()
{
    bool deu_certo  = false;
    deu_certo = diga_sua_idade();
    if(!deu_certo)
        cout << "Sim, eu sei que falhou";
    return 0;
}
