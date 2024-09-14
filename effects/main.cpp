#include <SFML/Graphics.hpp>
#include "Fade.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fade Effect Example");

    // Load textures for the sprites
    sf::Texture texture1, texture2;
    if (!texture1.loadFromFile("1.png") || !texture2.loadFromFile("1.png")) {
        return -1; // Error loading textures
    }

    // Create sprites and their corresponding Fade objects
    sf::Sprite* sprite1 = new sf::Sprite(texture1);
    sf::Sprite* sprite2 = new sf::Sprite(texture2);
    Fade fade1(sprite1);
    Fade fade2(sprite2);

    // Set initial positions for the sprites
    sprite1->setPosition(200, 200);
    sprite2->setPosition(400, 200);
    sprite1->setColor(sf::Color(255, 255, 255, 255));
    sprite2->setColor(sf::Color(255, 255, 255, 0));

    bool fadingIn = false;
    bool fadingOut = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Trigger fade effects using keyboard input
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::N) {
                    fadingOut = true;
                }
                else if (event.key.code == sf::Keyboard::M) {
                    fadingIn = true;
                }
            }
        }

        // Update and draw both sprites with their corresponding fade effects
        window.clear();
        fade1.update();
        window.draw(*fade1.getSprite());
        fade2.update();
        window.draw(*fade2.getSprite());
        window.display();

        // Start fade in or fade out when the corresponding key is pressed
        if (fadingIn) {
            fade2.startFadeIn(1.0f);
            fadingIn = false;
        }
        if (fadingOut) {
            fade1.startFadeOut(1.0f);
            fadingOut = false;
        }
    }

    delete sprite1;
    delete sprite2;
    return 0;
}