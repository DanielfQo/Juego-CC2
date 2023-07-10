#pragma once
#include<stdlib.h>
#include<time.h>
#include "MapaModel.h"

void MapaModel::imprimirMapa() {     //mostrar mapa  
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            std::cout << (mapa[i][j] ? ". " : "0 ");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void MapaModel::aplicarReglas(){ // Creador del mapa
    std::vector<std::vector<int>> newMapa = mapa;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            int caminosVecinos = 0; // Calcular caminos adyacentes
            for (int aux_x = -1; aux_x <= 1; aux_x++) {
                for (int aux_y = -1; aux_y <= 1; aux_y++) {
                    if (aux_x == 0 && aux_y == 0)continue; // No contar la posicion

                    int ni = i + aux_x;
                    int nj = j + aux_y;

                    if (ni >= 0 && ni < FILAS && nj >= 0 && nj < COLUMNAS) { // limites
                        caminosVecinos += mapa[ni][nj];
                    }
                }
            }
            // reglas
            if (mapa[i][j] == 1) {
                if (caminosVecinos < 3) {
                    newMapa[i][j] = 0;
                }
            }
            else {
                if (caminosVecinos > 3) {
                    newMapa[i][j] = 1;
                }
            }
        }
    }
    mapa = newMapa;
}

void MapaModel::generar_campo() {
    std::vector<std::vector<int>> NewMapa(FILAS, std::vector<int>(COLUMNAS, 0));
    mapa = NewMapa;
    srand(time(NULL));
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            mapa[i][j] = rand() % 2;
        }
    }

    for (int generacion = 0; generacion < GENERACIONES; generacion++)
        aplicarReglas();
}
