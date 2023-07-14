#include "EnemigoModel.h"
void EnemigoModel::seguir(float X, float Y) {

    if (pX < X && pY < Y) {
        pX += vel / sqrt(2);
        pY += vel / sqrt(2);
    }
    if (pX > X && pY < Y) {
        pX += -(vel / sqrt(2));
        pY += vel / sqrt(2);
    }
    if (pX < X && pY > Y) {
        pX += vel / sqrt(2);
        pY += -(vel / sqrt(2));
    }
    if (pX > X && pY > Y) {
        pX += -(vel / sqrt(2));
        pY += -(vel / sqrt(2));
    }
    if (pX < X) {
        pX += vel;
    }
    if (pX > X) {
        pX += -vel;
    }
    if (pY < Y) {
        pY += vel;
    }
    if (pY > Y) {
        pY += -vel;
    }
}

bool MeleeEnemigoModel::atacar(int x, int y, int posX, int posY) {
	float distancia = sqrt((posX - x) * (posX - x) + (posY - y) * (posY - y));
	if (distancia <= radioAtack)
		return true;
	else
		return false;
}

bool RangedEnemigoModel::atacar(int x, int y, int posX, int posY) {
	float distancia = sqrt((posX - x) * (posX - x) + (posY - y) * (posY - y));
	if (AtackMin <= distancia && distancia <= AtackMax)
		return true;
	else
		return false;
}

bool BomberEnemigoModel::atacar(int x, int y, int posX, int posY) {
	float distancia = sqrt((posX - x) * (posX - x) + (posY - y) * (posY - y));
	if (distancia <= radioAtack)
		return true;
	else
		return false;
}