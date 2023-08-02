#pragma once
#include <iostream>
#include <math.h>

class EntidadModel {
protected:
    float pX, pY;
    float Vida, Ataque, Escudo;
    float width,height;
    float vel;
    bool vivo;
public:
    EntidadModel(float,float, float, float, float,float,float,float);
    float getpX();
    float getpY();
    void setPosX(float);
    void setPosY(float);
    void sumarPosX(float);
    void sumarPosY(float);
    void restarPosX(float);
    void restarPosY(float);

    float getVida();
    float getAtaque();
    float getEscudo();
    
    void setVida(float);
    void setAtaque(float);
    void setEscudo(float);

    float getVel();
    float getWidth();
    float getHeight();

    void setVel(float);
    void setWidth(float);
    void setHeight(float);

    bool getVivo();
    void setVivo(bool);

    bool colision(EntidadModel &);
    void rebotar(EntidadModel&);
    void rebotarPared(float,float);
    void colisionProyectil(float, float);
    void Recibir_Daño(EntidadModel&);

    virtual void moverse(EntidadModel&) = 0;
    virtual bool atacar(float,float) = 0;
};