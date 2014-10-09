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
    sf::RenderWindow win(sf::VideoMode(820, 620), "Bola");
    sf::CircleShape circulo;
    float latE = 10;
    float latD = 810;
    sf::RectangleShape chao(Vector2f(800, 600));
    chao.setPosition(10, 10);
    circulo.setFillColor(Color(0,0,0));

    Bola bola;
    circulo.setRadius(bola.raio);
    bola.vx = 1;
    bola.x = 20;
    bola.y = 20;
    const float y_chao = 600;

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
        if(sf::Keyboard::isKeyPressed(Keyboard::Key::Right)){
            bola.acelerar(1, 0);
        }
        if(sf::Keyboard::isKeyPressed(Keyboard::Key::Left)){
            bola.acelerar(-1, 0);
        }

        bola.colidir_chao(y_chao);
        bola.colidir_laterais(latE, latD);
        bola.acelerar(0, 1);
        bola.update();
        circulo.setPosition(bola.x, bola.y);
        win.clear();
        win.draw(chao);
        win.draw(circulo);
        win.display();
    }
    return 0;
}
