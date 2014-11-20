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
	map<int, Pessoa> mapa;
	Pessoa a;
	a.cpf = 1;
	a.nome = "David";

	Pessoa b = {2, "Junior"};

	//base.push_back(a);
	mapa[a.cpf] = a;
	mapa[b.cpf] = b;
	mapa[5] = Pessoa{5, "fulano"};
	//base.push_back(b);
	//base.push_back(Pessoa{5, "Fulano"});

	cout << "Digite o cpf" << endl;
	int num;
	cin >> num;

	auto it = mapa.find(num);
	if(it == mapa.end())
		cout << "nao encontrei\n";
	else
		cout << "encontrei " << it->first << " " << it->second.nome << endl;

    cout << mapa[5].nome << endl;

	return 0;
}
