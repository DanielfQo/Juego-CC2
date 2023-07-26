#include "Viewer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

const int tamPersonajes = 3;

Viewer::Viewer()  {
	ventana.create(sf::VideoMode(1024, 640), "Floppa War", sf::Style::Close);
    ventana.setFramerateLimit(50);
}

bool Viewer::ventanaCerrada() {
	return ventana.isOpen();
}

void Viewer::actualizarVentana() {
    ventana.clear();
    tipoMenu->mostrarMenu(ventana);
    ventana.display();
}
void Viewer::manejarEventos() {
    sf::Event event;
    while (ventana.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            ventana.close();
        
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i coordMouse(event.mouseButton.x, event.mouseButton.y);
                if (typeid(*tipoMenu) == typeid(VentanaJuego)) {
                    updateJuego(coordMouse);
                }
                
                updateMenu(coordMouse);
                
            }
        }
        if (typeid(*tipoMenu) == typeid(VentanaJuego)) {
            if (event.type == sf::Event::KeyPressed) {
                tipoMenu->eventoMovimientoPress(event.key);
            }
            else if (event.type == sf::Event::KeyReleased) {
                tipoMenu->eventoMovimientoRele(event.key);
            }
        }
    }
}

void Viewer::updateMenu(sf::Vector2i coordMouse) {
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
    else if (nombre == "Singleplayer" || nombre == "Anterior" || nombre == "Siguiente") {
        int id = tipoMenu->getIDPersonaje1();

        if (nombre == "Anterior" && id > 0)
            id--;
        else if (nombre == "Siguiente" && id < tamPersonajes - 1)
            id++;

        tipoMenu = std::make_unique<SeleccionPersonajeSingle>(id);
    }
    else if (nombrePersonaje == "NombreFloppa" || nombrePersonaje == "NombreSogga" || nombrePersonaje == "NombreJinx") {
        int idPersonaje = 0;

        if (nombrePersonaje == "NombreSogga")
            idPersonaje = 1;
        else if (nombrePersonaje == "NombreJinx")
            idPersonaje = 2;

        tipoMenu = std::make_unique<VentanaJuego>(idPersonaje);
    }
    else if (nombre == "Multiplayer" || nombre == "Anterior1" || nombre == "Siguiente1" || nombre == "Anterior2" || nombre == "Siguiente2") {
        int id1 = tipoMenu->getIDPersonaje1();
        int id2 = tipoMenu->getIDPersonaje2();

        if (nombre == "Anterior1" && id1 > 0)
            id1--;
        else if (nombre == "Siguiente1" && id1 < tamPersonajes - 1)
            id1++;
        else if (nombre == "Anterior2" && id2 > 0)
            id2--;
        else if (nombre == "Siguiente2" && id2 < tamPersonajes - 1)
            id2++;

        tipoMenu = std::make_unique<SeleccionPersonajeMulti>(id1, id2);
    }
}
void Viewer::updateJuego(sf::Vector2i coordMouse) {
    float x = static_cast<float>(coordMouse.x);
    float y = static_cast<float>(coordMouse.y);
    tipoMenu->PersonajeAtaque(x,y);
}
void Viewer::actualizarMapa(float x, float y) {
    tipoMenu->setPosicionMapa(x, y);
}
void Viewer::actualizarEnemigos(const std::vector<std::pair<float, float>>& posicion) {
    tipoMenu->setPosicionEnemigos(posicion);
}