#pragma once
#include<stdlib.h>
#include<time.h>
#include <tuple>
#include "MapaModel.h"

MapaModel::MapaModel(){
    semilla = 0;
    posicionX = 0.00f;
    posicionY = 0.00f;

    Personaje1 = std::make_unique<FloppaModel>();

    for (int i = 0; i < cantEnemigos; ++i) {
        enemigosMelee.push_back(std::make_unique<MeleeEnemigoModel>());
        posicionEnemigosMelee.push_back(std::make_pair(0.00f, 0.00f));
    }
    for (int i = 0; i < cantEnemigos; ++i) {
        enemigosRanged.push_back(std::make_unique<RangedEnemigoModel>());
        posicionEnemigosRanged.push_back(std::make_pair(0.00f, 0.00f));
    }
    for (int i = 0; i < cantEnemigos; ++i) {
        enemigosBomber.push_back(std::make_unique<BomberEnemigoModel>());
        posicionEnemigosBomber.push_back(std::make_pair(0.00f, 0.00f));
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
    int posicion2X = 0; //std::rand() % 4;
    int posY1 = 1;
    matriz[0][posicion2X] = 2;
    matriz[posY1][posicion2X] = 1;
    //generamos los cuartos de forma aleatoria
    int numCuartos = 4;

    posicionX = (posicion2X * -2048);
    posicionY = 0;

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
                    
                    if (colision(posX + 54, posY + 10, 10, 44, 480, 292, 64, 64)) {
                        velocidadX = 0;
                        vector[2] = false;
                        posicionX -= (posX + 64 - 480);

                    }
                    if (colision(posX, posY + 10, 10, 44, 480, 292, 64, 64)) {
                        velocidadX = 0;
                        vector[3] = false;
                        posicionX += (480 + 64 - posX);
                    }
                    if (colision(posX + 10, posY + 54, 44, 10, 480, 292, 64, 64)) {
                        velocidadY = 0;
                        vector[0] = false;
                        posicionY -= (posY + 64 - 292);
                    }
                    if (colision(posX + 10, posY, 44, 10, 480, 292, 64, 64)) {
                        velocidadY = 0;
                        vector[1] = false;
                        posicionY += (292 + 64 - posY);
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
    for (auto& enem : enemigosRanged) {
        enem->setPosX(enem->getpX() + velocidadX);
        enem->setPosY(enem->getpY() + velocidadY);
    }
    for (auto& enem : enemigosBomber) {
        enem->setPosX(enem->getpX() + velocidadX);
        enem->setPosY(enem->getpY() + velocidadY);
    }
}
bool MapaModel::colision(float PosX, float PosY, float w, float h, float X, float Y, float width, float height) {
    if (PosX > X + width || PosX + w < X || PosY > Y + height || PosY + h < Y)
        return false;
    else
        return true;
}
bool MapaModel::colision(float PosX, float PosY, float w, float h, EntidadModel& entidad) {
    if (PosX > entidad.getpX() + entidad.getWidth() || PosX + w < entidad.getpX() || PosY > entidad.getpY() + 4 + entidad.getHeight() || PosY + h < entidad.getpY() + 4)
        return false;
    else
        return true;
}
void MapaModel::generar_entidades() {

    std::time_t currentTime = std::time(nullptr);
    std::srand(static_cast<unsigned int>(currentTime));
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    std::cout << (80 * 64) + posicionX << " : " << (80 * 64) + posicionY << std::endl;

    for (int i = 1; i < FILAS * 4 - 1; i++) {
        for (int j = 1; j < COLUMNAS * 4 - 1; j++) {
            int auxiliar = std::rand() % 50 + 1;
            if (mapaCompleto[i][j] == 1) {
                if (mapaCompleto[i - 1][j - 1] == 1 && mapaCompleto[i - 1][j] == 1 && mapaCompleto[i - 1][j + 1] == 1 && mapaCompleto[i][j - 1] == 1 && mapaCompleto[i][j + 1] == 1 && mapaCompleto[i + 1][j - 1] == 1 && mapaCompleto[i + 1][j] == 1 && mapaCompleto[i + 1][j + 1] == 1) {
                    if (count1 < cantEnemigos && auxiliar == 2 && enemigosMelee[count1]) {
                        enemigosMelee[count1]->setPosX((i * 64) + posicionX);
                        enemigosMelee[count1]->setPosY((j * 64) + posicionY);
                        ++count1;
                    }
                    if (count2 < cantEnemigos && auxiliar == 10 && enemigosRanged[count2]) {
                        enemigosRanged[count2]->setPosX((i * 64) + posicionX);
                        enemigosRanged[count2]->setPosY((j * 64) + posicionY);
                        ++count2;
                    }
                    if (count3 < cantEnemigos && auxiliar == 20 && enemigosBomber[count3]) {
                        enemigosBomber[count3]->setPosX((i * 64) + posicionX);
                        enemigosBomber[count3]->setPosY((j * 64) + posicionY);
                        ++count3;
                    }
                }
            }
        }
    }
}
void MapaModel::movimientoEnemigosPersonaje() {

    for (int i = 0;i < enemigosMelee.size();i++) {
        if (enemigosMelee[i]->getVivo()) {
            if (colision(enemigosMelee[i]->getpX() + 54, enemigosMelee[i]->getpY() + 10, 10, 44, 480, 292, 64, 64)) {
                enemigosMelee[i]->setPosX(416);
                enemigosMelee[i]->moverse(*Personaje1);
                Personaje1->Recibir_Daño(*enemigosMelee[i]);
            }
            else if (colision(enemigosMelee[i]->getpX(), enemigosMelee[i]->getpY() + 4, 4, 44, 480, 292, 64, 64)) {
                enemigosMelee[i]->setPosX(544);
                enemigosMelee[i]->moverse(*Personaje1);
                Personaje1->Recibir_Daño(*enemigosMelee[i]);
            }
            else if (colision(enemigosMelee[i]->getpX() + 10, enemigosMelee[i]->getpY() + 54, 44, 10, 480, 292, 64, 64)) {
                enemigosMelee[i]->setPosY(228);
                enemigosMelee[i]->moverse(*Personaje1);
                Personaje1->Recibir_Daño(*enemigosMelee[i]);
            }
            else if (colision(enemigosMelee[i]->getpX() + 10, enemigosMelee[i]->getpY(), 44, 10, 480, 292, 64, 64)) {
                enemigosMelee[i]->setPosY(356);
                enemigosMelee[i]->moverse(*Personaje1);
                Personaje1->Recibir_Daño(*enemigosMelee[i]);
            }
            else {
                enemigosMelee[i]->moverse(*Personaje1);
            }
        }
        else {
            enemigosMelee[i]->setPosX(-3000.00f);
            enemigosMelee[i]->setPosY(-3000.00f);
        }
        posicionEnemigosMelee[i].first = enemigosMelee[i]->getpX();
        posicionEnemigosMelee[i].second = enemigosMelee[i]->getpY();
        
    }
    //////

    for (int i = 0;i < enemigosRanged.size();i++) {
        if (enemigosRanged[i]->getVivo()) {
            if (colision(enemigosRanged[i]->getpX() + 54, enemigosRanged[i]->getpY() + 14, 10, 44, 480, 292, 64, 64)) {
                enemigosRanged[i]->setPosX(416);
                enemigosRanged[i]->moverse(*Personaje1);
                Personaje1->Recibir_Daño(*enemigosRanged[i]);
            }
            else if (colision(enemigosRanged[i]->getpX(), enemigosRanged[i]->getpY() + 4, 10, 44, 480, 292, 64, 64)) {
                enemigosRanged[i]->setPosX(544);
                enemigosRanged[i]->moverse(*Personaje1);
                Personaje1->Recibir_Daño(*enemigosRanged[i]);
            }
            else if (colision(enemigosRanged[i]->getpX() + 10, enemigosRanged[i]->getpY() + 54, 44, 10, 480, 292, 64, 64)) {
                enemigosRanged[i]->setPosY(228);
                enemigosRanged[i]->moverse(*Personaje1);
                Personaje1->Recibir_Daño(*enemigosRanged[i]);
            }
            else if (colision(enemigosRanged[i]->getpX() + 10, enemigosRanged[i]->getpY(), 44, 10, 480, 292, 64, 64)) {
                enemigosRanged[i]->setPosY(356);
                enemigosRanged[i]->moverse(*Personaje1);
                Personaje1->Recibir_Daño(*enemigosRanged[i]);
            }
            else {
                enemigosRanged[i]->moverse(*Personaje1);
            }
        }
        else {
            enemigosRanged[i]->setPosX(-3000.00f);
            enemigosRanged[i]->setPosY(-3000.00f);
        }
        posicionEnemigosRanged[i].first = enemigosRanged[i]->getpX();
        posicionEnemigosRanged[i].second = enemigosRanged[i]->getpY();
    }
    //////
    for (int i = 0;i < enemigosBomber.size();i++) {
        if (enemigosBomber[i]->getVivo()) {
            if (colision(enemigosBomber[i]->getpX() + 54, enemigosBomber[i]->getpY() + 10, 10, 44, 480, 292, 64, 64)) {
                enemigosBomber[i]->setPosX(416);
                enemigosBomber[i]->moverse(*Personaje1);
                Personaje1->Recibir_Daño(*enemigosBomber[i]);
            }
            else if (colision(enemigosBomber[i]->getpX(), enemigosBomber[i]->getpY() + 10, 10, 44, 480, 292, 64, 64)) {
                enemigosBomber[i]->setPosX(544);
                enemigosBomber[i]->moverse(*Personaje1);
                Personaje1->Recibir_Daño(*enemigosBomber[i]);
            }
            else if (colision(enemigosBomber[i]->getpX() + 10, enemigosBomber[i]->getpY() + 54, 44, 10, 480, 292, 64, 64)) {
                enemigosBomber[i]->setPosY(228);
                enemigosBomber[i]->moverse(*Personaje1);
                Personaje1->Recibir_Daño(*enemigosBomber[i]);
            }
            else if (colision(enemigosBomber[i]->getpX() + 10, enemigosBomber[i]->getpY(), 44, 10, 480, 292, 64, 64)) {
                enemigosBomber[i]->setPosY(356);
                enemigosBomber[i]->moverse(*Personaje1);
                Personaje1->Recibir_Daño(*enemigosBomber[i]);
            }
            else {
                enemigosBomber[i]->moverse(*Personaje1);
            }
        }
        else {
            enemigosBomber[i]->setPosX(-3000.00f);
            enemigosBomber[i]->setPosY(-3000.00f);
        }
        posicionEnemigosBomber[i].first = enemigosBomber[i]->getpX();
        posicionEnemigosBomber[i].second = enemigosBomber[i]->getpY();
    }

}
void MapaModel::movimientoEnemigosEnemigos() {
    for (int i = 0;i < enemigosMelee.size();i++) {
        if (enemigosMelee[i]->getVivo()) {
            for (int j = 0;j < enemigosMelee.size();j++) {
                //std::cout << enemigosMelee[i]->getpX() << " " << enemigosMelee[i]->getpY()<<" ";
                if (i != j && enemigosMelee[i]->colision(*enemigosMelee[j])) {
                    enemigosMelee[i]->rebotar(*enemigosMelee[j]);
                }
            }

            for (int j = 0;j < enemigosBomber.size();j++) {
                if (enemigosMelee[i]->colision(*enemigosBomber[j])) {
                    enemigosMelee[i]->rebotar(*enemigosBomber[j]);
                }
            }
            for (int j = 0;j < enemigosRanged.size();j++) {
                if (enemigosMelee[i]->colision(*enemigosRanged[j])) {
                    enemigosMelee[i]->rebotar(*enemigosRanged[j]);
                }
            }
        }
    }

    for (int i = 0;i < enemigosRanged.size();i++) {
        if (enemigosRanged[i]->getVivo()) {
            for (int j = 0;j < enemigosRanged.size();j++) {
                if (i != j && enemigosRanged[i]->colision(*enemigosRanged[j])) {
                    enemigosRanged[i]->rebotar(*enemigosRanged[j]);
                }
            }

            for (int j = 0;j < enemigosMelee.size();j++) {
                if (enemigosRanged[i]->colision(*enemigosMelee[j])) {
                    enemigosRanged[i]->rebotar(*enemigosMelee[j]);
                }
            }

            for (int j = 0;j < enemigosBomber.size();j++) {
                if (enemigosRanged[i]->colision(*enemigosBomber[j])) {
                    enemigosRanged[i]->rebotar(*enemigosBomber[j]);
                }
            }
        }
    }

    for (int i = 0;i < enemigosBomber.size();i++) {
        if (enemigosBomber[i]->getVivo()) {
            for (int j = 0;j < enemigosBomber.size();j++) {
                if (i != j && enemigosBomber[i]->colision(*enemigosBomber[j])) {
                    enemigosBomber[i]->rebotar(*enemigosBomber[j]);
                }
            }
            for (int j = 0;j < enemigosMelee.size();j++) {
                if (enemigosBomber[i]->colision(*enemigosMelee[j])) {
                    enemigosBomber[i]->rebotar(*enemigosMelee[j]);
                }
            }
            for (int j = 0;j < enemigosRanged.size();j++) {
                if (enemigosBomber[i]->colision(*enemigosRanged[j])) {
                    enemigosBomber[i]->rebotar(*enemigosRanged[j]);
                }
            }
        }
    }
}
void MapaModel::colisionEnemigo() {
    for (int y = 0; y < FILAS * 4; y++) {
        for (int x = 0; x < COLUMNAS * 4; x++) {
            float posX = x * 64 + posicionX;
            float posY = y * 64 + posicionY;
            for (int p = 0; p < enemigosMelee.size(); p++) {
                if (enemigosMelee[p]->getVivo()) {
                    if (mapaCompleto[y][x] == 0) {

                        if (colision(posX + 54, posY + 10, 10, 44, *enemigosMelee[p])) {
                            enemigosMelee[p]->sumarPosX(posX + 64 - enemigosMelee[p]->getpX());
                        }


                        if (colision(posX, posY + 10, 10, 44, *enemigosMelee[p])) {
                            enemigosMelee[p]->restarPosX(enemigosMelee[p]->getpX() + 64 - posX);
                        }

                        if (colision(posX + 10, posY + 54, 44, 10, *enemigosMelee[p])) {
                            enemigosMelee[p]->sumarPosY(posY + 60 - enemigosMelee[p]->getpY());
                        }

                        if (colision(posX + 10, posY, 44, 10, *enemigosMelee[p])) {
                            enemigosMelee[p]->restarPosY(enemigosMelee[p]->getpY() + 4 + 64 - posY);
                        }

                    }
                }
            }

            for (int p = 0; p < enemigosRanged.size(); p++) {
                if (enemigosRanged[p]->getVivo()) {
                    if (mapaCompleto[y][x] == 0) {
                        if (colision(posX + 54, posY + 10, 10, 44, *enemigosRanged[p])) {
                            enemigosRanged[p]->sumarPosX(posX + 64 - enemigosRanged[p]->getpX());
                        }
                        if (colision(posX, posY + 10, 10, 44, *enemigosRanged[p])) {
                            enemigosRanged[p]->restarPosX(enemigosRanged[p]->getpX() + 64 - posX);
                        }
                        if (colision(posX + 10, posY + 54, 44, 10, *enemigosRanged[p])) {
                            enemigosRanged[p]->sumarPosY(posY + 60 - enemigosRanged[p]->getpY());
                        }
                        if (colision(posX + 10, posY, 44, 10, *enemigosRanged[p])) {
                            enemigosRanged[p]->restarPosY(enemigosRanged[p]->getpY() + 4 + 64 - posY);
                        }
                    }
                }
            }
            for (int p = 0; p < enemigosBomber.size(); p++) {
                if (enemigosBomber[p]->getVivo()) {
                    if (mapaCompleto[y][x] == 0) {
                        if (colision(posX + 54, posY + 10, 10, 44, *enemigosBomber[p])) {
                            enemigosBomber[p]->sumarPosX(posX + 64 - enemigosBomber[p]->getpX());
                        }
                        if (colision(posX, posY + 10, 10, 54, *enemigosBomber[p])) {
                            enemigosBomber[p]->restarPosX(enemigosBomber[p]->getpX() + 64 - posX);
                        }
                        if (colision(posX + 10, posY + 54, 44, 10, *enemigosBomber[p])) {
                            enemigosBomber[p]->sumarPosY(posY + 60 - enemigosBomber[p]->getpY());
                        }
                        if (colision(posX + 10, posY, 44, 10, *enemigosBomber[p])) {
                            enemigosBomber[p]->restarPosY(enemigosBomber[p]->getpY() + 4 + 64 - posY);
                        }
                    }
                }
            }

        }
    }
}
void MapaModel::colisionProyectilEnemigo(const std::vector<std::tuple<float, float, bool>>& posiciones) {
    for (const auto& posicion : posiciones) {
        {
            for (size_t j = 0; j < enemigosMelee.size(); j++) {
                enemigosMelee[j]->colisionProyectil(std::get<0>(posicion), std::get<1>(posicion));
            }
        }
    }
    for (const auto& posicion : posiciones) {
        //if (std::get<2>(posicion) == true) 
        {
            for (size_t j = 0; j < enemigosRanged.size(); j++) {
                enemigosRanged[j]->colisionProyectil(std::get<0>(posicion), std::get<1>(posicion));
            }
        }
    }
    for (const auto& posicion : posiciones) {
        //if (std::get<2>(posicion) == true) 
        {
            for (size_t j = 0; j < enemigosBomber.size(); j++) {
                enemigosBomber[j]->colisionProyectil(std::get<0>(posicion), std::get<1>(posicion));
            }
        }
    }
}