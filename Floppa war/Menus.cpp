#include "Menus.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

MenuInicio::MenuInicio(){
	Boton jugar("Jugar", { 350,80 }, { 300,80 });
	Boton configuracion("Configuracion", { 350,230 }, { 300,80 });
	Boton tutorial("Tutorial", { 350,380 }, { 300,80 });
	Boton salir("Salir", { 350,530 }, { 300,80 });
	agregarBoton(jugar);
	agregarBoton(configuracion);
	agregarBoton(tutorial);
	agregarBoton(salir);
};
void MenuInicio::mostrarMenu(sf::RenderWindow& window) {
	
	dibujarBotones(window);
}
MenuInicio::~MenuInicio(){}