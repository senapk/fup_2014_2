#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

struct Bola{

    float x{0};
    float y{0};
    float vx{0};
    float vy{0};
    float raio{20};

    void print(){
        int casas = 5;
        cout << "x:" << setw(casas) << x << " y:" << setw(casas) << y << " ";
        cout << "vx:" << setw(casas) << vx << " vy:" << setw(casas) << vy << " ";
        cout << "r: " << setw(casas) << raio << endl;
    }

    void update(){
        x += vx;
        y += vy;
    }

    void acelerar(float ax, float ay){
        vx += ax;
        vy += ay;
    }

    void colidir_chao(float y_chao){
        if (y + 2 * raio >= y_chao){
            vy = -vy;
            y = y_chao - 2 * raio;
        }
    }
    void colidir_laterais(float latE, float latD){
        if(x < latE){
            x = latE;
            vx = -vx;
        }
        if(x + 2 * raio > latD){
            x = latD - 2 * raio;
            vx = -vx;
        }
    }
};

int main(){
    int largura = 800;
    int altura = 600;

    sf::RenderWindow win(sf::VideoMode(largura, altura), "Bola");
    win.setFramerateLimit(100);
    sf::CircleShape circulo;

    int borda = 10;
    sf::RectangleShape quadrado(Vector2f(largura - 2 * borda, altura - 2 * borda));
    quadrado.setPosition(borda, borda);
    circulo.setFillColor(Color(0,0,0));

    Bola bola;
    circulo.setRadius(bola.raio);
    bola.vx = 1;
    bola.x = 20;
    bola.y = 20;

    while(win.isOpen()){
        sf::Event event;
        while(win.pollEvent(event)){
            if(event.type == Event::Closed){
                win.close();
            }
            if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Key::Space){
                    circulo.setFillColor(Color(rand()%255,
                                               rand()%255,
                                               rand()%255));
                }
            }
        }
        float motor = 0.9;
        float gravidade = 1.0;
        if(sf::Keyboard::isKeyPressed(Keyboard::Key::Right)){
            bola.acelerar(motor, 0);
        }
        if(sf::Keyboard::isKeyPressed(Keyboard::Key::Left)){
            bola.acelerar(-motor, 0);
        }
        if(sf::Keyboard::isKeyPressed(Keyboard::Key::Up)){
            bola.acelerar(0, -motor);
        }
        if(sf::Keyboard::isKeyPressed(Keyboard::Key::Down)){
            bola.acelerar(0, motor);
        }

        bola.colidir_chao(altura - borda);
        bola.colidir_laterais(borda, largura);
        bola.acelerar(0, gravidade);
        bola.update();


        win.clear();
        win.draw(quadrado);
        circulo.setPosition(bola.x, bola.y);
        win.draw(circulo);
        win.display();
    }
    return 0;
}
