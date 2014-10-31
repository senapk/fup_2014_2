#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string.h>
using namespace std;

struct Aluno {
    string nome;
    int matricula;
    float media;
    char aprovado; // A-Aprovado, R-Reprovado
    bool existe;

    static const int nome_size = 20;

    Aluno(){
        nome = "null";
        matricula = 0;
        media = 0.0;
        aprovado = 'R';
        existe = true;
    }

    //formata a string pra ela ter exatos size chars
    //se for maior, corta
    //se for menor, completa
    string format(string str, int size){
        if((int) str.size() > size)
            return str.substr(0, size);
        stringstream ss;
        ss << setw(size) << str;
        return ss.str();
    }

    string get_string(){
        stringstream ss;
        ss << format(nome, nome_size) << setw(10) << matricula << setw(10) << media
            << setw(2) << aprovado << setw(2) << existe << '\n';
        return ss.str();
    }

    size_t size(){
        return this->get_string().size();
    }

    bool write(fstream &ofs){
        string str = get_string();
        ofs << str.c_str();
        return ofs.good();
    }

    bool read(fstream &ifs){
        int size = get_string().size();
        char *linha = new char[size];
        ifs.read(linha, size);
        stringstream(linha) >> nome >> matricula >> media >> aprovado >> existe;
        return ifs.good();
    }

    static Aluno ler_do_teclado(){
        Aluno aluno;
        while(true){
            cout << "Nome Matricula Media" << endl;
            cin >> aluno.nome >> aluno.matricula >> aluno.media;

            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
            }else{
                break;
            }
        }
        if(aluno.media >= 7.0)
            aluno.aprovado = 'A';
        else
            aluno.aprovado = 'R';
        return aluno;
    }

    void show(int ind = -1){
        if(ind != -1)
            cout << ind << " ";
        cout << "Nome: " << setw(nome_size) <<  nome
            << " Mat: " << matricula
            << " Media: " << media
            << " Situacao: " << aprovado << endl;
    }
};

struct Registro{
    string path;

    Registro(string path){
        this->path = path;
    }

    //adiciona um registro
    void add() {
        Aluno aluno =  Aluno::ler_do_teclado();
        fstream file(path.c_str(), ios::out | ios::in | ios::app);
        aluno.write(file);
    }

    //mostra os registros validos
    void show() {
        fstream file(path.c_str(), ios::in);
        if(file.fail() || this->qtd() == 0)
            return;
        Aluno aluno;
        int ind = 0;
        while(aluno.read(file)) {
            if(aluno.existe)
                aluno.show(ind);
            ind++;
        }
    }

    //mostra um registro pelo indice
    void show(int ind) {
        Aluno aluno;
        if(ind < 0 or ind >= qtd())
            return;
        fstream file(path.c_str(), ios::in);
        file.seekg(ind * aluno.size());
        aluno.read(file);
        aluno.show(ind);
    }

    //informa quantos registro existem, contando válidos e invalidos
    int qtd(){
        fstream file(path.c_str(), ios::in);
        if(file.fail())
            return 0;
        file.seekg(0, ios::end);
        int pos = file.tellg();
        Aluno alu;
        return pos/alu.size();
    }

    //altera um registro
    void change(int ind) {
        Aluno aluno = Aluno::ler_do_teclado();
        fstream file(path.c_str(),  ios::in | ios::out);
        if(ind >= 0 && ind < qtd()){
            file.seekp(ind * aluno.size());
            aluno.write(file);
        }
    }

    //remove um registro setando existe pra falso
    void remove(int ind) {
        fstream file(path.c_str(), ios::in | ios::out);
        Aluno aluno;
        if(ind >= 0 && ind < qtd()){
            file.seekg(ind * aluno.size());
            aluno.read(file);
            aluno.existe = false;
            file.seekp(-aluno.size(), ios::cur);
            aluno.write(file);
        }
    }

    //apaga o arquivo todo
    void del() {
        fstream file(path.c_str(), ios::out | ios::trunc);
    }

    void show_help(){
        cout << endl
            << "\tH   -  Help   - mostra esse help" << endl
            << "\tS   -  Show   - mostra todos" << endl
            << "\tA   -  Add    - adiciona um novo aluno" << endl
            << "\tD   -  Del    - deleta a lista toda" << endl
            << "\tQ   -  Qtd    - informa quantidade" << endl
            << "\tO n -  One    - mostra o aluno indice n" << endl
            << "\tC n -  Change - altera o aluno indice n" << endl
            << "\tR n -  Remove - apaga o aluno indice n" << endl
            << "\tX   -  eXit   - termina o programa" << endl << endl;
    }

    int getInt(){
        int pos;
        while(true){
            cin >> pos;
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Digite um numero" << endl;
            }else{
                break;
            }
        }
        return pos;
    }

    void menu(){
        char op = ' ';
        show_help();
        while(op != 'X'){
            string nome;
            cout << ">> ";
            cin >> op;
            switch(op) {
                case 'H': show_help(); break;
                case 'D': del(); break;
                case 'A': add(); break;
                case 'S': show(); break;
                case 'Q': cout << qtd() << endl; break;
                case 'C': change(getInt()); break;
                case 'O': show(getInt()); break;
                case 'R': remove(getInt()); break;
                case 'X': break;
                default :
                          cout << "Comando inválido" << endl;
            }
        }
    }
};


int main () {
    Registro registro("registro.txt");

    registro.menu();
    return 0;
}
