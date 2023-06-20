#include <SFML/Graphics.hpp>
#include <iostream>
#include "Boton.h"

int main() {
    
    Boton inicio("Inicio", { 512,120 },{400,100});

    sf::RenderWindow ventana(sf::VideoMode(1024, 640), "Floppa War");


    while (ventana.isOpen())
    {
        sf::Event evento;
        while (ventana.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                ventana.close();
        }
        ventana.clear();
        inicio.dibujarBoton(ventana);
        ventana.display();

    }
    
    

    return 0;
}
