#include "Particle.h"
#include <cstdlib>
#include <ctime>
#include <cmath>


Particles::Particles()
{
    srand(time(nullptr));
}

void Particles::setTexture(const std::string& texturePath)
{
    if (!texture.loadFromFile(texturePath))
    {

    }
}

void Particles::generateParticles(float x, float y, unsigned int count, float size, float life, float speed, float fadeThreshold, float appearDuration)
{

    const float angles[] = { 0.f, 0.785398f, 1.570796f, 2.356194f,
                          3.141592f, 3.926989f, 4.712387f, 5.497785f};

    for (unsigned int i = 0; i < count; ++i)
    {
        Particle particle;
        particle.sprite.setTexture(texture);
        particle.sprite.setOrigin(size / 2.f, size / 2.f);
        particle.sprite.setPosition(x, y);
        particle.sprite.setScale(size / (float)texture.getSize().x, size / (float)texture.getSize().y);
        particle.appearDuration = appearDuration; 

        unsigned int index = i % 8; 
        float angle = angles[index];
        particle.velocity.x = cos(angle) * speed;
        particle.velocity.y = sin(angle) * speed;
        particle.life = life;
        particle.fadeThreshold = fadeThreshold; 

        particles.push_back(particle);
    }
}

void Particles::update(float dt)
{
    for (auto it = particles.begin(); it != particles.end();)
    {
        it->life -= dt;

        if (it->life > it->fadeThreshold)
        {
            it->sprite.move(it->velocity.x * dt, it->velocity.y * dt);

            if (it->life <= it->appearDuration)
            {
                float alpha = (it->life / it->appearDuration) * 255.f;
                it->sprite.setColor(sf::Color(it->sprite.getColor().r, it->sprite.getColor().g, it->sprite.getColor().b, (unsigned char)alpha));
            }
        }
        else
        {
            it->sprite.move(it->velocity.x * dt * (it->life / it->fadeThreshold) * 0.5f, it->velocity.y * dt * (it->life / it->fadeThreshold) * 0.5f);
            it->sprite.setColor(sf::Color(it->sprite.getColor().r, it->sprite.getColor().g, it->sprite.getColor().b, (unsigned char)(it->life / it->fadeThreshold * 255.f)));
        }

        if (it->life <= 0.f)
        {
            it = particles.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Particles::draw(sf::RenderWindow& window)
{
    for (const auto& particle : particles)
    {
        window.draw(particle.sprite);
    }
}