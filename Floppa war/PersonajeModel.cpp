#include<cmath>
#include<thread>
#include "PersonajeModel.h"

PersonajeModel::PersonajeModel(float pX_, float pY_, float Vida_, float Ataque_, float Escudo_, float width_, float height_, float vel_) : EntidadModel(pX_, pY_, Vida_, Ataque_, Escudo_, width_, height_, vel_) {}

                   //(posicionX, posicionY, vida, ataque, escudo, ancho, alto, velocidad)
FloppaModel::FloppaModel() : PersonajeModel(480, 288, 100, 20, 50, 64, 64, 2) {}
bool FloppaModel::atacar(int x, int y,int posX, int posY) {
	float distancia = sqrt((posX - x) * (posX - x) + (posY - y) * (posY - y));
	if (distancia <= radioAtack)
		return true;
	else
		return false;
}
void FloppaModel::SpecialAbility() {}

SoggaModel::SoggaModel() : PersonajeModel(480, 288, 100, 20, 50, 64, 64, 2) {}
bool SoggaModel::atacar(int x, int y, int posX, int posY) {
	float distancia = sqrt((posX - x) * (posX - x) + (posY - y) * (posY - y));
	if (AtackMin <= distancia && distancia <= AtackMax)
		return true;
	else
		return false;
}
void SoggaModel::SpecialAbility(){}

JinxModel::JinxModel() : PersonajeModel(480, 288, 100, 20, 50, 64, 64, 2) {}
bool JinxModel::atacar(int x, int y, int posX, int posY) {
	float distancia = sqrt((posX - x) * (posX - x) + (posY - y) * (posY - y));
	if (distancia <= radioAtack)
		return true;
	else
		return false;
}
void JinxModel::SpecialAbility() {}
