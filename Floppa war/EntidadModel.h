#pragma once
#include <iostream>
#include <math.h>

class EntidadModel {
protected:
    float pX, pY;
    int Vida, Ataque, Escudo;
    float width,height;
    float vel;
    bool vivo;
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

    bool getVivo();
    void setVivo(bool);

    bool colision(EntidadModel &);
    void rebotar(EntidadModel&);
    void rebotarPared(float,float);
    void colisionProyectil(float, float);

    virtual void moverse(EntidadModel&) = 0;
    virtual bool atacar(float,float) = 0;
};