#include "Viewer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

const int tamPersonajes = 3;

Viewer::Viewer() {
	ventana.create(sf::VideoMode(1024, 640), "Floppa War");
    ventana.setFramerateLimit(24);
}
sf::RenderWindow& Viewer::getVentana() {
	return ventana;
}
bool Viewer::ventanaCerrada() {
	return ventana.isOpen();
}
void Viewer::updateMenu(sf::Vector2i coordMouse) {
    std::cout << tipoMenu->getIDPersonaje();
    std::string nombre = tipoMenu->botonPresionado(coordMouse);
    std::string nombrePersonaje = tipoMenu->PersonajePresionado(coordMouse);
    if (nombre == "Regresar")
        tipoMenu = std::make_unique<MenuInicio>();
    else if (nombre == "Jugar")
        tipoMenu = std::make_unique<MenuJugar>();
    else if (nombre == "Configuracion")
        tipoMenu = std::make_unique<MenuConfiguraciones>();
    else if (nombre == "Tutorial")
        tipoMenu = std::make_unique<MenuTutorial>();
    else if (nombre == "Salir")
        ventana.close();
    else if (nombre == "Singleplayer") {
        tipoMenu = std::make_unique<SeleccionPersonajeSingle>(0);
    }
    //////////////////////////////////
    else if (nombre == "Anterior") {
        int id = tipoMenu->getIDPersonaje();
        if (id > 0) {
            id--;
            tipoMenu = std::make_unique<SeleccionPersonajeSingle>(id);
        }
        else
            tipoMenu = std::make_unique<SeleccionPersonajeSingle>(0);
    }
    else if (nombre == "Siguiente") {
        int id = tipoMenu->getIDPersonaje();
        if (id < tamPersonajes-1) {
            id++;
            tipoMenu = std::make_unique<SeleccionPersonajeSingle>(id);
        }
        else 
            tipoMenu = std::make_unique<SeleccionPersonajeSingle>(tamPersonajes-1);
    }
    else if (nombrePersonaje == "NombreFloppa") 
        tipoMenu = std::make_unique<VentanaJuego>(0);
    else if (nombrePersonaje == "NombreSogga")
        tipoMenu = std::make_unique<VentanaJuego>(1);
    else if (nombrePersonaje == "NombreJinx")
        tipoMenu = std::make_unique<VentanaJuego>(2);
    //////////////////////////////////
    else if (nombre == "Multiplayer") 
        tipoMenu = std::make_unique<SeleccionPersonajeMulti>(0,0);
}
void Viewer::dibujarVentana() {
    
    while (ventana.isOpen()) {
        sf::Event event;
        while (ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                ventana.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i coordMouse(event.mouseButton.x, event.mouseButton.y);
                    updateMenu(coordMouse);
                }
            }
            else if (event.type == sf::Event::KeyPressed) {
                tipoMenu->updateJuego1(event.key);
            }
            else if (event.type == sf::Event::KeyReleased) {
                tipoMenu->updateJuego2(event.key);
            }
        }
        ventana.clear();
        tipoMenu->mostrarMenu(ventana);
        ventana.display();
    }
}
Viewer::~Viewer(){}