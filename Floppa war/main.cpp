
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <iostream>
#include "Viewer.h"
#include "Boton.h"

int main() {
    
    Viewer vista;
    vista.dibujarVentana();
    /*
    Boton jugar("Jugar", { 350,80 }, "BotonJugar.png");
    sf::RenderWindow window(sf::VideoMode(1600, 800), "Ventana SFML");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        jugar.dibujarBoton(window);
        window.display();
    }
    */
    
    return 0;
}

