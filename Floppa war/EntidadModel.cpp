#include "EntidadModel.h"
EntidadModel::EntidadModel(float pX_, float pY_, int Vida_, int Ataque_, int Escudo_, float radio_, float vel_) {
    this->pX = pX_;
    this->pY = pY_;
    this->Vida = Vida_;
    this-> Ataque = Ataque_;
    this->Escudo = Escudo_;
    this->radio = radio_;
    this->vel = vel_;
}

float EntidadModel::getpX() { return pX; }
float EntidadModel::getpY() { return pY; }
void EntidadModel::setPosX(float x) { this->pX = x; }
void EntidadModel::setPosY(float  y) { this->pY = y; }

int EntidadModel::getVida() { return Vida; }
int EntidadModel::getAtaque() { return Ataque; }
int EntidadModel::getEscudo() { return Escudo; }
void EntidadModel::setVida(int vida_) { this->Vida = vida_; }
void EntidadModel::setAtaque(int ataque_) { this->Ataque = ataque_; }
void EntidadModel::setEscudo(int escudo_) { this->Escudo = escudo_; }

float EntidadModel::getVel() { return vel; }
float EntidadModel::getRadio() { return radio; }

void EntidadModel::setVel(float vel_) { this->vel = vel_; }
void EntidadModel::setRadio(float radio_) { this->radio = radio_; }

bool EntidadModel::colision(float posX, float posY, float radio2) {
    float distancia = sqrt((posX - pX) * (posX - pX) + (posY - pY) * (posY - pY));
    if (distancia <= radio2 + radio)
        return true;
    else
        return false;
}
void EntidadModel::rebotar(float X, float Y) {
    float distanciaX = (X - pX);
    float distanciaY = (Y - pY);
    float norma = sqrt((distanciaX * distanciaX) + (distanciaY * distanciaY));
    pX -= (distanciaX / norma) * 5;
    pY -= (distanciaY / norma) * 5;
}