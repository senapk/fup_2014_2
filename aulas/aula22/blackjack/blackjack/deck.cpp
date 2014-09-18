//IMPLEMENTACOES
#include "deck.h"

vector<Carta> get_baralho() {
    vector<Carta> baralho;
    Carta carta;
    for(int i=0;i<4;i++){
        carta.naipe = (Naipe) i;
        for(int j=1;j<14;j++) {
            carta.valor = j;
            baralho.push_back(carta);
        }
    }
    return baralho;
}


string to_string(vector<Carta> cartas, int quebra){
    stringstream saida;
    if (quebra < 2 )
        quebra = 10;
    saida << "[";
    for(int i = 0; i < (int) cartas.size() - 1; i++){
        if(i != 0 and i % quebra == 0)
            saida << endl << " ";
        saida << to_string(cartas[i]) << ",";
    }
    saida << to_string(cartas.back()) << " ]" << endl;
    return saida.str();
}

void ordenar_valor(vector<Carta> & cartas){
    sort(begin(cartas), end(cartas), [](Carta c1, Carta c2){
        return c1.valor < c2.valor;
    });
}
void ordenar_naipe(vector<Carta> & cartas){
    sort(begin(cartas), end(cartas), [](Carta c1, Carta c2){
        if(c1.naipe == c2.naipe)
            return (c1.valor < c2.valor);
        return c1.naipe < c2.naipe;
    });
}

void embaralhar(vector<Carta> & cartas){
    static int init = 0;
    if(init == 0){
        init = 1;
        srand(time(NULL));
    }
    random_shuffle(begin(cartas), end(cartas));
}

//Se cartas vazio, retorna carta invalida
Carta puxar_carta(vector<Carta> & cartas){
    if(cartas.size() == 0)
        return Carta{0,(Naipe)0};

    Carta carta;
    carta = cartas.back();
    cartas.pop_back();
    return carta;
}
