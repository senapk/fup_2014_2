#include <iostream>
#include <vector>
//#include <algorithm> //find
#include <map>
using namespace std;

struct Pessoa{
	int cpf;
	string nome;
};

int main(){
	//vector<Pessoa> base;
	map<string, Pessoa> mapa;

		
	//base.push_back(a);
	mapa["zuleica_maria"] = Pessoa{1, "zuleica_maria"};
	mapa["fernando"] = Pessoa{2, "fernando"};
	mapa["fulano"] = Pessoa{5, "fulano"};

	
	cout << "Digite o nome" << endl;
	string nome;
	cin >> nome;

	auto it = mapa.find(nome);
	if(it == mapa.end())
		cout << "nao encontrei\n";
	else
		cout << "encontrei " << it->first << " " << it->second.cpf << endl;

	cout << "cpf fulano" << mapa["fulano"].cpf << endl;

	return 0;
}