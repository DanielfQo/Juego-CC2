#include <iostream>
#include <vector>
#include "mapa.h"

class Model{
private:
	mapa1* maparef;
    //mapa2  mapa2;	
public:
    void cargarMapa();
    //std::vector<std::vector<int>> getMapa();
	//void getposiciones();
	//void updateposicion();

};
void Model::cargarMapa(){
    mapa1 aux;
    maparef = &aux;
    maparef->generar_campo();

}
/*
std::vector<std::vector<int>> Model::getMapa(){
    return maparef->getMapa1();
}
*/