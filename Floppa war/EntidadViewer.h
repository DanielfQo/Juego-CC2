#pragma once
#include <SFML/Graphics.hpp>
class EntidadViewer {
protected:
	sf::Texture spriteTexture;
	sf::Sprite sprite;
	std::string rutaImagen;
	sf::Vector2f velocidad;
public:
	EntidadViewer(std::string);
	~EntidadViewer()=default;
	virtual void dibujarEntidad(sf::RenderWindow &) = 0;
	virtual void movimientoEntidadPress(const sf::Event::KeyEvent& keyevent) = 0;
	virtual void movimientoEntidadRele(const sf::Event::KeyEvent& keyevent) = 0;
};

