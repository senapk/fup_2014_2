#include "carta.h"

string to_string(Carta carta){
    int valor = carta.valor;
    Naipe naipe = carta.naipe;
    string svalor = "";
    switch(valor){
    case(14): svalor = " A"; break;
    case( 1): svalor = " A"; break;
    case(11): svalor = " J"; break;
    case(12): svalor = " Q"; break;
    case(13): svalor = " K"; break;
    case(10): svalor = "10"; break;
    default:
        svalor =  " " + std::to_string(valor);
    }

    string snaipe;
    switch(naipe){
    case COPAS : snaipe = "\xe2\x99\xa5" ;
    case OUROS : snaipe = "\xe2\x99\xa6" ;
    case PAUS : snaipe = "\xe2\x99\xa3" ;
    case ESPADAS : snaipe = "\xe2\x99\xa0" ;
    }

    return (svalor + snaipe);
}
