#include <iostream>
using namespace std;

struct Tempo{
    int hora;
    int minuto;
    int segundo;
};

int converte_tempo(Tempo tempo){
    return tempo.hora * 3600 + tempo.minuto * 60 + tempo.segundo;
}

Tempo converte_segundos(int segundos){
    Tempo tempo = {0, 0, 0};
    tempo.hora = segundos / 3600;
    tempo.minuto = (segundos % 3600) / 60;
    tempo.segundo = (segundos % 3600) % 60;
    return tempo;
}

int main ()
{
    Tempo agora = {2, 2, 2};
    cout << (converte_tempo(agora) == 7322);

    Tempo tempo = converte_segundos(7322);
    cout << (tempo.hora == 2 && tempo.minuto == 2 && tempo.segundo ==2);

    return 0;
}
