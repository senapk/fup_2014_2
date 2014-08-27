

#include <iostream>
using namespace std;

enum Valor {AS = 1, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, DEZ, VALETES, DAMAS, REIS};
enum Naipe {OUROS, ESPADAS, COPAS, PAUS};

struct Carta{
    Valor valor;
    Naipe naipe;
};

void imprime_carta(Carta carta){
    switch(carta.valor)
    {
        case AS: cout << "As "; break;
        case VALETES: cout << "Valetes "; break;
        case DAMAS: cout << "Damas "; break;
        case REIS: cout << "Reis "; break;
        default: cout << (int) carta.valor << " ";
    }
    cout << "de ";
    switch(carta.naipe)
    {
        case OUROS: cout << "Ouros"; break;
        case ESPADAS: cout << "Espadas"; break;
        case COPAS: cout << "Copas " ; break;
        case PAUS: cout << "Paus"; break;
    }
}


string nome_carta(Carta carta){
    string nome = "";
    switch(carta.valor)
    {
        case AS:
            nome = nome + "As ";
            break;
        case VALETES:
            nome += "Valetes ";
            break;
        case DAMAS: nome += "Damas "; break;
        case REIS: nome += "Reis "; break;
        default:
           nome += std::to_string(carta.valor); //C++11 apenas
           nome += " ";
    }
    nome += "de ";
    switch(carta.naipe)
    {
        case OUROS: nome += "Ouros"; break;
        case ESPADAS: nome += "Espadas"; break;
        case COPAS: nome += "Copas" ; break;
        case PAUS: nome += "Paus"; break;
    }
    return nome;
}

bool bateu(Carta um, Carta dois, Carta tres){
    if(um.valor == dois.valor && dois.valor == tres.valor)
        return true;
    if(um.naipe == dois.naipe && dois.naipe == tres.naipe)
        if((um.valor + 1 == dois.valor) && (dois.valor + 1 == tres.valor))
            return true;
    return false;
}

#include <cmath> //para usar o pow
bool bateu_sem_ordem(Carta um, Carta dois, Carta tres){
    if(um.valor == dois.valor && dois.valor == tres.valor)
        return true;
    if(um.naipe == dois.naipe && dois.naipe == tres.naipe)
    {
        unsigned long total = (pow(10, (int)um.valor) +
                               pow(10, (int)dois.valor) +
                               pow(10, (int)tres.valor)) ;
        if(total % 111 == 0)
            return true;
    }
    return false;
}

int main ()
{
    Carta carta = {TRES, COPAS}; //Criando uma carta
    imprime_carta(carta); //mandando imprimir a carta

    //testando a função que gera o nome da carta
    cout << (nome_carta(carta) == "3 de Copas");


    //construção Carta {} do c++11 apenas
    //Criando cartas apenas para passar por parametro e testar
    cout << (nome_carta(Carta{DAMAS, PAUS}) == "Damas de Paus");
    cout << (bateu(Carta{DOIS, PAUS}, Carta{TRES, OUROS}, Carta{QUATRO, ESPADAS}) == false);
    cout << (bateu(Carta{DOIS, OUROS}, Carta{TRES, OUROS}, Carta{QUATRO, OUROS}) == true);
    cout << (bateu(Carta{DOIS, OUROS}, Carta{DOIS, OUROS}, Carta{DOIS, OUROS}) == true);

    cout << (bateu(Carta{TRES, OUROS}, Carta{DOIS, OUROS}, Carta{QUATRO, OUROS}) == false);
    cout << (bateu_sem_ordem(Carta{DAMAS, OUROS}, Carta{REIS, OUROS}, Carta{VALETES, OUROS}) == true);
    return 0;
}
