#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
    vector<int> vet {1, 2, 3, 4, 5, 6, 7, 8};

    for(int pos = (vet.size() - 1); pos >=0; pos--){
        cout << vet[pos] << endl;
    }
    //apagando os impares
    for(int pos = (vet.size() - 1); pos >=0; pos--){
        if(vet[pos] % 3 == 0)
            vet.erase(vet.begin() + pos);
    }

    for(int x : vet)
        cout << x << " ";
    cout << endl;

    return 0;
}
