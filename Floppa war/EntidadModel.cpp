#include "EntidadModel.h"
EntidadModel::EntidadModel(float pX_, float pY_, int Vida_, int Ataque_, int Escudo_, float width_,float height_,float vel_) {
    this->pX = pX_;
    this->pY = pY_;
    this->Vida = Vida_;
    this-> Ataque = Ataque_;
    this->Escudo = Escudo_;
    this->width = width_;
    this->height = height_;
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
float EntidadModel::getWidth() { return width; }
float EntidadModel::getHeight() { return height; }

void EntidadModel::setVel(float vel_) { this->vel = vel_; }
void EntidadModel::setWidth(float width_) { this->width = width_; }
void EntidadModel::setHeight(float height_) { this->height = height_; }

bool EntidadModel::colision(float posX, float posY, float w,float h) {
    if (pX > posX + w)
        return false;
    else if (pX + width < posX)
        return false;
    else if (pY > posY + h)
        return false;
    else if (pY + height < posY)
        return false;
    else
        return true;
}
void EntidadModel::rebotar(float X, float Y) {
    float distanciaX = (X - pX);
    float distanciaY = (Y - pY);
    float norma = sqrt((distanciaX * distanciaX) + (distanciaY * distanciaY));
    pX -= (distanciaX / norma) * 5;
    pY -= (distanciaY / norma) * 5;
}