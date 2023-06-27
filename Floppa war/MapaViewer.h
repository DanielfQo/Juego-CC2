#pragma once
#include <SFML/Graphics.hpp>
class MapaViewer{
	sf::Texture spriteTexture;
	sf::Sprite sprite;
public:
	MapaViewer(std::string);
	~MapaViewer() = default;
	void mostrarMapa(sf::RenderWindow& );
};

