#pragma once
#include "EntidadModel.h"

class EnemigoModel :public EntidadModel{
private:
    float vel;
public:
    EnemigoModel(float,float,int,int,int,float,float);
    virtual bool atacar(float, float) = 0;
    void seguir(float, float);
};

// leaf

class MeleeEnemigoModel : public EnemigoModel {
private:
    float radioAtack = 10;
public:
    MeleeEnemigoModel();
    bool atacar(float, float) override; //atack meele
};


class RangedEnemigoModel :public EnemigoModel { // atack large
private:
    float AtackMin = 30;
    float AtackMax = 60;
public:
    RangedEnemigoModel();
    bool atacar(float, float) override;
};


class  BomberEnemigoModel :public EnemigoModel { //atack medium
private:
    float radioAtack = 30;
public:
    BomberEnemigoModel();
    bool atacar(float, float) override;
};