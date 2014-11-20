#include <iostream>
#include <vector>
#include <map>
#include <algorithm> //find
using namespace std;

int main(){
    vector<string> frutas = {"abacaxi", "pera", "uva", "morango"};

    auto itf = find(frutas.begin(), frutas.end(), "pera");
    if(itf == frutas.end())
        cout << "nao existe pera";
    else{
        *itf = "Pera";
        cout << "achei e troquei para "  << *itf << endl;
    }

    map<string, int> cpf = {{"davi", 123}, {"erick", 2321}, {"joao", 5430}};
    cout << cpf["davi"];

    cpf["mario"] = 4321;
    cpf["mario"] = 43211231;

    cpf["fernando"] = 1239805;

    auto it = cpf.find( "jose");
    if(it == cpf.end())
        cout << "nao existe" << endl;

    cpf["joao"] = 125;

    it = cpf.find( "mario");
    if(it != cpf.end()){
        cout << it->first << " " << it->second << endl;
    }


    cpf.erase("erick");

    it = cpf.find("joao");
    cpf.erase(it);

    if(cpf.find("joao") == cpf.end())
        cout << "Joao morreu\n" << endl;

    if(cpf.find("erick") == cpf.end())
        cout << "Erick morreu\n" << endl;

    cout << frutas[3];

    return 0;
}


