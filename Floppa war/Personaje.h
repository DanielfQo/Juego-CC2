/*
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Personaje : public sf::Sprite {
private:
	sf::Vector2f size;
	int velocidad;
	int posx;
	int posy;
	int numfloppa;
public:
	int vida;
	int escudo;
	bool disparar;
	sf::Sprite arma;
	int danio = 1;
	float veldisparo = 1;
	bool posicion;
	bool posicionarma;
	static Personaje* crearpersonaje(int numfloppa);
    bool init();
    void enemyInit(int numfloppa);
    void update(float dt);
    void frameChange();
    void setSpeedX(int x);
    void setSpeedY(int y);
    int getSpeedX();
    int getSpeedY();
    void heroRightStatic();
    void heroRightMove();
    void heroLeftStatic();
    void heroLeftMove();
    void getBarrier(int a[][34], int length);
    void gunDirection();
    void showTimeBegan();
    void showTimeEnded();
    void myUpdate(float dt);
    void myUpdate2(float dt);
    void setSpeed();
    void resetSpeed();
};
*/