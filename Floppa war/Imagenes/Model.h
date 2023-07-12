#include <iostream>
#include <vector>
#include "MapaModel.h"

class Model{
private:
	std::unique_ptr<MapaModel> maparef = std::make_unique<MapaModel>();
    //mapa2  mapa2;	
public:

	void cargarMapa();
	bool colisiones(int, int, int, int, int, int);
	void actualizarMapa(bool[4]);
	float getPosicionMapaX() { return maparef->getPosicionX(); }
	float getPosicionMapaY() { return maparef->getPosicionY(); }
    //std::vector<std::vector<int>> getMapa();
	//void getposiciones();
	//void updateposicion();

};

