#include <SFML/Graphics.hpp>
#include "Fade.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fade Effect Example");

    sf::Texture texture1;
    texture1.loadFromFile("1.png");

    sf::Sprite* sprite1 = new sf::Sprite(texture1);
    Fade fade1(sprite1);

    sprite1->setPosition(200, 200);
    sprite1->setColor(sf::Color(255, 255, 255, 0));


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    fade1.startFadeIn(1.0f);
                }
                else if (event.key.code == sf::Keyboard::Num2) {
                    fade1.startFadeOut(1.0f);
                }
            }
        }

        window.clear();
        fade1.update();
        window.draw(*fade1.getSprite());
        window.display();
    }

    return 0;
}