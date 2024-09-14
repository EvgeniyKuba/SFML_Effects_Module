#include "Fade.h"

Fade::Fade(sf::Sprite* sprite)
    : sprite(sprite), alpha(0), fading(false), fadeIn(false) {}

void Fade::startFadeIn(float duration) {
    fadeIn = true;
    fading = true;
    fadeDuration = duration;
    alpha = 0;
    clock.restart();
}

void Fade::startFadeOut(float duration) {
    fadeIn = false;
    fading = true;
    fadeDuration = duration;
    alpha = 255;
    clock.restart();
}

void Fade::update() {
    if (fading && sprite) {
        float elapsed = clock.getElapsedTime().asSeconds();
        float progress = elapsed / fadeDuration;

        if (fadeIn) {
            alpha = static_cast<sf::Uint8>(255 * progress);
            if (progress >= 1.0f) {
                alpha = 255;
                fading = false;
            }
        }
        else {
            alpha = static_cast<sf::Uint8>(255 * (1 - progress));
            if (progress >= 1.0f) {
                alpha = 0;
                fading = false;
            }
        }

        // Apply the alpha channel to the sprite
        sprite->setColor(sf::Color(255, 255, 255, alpha));
    }
}