/*#include "Personaje.h"

Personaje* Personaje::crearpersonaje(int numfloppa) {
	Personaje* personaje = new Personaje();
	if (personaje && personaje->init()) {
		personaje->enemyInit(numfloppa);
	}
	delete personaje;
	return nullptr;
}

bool Personaje::init() {
	if (!Sprite::init()) {
		return false;
	}
	return true;
}

void Personaje::enemyInit(int numfloppa) {
	this->numfloppa = numfloppa;
	setTextureRect(IntRect(0, 0, 99, 99));
	if (numfloppa == 1) {
		vida = 100;
		escudo = 100;
	}
	if (numfloppa == 2) {
		vida = 100;
		escudo = 100;
	}
	else if (numfloppa == 3) {
		vida = 100;
		escudo = 100;
	}
	arma.setTextureRect(IntRect(0, 0, 99, 99));
	size = Vector2f(getTextureRect().width, getTextureRect().height);
	setOrigin(size.x / 2, size.y / 2);
}
*/