#include "agenda.h"

Agenda::Agenda(){
    path = "agenda.txt";
    carregar(false);
    log.open("log.txt", ios::app);
    alterou = false;
}

Agenda::~Agenda(){
    if(alterou){
        cout << "Voce deseja salvar S/N" << endl;
        string opcao;
        cin >> opcao;
        if(opcao == "S")
            salvar();
    }
    log.close();
}

void Agenda::msg(string str){
    cout << str;
    log << str;
}

void Agenda::carregar(bool perguntar){
    agenda.clear();
    ifstream arq;
    if(perguntar){
        cout << "Digite o nome do arquivo : ";
        cin >> path;
    }
    arq.open(path);
    if(arq.fail()){
        msg("Arquivo " + path + " nao existe \n");
        msg("Criando arquivo " + path + "\n");
        ofstream arq(path);
        arq.close();
        return;
    }

    string nome, telefone;
    while(arq >> nome >> telefone){
        Pessoa p{nome, telefone};
        agenda.push_back(p);
    }
    arq.close();
}

void Agenda::mostrar(){
    for(int i = 0 ; i < (int) agenda.size(); i++){
        Pessoa pessoa = agenda[i];
        cout << i << " Nome: " << pessoa.nome
             << "\tTel : " << pessoa.tel
             << endl;
    }
}

void Agenda::salvar(){
    ofstream arq;
    arq.open(path);
    for(auto pessoa : agenda){
        arq << pessoa.nome << "\t"
            << pessoa.tel << "\n";
    }
    arq.close();
    alterou = false;
}

void Agenda::inserir(){
    string valor;
    while(valor != "S"){
        cout << "Digite I para inserir, S para sair " << endl;
        cin >> valor;
        if(valor == "I"){
            string nome, tel;
            cout << "Digite nome e telefone \n";
            cin >> nome >> tel;
            agenda.push_back(Pessoa{nome, tel});
            log << "inserindo " << nome << " " << tel << endl;
            alterou = true;
        }
    }
}

void Agenda::apagar(){
    int ind = 0;
    while(ind != -1){
        mostrar();
        cout << "Digite o indice para apagar ou -1 \n";
        cin >> ind;
        if(ind >=0 && ind < (int)agenda.size()){
            agenda.erase(begin(agenda) + ind);
        }
    }
}

void Agenda::menu(){
    string resp;
    while(resp != "X"){
        cout << "Digite I(Inserir), M(Mostrar), C(Carregar), "
             << "A(Apagar), S(Salvar), X(Sair) \n";
        cin >> resp;
        if(resp == "I")
            this->inserir();
        else if(resp == "M")
            this->mostrar();
        else if(resp == "C")
            carregar();
        else if(resp == "A")
            apagar();
        else if(resp == "S")
            salvar();
    }
}
