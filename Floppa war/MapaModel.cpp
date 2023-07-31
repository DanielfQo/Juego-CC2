#pragma once
#include<stdlib.h>
#include<time.h>
#include "MapaModel.h"

MapaModel::MapaModel(){
    semilla = 0;
    posicionX = 0.00f;
    posicionY = 0.00f;
    for (int i = 0; i < cantEnemigos; ++i) {
        enemigosMelee.push_back(std::make_unique<MeleeEnemigoModel>());
    }
    for (int i = 0; i < cantEnemigos; ++i) {
        posicionEnemigosMelee.push_back(std::make_pair(0.00f, 0.00f));
    }
}
void MapaModel::imprimirMapa() {     //mostrar mapa  
    for (const auto& fila : cuartos) {
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
    std::time_t currentTime = std::time(nullptr);
    std::srand(static_cast<unsigned int>(currentTime));
    int posicion2X = std::rand() % 4;
    int posY1 = 1;
    matriz[0][posicion2X] = 2;
    matriz[posY1][posicion2X] = 1;
    //generamos los cuartos de forma aleatoria
    int numCuartos = 4;

    posicionX = (posicion2X * -2048);
    posicionY = 0;

    std::cout << posicionX << " " << posicionY << "\n";

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

    //piedra 0
    //pasto 1
    // Crear la matriz resultante
    std::vector<std::vector<int>> matrizResultado(80, std::vector<int>(128, 0));
    // Generar la matriz más grande
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            
            if (cuartos[i][j] == 1 || cuartos[i][j] == 3) {
                generar_campo();
                semilla++;
                for (int x = 0; x < FILAS; x++) {
                    for (int y = 0; y < COLUMNAS; y++) {
                        matrizResultado[i * FILAS + x][j * COLUMNAS + y] = mapai[x][y];
                        //hacemos los caminos
                        if (i != 0 ) {
                            //arriba
                            if (cuartos[i - 1][j] != 0) {
                                if ((y >= 14 && y <= 17) && (x >= 0 && x <= 3)) {
                                    matrizResultado[i * FILAS + x][j * COLUMNAS + y] = 1;
                                }
                            }
                        }
                        if (i != 3) {
                            //abajo
                            if (cuartos[i + 1][j] != 0) {
                                if ((y >= 14 && y <= 17) && (x >= 16 && x <= 19)) {
                                    matrizResultado[i * FILAS + x][j * COLUMNAS + y] = 1;
                                }
                            }
                        }
                        if (j != 3) {
                            //derecha
                            if (cuartos[i][j + 1] != 0) {
                                if ((x >= 8 && x <= 11) && (y >= 28 && y <= 31)) {
                                    matrizResultado[i * FILAS + x][j * COLUMNAS + y] = 1;
                                }
                            }
                        }
                        if (j != 0){
                            //izquierda
                            if (cuartos[i][j - 1] != 0) {
                                if ((x >= 8 && x <= 11) && (y >= 0 && y <= 3)) {
                                    matrizResultado[i * FILAS + x][j * COLUMNAS + y] = 1;
                                }
                            }
                        } 
                    }
                }
            }
            else if(cuartos[i][j] == 2) {
                generar_campo();
                semilla++;
                for (int x = 0; x < FILAS; x++) {
                    for (int y = 0; y < COLUMNAS; y++) {
                        if (x == 0 || x == FILAS - 1 || y == 0 || y == COLUMNAS - 1) {
                            matrizResultado[i * FILAS + x][j * COLUMNAS + y] = 0;
                        }
                        else {
                            matrizResultado[i * FILAS + x][j * COLUMNAS + y] = 1;
                        }
                        if ((y >=14 && y <= 17) && x == 19) {
                            matrizResultado[i * FILAS + x][j * COLUMNAS + y] = 1;
                        }
                    }
                }
            }
            else if(cuartos[i][j] == 0){
                for (int x = 0; x < FILAS; x++) {
                    for (int y = 0; y < COLUMNAS; y++) {
                        matrizResultado[i * FILAS + x][j * COLUMNAS + y] = -1;
                    }
                }
            }
        }
    }
    //arreglamos la matriz
    mapaCompleto = matrizResultado;
}

void MapaModel::moverMapa(bool vector[4]) {
    for (int y = 0; y < FILAS * 4; y++) {
        for (int x = 0; x < COLUMNAS * 4; x++) {
            float posX = x * 64 + posicionX;
            float posY = y * 64 + posicionY;
            if (posX >= -64 && posX <= 1088 && posY >= -64 && posY <= 704) {
                if ( mapaCompleto[y][x] == 0) {
                    
                    if (colisionMapa(posX + 22, posY + 10, 10, 12, 480, 292, 64, 64)) {
                        velocidadX = 0;
                        vector[2] = false;
                        posicionX -= (posX + 64 - 480);

                    }
                    if (colisionMapa(posX, posY + 10, 10, 12, 480, 292, 64, 64)) {
                        velocidadX = 0;
                        vector[3] = false;
                        posicionX += ( 480 + 64 - posX);
                    }
                    if (colisionMapa(posX + 10, posY + 22, 12, 10, 480, 292, 64, 64)) {
                        velocidadY = 0;
                        vector[0] = false;
                        posicionY -= (posY + 64 - 292);
                    }
                    if (colisionMapa(posX + 10, posY, 12, 10, 480, 292, 64, 64)) {
                        velocidadY = 0;
                        vector[1] = false;
                        posicionY += (292 +64 - posY);
                    }


                }
            }
        }
    }

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

    for (auto &enem : enemigosMelee) {
        enem->setPosX(enem->getpX() + velocidadX);
        enem->setPosY(enem->getpY() + velocidadY);
    }
}

bool MapaModel::colisionMapa(float PosX, float PosY,float w, float h, float X, float Y, float width,float height) {
    if (PosX > X + width || PosX + w < X || PosY > Y + height || PosY + h < Y)
        return false;
    else
        return true;
}

void MapaModel::generar_entidades(){
    
    for (int i = 0; i < cantEnemigos;i++) {
        enemigosMelee[i]->setPosX(i*100.00f);
        enemigosMelee[i]->setPosY(i*1.00f);
    }
}
void MapaModel::movimientoEnemigosPersonaje() {
    for (int i = 0;i < cantEnemigos;i++) {
        if (enemigosMelee[i]->colision(480, 288,64,64)) {
            enemigosMelee[i]->rebotar(480, 288);
        }
        else {
            enemigosMelee[i]->moverse(480, 288);
        }
        posicionEnemigosMelee[i].first = enemigosMelee[i]->getpX();
        posicionEnemigosMelee[i].second = enemigosMelee[i]->getpY();
    }
    
}
void MapaModel::movimientoEnemigosEnemigos() {
    for (int i = 0;i < cantEnemigos;i++) {
        for (int j = 0;j < cantEnemigos;j++) {
            if (i != j && enemigosMelee[i]->colision(enemigosMelee[j]->getpX(), enemigosMelee[j]->getpY() + 4, enemigosMelee[j]->getWidth(), enemigosMelee[j]->getHeight())) {
                enemigosMelee[i]->rebotar(enemigosMelee[j]->getpX(), enemigosMelee[j]->getpY());
            }
            posicionEnemigosMelee[i].first = enemigosMelee[i]->getpX();
            posicionEnemigosMelee[i].second = enemigosMelee[i]->getpY();
        }
    }
}
void MapaModel::colisionEnemigo() {
    for (int y = 0; y < FILAS * 4; y++) {
        for (int x = 0; x < COLUMNAS * 4; x++) {
            float posX = x * 64 + posicionX;
            float posY = y * 64 + posicionY;
            for (int p = 0; p < cantEnemigos; p++) {
                if (colisionMapa(posX, posY,64,64, enemigosMelee[p]->getpX(), enemigosMelee[p]->getpY()+4, 64,64) == true && mapaCompleto[y][x] == 0) {
                        enemigosMelee[p]->rebotar(posX, posY);
                }
            
            }
        }
    }
}