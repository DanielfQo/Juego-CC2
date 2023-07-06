#include <iostream>
#include <vector>
#include "EntidadModel.h"

class MapaModel{
    private:
        int FILAS = 25;
        int COLUMNAS = 40;
        int GENERACIONES = 2;
        std::vector<std::vector<int>> mapa;

    public:
        std::vector<std::vector<int>> getMapa1(){
            return mapa;
        }
        int getFilas(){
            return FILAS;
        }
        int getColumnas(){
            return COLUMNAS;
        }
        void imprimirMapa();
        void aplicarReglas();
        void generar_campo();
        //void load_entidades();
};
