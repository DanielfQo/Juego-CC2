#include <iostream>
#include <vector>
#include "EntidadModel.h"

class MapaModel{
    private:

        int FILAS = 30;
        int COLUMNAS = 40;
        int GENERACIONES = 2;

        //movimiento del mapa
        float velocidadX = 0.0f;
        float velocidadY = 0.0f;
        float posicionX = -500.00f;
        float posicionY = -500.00f; 
        const float aceleracion = 0.50f;
        const float desaceleracion = 0.25f;
        const float velocidadMaxima = 5.00f;
        std::vector<std::vector<int>> mapa;

    public:
        std::vector<std::vector<int>> getMapa1(){return mapa;}
        int getFilas(){return FILAS;}
        int getColumnas(){return COLUMNAS;}
        float getPosicionX() {return posicionX;}
        float getPosicionY() {return posicionY;}
        void moverMapa(bool[4]);
        void imprimirMapa();
        void aplicarReglas();
        void generar_campo();
        //void load_entidades();
};
