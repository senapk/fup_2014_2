#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Animal{
    string nome;
    string especie;
};

template <class T>
T get_valor(string texto){
    while(true){
        cout << texto << endl;
        T valor;
        cin >> valor;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }else{
            return valor;
        }
    }
}

void mostrar_especies (vector<string> especies)
{
    int i = 0;
    for(auto especie : especies){
        cout << i++ << " " <<  especie << endl;
    }
}

void mostrar_animais (vector<Animal> animais)
{
    for (auto animal : animais){
        cout << animal.nome << " : " << animal.especie << endl;
    }
}

void adicionar_animais(vector<Animal>& animais, vector<string> especies){
    cout << "Escolha a especie:\n";
    mostrar_especies(especies);
    int ind = get_valor<int>("Digite o indice da especie ou -1 para sair");
    if(ind < 0 or ind > (int)especies.size())
        return;

    cout << "Digite o nome do animal :" << endl;
    string nome;
    cin.ignore(1000, '\n');
    getline(std::cin, nome);

    Animal animal;
    animal.nome = nome;
    animal.especie = especies[ind];
    animais.push_back(animal);
}

void adicionar_especie(vector<string>& especies){
    cout << "Digite o nome da especie :" << endl;
    string especie = " ";
    getline(std::cin, especie);

    for(auto esp : especies){
        if(esp == especie){
            cout << "Essa especie ja existe" << endl;
            return;
        }
    }

    especies.push_back(especie);
    cout << "Especie adicionada com sucesso" << endl;
}

//void carregar_loja(vector<Animal> & animais, vector<string> & especies){
    //especies.push_back("Prea");
    //especies.push_back("Cachorro");
    //especies.push_back("Gato");
    //especies.push_back("Periquito Australiano");
    //especies.push_back("Galo Chines");
    //animais.push_back(Animal{"Chiquinho", "Prea"});
    //animais.push_back(Animal{"Chico", "Galo Chines"});
//}

void salvar_loja(vector<Animal> & animais, vector<string> & especies){
    ofstream arq("loja.txt");
    arq << especies.size() << endl;
    for(auto esp : especies)
        arq << esp << endl;
    arq << animais.size() << endl;
    for(auto ani : animais){
        arq << ani.nome << ';' << ani.especie << ';' << endl;
    }
}

void carregar_loja(vector<Animal> & animais, vector<string> & especies){
    ifstream arq("loja.txt");
    string str;
    int qtd;
    arq >> qtd;
    getline(arq, str);
    for(int i = 0; i < qtd; i++){
        getline(arq, str);
        especies.push_back(str);
    }

    arq >> qtd;
    getline(arq, str);
    for(int i = 0; i < qtd; i++){
        string nome;
        string especie;
        getline(arq, nome, ';');
        getline(arq, especie, ';');
        getline(arq, str);
        animais.push_back(Animal{nome, especie});
    }
}



int main(){
    vector<string> especies;
    vector<Animal> animais;

    carregar_loja(animais, especies);

    string perguntas =
    "A(Adicionar Animal) B(Mostrar Animais)\n"
    "C(Adicionar Especie) D(Mostrar Especies)\n"
    "S(Sair) H(Help)\n";
    cout << perguntas;
    char opcao = ' ';
    while(opcao != 'S'){
        cout << ">>";
        cin >> opcao;
        cin.ignore(1000, '\n');
        switch(opcao){
            case 'H':
                cout << perguntas << endl;
                break;
            case 'S':
                salvar_loja(animais, especies);
                break;
            case 'D':
                mostrar_especies(especies);
                break;
            case 'B':
                mostrar_animais(animais);
                break;
            case 'C':
                adicionar_especie(especies);
                break;
            case 'A':
                adicionar_animais(animais,  especies);
        }
    }

    return 0;
}
