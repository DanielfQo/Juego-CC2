#pragma once
#include <SFML/Graphics.hpp>
class EntidadViewer {
private:
	sf::Texture spriteTexture;
	sf::Sprite sprite;
	sf::Vector2f velocidad;
public:
	EntidadViewer(std::string);
	~EntidadViewer()=default;
	void dibujarEntidad(sf::RenderWindow &);
	void movimientoEntidad(const sf::Event::KeyEvent& );

};

