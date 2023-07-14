#include "EnemigoModel.h"


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