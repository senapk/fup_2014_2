//#include "rules.h"
#include <vector>
#include <functional>
using namespace std;

bool naipes_iguais(vector<int> vet, int inicio, int fim){
    return true;
}
bool eh_sequencia(vector<int> vet, int inicio, int fim){
    return true;
}
bool eh_igual(vector<int> vet, int inicio, int fim){
    return true;
}
int  contar_valor(vector<int> vet, int valor){
    return true;
}


int is_seq_real(vector<int> cartas){ return 0; }
int is_seq_naipe(vector<int> cartas){ return 0; }
int is_quadra(vector<int> cartas){return 0;}
int is_trinca_par(vector<int> cartas){return 0;}
int is_flush(vector<int> cartas){return 0;}
int is_seq(vector<int> cartas){return 0;}
int is_trinca(vector<int> cartas){return 0;}
int is_dois_pares(vector<int> cartas){return 0;}
int is_par(vector<int> cartas){return 0;}
int is_carta_alta(vector<int> cartas){return 0;}

typedef function<int(vector<int>)> Funcao;

struct Regra{
    Funcao funcao;
    string nome;
};

vector<Regra> regras = {
    {is_seq_real,"seq real"},
    {is_seq_naipe,"seq naipe"},
    {is_quadra, "quadra"},
               is_trinca_par,
               is_flush,
               is_seq,
               is_trinca,
               is_dois_pares,
               is_par,
               is_carta_alta};

