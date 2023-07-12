#pragma once
#include <SFML/Graphics.hpp>
class MapaViewer{
	sf::Texture spriteTexture;
	sf::Sprite sprite;
	float posicionX;
	float posicionY;
public:
	MapaViewer(std::string);
	~MapaViewer() = default;
	void mostrarMapa(sf::RenderWindow& );
	void setPosicion(float, float);
};

