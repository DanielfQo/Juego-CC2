#include "EntidadModel.h"
class PersonajeModel: public EntidadModel {
public:
    PersonajeModel(float, float, float, float,float, float, float, float);
    virtual bool atacar(int, int,int, int) = 0;
    virtual void SpecialAbility() = 0;
    void moverse(EntidadModel&) {}
    bool atacar(float, float) { return true; }
};
// leaf


class FloppaModel : public PersonajeModel {
private:
    float radioAtack = 10;
public:
    FloppaModel();
    bool atacar(int, int,int, int) override; //atack meele
    void SpecialAbility() override;
};
class SoggaModel :public PersonajeModel { // atack large
private:
    float AtackMin = 30;
    float AtackMax = 60;
public:
    SoggaModel();
    bool atacar(int, int, int, int) override;
    void SpecialAbility() override;
};
class JinxModel :public PersonajeModel { //atack medium
private:
    float radioAtack = 30;
public:
    JinxModel();
    bool atacar(int, int, int, int) override;
    void SpecialAbility() override;
};