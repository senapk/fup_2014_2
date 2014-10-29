#include <iostream>
using namespace std;

enum DiadaSemana{SEG, TER, QUA, QUI, SEX, SAB, DOM };

bool eh_final_de_semana(DiadaSemana dia){
    if(dia == SAB or dia == DOM)
        return true;
    return false;
}

int main ()
{
    cout << (eh_final_de_semana(DOM) == true);
    cout << (eh_final_de_semana(SEX) == true);
    return 0;
}
