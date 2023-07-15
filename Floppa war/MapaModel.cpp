#pragma once
#include<stdlib.h>
#include<time.h>
#include "MapaModel.h"

MapaModel::MapaModel(){
    semilla = 0;
    posicionX = -100.00f;
    posicionY = -100.00f;
}
void MapaModel::imprimirMapa() {     //mostrar mapa  
    for (const auto& fila : mapai) {
        for (int elemento : fila) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
    }
}
void MapaModel::aplicarReglas(){ // Creador del mapa
    std::vector<std::vector<int>> newMapa = mapai;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            int caminosVecinos = 0; // Calcular caminos adyacentes
            for (int aux_x = -1; aux_x <= 1; aux_x++) {
                for (int aux_y = -1; aux_y <= 1; aux_y++) {
                    if (aux_x == 0 && aux_y == 0)continue; // No contar la posicion

                    int ni = i + aux_x;
                    int nj = j + aux_y;

                    if (ni >= 0 && ni < FILAS && nj >= 0 && nj < COLUMNAS) { // limites
                        caminosVecinos += mapai[ni][nj];
                    }
                }
            }
            // reglas
            if (mapai[i][j] == 1) {
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
    //ponemos bordes al mapa
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (i == 0 || i == FILAS - 1 || j == 0 || j == COLUMNAS - 1) {
                newMapa[i][j] = 0;
            }
        }
    }
    mapai = newMapa;
}

void MapaModel::generar_campo() {
    std::vector<std::vector<int>> NewMapa(FILAS, std::vector<int>(COLUMNAS, 0));
    mapai = NewMapa;
    std::srand(semilla);
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            mapai[i][j] = std::rand() % 2;
        }
    }

    for (int generacion = 0; generacion < GENERACIONES; generacion++)
        aplicarReglas();
}

void MapaModel::generarCuartos() {
    std::vector<std::vector<int>> matriz(4, std::vector<int>(4, 0));

    int posicion2X = std::rand() % 4;
    int posY1 = 1;
    matriz[0][posicion2X] = 2;
    matriz[posY1][posicion2X] = 1;
    //generamos los cuartos de forma aleatoria
    int numCuartos = 4;

    for (int i = 0; i < numCuartos; i++) {
        if (posY1 != 3) {
            if (posicion2X == 0) {
                int aux = std::rand() % 2;
                if (aux == 0) {
                    posicion2X++;
                    matriz[posY1][posicion2X] = 1;
                }
                else {
                    posY1++;
                    matriz[posY1][posicion2X] = 1;
                }
            }
            else if (posicion2X == 3) {
                int aux = std::rand() % 2;
                if (aux == 0) {
                    posicion2X--;
                    matriz[posY1][posicion2X] = 1;
                }
                else {
                    posY1++;
                    matriz[posY1][posicion2X] = 1;
                }
            }
            else {
                int aux = std::rand() % 3;
                if (aux == 0) {
                    posicion2X--;
                    matriz[posY1][posicion2X] = 1;
                }
                else if (aux == 1) {
                    posicion2X++;
                    matriz[posY1][posicion2X] = 1;
                }
                else {
                    posY1++;
                    matriz[posY1][posicion2X] = 1;
                }
            }
        }
    }

    if (posicion2X + 1 < 4 && matriz[posY1][posicion2X + 1] == 0) {
        matriz[posY1][posicion2X + 1] = 3;
    }
    else if (posY1 + 1 < 4 && matriz[posY1 + 1][posicion2X] == 0) {
        matriz[posY1 + 1][posicion2X] = 3;
    }
    else if (posY1 - 1 >= 0 && matriz[posY1 - 1][posicion2X] == 0) {
        matriz[posY1 - 1][posicion2X] = 3;
    }
    else if (posicion2X - 1 >= 0 && matriz[posY1][posicion2X - 1] == 0) {
        matriz[posY1][posicion2X - 1] = 3;
    }
    cuartos = matriz;
}

void MapaModel::generarMapaCompleto() {


    // Crear la matriz resultante
    std::vector<std::vector<int>> matrizResultado(80, std::vector<int>(128, 0));
    generarCuartos();
    // Generar la matriz más grande
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            
            if (cuartos[i][j] != 0) {
                generar_campo();
                semilla++;
                for (int x = 0; x < FILAS; x++) {
                    for (int y = 0; y < COLUMNAS; y++) {
                        matrizResultado[i * FILAS + x][j * COLUMNAS + y] = mapai[x][y];
                    }
                }
            }
            else {
                for (int x = 0; x < FILAS; x++) {
                    for (int y = 0; y < COLUMNAS; y++) {
                        matrizResultado[i * FILAS + x][j * COLUMNAS + y] = -1;
                    }
                }
            }
        }
    }
    mapaCompleto = matrizResultado;
}

void MapaModel::moverMapa(bool vector[4]) {

    // Ajustar las velocidades en función de los flags
    if (vector[0])
        velocidadY += aceleracion;
    if (vector[1])
        velocidadY -= aceleracion;
    if (vector[2])
        velocidadX += aceleracion;
    if (vector[3])
        velocidadX -= aceleracion;

    // Aplicar desaceleración
    if (!vector[0] && !vector[1])
        velocidadY -= (velocidadY * desaceleracion);
    if (!vector[2] && !vector[3])
        velocidadX -= (velocidadX * desaceleracion);

    // Limitar la velocidad máxima
    if (velocidadY > velocidadMaxima)
        velocidadY = velocidadMaxima;
    if (velocidadY < -velocidadMaxima)
        velocidadY = -velocidadMaxima;
    if (velocidadX > velocidadMaxima)
        velocidadX = velocidadMaxima;
    if (velocidadX < -velocidadMaxima)
        velocidadX = -velocidadMaxima;

    // Mover la posición en función de las velocidades
    posicionY += velocidadY;
    posicionX += velocidadX;
}
