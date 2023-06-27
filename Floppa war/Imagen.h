#pragma once
#include <SFML/Graphics.hpp>

class Imagen {
protected:
	sf::Texture spriteTexture;
	sf::Sprite sprite;
public:
	Imagen(std::string );
	~Imagen()=default;
	void dibujarSprite(sf::RenderWindow & window);
	virtual void updateImagen() = 0;
};
