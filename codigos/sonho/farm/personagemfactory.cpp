#include "personagemfactory.h"

PersonagemFactory::PersonagemFactory() {
}

ComponenteMovel* PersonagemFactory::criarPersonagem(int x, int y) {
    ComponenteMovel* cm;
    cm = new ComponenteMovel(x, y, TAM_BLOCO, TAM_BLOCO, PERSONAGEM);
    return cm;
}

Componente* PersonagemFactory::criar(Objeto objeto, int variacao, int x, int y) {
    Componente* co;
    co = new Componente(x, y, TAM_BLOCO, TAM_BLOCO, objeto);
    co->setVariacao(variacao);
    return co;
}
