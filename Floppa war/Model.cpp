#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <memory>
#include "Model.h"

Model::Model() {}


// Suponiendo que MapaModel y otros encabezados relevantes se proporcionan en MapaModel.h

void Model::generarMapa() {
    if (idmapa == 1) {
        maparef = std::make_unique<MapaModel>();

        // Iniciar un hilo asíncrono para generar el mapa y las entidades
        std::future<void> mapaFuture = std::async(std::launch::async, [this]() {
            maparef->generarCuartos();
            maparef->generarMapaCompleto();
            maparef->imprimirMapa();
            maparef->generar_entidades();
            });

        // El hilo principal continúa ejecutándose mientras el mapa se genera en segundo plano

        mapaFuture.get(); // Esperar a que el hilo del mapa termine antes de continuar.
        idmapa++;
    }
}
void Model::actualizarMapa(bool direccion[4]) { 
    maparef->moverMapa(direccion);
}

void Model::actualizarPosicionEnemigos() {
    maparef->movimientoEnemigosPersonaje();
    maparef->movimientoEnemigosEnemigos();
    maparef->colisionEnemigo();
}

void Model::actualizarPosicionProyectiles(const std::vector<std::tuple<float, float, bool>>& posicionesProyectil){
    maparef->colisionProyectilEnemigo(posicionesProyectil);
}

