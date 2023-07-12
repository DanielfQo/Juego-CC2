#include <iostream>

class EntidadModel {
protected:
    float posX, posY;
    int Vida, Ataque, Escudo;
public:
    float getPosX();
    float getPosY();
    void setPosX(float);
    void setPosY(float);

    int getVida();
    int getAtaque();
    int getEscudo();
    
    void setVida(int);
    void setAtaque(int);
    void setEscudo(int);



    virtual void moverse(float, float) = 0;
    virtual void atacar() = 0;
};