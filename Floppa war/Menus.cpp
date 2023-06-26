#include "Menus.h"
#include "Boton.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

MenuInicio::MenuInicio(){
	texturas.resize(4);
	texturas[0].loadFromFile("BotonJugar.png");
	texturas[1].loadFromFile("BotonConfiguracion.png");
	texturas[2].loadFromFile("BotonTutorial.png");
	texturas[3].loadFromFile("BotonSalir.png");
	Boton jugar("Jugar", sf::Vector2f(144, 352), texturas[0]);
	Boton configuracion("Configuracion", { 144,496 }, texturas[1]);
	Boton tutorial("Tutorial", { 584,352 }, texturas[2]);
	Boton salir("Salir", sf::Vector2f(584, 496), texturas[3]);
	agregarBoton(jugar);
	agregarBoton(configuracion);
	agregarBoton(tutorial);
	agregarBoton(salir);
};
void MenuInicio::mostrarMenu(sf::RenderWindow& window) {
	dibujarBotones(window);
}

MenuJugar::MenuJugar() {
	texturas.resize(3);
	texturas[2].loadFromFile("BotonRegresar.png");
	//Boton singleplayer("Singleplayer", { 350,80 }, "BotonJugar.png");
	//Boton multiplayer("Multiplayer", { 350,230 }, "BotonJugar.png");
	Boton regresar("Regresar", { 0,0 }, texturas[2]);
	agregarBoton(regresar);
	//agregarBoton(singleplayer);
	//agregarBoton(multiplayer);
	
}
void MenuJugar::mostrarMenu(sf::RenderWindow& window) {
	dibujarBotones(window);
}

MenuConfiguraciones::MenuConfiguraciones() {
	sf::Image image;
	if (image.loadFromFile("BotonJugar.png")) {

	}
	/*
	Boton cancelar("Cancelar", { 100,550 }, "BotonJugar.png");
	Boton aceptar("Aceptar", { 500,550 }, "BotonJugar.png");
	Boton regresar("Regresar", { 0,0 }, "BotonJugar.png");
	agregarBoton(regresar);
	agregarBoton(cancelar);
	agregarBoton(aceptar);*/
}
void MenuConfiguraciones::mostrarMenu(sf::RenderWindow& window) {
	dibujarBotones(window);
}
MenuTutorial::MenuTutorial() {
	sf::Image image;
	if (image.loadFromFile("BotonJugar.png")) {

	}
	/*
	Boton regresar("Regresar", { 0,0 }, "BotonJugar.png");
	agregarBoton(regresar);*/
}
void MenuTutorial::mostrarMenu(sf::RenderWindow& window) {
	dibujarBotones(window);
}