#include <iostream>
#include <vector>
#include "EntidadModel.h"
#include "EnemigoModel.h"
#include "PersonajeModel.h"

class MapaModel{
    private:
        //generacion mapa
        int FILAS = 20;
        int COLUMNAS = 32;
        int GENERACIONES = 2;
        int semilla = 0;
        //movimiento del mapa
        float velocidadX = 0.00f;
        float velocidadY = 0.00f;
        float posicionX = 0.00f;
        float posicionY = 0.00f;
        const float aceleracion = 0.50f;
        const float desaceleracion = 0.25f;
        const float velocidadMaxima = 5.00f;
        
        std::vector<std::vector<int>> mapai;
        std::vector<std::vector<int>> cuartos;
        std::vector<std::vector<int>> mapaCompleto;
        int cantEnemigos = 5;

        std::unique_ptr<EntidadModel> Personaje1;

        std::vector<std::unique_ptr<EntidadModel>> enemigosMelee;
        std::vector<std::pair<float,float>> posicionEnemigosMelee;

        std::vector<std::unique_ptr<EntidadModel>> enemigosRanged;
        std::vector<std::pair<float, float>> posicionEnemigosRanged;

        std::vector<std::unique_ptr<EntidadModel>> enemigosBomber;
        std::vector<std::pair<float, float>> posicionEnemigosBomber;

    public:
        MapaModel();
        std::vector<std::vector<int>> getMapa1(){return mapaCompleto;}
        int getFilas(){return FILAS;}
        int getColumnas(){return COLUMNAS;}
        float getPosicionX() {return posicionX;}
        float getPosicionY() {return posicionY;}
        std::vector<std::pair<float, float>> getPosicionEnemigoMelee() { return posicionEnemigosMelee; }
        std::vector<std::pair<float, float>> getPosicionEnemigoRanged() { return posicionEnemigosRanged; }
        std::vector<std::pair<float, float>> getPosicionEnemigoBomber() { return posicionEnemigosBomber; }
        void moverMapa(bool[4]);
        void imprimirMapa();
        void aplicarReglas();
        bool colisionMapa(float, float, float, float, float, float, float, float);
        void generar_campo();
        void generarCuartos();
        void generarMapaCompleto();
        void generar_entidades();
        void movimientoEnemigosPersonaje();
        void movimientoEnemigosEnemigos();
        void colisionEnemigo();
        void colisionProyectilEnemigo(const std::vector<std::tuple<float, float, bool>>&);
};