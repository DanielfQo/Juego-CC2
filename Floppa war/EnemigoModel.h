#pragma once
#include "EntidadModel.h"

class EnemigoModel {
private:
    float pX = 0;
    float pY = 0;
    float vel = 1;
public:
    virtual bool atacar(int, int, int, int) = 0;
    void seguir(float X, float Y);
};

// leaf

class MeleeEnemigoModel : public EnemigoModel {
private:
    float radioAtack = 10;
public:
    bool atacar(int, int, int, int) override; //atack meele
};


class RangedEnemigoModel :public EnemigoModel { // atack large
private:
    float AtackMin = 30;
    float AtackMax = 60;
public:
    bool atacar(int, int, int, int) override;
};


class  BomberEnemigoModel :public EnemigoModel { //atack medium
private:
    float radioAtack = 30;
public:
    bool atacar(int, int, int, int) override;
};