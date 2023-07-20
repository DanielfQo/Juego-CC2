#include <iostream>
#include <vector>
#include "EntidadModel.h"

class MapaModel{
    private:

        int FILAS = 20;
        int COLUMNAS = 32;
        int GENERACIONES = 2;
        int semilla = 0;
        //movimiento del mapa
        float velocidadX = 0.0f;
        float velocidadY = 0.0f;
        float posicionX = 0.00f;
        float posicionY = 0.00f;
        const float aceleracion = 0.50f;
        const float desaceleracion = 0.25f;
        const float velocidadMaxima = 5.00f;
        std::vector<std::vector<int>> mapai;
        std::vector<std::vector<int>> cuartos;
        std::vector<std::vector<int>> mapaCompleto;
    public:
        MapaModel();
        std::vector<std::vector<int>> getMapa1(){return mapaCompleto;}
        int getFilas(){return FILAS;}
        int getColumnas(){return COLUMNAS;}
        float getPosicionX() {return posicionX;}
        float getPosicionY() {return posicionY;}
        void moverMapa(bool[4]);
        void imprimirMapa();
        void aplicarReglas();
        void generar_campo();
        void generarCuartos();
        void generarMapaCompleto();
        //void load_entidades();
};
