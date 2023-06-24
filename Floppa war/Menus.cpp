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


MenuJugar::MenuJugar() {
	Boton singleplayer("Singleplayer", { 350,80 }, { 300,80 });
	Boton multiplayer("Multiplayer", { 350,230 }, { 300,80 });
	Boton regresar("Regresar", { 0,0 }, { 50,50 });
	agregarBoton(regresar);
	agregarBoton(singleplayer);
	agregarBoton(multiplayer);
	
}
void MenuJugar::mostrarMenu(sf::RenderWindow& window) {
	dibujarBotones(window);
}

MenuConfiguraciones::MenuConfiguraciones() {
	Boton cancelar("Cancelar", { 100,550 }, { 300,80 });
	Boton aceptar("Aceptar", { 500,550 }, { 300,80 });
	Boton regresar("Regresar", { 0,0 }, { 50,50 });
	agregarBoton(regresar);
	agregarBoton(cancelar);
	agregarBoton(aceptar);
}
void MenuConfiguraciones::mostrarMenu(sf::RenderWindow& window) {
	dibujarBotones(window);
}
MenuTutorial::MenuTutorial() {
	Boton regresar("Regresar", { 0,0 }, { 50,50 });
	agregarBoton(regresar);
}
void MenuTutorial::mostrarMenu(sf::RenderWindow& window) {
	dibujarBotones(window);
}