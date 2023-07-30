#pragma once
#include <iostream>
#include <math.h>

class EntidadModel {
protected:
    float pX, pY;
    int Vida, Ataque, Escudo;
    float width,height;
    float vel;
public:
    EntidadModel(float,float,int,int,int,float,float,float);
    float getpX();
    float getpY();
    void setPosX(float);
    void setPosY(float);

    int getVida();
    int getAtaque();
    int getEscudo();
    
    void setVida(int);
    void setAtaque(int);
    void setEscudo(int);

    float getVel();
    float getWidth();
    float getHeight();

    void setVel(float);
    void setWidth(float);
    void setHeight(float);

    bool colision(float, float, float,float);
    void rebotar(float X, float Y);

    virtual void moverse(float, float) = 0;
    virtual bool atacar(float,float) = 0;
};