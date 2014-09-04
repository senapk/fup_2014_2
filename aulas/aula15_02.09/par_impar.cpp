#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum Opcao {PAR, IMPAR};

bool jogador_um_ganhou(Opcao opcao, int valor1, int valor2){
    int total = valor1 + valor2;
    if((opcao == PAR) and (total % 2 == 0))
        return true;
    if((opcao == IMPAR) and (total % 2 != 0))
        return true;
    return false;
}

int pegar_numero_valido(string texto, int minimo, int maximo){
    int escolha = 0;
    while(true){
        cout << texto << endl;
        cin >> escolha;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if(escolha >= minimo and escolha <= maximo)
            break;
    }
    return escolha;
}

void jogar_outra_rodada(int& vitorias, int& derrotas, bool& acabou){
    int escolha;
    int valor;
    int pc;

    cout << "vitorias " << vitorias << " derrotas " << derrotas << "!\n";

    escolha = pegar_numero_valido("Escolha Par:0, Impar:1, Sair:2", 0, 2);

    if (escolha == 2){
        acabou = true;
        return;
    }
    valor = pegar_numero_valido("Escolha o valor entre 0 e 9", 0, 9);

    pc = rand() % 10;
    cout << "O Pc escolheu o valor " << pc << endl;

    if(jogador_um_ganhou((Opcao)escolha, valor, pc)){
        vitorias++;
    }else{
        derrotas++;
    }
}

int main ()
{
    int vitorias = 0;
    int derrotas = 0;
    bool acabou = false;


    srand(time(NULL));

    while(!acabou){
        jogar_outra_rodada(vitorias, derrotas, acabou);
    }

    return 0;
}
