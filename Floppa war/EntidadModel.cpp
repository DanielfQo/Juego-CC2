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
    this->vivo = true;
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

bool EntidadModel::getVivo() { return vivo; }
void EntidadModel::setVivo(bool vivo) { this->vivo = vivo; }

bool EntidadModel::colision(EntidadModel &entidad) { //(float posX, float posY, float w,float h) 
    if (this->pX > entidad.pX + entidad.width)
        return false;
    else if (this->pX + this->width < entidad.pX)
        return false;
    else if (this->pY > entidad.pY + entidad.height)
        return false;
    else if (this->pY + this->height < entidad.pY)
        return false;
    else
        return true;
}
void EntidadModel::rebotar(EntidadModel& entidad) {
    float distanciaX = (entidad.pX - this->pX);
    float distanciaY = (entidad.pY - this->pY);
    float norma = sqrt(abs((distanciaX * distanciaX) + (distanciaY * distanciaY)));
    if (norma != 0) {
        this->pX -= (distanciaX / norma) * 5;
        this->pY -= (distanciaY / norma) * 5;
    }
    
}
void EntidadModel::rebotarPared(float x, float y) {
    float distanciaX = (x - this->pX);
    float distanciaY = (y - this->pY);
    float norma = sqrt(abs((distanciaX * distanciaX) + (distanciaY * distanciaY)));
    if (norma != 0) {
        this->pX -= (distanciaX / norma) * 5;
        this->pY -= (distanciaY / norma) * 5;
    }
}
void EntidadModel::colisionProyectil(float x, float y) {
    if (x >= pX && x <= pX + width && y >= pY && y <= pY + height) {
        Vida -= 20;
    }
    if (Vida <= 0) {
        vivo = false;
    }
}