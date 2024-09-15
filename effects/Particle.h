#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

struct Particle
{
    sf::Sprite sprite;
    sf::Vector2f velocity;
    float life;
    float fadeThreshold; 
    float appearDuration;

};

class Particles
{
public:
    Particles();

    void setTexture(const std::string& texturePath);
    void generateParticles(float x, float y, unsigned int count, float size, float life, float speed, float fadeThreshold, float appearDuration);
    void update(float dt);
    void draw(sf::RenderWindow& window);

private:
    std::vector<Particle> particles;
    sf::Texture texture;
};