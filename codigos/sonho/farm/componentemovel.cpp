#include "componentemovel.h"

ComponenteMovel::ComponenteMovel(int x, int y, int largura, int altura, Objeto tipo) : Componente(x, y, largura, altura, tipo){
    xAnt = x;
    yAnt = y;
    estado = PARADO;
    direcao = SUL;
    frameOlhar = 0;
}

void ComponenteMovel::carregarSprite() {
    sprite.setTexture(*ImageManager::getTexture(tipo, 0, SUL));
}

void ComponenteMovel::paint(RenderWindow *j) {
    Texture* t = ImageManager::getTexture(frame, direcao);
    t->setSmooth(true);
    sprite.setTexture(*t);
    setSize(largura, altura);

    if(estado == ANDANDO)
        ++frame %= ImageManager::getAnimacaoSize() - 1;
    else
        frame = ImageManager::getAnimacaoSize() - 1;
    sprite.setPosition(x, y);
    j->draw(sprite);

    if(estado == OLHANDO)
        paintOlhar(j);
}

void ComponenteMovel::paintOlhar(RenderWindow *j) {
    ComponenteMovel* c = getVizinho(ladoOlhando);
    Texture* t = ImageManager::getTextureOlhar(frameOlhar, c->getDirecao());
    t->setSmooth(true);

    Sprite *sprite = c->getSprite();

    sprite->setTexture(*t);
    c->setSize(largura, altura);

    ++frameOlhar
            %= ImageManager::getAnimacaoSizeOlhar() - 1;

    sprite->setPosition(c->getX(), c->getY());
    j->draw(*sprite);

}

ComponenteMovel* ComponenteMovel::getVizinho(Rotacao lado) {

    ComponenteMovel* p2 = new ComponenteMovel(getX(), getY(), TAM_BLOCO, TAM_BLOCO, OBSTACULO);

    switch(lado) {
    case DIREITA:
        if(getDirecao() == NORTE) {
            p2->setX(getX() + TAM_BLOCO);
            p2->setDirecao(LESTE);
        }
        if(getDirecao() == SUL) {
            p2->setX(getX() - TAM_BLOCO);
            p2->setDirecao(OESTE);
        }
        if(getDirecao() == LESTE) {
            p2->setY(getY() + TAM_BLOCO);
            p2->setDirecao(SUL);
        }
        if(getDirecao() == OESTE) {
            p2->setY(getY() - TAM_BLOCO);
            p2->setDirecao(NORTE);
        }
        break;
    case ESQUERDA:
        if(getDirecao() == NORTE) {
            p2->setX(getX() - TAM_BLOCO);
            p2->setDirecao(OESTE);
        }
        if(getDirecao() == SUL) {
            p2->setX(getX() + TAM_BLOCO);
            p2->setDirecao(LESTE);
        }
        if(getDirecao() == LESTE) {
            p2->setY(getY() - TAM_BLOCO);
            p2->setDirecao(NORTE);
        }
        if(getDirecao() == OESTE) {
            p2->setY(getY() + TAM_BLOCO);
            p2->setDirecao(SUL);
        }
        break;
    case FRENTE:
        if(getDirecao() == NORTE) {
            p2->setY(getY() - TAM_BLOCO);
            p2->setDirecao(NORTE);
        }
        if(getDirecao() == SUL) {
            p2->setY(getY() + TAM_BLOCO);
            p2->setDirecao(SUL);
        }
        if(getDirecao() == LESTE) {
            p2->setX(getX() + TAM_BLOCO);
            p2->setDirecao(LESTE);
        }
        if(getDirecao() == OESTE) {
            p2->setX(getX() - TAM_BLOCO);
            p2->setDirecao(OESTE);
        }
        break;
    }

    return p2;
}

void ComponenteMovel::andar(int distancia) {
    int xp = xAnt = getX();
    int yp = yAnt = getY();
    switch(direcao) {
        case NORTE:
            yp -= distancia;
            break;
        case SUL:
            yp += distancia;
            break;
        case LESTE:
            xp += distancia;
            break;
        case OESTE:
            xp -= distancia;
            break;
    }
    setPosicao(xp, yp);
}

void ComponenteMovel::setEstado(Estado e) {
    estado = e;
}

void ComponenteMovel::setDirecao(Direcao d) {
    direcao = d;
}

void ComponenteMovel::setLadoOlhando(Rotacao lado) {
    ladoOlhando = lado;
}

void ComponenteMovel::setFrameOlhando(int frame) {
    frameOlhar = frame;
}

Direcao ComponenteMovel::getDirecao() {
    return direcao;
}

Rotacao ComponenteMovel::getLadoOlhando() {
    return ladoOlhando;
}
