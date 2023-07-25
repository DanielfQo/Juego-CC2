#pragma once
#include "EntidadViewer.h"

class EnemigoViewer :public EntidadViewer {
protected:
	sf::IntRect frameRect;
	float posX = 0;
	float posY = 0;
public:
	EnemigoViewer(std::string);
	void dibujarEntidad(sf::RenderWindow&)override;
	void setPosicion(float,float)override;
	void movimientoEntidadPress(const sf::Event::KeyEvent& keyevent) override;
	void movimientoEntidadRele(const sf::Event::KeyEvent& keyevent) override;
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
