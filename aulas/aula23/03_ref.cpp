#include <iostream>
using namespace std;

int swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}
int swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main ()
{
    int x = 5;
    int y = 7;
    swap(&x, &y);
    return 0;
}
