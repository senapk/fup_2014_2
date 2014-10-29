// Abrir arquivo: binary: binário, in: leitura, out: escrita
// trunc: apaga tudo, app: adiciona no final

/*
   (1) istream& seekg (streampos pos);
   (2) istream& seekg (streamoff off, ios_base::seekdir way);

   Em (1), pula para posicao
   Em (2), avanca ou retrocede

   seekdir opcões
   off pode ser positivo ou negativo
   ios_base::beg   beginning of the stream
   ios_base::cur   current position in the stream
   ios_base::end   end of the stream
   */
#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

struct Aluno {
    char nome[30];
    int matricula;
    float media;
    char aprovado; // A-Aprovado, R-Reprovado
};

struct AlunoRn : public Aluno{

    static size_t size(){
        return sizeof(nome) + sizeof(matricula) + sizeof(media) + sizeof(aprovado);
    }

    void save(fstream &ofs){
        ofs.write(nome, sizeof(nome));
        ofs.write((char*)&matricula, sizeof(matricula));
        ofs.write((char*)&media, sizeof(media));
        ofs.write((char*)&aprovado, sizeof(aprovado));
    }

    void load(fstream &ifs){
        ifs.read(nome, sizeof(nome));
        ifs.read((char*)&matricula, sizeof(matricula));
        ifs.read((char*)&media, sizeof(media));
        ifs.read((char*)&aprovado, sizeof(aprovado));
    }

    void ler_teclado(){
        cout << "Nome Matricula Media" << endl;
        cin >> nome >> matricula >> media;
        if(media >= 7.0)
            aprovado = 'A';
        else
            aprovado = 'R';
    }

    string to_string(){
        stringstream ss;
        ss << " Nome: " << nome
            << " Matrícula: " << matricula
            << " Média: " << media;
        return ss.str();
    }
};



struct Registro{
    string file_name;
    fstream file;

    Registro(string path){
        file_name = path;
    }

    void add() {
        AlunoRn aluno;
        aluno.ler_teclado();

        file.open(file_name.c_str(), ios::binary | ios::out | ios::app);
        aluno.save(file);
        file.close();
    }

    int show() {
        int qtd = 0;
        AlunoRn aluno;

        file.open(file_name.c_str(), ios::binary | ios::in);
        if(file.fail()) {
            cout << "Falha para abrir arquivo" << endl;
            return 0;
        }

        while(1) {
            aluno.load(file);
            if(file.fail()) break;
            cout << qtd << " " << aluno.to_string() << endl;
            qtd++;
        }

        file.close();
        return qtd;
    }

    void change(int x) {
        AlunoRn aluno;
        aluno.ler_teclado();

        file.open(file_name.c_str(), ios::binary | ios::out); // Abrir arquivo
        file.seekp(x * aluno.size());
        aluno.save(file);
        file.close();
    }
};

void show_help(){
    cout << "H(Help), S(Show), A(Add), C(Change), R(Remove), X(eXit)" << endl;

    cout << endl
        << "\tH    mostra esse help" << endl
        << "\tS    mostra todos" << endl
        << "\tA    adiciona um novo aluno" << endl
        << "\tC n  altera o aluno indice n" << endl
        << "\tR n  apaga o aluno indice n" << endl
        << "\tX    termina o programa" << endl << endl;
}

int main () {
    cout << sizeof(Aluno) << endl;
    cout << AlunoRn::size() << endl;
    Registro registro("registro.bin");
    char op = ' ';
    show_help();
    while(op != 'X'){
        cout << ">> ";
        cin >> op;
        switch(op) {
            case 'H':
                show_help();
                break;
            case 'A':
                registro.add();
                break;
            case 'S':
                registro.show();
                break;
            case 'X':
                break;
            case 'C':
                int pos;
                cin >> pos;
                registro.change(pos);
                break;
            default :
                cout << "Comando inválido" << endl;
        }
    }

    return 0;
}
