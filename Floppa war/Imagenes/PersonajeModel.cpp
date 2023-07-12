#include<cmath>
#include "PersonajeModel.h"

// personajeAbstract
bool FloppaModel::atacar(int x, int y,int posX, int posY) {
	float distancia = sqrt((posX - x) * (posX - x) + (posY - y) * (posY - y));
	if (distancia <= radioAtack)
		return true;
	else
		return false;
}
void FloppaModel::SpecialAbility() {}

bool SoggaModel::atacar(int x, int y, int posX, int posY) {
	float distancia = sqrt((posX - x) * (posX - x) + (posY - y) * (posY - y));
	if (AtackMin <= distancia && distancia <= AtackMax)
		return true;
	else
		return false;
}
void SoggaModel::SpecialAbility(){}

bool JinxModel::atacar(int x, int y, int posX, int posY) {
	float distancia = sqrt((posX - x) * (posX - x) + (posY - y) * (posY - y));
	if (distancia <= radioAtack)
		return true;
	else
		return false;
}
void JinxModel::SpecialAbility() {}
