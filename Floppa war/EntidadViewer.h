#pragma once
#include <SFML/Graphics.hpp>
class EntidadViewer {
protected:
	sf::Texture spriteTexture;
	sf::Sprite sprite;
	std::string rutaImagen;
	sf::Vector2f velocidad;
	bool mueveArriba = false, mueveAbajo = false, mueveDerecha = false, mueveIzquierda = false;


public:
	EntidadViewer(std::string);
	~EntidadViewer()=default;
	virtual void dibujarEntidad(sf::RenderWindow &) = 0;

	virtual void movimientoEntidadPress(const sf::Event::KeyEvent& keyevent) = 0;
	virtual void movimientoEntidadRele(const sf::Event::KeyEvent& keyevent) = 0;

	bool getMueveArriba() { return mueveArriba; }
	bool getMueveAbajo() { return mueveAbajo; }
	bool getMueveIzquierda() { return mueveIzquierda; }
	bool getMueveDerecha() { return mueveDerecha; }
	virtual void setPosicion(float, float) = 0;
};

