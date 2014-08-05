#include <iostream>
using namespace std;

int main(){
	int idade = 30;
	float peso = 75.6;
	char inicial = 'D';
	string sobrenome = "sena";
	
	bool esta_vivo = true;
	bool com_fome = false;
	
	int num1 = 12;
	int num2 = 7;
	
	cout << 13 / 5 << " " << 13 % 5 << endl;
	
	cout << (float)num1 / num2 << " " << (int)13.5 % 5 << endl;
	
	cout << (esta_vivo || com_fome) << endl;
	
	cout << idade << ' '
	     << peso << ' '
	     << inicial << ' '
	     << sobrenome << endl;
	return 0;
}
