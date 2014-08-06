#include "escritor.h"

Escritor::Escritor() {
    fonte.loadFromFile(FONTE);
    texto.setFont(fonte);

    s = "Helo word";
    cor = Color::Black;
    tamanho = 50;
    x = y = 0;
}

void Escritor::setPosicao(int x, int y) {
    this->x = x;
    this->y = y;
}

void Escritor::setTamanho(int tamanho) {
    this->tamanho = tamanho;
}

void Escritor::setCor(Color cor) {
    this->cor = cor;
}

void Escritor::Reset() {
    texto.setColor(cor);
    texto.setCharacterSize(tamanho);
    texto.setPosition(x, y);
    texto.setString(s);
}

void Escritor::escrever(string s) {
    texto.setCharacterSize(tamanho);
    texto.setString(s);
    FloatRect rect = texto.getGlobalBounds();

    x = Interface::getJanela()->getSize().x/2 - rect.width/2;
    y = Interface::getJanela()->getSize().y/2 - rect.height/2;

    escrever(s, x, y, cor);
}

void Escritor::escrever(string s, Color cor) {
    this->cor = cor;
    escrever(s);
}

void Escritor::escrever(string s, int x, int y) {
    escrever(s, x, y, cor);
}

void Escritor::escrever(string s, int x, int y, Color cor) {
    this->x = x;
    this->y = y;
    this->cor = cor;
    this->s = s;

    Reset();

    Interface::getJanela()->draw(texto);
}

void Escritor::escreverAnimacao(string s) {
    float tamAux = tamanho;
    tamanho = 1;

    float vel = 10;

    for(int i = 0; i < 80; i++) {

        tamanho += vel;

        if(tamanho > tamAux + vel && vel > 0) {
            vel -= 2;
            vel = -vel;
        } else if(tamanho < tamAux - vel && vel < 0) {
            vel += 2;
            vel = -vel;
        }

        Interface::mostrarComponentesSemDisplay();

        escrever(s);

        Interface::getJanela()->display();
        sleep(milliseconds(SLEEP_MOVIMENTO));
    }
}
