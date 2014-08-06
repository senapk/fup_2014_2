#ifndef PERSONAGEMFACTORY_H
#define PERSONAGEMFACTORY_H

#include "constantes.h"
#include "componente.h"
#include "componentemovel.h"

class PersonagemFactory {
public:
    PersonagemFactory();
    ComponenteMovel* criarPersonagem(int x, int y);
    Componente* criar(Objeto objeto, int variacao, int x, int y);
};

#endif // PERSONAGEMFACTORY_H
