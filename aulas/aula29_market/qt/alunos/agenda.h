#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Pessoa{
    string nome;
    string tel;
};

struct Agenda{
    vector<Pessoa> agenda;
    string path;
    ofstream log;
    bool alterou;

    Agenda();

    ~Agenda();

    void msg(string str);

    void carregar(bool perguntar = true);

    void mostrar();

    void salvar();

    void inserir();

    void apagar();

    void menu();
};


#endif // AGENDA_H
