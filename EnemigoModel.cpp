#include "EnemigoModel.h"

EnemigoModel::EnemigoModel(float pX_, float pY_, int Vida_, int Ataque_, int Escudo_, float width_, float height_, float vel_) : EntidadModel(pX_, pY_, Vida_, Ataque_, Escudo_, width_, height_, vel_) {}

void EnemigoModel::moverse(float X, float Y) {
	float distanciaX = (X - EntidadModel::getpX());
	float distanciaY = (Y - EntidadModel::getpY());
	float norma = sqrt((distanciaX * distanciaX) + (distanciaY * distanciaY));
	pX += (distanciaX / norma) * vel;
	pY += (distanciaY / norma) * vel;
}

//						EnemigoModel(posicionX,posicionY,vida,ataque,escudo,ancho,alto,velocidad)
MeleeEnemigoModel::MeleeEnemigoModel(): EnemigoModel(0, 0, 100, 5, 50, 64 , 64, 2){}

bool MeleeEnemigoModel::atacar(float posX,float posY) {
	float distancia = sqrt((posX - EntidadModel::getpX()) * (posX - EntidadModel::getpX()) + (posY - EntidadModel::getpY()) * (posY - EntidadModel::getpY()));
	if (distancia <= radioAtack)
		return true;
	else
		return false;
}
//						EnemigoModel(posicionX,posicionY,vida,ataque,escudo,ancho,alto,velocidad)
RangedEnemigoModel::RangedEnemigoModel() : EnemigoModel(0, 0, 100, 5, 50, 64, 64, 2) {}

bool RangedEnemigoModel::atacar(float posX,float posY) {
	float distancia = sqrt((posX - EntidadModel::getpX()) * (posX - EntidadModel::getpX()) + (posY - EntidadModel::getpY()) * (posY - EntidadModel::getpY()));
	if (AtackMin <= distancia && distancia <= AtackMax)
		return true;
	else
		return false;
}
//						EnemigoModel(posicionX,posicionY,vida,ataque,escudo,ancho,alto,velocidad)
BomberEnemigoModel::BomberEnemigoModel() : EnemigoModel(0, 0, 70, 30, 20, 64, 64, 5) {}

bool BomberEnemigoModel::atacar(float posX, float posY) {
	float distancia = sqrt((posX - EntidadModel::getpX()) * (posX - EntidadModel::getpX()) + (posY - EntidadModel::getpY()) * (posY - EntidadModel::getpY()));
	if (distancia <= radioAtack)
		return true;
	else
		return false;
}

