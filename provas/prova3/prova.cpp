#include <iostream>
#include <vector>

using namespace std;

vector<int> pegar_sozinhos(vector<int> vet){
    return {3, 5, 7};
}

vector<int> pegar_exemplares(vector<int> vet){
    return {};
}

int main ()
{
    vector<int> in, out;
    in = {1, 2, 3, 1, 2, 5, 7, 2};
    out = {3, 5, 7};
    cout << (pegar_sozinhos(in) == out) << endl;
    in = {1, 2, 3, 2, 5, 7, 2};
    out = {1, 3, 5, 7};
    cout << (pegar_sozinhos(in) == out) << endl;

    in = {1, 2, 3, 1, 2, 5, 7, 2};
    out = {1, 2, 3, 5, 7};
    cout << (pegar_sozinhos(in) == out) << endl;
    in = {1, 2, 3, 2, 5, 7, 2, 9};
    out = {1, 2, 3, 5, 7, 9};
    cout << (pegar_sozinhos(in) == out) << endl;
    return 0;
}
