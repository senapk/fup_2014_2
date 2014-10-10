#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

enum Direcao{Up, Down, Right, Left};

struct Cabeca{
    int x;
    int y;
    Direcao direcao;

    void andar(){
        if(direcao == Up)
            y -= 1;
        if(direcao == Down)
            y += 1;
        if(direcao == Right)
            x += 1;
        if(direcao == Left)
            x -= 1;
    }
};

int main(){
    const int largura = 800;
    const int altura = 600;
    const int LADO = 20;
    Cabeca cabeca{10, 10, Right};

    RenderWindow win(sf::VideoMode(largura, altura), "Cobra");
    win.setFramerateLimit(60);

    sf::RectangleShape quadrado(Vector2f(LADO, LADO));
    quadrado.setFillColor(Color::Cyan);
    quadrado.setOutlineColor(Color::White);
    quadrado.setOutlineThickness(1.5);

    sf::Clock clock;
    sf::Time tempoAtualizacao = sf::seconds(0.2); //10 milesegundos

    while(win.isOpen()){
        sf::Event event;
        while(win.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                win.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Up)
                    cabeca.direcao = Up;
                if(event.key.code == sf::Keyboard::Down)
                    cabeca.direcao = Down;
                if(event.key.code == sf::Keyboard::Left)
                    cabeca.direcao = Left;
                if(event.key.code == sf::Keyboard::Right)
                    cabeca.direcao = Right;
            }
        }
        if(clock.getElapsedTime() > tempoAtualizacao){
            cabeca.andar();
            clock.restart();
        }

        win.clear();
        quadrado.setPosition(cabeca.x * LADO, cabeca.y * LADO);
        win.draw(quadrado);
        win.display();
    }


}


