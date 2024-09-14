#ifndef FADE_H
#define FADE_H

#include <SFML/Graphics.hpp>

class Fade {
public:
    Fade(sf::Sprite* sprite);

    void startFadeIn(float duration);

    void startFadeOut(float duration);

    void update();

    sf::Sprite* getSprite() const { return sprite; }

private:
    sf::Sprite* sprite;
    sf::Clock clock;
    float fadeDuration;
    sf::Uint8 alpha;
    bool fading;
    bool fadeIn;
};

#endif