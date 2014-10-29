#include<fstream>
#include<iostream>

using namespace std;

struct REG_ALUNO {
    char nome[30];
    int matricula;
    float media;
    char aprovado; // A-Aprovado, R-Reprovado
};

void escrever_alunos(char file_name[]) {
    fstream file;
    REG_ALUNO aluno;

    file.open(file_name, ios::binary | ios::in | ios::out | ios::trunc);
    // Abrir arquivo: binary: binário, in: leitura, out: escrita
    // trunc: apaga tudo, app: adiciona no final
    for(int i=0; i<3;i++) {
        cout << "Digite o nome do aluno: ";
        cin >> aluno.nome;
        cout << "Digite a matrícula: ";
        cin >> aluno.matricula;
        cout << "Média: ";
        cin >> aluno.media;
        if(aluno.media >= 7.0) aluno.aprovado = 'A';
        else aluno.aprovado = 'R';

        file.write((char*) &aluno, sizeof(REG_ALUNO)); // Escreve um registro no arquivo binário
    }

    file.close(); // Fecha o arquivo. NÃO ESQUECER!
}

int ler_alunos(char file_name[]) {
    fstream file;
    int qtd=0;
    REG_ALUNO aluno;

    file.open(file_name, ios::binary | ios::in | ios::out);
    if(file.fail()) {
        cout << "Falha para abrir arquivo" << endl;
        return 0;
    }
    while(1) {
        file.read((char *) &aluno, sizeof(REG_ALUNO)); // Ler um registro do arquivo binário
        if(file.fail()) break;
        qtd++;
        cout << "Nome: " << aluno.nome << " Matrícula: " << aluno.matricula << " Média: " << aluno.media << endl;
    }

    file.close();
    return qtd;
}

bool buscar_matricula(char file_name[], int x) {
    fstream file;
    REG_ALUNO aluno;

    file.open(file_name, ios::binary | ios::in); // Abrir arquivo
    while(1) {
        file.read((char*) &aluno, sizeof(REG_ALUNO));
        if(file.fail()) break;

        if(aluno.matricula == x) return true;
    }

    file.close();
    return false;
}

// Exercício
// Imprime o x-ésimo registro
void imprimir_registro(char file_name[], int x) {
    fstream file;
    REG_ALUNO aluno;
    int cont=0;

    file.open(file_name, ios::binary | ios::in); // Abrir arquivo
    file.seekg((x-1)*sizeof(REG_ALUNO), ios::beg); // Pula x-1 registros a partir do comeco do arquivo
    file.read((char*) &aluno, sizeof(REG_ALUNO));
    cout << "Nome: " << aluno.nome << " Matrícula: " << aluno.matricula << " Média: " << aluno.media << endl;

    file.close();
}

// Exercício
// Copia os registros dos alunos reprovados para outro arquivo binário
int copiar_reprovados(char file_name[]) {
    fstream file, file_reprovados;
    int qtd=0;
    REG_ALUNO aluno;

    file.open(file_name, ios::binary | ios::in | ios::out);
    file_reprovados.open("Reprovados.bin", ios::binary | ios::in | ios::out | ios::app);
    if(file.fail()) {
        cout << "Falha para abrir arquivo" << endl;
        return 0;
    }
    while(1) {
        file.read((char *) &aluno, sizeof(REG_ALUNO));
        if(file.fail()) break;
        if(aluno.aprovado == 'R') file_reprovados.write((char*) &aluno, sizeof(REG_ALUNO));
    }

    file.close();
    file_reprovados.close();
    return qtd;
}

int main () {
    char file_name[30];
    int op=0, qtd, x;
    bool existe = false;

    cout << "Digite o nome do arquivo: ";
    cin >> file_name;
    cout << "Digite a operação:" << endl;
    cout << "1- Escrever no arquivo"<< endl;
    cout << "2- Ler do arquivo"<<endl;
    cout << "3- Buscar matrícula no arquivo"<<endl;
    cin >> op;
    switch(op) {
        case 1: escrever_alunos(file_name);
                break;
        case 2: qtd = ler_alunos(file_name);
                cout << "A quantidade de registros é " << qtd << endl;
                break;
        case 3: cout << "Digite a matrícula a ser pesquisada: ";
                cin >> x;
                existe = buscar_matricula(file_name,x);
                if(existe) cout << "Existe aluno com matrícula " << x << endl;
                else cout << "NÃO Existe aluno com matrícula " << x << endl;
                break;
        default: cout << "Comando inválido" << endl;
    }

    return 0;
}
