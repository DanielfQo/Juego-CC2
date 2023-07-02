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

    int idPersonaje1 = 0;
    int idPersonaje2 = 1;
public:
    virtual void mostrarMenu(sf::RenderWindow&) = 0;
    

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

    void updateJuego1(const sf::Event::KeyEvent& keyevent) {
        Personaje->movimientoEntidad1(keyevent);
    }void updateJuego2(const sf::Event::KeyEvent& keyevent) {
        Personaje->movimientoEntidad2(keyevent);
    }
    int getIDPersonaje() {return idPersonaje1;}
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


