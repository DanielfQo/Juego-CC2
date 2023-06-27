#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Imagen : public sf::Drawable{
	sf::Sprite spr;
	sf::Texture txt;
	sf::Vector2f vel;
	sf::Texture background;
	sf::Sprite spritebackground;
public:
	Imagen();
	void update();
	void draw(RenderTarget& target, RenderStates states) const override;
};





