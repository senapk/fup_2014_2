#include <iostream>
#include <vector>
using namespace std;

enum Banana{Verde, Amarela, Preta};

int contar_bananas(vector<Banana> sacola, Banana tipo){
    return 0;
}

int main ()
{
    vector<Banana> sacola = {Verde, Amarela, Preta, Verde,
                             Verde, Amarela, Amarela, Verde,
                             Verde, Verde, Verde, Verde, Verde};

    int qtd = 0;

    for(auto banana : sacola){
        if(banana == Verde)
            qtd++;
    }
    cout << "Mamae, existem " << qtd << " bananas verdes" << endl;
    sacola.pop_back();
    sacola.pop_back();
    qtd = 0;
    for(auto banana : sacola){
        if(banana == Verde)
            qtd++;
    }
    cout << "Mamae, existem " << qtd << " bananas verdes" << endl;
    sacola.push_back(Verde);
    qtd = 0;
    for(auto banana : sacola){
        if(banana == Verde)
            qtd++;
    }
    cout << "Mamae, existem " << qtd << " bananas verdes" << endl;


    return 0;
}
