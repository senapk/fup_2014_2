
#include <iostream>
#include <ctime> //time(NULL)
#include <cstdlib> //rand(), srand()
using namespace std;

int main ()
{
    srand(time(NULL));

    cout << rand() % 3 << endl;

    cout << rand() % 10 << endl;
    cout << rand() % 10 << endl;
    cout << rand() % 10 << endl;
    cout << rand() % 10 << endl;
    cout << rand() % 10 << endl;
    return 0;

    //13 e 30 - 18
    //rand()%18 + 13
    //
    //34 e 75
    //rand() % 42 + 34
}
