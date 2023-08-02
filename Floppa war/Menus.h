#pragma once
#include <SFML/Graphics.hpp>
#include "Boton.h"
#include "EntidadViewer.h"
#include "MapaViewer.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Menu {
protected:
    sf::Texture fondoTexture;
    sf::Sprite fondoSprite;

    std::unique_ptr<EntidadViewer> Personaje1;
    std::vector<std::unique_ptr<EntidadViewer>> enemigosMelee;
    std::vector<std::unique_ptr<EntidadViewer>> enemigosRanged;
    std::vector<std::unique_ptr<EntidadViewer>> enemigosBomber;
    std::unique_ptr<MapaViewer> Mapa;
    std::vector<std::unique_ptr<Boton>> botones;
    std::vector<std::unique_ptr<Boton>> seleccionPersonaje;
    std::vector<std::vector<int>> mapaGenerado;
    
    bool direccion[4];

    int idPersonaje1 = 0;
    int idPersonaje2 = 1;
    const int cantEnemigos = 5;
public:
    virtual void mostrarMenu(sf::RenderWindow&) = 0;
    
    void actualizarDireccion() {
        direccion[0] = Personaje1->getMueveArriba();
        direccion[1] = Personaje1->getMueveAbajo();
        direccion[2] = Personaje1->getMueveIzquierda();
        direccion[3] = Personaje1->getMueveDerecha();
    }
    bool* getDireccion() {return direccion;}

    void setPosicionMapa(float x, float y) {
        Mapa->setPosicion(x, y);
    }

    void setPosicionEnemigosMelee(const std::vector<std::pair<float, float>>& posicion) {
        for (int i = 0;i < posicion.size();i++) {
            enemigosMelee[i]->setPosicion(posicion[i].first, posicion[i].second);
        }
    }
    void setPosicionEnemigosRanged(const std::vector<std::pair<float, float>>& posicion) {
        for (int i = 0;i < posicion.size();i++) {
            enemigosRanged[i]->setPosicion(posicion[i].first, posicion[i].second);
        }
    }
    void setPosicionEnemigosBomber(const std::vector<std::pair<float, float>>& posicion) {
        for (int i = 0;i < posicion.size();i++) {
            enemigosBomber[i]->setPosicion(posicion[i].first, posicion[i].second);
        }
    }

    void dibujarBotones(sf::RenderWindow& window) {
        for (const auto& boton : botones) {
            boton->dibujarBoton(window);  
        }
    }
    std::string botonPresionado(sf::Vector2i coordMouse) {
        for (const auto& boton : botones) {
            boton->estaPresionado(coordMouse);  
            if (boton->getPresionado()) {
                return boton->getTexto();
            }
        }
        return "";
    }

    std::string PersonajePresionado(sf::Vector2i coordMouse) {
        for (const auto& boton : seleccionPersonaje) {
            if (boton->getDibujado()) {
                boton->estaPresionado(coordMouse);
                if (boton->getPresionado()) {
                    return boton->getTexto();
                }
            }
        }
        return "";
    }

    void eventoMovimientoPress(const sf::Event::KeyEvent& keyevent) {
        Personaje1->movimientoEntidadPress(keyevent);
    }
    void eventoMovimientoRele(const sf::Event::KeyEvent& keyevent) {
        Personaje1->movimientoEntidadRele(keyevent);
    }
    void PersonajeAtaque(float x , float y) {
        Personaje1->Atacar(x, y);
    }
    std::vector<std::tuple<float, float, bool>> getPosicionesProyectiles() {
        return Personaje1->getPosicionesProyectiles();
    }

    void setMapa(std::vector<std::vector<int>> m) { Mapa->setMapa(m); }
    int getIDPersonaje1() {return idPersonaje1;}
    int getIDPersonaje2() {return idPersonaje2;}
};

class MenuInicio:public Menu{
public:
	MenuInicio();
	~MenuInicio() = default;
	void mostrarMenu(sf::RenderWindow&) override;
};

class MenuJugar:public Menu {
public:
	MenuJugar();
	~MenuJugar() = default;
	void mostrarMenu(sf::RenderWindow&) override;
};

class MenuConfiguraciones:public Menu {
public:
	MenuConfiguraciones();
	~MenuConfiguraciones() = default;
	void mostrarMenu(sf::RenderWindow&) override;
};
class MenuTutorial:public Menu {
public:
	MenuTutorial();
	~MenuTutorial() = default;
	void mostrarMenu(sf::RenderWindow&) override;
};

class SeleccionPersonajeSingle :public Menu {

public:
    SeleccionPersonajeSingle(int);
    ~SeleccionPersonajeSingle() = default;
    void mostrarMenu(sf::RenderWindow&) override;
    void dibujarBotonSeleccionPersonaje(sf::RenderWindow&);

};

class SeleccionPersonajeMulti :public Menu {

public:
    SeleccionPersonajeMulti(int,int);
    ~SeleccionPersonajeMulti() = default;
    void mostrarMenu(sf::RenderWindow&) override;
    void dibujarBotonSeleccionPersonaje(sf::RenderWindow&);

};

class VentanaJuego :public Menu{

public:
    VentanaJuego(int);
    ~VentanaJuego() = default;
    void mostrarMenu(sf::RenderWindow&) override;
};


