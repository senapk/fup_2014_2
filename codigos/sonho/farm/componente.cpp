#include "componente.h"

Componente::Componente(int x = 0, int y = 0, int l = 0, int h = 0, Objeto tipo = OBSTACULO) {
    this->x = x;
    this->y = y;
    this->tipo = tipo;
    altura = h;
    largura = l;
    frame = 0;
    variacaoDeTipo = 0;
}

void Componente::carregarSprite() {
    sprite.setTexture(*ImageManager::getTexture(tipo, frame, variacaoDeTipo));
}

void Componente::paint(RenderWindow* j) {

    Texture* t = ImageManager::getTexture(tipo, frame, variacaoDeTipo);
    t->setSmooth(true);

    sprite.setTexture(*t);
    setSize(largura, altura);

    ++frame %= ImageManager::getAnimacaoSize(tipo, variacaoDeTipo);
    sprite.setPosition(x, y);
    j->draw(sprite);

}

int Componente::getX() {
    return x;
}

int Componente::getY() {
    return y;
}

void Componente::setX(int x) {
    this->x = x;
}

void Componente::setY(int y) {
    this->y = y;
}

void Componente::setPosicao(int x, int y) {
    setX(x); setY(y);
}

Objeto Componente::getTipo() {
    return tipo;
}

Sprite* Componente::getSprite() {
    return &sprite;
}

bool Componente::colide(Componente* c) {
    return x == c->getX() && y == c->getY();
}

void Componente::setSize(int largura, int altura) {
    sprite.setScale((float)largura/sprite.getTexture()->getSize().x,\
                    (float)altura /sprite.getTexture()->getSize().y);
}

void Componente::setVariacao(int variacao) {
    //cout << variacao << endl;
    this->variacaoDeTipo = variacao;
}
