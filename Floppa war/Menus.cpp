#include "Menus.h"
#include "Boton.h"
#include "EntidadViewer.h"
#include "EnemigoViewer.h"
#include "MapaViewer.h"
#include "PersonajesViewer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
const int cantidadPersonajes = 3;
///////////////////////////
MenuInicio::MenuInicio() {
	fondoTexture.loadFromFile("Imagenes/FondoJuego.png");
	fondoSprite.setTexture(fondoTexture);

	std::unique_ptr<Boton> jugar = std::make_unique<Boton>("Jugar", sf::Vector2f(144, 352), "Imagenes/BotonJugar.png");
	std::unique_ptr<Boton> configuracion = std::make_unique<Boton>("Configuracion", sf::Vector2f(144, 496), "Imagenes/BotonConfiguracion.png");
	std::unique_ptr<Boton> tutorial = std::make_unique<Boton>("Tutorial", sf::Vector2f(584, 352), "Imagenes/BotonTutorial.png");
	std::unique_ptr<Boton> salir = std::make_unique<Boton>("Salir", sf::Vector2f(584, 496), "Imagenes/BotonSalir.png");
	botones.push_back(std::move(jugar));
	botones.push_back(std::move(configuracion));
	botones.push_back(std::move(tutorial));
	botones.push_back(std::move(salir));

}
void MenuInicio::mostrarMenu(sf::RenderWindow& window) {
	window.draw(fondoSprite);
	dibujarBotones(window);
}
///////////////////////////
MenuJugar::MenuJugar() {
	fondoTexture.loadFromFile("Imagenes/FondoJuego.png");
	fondoSprite.setTexture(fondoTexture);
	std::unique_ptr<Boton> singleplayer = std::make_unique<Boton>("Singleplayer", sf::Vector2f(364, 352), "Imagenes/BotonSingleplayer.png");
	std::unique_ptr<Boton> multiplayer = std::make_unique<Boton>("Multiplayer", sf::Vector2f(364, 496), "Imagenes/BotonMultiplayer.png");
	std::unique_ptr<Boton> regresar = std::make_unique<Boton>("Regresar", sf::Vector2f(4, 4), "Imagenes/BotonRegresar.png");
	botones.push_back(std::move(singleplayer));
	botones.push_back(std::move(multiplayer));
	botones.push_back(std::move(regresar));
}
void MenuJugar::mostrarMenu(sf::RenderWindow& window) {
	window.draw(fondoSprite);
	dibujarBotones(window);
}
///////////////////////////
MenuConfiguraciones::MenuConfiguraciones() {
	fondoTexture.loadFromFile("Imagenes/FondoJuego.png");
	fondoSprite.setTexture(fondoTexture);

	std::unique_ptr<Boton> cancelar = std::make_unique<Boton>("Cancelar", sf::Vector2f(144, 496), "Imagenes/BotonCancelar.png");
	std::unique_ptr<Boton> aceptar = std::make_unique<Boton>("Aceptar", sf::Vector2f(584, 496), "Imagenes/BotonAceptar.png");
	std::unique_ptr<Boton> regresar = std::make_unique<Boton>("Regresar", sf::Vector2f(4, 4), "Imagenes/BotonRegresar.png");
	botones.push_back(std::move(cancelar));
	botones.push_back(std::move(aceptar));
	botones.push_back(std::move(regresar));
}
void MenuConfiguraciones::mostrarMenu(sf::RenderWindow& window) {
	window.draw(fondoSprite);
	dibujarBotones(window);
}
///////////////////////////
MenuTutorial::MenuTutorial() {
	fondoTexture.loadFromFile("Imagenes/FondoJuego.png");
	fondoSprite.setTexture(fondoTexture);
	tutoTexture.loadFromFile("Imagenes/Tutorial.png");
	tutoSprite.setTexture(tutoTexture);
	tutoSprite.setPosition(212.00f, 20.00f);
	std::unique_ptr<Boton> regresar = std::make_unique<Boton>("Regresar", sf::Vector2f(4, 4), "Imagenes/BotonRegresar.png");
	botones.push_back(std::move(regresar));
}
void MenuTutorial::mostrarMenu(sf::RenderWindow& window) {
	window.draw(fondoSprite);
	window.draw(tutoSprite);
	dibujarBotones(window);
}
///////////////////////////
SeleccionPersonajeSingle::SeleccionPersonajeSingle(int selecPersonaje) {
	fondoTexture.loadFromFile("Imagenes/FondoJuego.png");
	fondoSprite.setTexture(fondoTexture);
	idPersonaje1 = selecPersonaje;
	
	std::unique_ptr<Boton> regresar = std::make_unique<Boton>("Regresar", sf::Vector2f(4, 4), "Imagenes/BotonRegresar.png");

	std::unique_ptr<Boton> anterior = std::make_unique<Boton>("Anterior", sf::Vector2f(324, 516), "Imagenes/BotonAnterior.png");
	std::unique_ptr<Boton> siguiente = std::make_unique<Boton>("Siguiente", sf::Vector2f(668, 516), "Imagenes/BotonSiguiente.png");

	std::unique_ptr<Boton> NombreFloppa = std::make_unique<Boton>("NombreFloppa", sf::Vector2f(364, 496), "Imagenes/NombreFloppa.png");
	std::unique_ptr<Boton> NombreSogga = std::make_unique<Boton>("NombreSogga", sf::Vector2f(364, 496), "Imagenes/NombreSogga.png");
	std::unique_ptr<Boton> NombreJinx = std::make_unique<Boton>("NombreJinx", sf::Vector2f(364, 496), "Imagenes/NombreJinx.png");
	botones.push_back(std::move(regresar));
	botones.push_back(std::move(anterior));
	botones.push_back(std::move(siguiente));
	seleccionPersonaje.push_back(std::move(NombreFloppa));
	seleccionPersonaje.push_back(std::move(NombreSogga));
	seleccionPersonaje.push_back(std::move(NombreJinx));
}
void SeleccionPersonajeSingle::mostrarMenu(sf::RenderWindow& window) {
	window.draw(fondoSprite);
	dibujarBotones(window);
	dibujarBotonSeleccionPersonaje(window);
}
void SeleccionPersonajeSingle::dibujarBotonSeleccionPersonaje(sf::RenderWindow& window) {
	seleccionPersonaje[idPersonaje1]->dibujarBoton(window);
}
///////////////////////////
SeleccionPersonajeMulti::SeleccionPersonajeMulti(int selecPersonaje1, int selecPersonaje2) {
	fondoTexture.loadFromFile("Imagenes/FondoJuego.png");
	fondoSprite.setTexture(fondoTexture);
	idPersonaje1 = selecPersonaje1;
	idPersonaje2 = selecPersonaje2;

	std::unique_ptr<Boton> regresar = std::make_unique<Boton>("Regresar", sf::Vector2f(4, 4), "Imagenes/BotonRegresar.png");

	std::unique_ptr<Boton> anterior1 = std::make_unique<Boton>("Anterior1", sf::Vector2f(104, 516), "Imagenes/BotonAnterior.png");
	std::unique_ptr<Boton> siguiente1 = std::make_unique<Boton>("Siguiente1", sf::Vector2f(448, 516), "Imagenes/BotonSiguiente.png");

	std::unique_ptr<Boton> anterior2 = std::make_unique<Boton>("Anterior2", sf::Vector2f(544, 516), "Imagenes/BotonAnterior.png");
	std::unique_ptr<Boton> siguiente2 = std::make_unique<Boton>("Siguiente2", sf::Vector2f(888, 516), "Imagenes/BotonSiguiente.png");

	std::unique_ptr<Boton> NombreFloppa1 = std::make_unique<Boton>("NombreFloppa1", sf::Vector2f(144, 496), "Imagenes/NombreFloppa.png");
	std::unique_ptr<Boton> NombreSogga1 = std::make_unique<Boton>("NombreSogga1", sf::Vector2f(144, 496), "Imagenes/NombreSogga.png");
	std::unique_ptr<Boton> NombreJinx1 = std::make_unique<Boton>("NombreJinx1", sf::Vector2f(144, 496), "Imagenes/NombreJinx.png");

	std::unique_ptr<Boton> NombreFloppa2 = std::make_unique<Boton>("NombreFloppa2", sf::Vector2f(584, 496), "Imagenes/NombreFloppa.png");
	std::unique_ptr<Boton> NombreSogga2 = std::make_unique<Boton>("NombreSogga2", sf::Vector2f(584, 496), "Imagenes/NombreSogga.png");
	std::unique_ptr<Boton> NombreJinx2 = std::make_unique<Boton>("NombreJinx2", sf::Vector2f(584, 496), "Imagenes/NombreJinx.png");

	botones.push_back(std::move(regresar));

	botones.push_back(std::move(anterior1));
	botones.push_back(std::move(siguiente1));
	botones.push_back(std::move(anterior2));
	botones.push_back(std::move(siguiente2));

	seleccionPersonaje.push_back(std::move(NombreFloppa1));
	seleccionPersonaje.push_back(std::move(NombreSogga1));
	seleccionPersonaje.push_back(std::move(NombreJinx1));
	seleccionPersonaje.push_back(std::move(NombreFloppa2));
	seleccionPersonaje.push_back(std::move(NombreSogga2));
	seleccionPersonaje.push_back(std::move(NombreJinx2));
}
void SeleccionPersonajeMulti::mostrarMenu(sf::RenderWindow& window) {
	window.draw(fondoSprite);
	dibujarBotones(window);
	dibujarBotonSeleccionPersonaje(window);
}
void SeleccionPersonajeMulti::dibujarBotonSeleccionPersonaje(sf::RenderWindow& window) {
	seleccionPersonaje[idPersonaje1]->dibujarBoton(window);
	seleccionPersonaje[idPersonaje2+ cantidadPersonajes]->dibujarBoton(window);
}
///////////////////////////
VentanaJuego::VentanaJuego(int id) {
	direccion[0] = false;
	direccion[1] = false;
	direccion[2] = false;
	direccion[3] = false;
	Mapa = std::make_unique<MapaViewer>("Imagenes/TileSetMapa.png", mapaGenerado);
	std::unique_ptr<Boton> regresar = std::make_unique<Boton>("Regresar", sf::Vector2f(4, 4), "Imagenes/BotonRegresar.png");
	botones.push_back(std::move(regresar));
	
	if (id == 0) {
		std::unique_ptr<EntidadViewer>Personaje0 = std::make_unique<PersonajesViewer>("Imagenes/FloppaSpriteSheet.png");
		Personaje1 = std::move(Personaje0);
	}
	else if (id == 1) {
		std::unique_ptr<EntidadViewer>Personaje2 = std::make_unique<PersonajesViewer>("Imagenes/SoggaSpriteSheet.png");
		Personaje1 = std::move(Personaje2);
	}
	else if (id == 2) {
		std::unique_ptr<EntidadViewer>Personaje3 = std::make_unique<PersonajesViewer>("Imagenes/JinxSpriteSheet.png");
		Personaje1 = std::move(Personaje3);
	}

	for (int i = 0; i < cantEnemigos; ++i) {
		enemigosMelee.push_back(std::make_unique<MeleeEnemigoViewer>());
		enemigosRanged.push_back(std::make_unique<RangedEnemigoViewer>());
		enemigosBomber.push_back(std::make_unique<BomberEnemigoViewer>());
	}

}
void VentanaJuego::mostrarMenu(sf::RenderWindow& window){
	Mapa->mostrarMapa(window);
	//Mapa->imprimirMapa();
	Personaje1->dibujarEntidad(window);
	for (int i = 0;i < cantEnemigos;i++) {
		enemigosMelee[i]->dibujarEntidad(window);
		enemigosRanged[i]->dibujarEntidad(window);
		enemigosBomber[i]->dibujarEntidad(window);
	}
	for (int i = 0;i < cantEnemigos;i++) {
		Personaje1->verificarAtaqueToEnemigo(*enemigosMelee[i]);
		Personaje1->verificarAtaqueToEnemigo(*enemigosRanged[i]);
		Personaje1->verificarAtaqueToEnemigo(*enemigosBomber[i]);
	}
	dibujarBotones(window);
	actualizarDireccion();
}
///////////////////////////
VentanaJuegoMulti::VentanaJuegoMulti(int id1, int id2) {
	direccion[0] = false;
	direccion[1] = false;
	direccion[2] = false;
	direccion[3] = false;
	Mapa = std::make_unique<MapaViewer>("Imagenes/TileSetMapa.png", mapaGenerado);
	std::unique_ptr<Boton> regresar = std::make_unique<Boton>("Regresar", sf::Vector2f(4, 4), "Imagenes/BotonRegresar.png");
	botones.push_back(std::move(regresar));

	if (id1 == 0) {
		std::unique_ptr<EntidadViewer>floppa = std::make_unique<PersonajesViewer>("Imagenes/FloppaSpriteSheet.png");
		Personaje1 = std::move(floppa);
	}
	else if (id1 == 1) {
		std::unique_ptr<EntidadViewer>sogga = std::make_unique<PersonajesViewer>("Imagenes/SoggaSpriteSheet.png");
		Personaje1 = std::move(sogga);
	}
	else if (id1 == 2) {
		std::unique_ptr<EntidadViewer>jinx = std::make_unique<PersonajesViewer>("Imagenes/JinxSpriteSheet.png");
		Personaje1 = std::move(jinx);
	}
	
	if (id2 == 0) {
		std::unique_ptr<EntidadViewer>floppa = std::make_unique<PersonajesViewer>("Imagenes/FloppaSpriteSheet.png");
		Personaje2 = std::move(floppa);
	}
	else if (id2 == 1) {
		std::unique_ptr<EntidadViewer>sogga = std::make_unique<PersonajesViewer>("Imagenes/SoggaSpriteSheet.png");
		Personaje2 = std::move(sogga);
	}
	else if (id2 == 2) {
		std::unique_ptr<EntidadViewer>jinx = std::make_unique<PersonajesViewer>("Imagenes/JinxSpriteSheet.png");
		Personaje2 = std::move(jinx);
	}
	
	for (int i = 0; i < cantEnemigos; ++i) {
		enemigosMelee.push_back(std::make_unique<MeleeEnemigoViewer>());
		enemigosRanged.push_back(std::make_unique<RangedEnemigoViewer>());
		enemigosBomber.push_back(std::make_unique<BomberEnemigoViewer>());
	}
	Personaje2->setPosicion(100, 500);
}
void VentanaJuegoMulti::mostrarMenu(sf::RenderWindow& window) {
	Mapa->mostrarMapa(window);
	//Mapa->imprimirMapa();
	Personaje1->dibujarEntidad(window);
	Personaje2->dibujarEntidad(window);
	for (int i = 0;i < cantEnemigos;i++) {
		enemigosMelee[i]->dibujarEntidad(window);
		enemigosRanged[i]->dibujarEntidad(window);
		enemigosBomber[i]->dibujarEntidad(window);
	}
	for (int i = 0;i < cantEnemigos;i++) {
		Personaje1->verificarAtaqueToEnemigo(*enemigosMelee[i]);
		Personaje1->verificarAtaqueToEnemigo(*enemigosRanged[i]);
		Personaje1->verificarAtaqueToEnemigo(*enemigosBomber[i]);
	}
	dibujarBotones(window);
	actualizarDireccion();
}

MenuFinJuego::MenuFinJuego() {
	fondoTexture.loadFromFile("Imagenes/fin.png");
	fondoSprite.setTexture(fondoTexture);
	std::unique_ptr<Boton> regresar = std::make_unique<Boton>("Regresar", sf::Vector2f(4, 4), "Imagenes/BotonRegresar.png");
	botones.push_back(std::move(regresar));
}
void MenuFinJuego::mostrarMenu(sf::RenderWindow& window) {
	window.draw(fondoSprite);
	dibujarBotones(window);
}