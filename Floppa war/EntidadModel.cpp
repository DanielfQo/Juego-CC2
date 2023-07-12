#include "EntidadModel.h"
float EntidadModel::getPosX() { return posX; }
float EntidadModel::getPosY() { return posY; }
void EntidadModel::setPosX(float x) { this->posX = x; }
void EntidadModel::setPosY(float  y) { this->posY = y; }

int EntidadModel::getVida() { return Vida; }
int EntidadModel::getAtaque() { return Ataque; }
int EntidadModel::getEscudo() { return Escudo; }
void EntidadModel::setVida(int vida_) { this->Vida = vida_; }
void EntidadModel::setAtaque(int ataque_) { this->Ataque = ataque_; }
void EntidadModel::setEscudo(int escudo_) { this->Escudo = escudo_; }