#include <iostream>
using namespace std;
#include <sstream>


int main ()
{
    stringstream ss;
    ss << "batata 10 " << 15 << " " << 20 << " xilitos";

    string nome;
    int valor;

    cout << ss.str();
    //ss >> nome;
    //cout << nome << endl;

    //ss >> valor;
    //cout << valor << endl;

    //ss >> nome;
    //cout << nome << endl;

    return 0;
}
