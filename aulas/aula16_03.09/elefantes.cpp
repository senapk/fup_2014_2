#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum Sexo{MACHO, FEMEA};
struct Elefante{
    int peso;
    string nome;
    Sexo sexo;
};

bool um_vem_primeiro(Elefante um, Elefante dois){
    if(um.sexo == dois.sexo){
        if(um.peso < dois.peso)
            return true;
        return false;
    }
    if(um.sexo == FEMEA && dois.sexo == MACHO)
        return true;
    return false;
}

void print(vector<Elefante> elefantes){
    for(Elefante elef : elefantes){
        cout << elef.nome << " " << elef.peso << endl;
    }
    cout << "Fim" << endl;
}


int main ()
{
    vector<Elefante> circo = {{3400, "Sofia", FEMEA}, {2500, "Jorge", MACHO},
                           {2000, "Gorete", FEMEA}, {10000, "Faustao", MACHO}};
    print(circo);
    sort(circo.begin(), circo.end(), um_vem_primeiro);
    print(circo);

    return 0;
}
