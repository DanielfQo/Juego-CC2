#include "MapaViewer.h"
MapaViewer::MapaViewer(std::string rutaImagen){
	spriteTexture.loadFromFile(rutaImagen);
	sprite.setTexture(spriteTexture);
	posicionX = -500.0f;
	posicionY = -500.0f;
}
void MapaViewer::mostrarMapa(sf::RenderWindow& window) {
	window.draw(sprite);
	sprite.setPosition(posicionX, posicionY);
}
void MapaViewer::setPosicion(float x, float y) {
	posicionX = x;
	posicionY = y;
}
