#include "Menus.h"
#include "Boton.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

MenuInicio::MenuInicio() {
	std::unique_ptr<Boton> jugar = std::make_unique<Boton>("Jugar", sf::Vector2f(144, 352), "BotonJugar.png");
	std::unique_ptr<Boton> configuracion = std::make_unique<Boton>("Configuracion", sf::Vector2f(144, 496), "BotonConfiguracion.png");
	std::unique_ptr<Boton> tutorial = std::make_unique<Boton>("Tutorial", sf::Vector2f(584, 352), "BotonTutorial.png");
	std::unique_ptr<Boton> salir = std::make_unique<Boton>("Salir", sf::Vector2f(584, 496), "BotonSalir.png");
	botones.push_back(std::move(jugar));
	botones.push_back(std::move(configuracion));
	botones.push_back(std::move(tutorial));
	botones.push_back(std::move(salir));
}

void MenuInicio::mostrarMenu(sf::RenderWindow& window) {
	dibujarBotones(window);
}

MenuJugar::MenuJugar() {
	std::unique_ptr<Boton> singleplayer = std::make_unique<Boton>("Singleplayer", sf::Vector2f(350, 80), "BotonJugar.png");
	std::unique_ptr<Boton> multiplayer = std::make_unique<Boton>("Multiplayer", sf::Vector2f(350, 230), "BotonJugar.png");
	std::unique_ptr<Boton> regresar = std::make_unique<Boton>("Regresar", sf::Vector2f(0, 0), "BotonRegresar.png");
	botones.push_back(std::move(singleplayer));
	botones.push_back(std::move(multiplayer));
	botones.push_back(std::move(regresar));
}
void MenuJugar::mostrarMenu(sf::RenderWindow& window) {
	dibujarBotones(window);
}

MenuConfiguraciones::MenuConfiguraciones() {
	std::unique_ptr<Boton> cancelar = std::make_unique<Boton>("Cancelar", sf::Vector2f(100, 550), "BotonJugar.png");
	std::unique_ptr<Boton> aceptar = std::make_unique<Boton>("Aceptar", sf::Vector2f(500, 550), "BotonJugar.png");
	std::unique_ptr<Boton> regresar = std::make_unique<Boton>("Regresar", sf::Vector2f(0, 0), "BotonRegresar.png");
	botones.push_back(std::move(cancelar));
	botones.push_back(std::move(aceptar));
	botones.push_back(std::move(regresar));
}
void MenuConfiguraciones::mostrarMenu(sf::RenderWindow& window) {
	dibujarBotones(window);
}
MenuTutorial::MenuTutorial() {
	std::unique_ptr<Boton> regresar = std::make_unique<Boton>("Regresar", sf::Vector2f(0, 0), "BotonRegresar.png");
	botones.push_back(std::move(regresar));
}
void MenuTutorial::mostrarMenu(sf::RenderWindow& window) {
	dibujarBotones(window);
}