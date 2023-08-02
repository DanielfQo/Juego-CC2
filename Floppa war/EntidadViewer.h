#pragma once
#include <SFML/Graphics.hpp>
class EntidadViewer {
protected:
	sf::Texture spriteTexture;
	sf::Sprite sprite;
	std::string rutaImagen;
	sf::Vector2f velocidad;
	int armaCambiar = 0;
	bool mueveArriba = false, mueveAbajo = false, mueveDerecha = false, mueveIzquierda = false;
	float posX = 0;
	float posY = 0;
	int vida;

public:
	EntidadViewer(std::string);
	~EntidadViewer()=default;
	virtual void dibujarEntidad(sf::RenderWindow &) = 0;

	virtual void movimientoEntidadPress(bool,bool,bool,bool) = 0;
	virtual void movimientoEntidadRele(bool, bool, bool, bool) = 0;
	virtual void movimientoEntidadPress2(bool, bool, bool, bool) = 0;
	virtual void movimientoEntidadRele2(bool, bool, bool, bool) = 0;

	bool getMueveArriba() { return mueveArriba; }
	bool getMueveAbajo() { return mueveAbajo; }
	bool getMueveIzquierda() { return mueveIzquierda; }
	bool getMueveDerecha() { return mueveDerecha; }
	int getVidaPersonaje() { return vida; }
	float getPosicionX() { return posX; }
	float getPosicionY() { return posY; }
	int getCambiarArma() { return armaCambiar; }
	void setCambiarArma(int a) { armaCambiar = a; }
	void setVida(int a) { this->vida = a; }
	virtual void setPosicion(float, float) = 0;
	virtual void Atacar(float, float) = 0;
	virtual void verificarAtaqueToEnemigo(EntidadViewer& enemigo) = 0;
	virtual std::vector<std::tuple<float, float, bool>> getPosicionesProyectiles() = 0;
};

