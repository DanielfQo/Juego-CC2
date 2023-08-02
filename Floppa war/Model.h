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
	float getVidaPersonaje1() { return maparef->getVidaPersonaje1(); }
	std::vector<std::pair<float, float>> getPosicionEnemigosMelee() { return maparef->getPosicionEnemigoMelee(); }
	std::vector<std::pair<float, float>> getPosicionEnemigosRanged() { return maparef->getPosicionEnemigoRanged(); }
	std::vector<std::pair<float, float>> getPosicionEnemigosBomber() { return maparef->getPosicionEnemigoBomber(); }
	void actualizarPosicionEnemigos();
	void actualizarPosicionProyectiles(const std::vector<std::tuple<float, float, bool>>&);
};

