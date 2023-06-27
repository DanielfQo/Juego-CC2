#include "Imagen.h"

Imagen::Imagen() {
    vel = {4,4};
    background.loadFromFile("background.png");
    spritebackground.setTexture(background);
	txt.loadFromFile("floppa.png");
	spr.setTexture(txt);
    spr.setOrigin(spr.getGlobalBounds().width/2, spr.getGlobalBounds().height);
}

void Imagen::update() {
    vel = { 0,0 };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        vel.y = -4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        vel.x = -4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        vel.y = 4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        vel.x = 4;
    }

    spr.move(vel);
    if (vel.x < 0) {
        spr.setScale(-1, 1);
    }
    else if (vel.x > 0) {
        spr.setScale(1, 1);
    }

    if (spr.getGlobalBounds().left < 0) {
        spr.setPosition(spr.getOrigin().x, spr.getPosition().y);
    }
    if (spr.getGlobalBounds().top < 0) {
        spr.setPosition(spr.getPosition().x, spr.getOrigin().y);
    }
    if (spr.getGlobalBounds().left + spr.getGlobalBounds().width > 800) {
        spr.setPosition(800 - (spr.getGlobalBounds().width - spr.getOrigin().x), spr.getPosition().y);
    }
    if (spr.getGlobalBounds().top + spr.getGlobalBounds().height > 600) {
        spr.setPosition(spr.getPosition().x, 600 + (spr.getGlobalBounds().height - spr.getOrigin().y));
    }
}

void Imagen::draw(RenderTarget& target, RenderStates states) const{
    target.draw(spritebackground, states);
    target.draw(spr, states);
}
