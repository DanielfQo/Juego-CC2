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
    std::unique_ptr<EntidadViewer> Personaje1;
    std::unique_ptr<MapaViewer> Mapa;
    std::vector<std::unique_ptr<Boton>> botones;  
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
    void updateVentana(const sf::Event::KeyEvent& keyevent) {
        Personaje1->movimientoEntidad(keyevent);
    }
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

class VentanaJuego :public Menu{

public:
    VentanaJuego();
    ~VentanaJuego() = default;
    void mostrarMenu(sf::RenderWindow&) override;
};

