#include <chrono>
#include "EntidadModel.h"
EntidadModel::EntidadModel(float pX_, float pY_, float Vida_, float Ataque_, float Escudo_, float width_,float height_,float vel_) {
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

void EntidadModel::sumarPosX(float sumar_) { this->pX += sumar_; }
void EntidadModel::sumarPosY(float sumar_) { this->pY += sumar_; }
void EntidadModel::restarPosX(float restar_) { this->pX -= restar_; }
void EntidadModel::restarPosY(float restar_) { this->pY -= restar_; }

float EntidadModel::getVida() { return Vida; }
float EntidadModel::getAtaque() { return Ataque; }
float EntidadModel::getEscudo() { return Escudo; }
void EntidadModel::setVida(float vida_) { this->Vida = vida_; }
void EntidadModel::setAtaque(float ataque_) { this->Ataque = ataque_; }
void EntidadModel::setEscudo(float escudo_) { this->Escudo = escudo_; }

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
void EntidadModel::Recibir_Daño(EntidadModel& entidad) {

    if (this->vivo == true && this->Vida > 0 ) {
        this->Vida -= entidad.getAtaque();
        std::cout << this->Vida << std::endl;
 
    }
    else {
        this->vivo = false;
    }
}