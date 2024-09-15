#include <SFML/Graphics.hpp>
#include "Particle.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Particles");

    Particles particles;
    particles.setTexture("4.png"); 

    sf::Clock clock;
    sf::Time dt;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                particles.generateParticles(200, 200, 8, 50.f, 1.0f, 10.f, 0.5f, 0.5f); //X, Y, количество , размер, длительность жизни, скорость, fadeOut, fadeIn
            }
        }

        dt = clock.restart();
        particles.update(dt.asSeconds());
        window.clear();
        particles.draw(window);
        window.display();
    }

    return 0;
}