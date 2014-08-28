#include <iostream>
#include <vector>

using namespace std;

enum Fruta{Banana, Melao, Uva, Maracuja, Limao, Acerola};

struct Vagao{
    Fruta fruta;
    float peso;
};

//int peso_total(vector<Vagao> trem, Fruta fruta){
    //return 0;
//}


int main ()
{
    Vagao vagao1 = {Banana, 7658.0};
    Vagao vagao2 = {Maracuja, 2567.0};
    Vagao vagao3 = {Banana, 658.0};
    Vagao vagao4 = {Acerola, 2567.0};
    Vagao vagao5 = {Banana, 358.0};

    vector<Vagao> trem = {vagao1, vagao2, vagao3, vagao4, vagao5, {Banana, 1000.0}};

    float peso_total = 0.0;
    for(Vagao vagao : trem){
        if(vagao.fruta == Banana)
            peso_total += vagao.peso;
    }
    cout << "Contei " << peso_total << " kilos de banana" << endl;

    return 0;
}

