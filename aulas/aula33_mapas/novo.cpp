#include <iostream>
#include <vector>
#include <algorithm> //find
using namespace std;

struct Pessoa{
	int cpf;
	string nome;
};

int main(){
	vector<Pessoa> base;
	Pessoa a;
	a.cpf = 1;
	a.nome = "David";
	
	Pessoa b = {2, "Junior"};
	
	base.push_back(a);
	base.push_back(b);
	base.push_back(Pessoa{5, "Fulano"});
	
	cout << "Digite o cpf" << endl;
	int num;
	cin >> num;

	auto it = find_if(base.begin(), base.end(), [&](Pessoa pessoa)->bool{
		return (pessoa.cpf == num);
	});
	
	if(it != base.end())
		cout << "Encontrei " << it->nome << endl;


	return 0;
}