#pragma once
#include "EntidadModel.h"
class EnemigoModel:public EntidadModel{
public:
    virtual void moverse(float, float) = 0;
    virtual void atacar() = 0;
};

class MeleeEnemigoModel :public EnemigoModel {
public:
    void moverse(float, float) override;
    void atacar() override;
};
class RangedEnemidoModel :public EnemigoModel {
public:
    void moverse(float, float) override;
    void atacar() override;
};
class TanqueEnemigoModel :public EnemigoModel {
public:
    void moverse(float, float) override;
    void atacar() override;
};