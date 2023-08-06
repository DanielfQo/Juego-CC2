#include "Viewer.h"
#include <thread>
#include <future>
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
                
                if (typeid(*tipoMenu) == typeid(VentanaJuegoMulti)) {
                    updateJuego(coordMouse);
                }
                updateMenu(coordMouse);
            }
        }
        if (typeid(*tipoMenu) == typeid(VentanaJuego)) {
            bool arriba = false, abajo = false, izquierda = false, derecha = false;
            if (event.type == sf::Event::KeyPressed) {   
                if (event.key.code == sf::Keyboard::C)
                    tipoMenu->cambiarArma();
                if (event.key.code == sf::Keyboard::W)
                    arriba = true;
                else if (event.key.code == sf::Keyboard::S)
                    abajo = true;
                if (event.key.code == sf::Keyboard::A)
                    izquierda = true;
                else if (event.key.code == sf::Keyboard::D)
                    derecha = true;
                tipoMenu->eventoMovimientoPress1(arriba, izquierda,abajo,derecha);
            }
            else if (event.type == sf::Event::KeyReleased) {
                
                if (event.key.code == sf::Keyboard::W)
                    arriba = true;
                else if (event.key.code == sf::Keyboard::S)
                    abajo = true;
                if (event.key.code == sf::Keyboard::A)
                    izquierda = true;
                else if (event.key.code == sf::Keyboard::D)
                    derecha = true;
                tipoMenu->eventoMovimientoRele1(arriba, izquierda, abajo, derecha);
            }
        }
        
        if (typeid(*tipoMenu) == typeid(VentanaJuegoMulti)) {
            std::future<void> future1 = std::async(std::launch::async, [&]() {
                bool arriba = false, abajo = false, izquierda = false, derecha = false;
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::C)
                        tipoMenu->cambiarArma();
                    if (event.key.code == sf::Keyboard::W)
                        arriba = true;
                    else if (event.key.code == sf::Keyboard::S)
                        abajo = true;
                    if (event.key.code == sf::Keyboard::A)
                        izquierda = true;
                    else if (event.key.code == sf::Keyboard::D)
                        derecha = true;
                    tipoMenu->eventoMovimientoPress1(arriba, izquierda, abajo, derecha);
                }
                else if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::W)
                        arriba = true;
                    else if (event.key.code == sf::Keyboard::S)
                        abajo = true;
                    if (event.key.code == sf::Keyboard::A)
                        izquierda = true;
                    else if (event.key.code == sf::Keyboard::D)
                        derecha = true;
                    tipoMenu->eventoMovimientoRele1(arriba, izquierda, abajo, derecha);
                }
                });
            std::future<void> future2 = std::async(std::launch::async, [&]() {
                bool arriba2 = false, abajo2 = false, izquierda2 = false, derecha2 = false;
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Up)
                        arriba2 = true;
                    else if (event.key.code == sf::Keyboard::Left)
                        izquierda2 = true;
                    if (event.key.code == sf::Keyboard::Down)
                        abajo2 = true;
                    else if (event.key.code == sf::Keyboard::Right)
                        derecha2 = true;
                    tipoMenu->eventoMovimientoPress2(arriba2, izquierda2, abajo2, derecha2);
                }
                else if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Up)
                        arriba2 = true;
                    else if (event.key.code == sf::Keyboard::Left)
                        izquierda2 = true;
                    if (event.key.code == sf::Keyboard::Down)
                        abajo2 = true;
                    else if (event.key.code == sf::Keyboard::Right)
                        derecha2 = true;
                    tipoMenu->eventoMovimientoRele2(arriba2, izquierda2, abajo2, derecha2);
                }
            });
            future1.get();
            future2.get();
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
    else if (nombre == "Aceptar" || nombre== "Cancelar")
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

        if (nombre == "Anterior1" && id1 > 0) {
            id1--;
            tipoMenu->setIDPersonaje1(id1);
        }
        else if (nombre == "Siguiente1" && id1 < tamPersonajes - 1) {
            id1++;
            tipoMenu->setIDPersonaje1(id1);
        }
        else if (nombre == "Anterior2" && id2 > 0) {
            id2--;
            tipoMenu->setIDPersonaje2(id2);
        }
        else if (nombre == "Siguiente2" && id2 < tamPersonajes - 1) {
            id2++;
            tipoMenu->setIDPersonaje2(id2);
        }   
        tipoMenu = std::make_unique<SeleccionPersonajeMulti>(id1, id2);
    }
    else if (nombrePersonaje == "NombreFloppa1" || nombrePersonaje == "NombreSogga1" || nombrePersonaje == "NombreJinx1" 
             || nombrePersonaje == "NombreFloppa2" || nombrePersonaje == "NombreSogga2" || nombrePersonaje == "NombreJinx2") {

        tipoMenu = std::make_unique<VentanaJuegoMulti>(tipoMenu->getIDPersonaje1(), tipoMenu->getIDPersonaje2());
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
void Viewer::actualizarEnemigosMelee(const std::vector<std::pair<float, float>>& posicion) {
    tipoMenu->setPosicionEnemigosMelee(posicion);
}
void Viewer::actualizarEnemigosRanged(const std::vector<std::pair<float, float>>& posicion) {
    tipoMenu->setPosicionEnemigosRanged(posicion);
}
void Viewer::actualizarEnemigosBomber(const std::vector<std::pair<float, float>>& posicion) {
    tipoMenu->setPosicionEnemigosBomber(posicion);
}
void Viewer::actualizarVidaPersonaje1(float vida) {
    tipoMenu->setVidaPersonaje1(static_cast<int>(vida));
    if (vida <= 0) {
        tipoMenu = std::make_unique<MenuFinJuego>();
    }
}
