#include <iostream>

using namespace std;

int main(){

    int n1 = 4;
    int n2 = 5;
    int n3 = 3;

    if( (n1 < n2 and n2 < n3) or (n3 < n2 and n2 < n1))
        cout << "o cara ta no meio \n";
    else {
        cout << "o cara nao ta no meio \n";
    }

    return 0;
}
