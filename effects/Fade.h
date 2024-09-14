#ifndef FADE_H
#define FADE_H

#include <SFML/Graphics.hpp>

class Fade {
public:
    // Constructor, now accepting a pointer to the sprite to fade
    Fade(sf::Sprite* sprite);

    // Start fade in with a given duration
    void startFadeIn(float duration);

    // Start fade out with a given duration
    void startFadeOut(float duration);

    // Update the fade effect
    void update();

    // Get the sprite pointer
    sf::Sprite* getSprite() const { return sprite; }

private:
    sf::Sprite* sprite; // Pointer to the sprite to fade
    sf::Clock clock;
    float fadeDuration;
    sf::Uint8 alpha;
    bool fading;
    bool fadeIn;
};

#endif // FADE_H