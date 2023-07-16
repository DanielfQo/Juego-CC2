#include "EnemigoModel.h"
EnemigoModel::EnemigoModel(float pX_,float pY_,int Vida_,int Ataque_,int Escudo_,float radio_,float vel_) : EntidadModel(pX_,pY_,Vida_,Ataque_,Escudo_,radio_,vel_){}
void EnemigoModel::seguir(float X, float Y) {
	float distanciaX = (X - EntidadModel::getpX());
	float distanciaY = (Y - EntidadModel::getpY());
	float norma = sqrt((distanciaX * distanciaX) + (distanciaY * distanciaY));
	pX += (distanciaX / norma) * vel;
	pY += (distanciaY / norma) * vel;
}

//						EnemigoModel(posicionX,posicionY,vida,ataque,escudo,radio,velocidad)
MeleeEnemigoModel::MeleeEnemigoModel(): EnemigoModel(200, 400, 100, 5, 50, 30, 2){}
bool MeleeEnemigoModel::atacar(float posX,float posY) {
	float distancia = sqrt((posX - EntidadModel::getpX()) * (posX - EntidadModel::getpX()) + (posY - EntidadModel::getpY()) * (posY - EntidadModel::getpY()));
	if (distancia <= radioAtack)
		return true;
	else
		return false;
}
//						EnemigoModel(posicionX,posicionY,vida,ataque,escudo,radio,velocidad)
RangedEnemigoModel::RangedEnemigoModel() : EnemigoModel(200, 400, 100, 5, 50, 30, 2) {}
bool RangedEnemigoModel::atacar(float posX,float posY) {
	float distancia = sqrt((posX - EntidadModel::getpX()) * (posX - EntidadModel::getpX()) + (posY - EntidadModel::getpY()) * (posY - EntidadModel::getpY()));
	if (AtackMin <= distancia && distancia <= AtackMax)
		return true;
	else
		return false;
}
//						EnemigoModel(posicionX,posicionY,vida,ataque,escudo,radio,velocidad)
BomberEnemigoModel::BomberEnemigoModel() : EnemigoModel(200, 400, 70, 30, 20, 30, 5) {}
bool BomberEnemigoModel::atacar(float posX, float posY) {
	float distancia = sqrt((posX - EntidadModel::getpX()) * (posX - EntidadModel::getpX()) + (posY - EntidadModel::getpY()) * (posY - EntidadModel::getpY()));
	if (distancia <= radioAtack)
		return true;
	else
		return false;
}

