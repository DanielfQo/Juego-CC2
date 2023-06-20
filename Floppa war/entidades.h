#include <iostream>

class entidades{
private:
	int vida;
    int posX, posY;
    int ataque;
    int nivel;

public:
	void view_entidad();
    virtual void moverse(int, int);
    virtual void atacar();

};
