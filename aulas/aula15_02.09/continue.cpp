#include <iostream>
using namespace std;

int main ()
{
    for(int i = 0; i < 20; i++){
        if(i < 5){
            for(int j = 0; j < 10; j++){
                if(j == 4)
                    break;
                cout << j << " ";
            }
            continue;
        }
        if(i == 18)
            break;
        cout << i << " ";
    }
    return 0;
}
