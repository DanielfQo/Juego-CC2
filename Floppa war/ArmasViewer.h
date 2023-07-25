#pragma once
#include <SFML/Graphics.hpp>
class ArmasViewer{
protected:
	sf::Texture spriteTexture;
	sf::Sprite sprite;
	std::string rutaImagen;
public:
	ArmasViewer(std::string,float,float);
	~ArmasViewer() = default;
	void dibujarArma(sf::RenderWindow&);
};

