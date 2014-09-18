#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> pegar_exemplares(vector<int> vet){
    vector<int> exemplares;
    for(auto it = vet.begin(); it != vet.end(); ++it){
        auto pos = find(begin(vet), end(vet), *it);
        if(pos == it)
            exemplares.push_back(*it);
    }
    return exemplares;
}

int main ()
{
    //begin e end apontam para o primeiro e o próximo apos o ultimo
    vector<int> vi = {1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
    //chamamos esses "ponteiros" que operam sobre a stl de iteradores
    //eles se comportam como ponteiros
    auto it = vi.begin();
    cout << *it << endl;
    auto exemplares = pegar_exemplares(vi);
    for(auto x : exemplares)
        cout << x << " ";
    cout << endl;

    //retorna a pos do menor elemento
    auto menor = min_element(begin(vi), end(vi));
    cout << *menor << endl;



    return 0;
}
