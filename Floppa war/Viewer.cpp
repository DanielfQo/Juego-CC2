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
void Viewer::updateMenu(sf::Vector2i coordMouse){
    std::string nombre = tipoMenu->botonPresionado(coordMouse);
    if (nombre == "Regresar")
        tipoMenu = std::make_unique<MenuInicio>();
    else if (nombre == "Jugar") 
        tipoMenu = std::make_unique<MenuJugar>();
    else if (nombre == "Configuracion") 
        tipoMenu = std::make_unique<MenuConfiguraciones>();
    else if (nombre == "Tutorial")
        tipoMenu = std:: make_unique<MenuTutorial>();
    else if(nombre=="Salir")
        ventana.close();
    else if(nombre=="Singleplayer")
        tipoMenu = std::make_unique<VentanaJuego>();
    else if (nombre == "Multiplayer") {
        tipoMenu = std::make_unique<VentanaJuego>();

    }
        

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
                tipoMenu->updateVentana(event.key);
            }
        }
        ventana.clear();
        
        tipoMenu->mostrarMenu(ventana);
        ventana.display();
    }
}
Viewer::~Viewer(){}