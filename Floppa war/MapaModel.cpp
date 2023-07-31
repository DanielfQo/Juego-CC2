#pragma once
#include<stdlib.h>
#include<time.h>
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
    int posicion2X = std::rand() % 4;
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
                    
                    if (colisionMapa(posX + 54, posY + 10, 10, 44, 480, 292, 64, 64)) {
                        velocidadX = 0;
                        vector[2] = false;
                        posicionX -= (posX + 64 - 480);

                    }
                    if (colisionMapa(posX, posY + 10, 10, 44, 480, 292, 64, 64)) {
                        velocidadX = 0;
                        vector[3] = false;
                        posicionX += (480 + 64 - posX);
                    }
                    if (colisionMapa(posX + 10, posY + 54, 44, 10, 480, 292, 64, 64)) {
                        velocidadY = 0;
                        vector[0] = false;
                        posicionY -= (posY + 64 - 292);
                    }
                    if (colisionMapa(posX + 10, posY, 44, 10, 480, 292, 64, 64)) {
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

bool MapaModel::colisionMapa(float PosX, float PosY,float w, float h, float X, float Y, float width,float height) {
    if (PosX > X + width || PosX + w < X || PosY > Y + height || PosY + h < Y)
        return false;
    else
        return true;
}

void MapaModel::generar_entidades(){
    //////
    for (int i = 0; i < enemigosMelee.size();i++) {
        enemigosMelee[i]->setPosX(i * 200.00f);
        enemigosMelee[i]->setPosY(i * 1.00f);
    }
    //////
    
    for (int i = 0; i < enemigosRanged.size();i++) {
        enemigosRanged[i]->setPosX(posicionX);
        enemigosRanged[i]->setPosY(posicionY);
    }
    //////
    for (int i = 0; i < enemigosBomber.size();i++) {
        enemigosBomber[i]->setPosX(posicionX);
        enemigosBomber[i]->setPosY(posicionY);
    }
    
}
void MapaModel::movimientoEnemigosPersonaje() {

    for (int i = 0;i < enemigosMelee.size();i++) {
        if (enemigosMelee[i]->colision(*Personaje1)) {
            enemigosMelee[i]->rebotar(*Personaje1);
        }
        else {
            enemigosMelee[i]->moverse(*Personaje1);
        }
        posicionEnemigosMelee[i].first = enemigosMelee[i]->getpX();
        posicionEnemigosMelee[i].second = enemigosMelee[i]->getpY();
    }
    //////
    
    for (int i = 0;i < enemigosRanged.size();i++) {
        if (enemigosRanged[i]->colision(*Personaje1)) {
            enemigosRanged[i]->rebotar(*Personaje1);
        }
        else {
            enemigosRanged[i]->moverse(*Personaje1);
        }
        posicionEnemigosRanged[i].first = enemigosRanged[i]->getpX();
        posicionEnemigosRanged[i].second = enemigosRanged[i]->getpY();
    }
    //////
    for (int i = 0;i < enemigosBomber.size();i++) {
        if (enemigosBomber[i]->colision(*Personaje1)) {
            enemigosBomber[i]->rebotar(*Personaje1);
        }
        else {
            enemigosBomber[i]->moverse(*Personaje1);
        }
        //////
        posicionEnemigosBomber[i].first = enemigosBomber[i]->getpX();
        posicionEnemigosBomber[i].second = enemigosBomber[i]->getpY();
    }
    
}
void MapaModel::movimientoEnemigosEnemigos() {
    for (int i = 0;i < enemigosMelee.size();i++) {
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
        
        posicionEnemigosMelee[i].first = enemigosMelee[i]->getpX();
        posicionEnemigosMelee[i].second = enemigosMelee[i]->getpY();
        
    }
    
    for (int i = 0;i < enemigosRanged.size();i++) {

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
        posicionEnemigosRanged[i].first = enemigosRanged[i]->getpX();
        posicionEnemigosRanged[i].second = enemigosRanged[i]->getpY();
    }
    /*
    for (int i = 0;i < enemigosBomber.size();i++) {
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
        posicionEnemigosBomber[i].first = enemigosBomber[i]->getpX();
        posicionEnemigosBomber[i].second = enemigosBomber[i]->getpY();
    }
    */
}
void MapaModel::colisionEnemigo() {
    for (int y = 0; y < FILAS * 4; y++) {
        for (int x = 0; x < COLUMNAS * 4; x++) {
            float posX = x * 64 + posicionX;
            float posY = y * 64 + posicionY;
            for (int p = 0; p < enemigosMelee.size(); p++) {
                if (colisionMapa(posX, posY,64,64, enemigosMelee[p]->getpX(), enemigosMelee[p]->getpY()+4, 64,64) == true && mapaCompleto[y][x] == 0) {
                        enemigosMelee[p]->rebotarPared(posX, posY);
                }
            }
            
            for (int p = 0; p < enemigosRanged.size(); p++) {
                if (colisionMapa(posX, posY, 64, 64, enemigosRanged[p]->getpX(), enemigosRanged[p]->getpY() + 4, 64, 64) == true && mapaCompleto[y][x] == 0) {
                    enemigosRanged[p]->rebotarPared(posX, posY);
                }
            }
            for (int p = 0; p < enemigosBomber.size(); p++) {
                if (colisionMapa(posX, posY, 64, 64, enemigosBomber[p]->getpX(), enemigosBomber[p]->getpY() + 4, 64, 64) == true && mapaCompleto[y][x] == 0) {
                    enemigosBomber[p]->rebotarPared(posX, posY);
                }
            }
            
        }
    }
}