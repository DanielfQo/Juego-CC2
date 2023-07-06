#pragma once
#include "EntidadModel.h"
class PersonajeModel :public EntidadModel{
protected:
    std::string arma1, arma2;
public:
    virtual void moverse(float, float) = 0;
    virtual void atacar() = 0;
    virtual void ataqueEspecial() = 0;
};

class FloppaModel :public PersonajeModel {
public:
    void moverse(float, float) override;
    void atacar() override;
    void ataqueEspecial() override;
};
class SoggaModel :public PersonajeModel {
public:
    void moverse(float, float) override;
    void atacar() override;
    void ataqueEspecial() override;
};
class JinxModel :public PersonajeModel {
public:
    void moverse(float, float) override;
    void atacar() override;
    void ataqueEspecial() override;
};
