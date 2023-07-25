#include <iostream>
#include <vector>
#include "MapaModel.h"

class Model{
private:
	std::unique_ptr<MapaModel> maparef;
	int idmapa = 1;
    //mapa2  mapa2;	
public:
	Model();
	~Model() = default;
	void setIdMapa(int x) { idmapa = x; }
	int getIdMapa() { return idmapa; }
	void generarMapa();
	void actualizarMapa(bool[4]);
	std::vector<std::vector<int>> getMapa1() { return maparef->getMapa1(); }
	float getPosicionMapaX() { return maparef->getPosicionX(); }
	float getPosicionMapaY() { return maparef->getPosicionY(); }
	std::vector<std::pair<float, float>> getPosicionEnemigosXY() { return maparef->getPosicionEnemigoXY(); }
	void actualizarPosicionEnemigos();
    //std::vector<std::vector<int>> getMapa();
	//void getposiciones();
	//void updateposicion();

};

