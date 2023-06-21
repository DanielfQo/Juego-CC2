#include "Viewer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Viewer::Viewer() {
	ventana.create(sf::VideoMode(1024, 640), "Floppa War");
    ventana.setFramerateLimit(60);
}
sf::RenderWindow& Viewer::getVentana() {
	return ventana;
}
bool Viewer::ventanaCerrada() {
	return ventana.isOpen();
}
void Viewer::updateMenu() {
    delete tipoMenu;  
    tipoMenu = new MenuInicio();
}
void Viewer::dibujarVentana() {
    updateMenu();
    while (ventana.isOpen()) {
        sf::Event event;
        while (ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                ventana.close();
        }
        ventana.clear();
        tipoMenu->mostrarMenu(ventana);
        ventana.display();
    }
}
Viewer::~Viewer(){
    delete tipoMenu;
}