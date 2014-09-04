#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
    vector<int> vi = {1, 2, 3, 4, 5, 6, 6, 7, 8, 6};
    for(auto elem : vi)
        cout << elem << " ";
    cout << endl;

    auto pos_after = std::remove(vi.begin(), vi.end(), 6);
    vi.erase(pos_after, vi.end());

    //ou
    //vi.erase(std::remove(vi.begin(), vi.end(), 6), vi.end());

    for(auto elem : vi)
        cout << elem << " ";
    cout << endl;

    auto eh_impar = [](int i)->bool{
        return(i % 2 == 1);
    };

    vi.erase(std::remove_if(vi.begin(), vi.end(), eh_impar), vi.end());
    for(auto elem : vi)
        cout << elem << " ";
    cout << endl;

    return 0;
}
