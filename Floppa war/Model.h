#include <iostream>
#include <vector>
#include "MapaModel.h"

class Model{
private:
	std::shared_ptr<MapaModel> maparef;
    //mapa2  mapa2;	
public:
	std::shared_ptr<MapaModel> getMapa() {
		return maparef;
	}

	void cargarMapa();
	bool colisiones(int, int, int, int, int, int);
    //std::vector<std::vector<int>> getMapa();
	//void getposiciones();
	//void updateposicion();

};

