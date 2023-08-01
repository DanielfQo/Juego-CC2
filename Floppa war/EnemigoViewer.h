#pragma once
#include "EntidadViewer.h"

class EnemigoViewer :public EntidadViewer {
protected:
	sf::IntRect frameRect;
	std::vector<std::tuple<float, float, bool>> a;
public:
	EnemigoViewer(std::string);
	void dibujarEntidad(sf::RenderWindow&)override;
	void setPosicion(float,float)override;
	void movimientoEntidadPress(const sf::Event::KeyEvent& keyevent) override;
	void movimientoEntidadRele(const sf::Event::KeyEvent& keyevent) override;
	void Atacar(float x, float y) {}
	void verificarAtaqueToEnemigo(EntidadViewer& enemigo) override {};
	std::vector<std::tuple<float, float, bool>> getPosicionesProyectiles()override { return a; };
};

// leaf

class MeleeEnemigoViewer : public EnemigoViewer {
public:
	MeleeEnemigoViewer();
};


class RangedEnemigoViewer :public EnemigoViewer { // atack large
public:
	RangedEnemigoViewer();
};


class  BomberEnemigoViewer :public EnemigoViewer { //atack medium
public:
	BomberEnemigoViewer();
};
