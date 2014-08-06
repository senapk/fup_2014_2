#ifndef COMANDO_H
#define COMANDO_H

#include "constantes.h"
#include "componentemovel.h"
#include "interface.h"

#define REPITA(vezes) for(int i = 0; i < vezes; i++)
#define ENQUANTO(condicao) while(condicao)
#define SE(condicao) if(condicao)
#define SENAOSE(condicao) else if(condicao)
#define SENAO else

void andar() {
    ComponenteMovel* per = Interface::getPersonagem();
    per->setEstado(ANDANDO);

    for(int i = 0; i < TAM_BLOCO/TAM_PASSO; i++) {
        Interface::mostrarComponentes();
        sleep(milliseconds(Interface::SLEEP_MOV));
        per->andar(TAM_PASSO);
    }
    per->setEstado(PARADO);

    showL("ANDANDO", BLUE);

    Interface::tratarColisao();
}

void virar(Rotacao r) {
    ComponenteMovel* per = Interface::getPersonagem();

    Direcao d = per->getDirecao();
    if(r == DIREITA) {
        d = d == NORTE? LESTE: d == LESTE? SUL: d == SUL? OESTE: NORTE;
    } else if(r == ESQUERDA) {
        d = d == NORTE? OESTE: d == OESTE? SUL: d == SUL? LESTE: NORTE;
    }

    per->setDirecao(d);

    Interface::mostrarComponentes();
    sleep(milliseconds(Interface::SLEEP_MOV*3));

    showL("GIRANDO", YELLOW);
}

Objeto olhar(Rotacao lado) {
    ComponenteMovel* per = Interface::getPersonagem();
    vector<Componente*> componentes = Interface::getComponentes();

    ComponenteMovel* p2;
    p2 = per->getVizinho(lado);

    per->setEstado(OLHANDO);
    per->setLadoOlhando(lado);
    per->setFrameOlhando(0);

    for(int i = 0; i < 5; i++) {
        Interface::mostrarComponentes();
        sleep(milliseconds(Interface::SLEEP_MOV));
    }

    showL("OLHANDO", GREEN);
    per->setEstado(PARADO);

    for(int i = 0; i < (int)componentes.size(); i++)
        if(p2->colide(componentes[i]) && componentes[i]->getTipo() != CAMINHO)
            return componentes[i]->getTipo();

    return CAMINHO;
}

#endif // COMANDO_H
