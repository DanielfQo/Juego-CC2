#include <iostream>

class EntidadModel {
protected:
    float posX, posY;
    int vida, ataque, nivel, escudo;
public:
    virtual void moverse(float, float) = 0;
    virtual void atacar() = 0;
};