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
    std::unique_ptr<EntidadViewer> Personaje;
    std::unique_ptr<MapaViewer> Mapa;
    std::vector<std::unique_ptr<Boton>> botones;
    std::vector<std::unique_ptr<Boton>> seleccionPersonaje;

    bool direccion[4];

    int idPersonaje1 = 0;
    int idPersonaje2 = 1;
public:
    virtual void mostrarMenu(sf::RenderWindow&) = 0;
    
    void actualizarDireccion() {
        direccion[0] = Personaje->getMueveArriba();
        direccion[1] = Personaje->getMueveAbajo();
        direccion[2] = Personaje->getMueveIzquierda();
        direccion[3] = Personaje->getMueveDerecha();
    }
    bool* getDireccion() {return direccion;}

    void setPosicionMapa(float x, float y) {
        Mapa->setPosicion(x, y);
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
        Personaje->movimientoEntidadPress(keyevent);
    }
    void eventoMovimientoRele(const sf::Event::KeyEvent& keyevent) {
        Personaje->movimientoEntidadRele(keyevent);
    }
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


