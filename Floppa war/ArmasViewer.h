#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TipoProyectilViewer.h"
class ArmasViewer{
protected:
	sf::Texture spriteTexture;
	sf::Sprite sprite;
	std::string rutaImagen;
	float rotation = 0;
	float x;
	float y;
public:
	ArmasViewer(std::string,float,float);
	~ArmasViewer() = default;
	void dibujarArma(sf::RenderWindow&);
	
	virtual void usarArma(float, float)=0;
	virtual void mostrarAtaque(sf::RenderWindow&) = 0;
	virtual void verificarColisionEnemigo(EntidadViewer&) = 0;
	virtual std::vector<std::tuple<float,float,bool>> getPosicionProyectiles() = 0;
};

class ArmaDistancia: public ArmasViewer {
private:
	std::unique_ptr<TipoProyectil < BalaViewer, 30>> balas;
public:
	ArmaDistancia(std::string, float, float);
	~ArmaDistancia() = default;
	void usarArma(float, float)override;
	void mostrarAtaque(sf::RenderWindow&)override;
	void verificarColisionEnemigo(EntidadViewer&)override;
	std::vector<std::tuple<float, float, bool>> getPosicionProyectiles()override { return balas->obtenerPosiciones(); };
};

class ArmaMelee : public ArmasViewer {
private:
	std::unique_ptr<TipoProyectil < MacheteViewer, 30>> machete;
public:
	ArmaMelee(std::string, float, float);
	~ArmaMelee() = default;
	void usarArma(float, float)override;
	void mostrarAtaque(sf::RenderWindow&)override;
	void verificarColisionEnemigo(EntidadViewer&)override;
	std::vector<std::tuple<float, float, bool>> getPosicionProyectiles()override { return machete->obtenerPosiciones(); };
};
