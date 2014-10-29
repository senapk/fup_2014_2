#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

using namespace std;
using namespace sf;

enum Direcao{Up, Down, Right, Left};

struct Cabeca{
    vector<Vector2i> gomos;
    Direcao direcao;

    Vector2i getNext(){
        Vector2i inc;
        if(direcao == Up)
            inc = Vector2i(+0, -1);
        if(direcao == Down)
            inc = Vector2i(+0, +1);
        if(direcao == Right)
            inc = Vector2i(+1, +0);
        if(direcao == Left)
            inc = Vector2i(-1, +0);
        return gomos[0] + inc;
    }

    void walk(){
        int tam = gomos.size();
        for(int i = tam - 1; i >= 1; i--){
            gomos[i] = gomos[i - 1];
        }
        gomos.front() = getNext();
    }
    void grow(){
        Vector2i ultimo = gomos.back();
        gomos.push_back(ultimo);
    }
};

int main(){
    const int largura = 800;
    const int altura = 600;
    const int LADO = 40;
    vector<Vector2i> corpo {{10, 10}};
    Cabeca cobra{corpo, Right};

    RenderWindow win(sf::VideoMode(largura, altura), "Cobra");
    win.setFramerateLimit(60);

    sf::RectangleShape quadrado(Vector2f(LADO - 4 , LADO - 4));
    quadrado.setFillColor(Color::Blue);
    quadrado.setOutlineColor(Color::White);
    quadrado.setOutlineThickness(1);

    sf::Texture cobraImagem;
    if(!cobraImagem.loadFromFile("../imagens/couro.jpg"))
        return EXIT_FAILURE;
    sf::Sprite cobraSprite(cobraImagem);
    //cobraSprite.setOrigin(cobraSprite.getGlobalBounds().width/2,
    //                      cobraSprite.getGlobalBounds().height/2);
    {
        float tam = LADO - 4;
        float largura = cobraSprite.getGlobalBounds().width;
        float altura = cobraSprite.getGlobalBounds().height;
        cobraSprite.setScale(tam / largura, tam / altura);
    }

    sf::Clock clock_walk;
    sf::Time tempoAtualizacao = sf::seconds(0.2); //

    while(win.isOpen()){
        sf::Event event;
        while(win.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                win.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Up)
                    if(cobra.direcao != Down)
                        cobra.direcao = Up;
                if(event.key.code == sf::Keyboard::Down)
                    if(cobra.direcao != Up)
                        cobra.direcao = Down;
                if(event.key.code == sf::Keyboard::Left)
                    if(cobra.direcao != Right)
                        cobra.direcao = Left;
                if(event.key.code == sf::Keyboard::Right)
                    if(cobra.direcao != Left)
                        cobra.direcao = Right;
                if(event.key.code == sf::Keyboard::G)
                    cobra.grow();
            }
        }
        if(clock_walk.getElapsedTime() > tempoAtualizacao){
            cobra.walk();
            clock_walk.restart();
        }

        win.clear();
        //win.draw(cobraSprite);

        for(auto gomo : cobra.gomos){
            //quadrado.setPosition(gomo.x * LADO + 2, gomo.y * LADO + 2);
            cobraSprite.setPosition(gomo.x * LADO + 2, gomo.y * LADO + 2);
            win.draw(cobraSprite);
        }

        win.display();
    }


}


