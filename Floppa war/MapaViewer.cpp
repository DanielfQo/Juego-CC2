#include "MapaViewer.h"
MapaViewer::MapaViewer(std::string rutaImagen){
	spriteTexture.loadFromFile(rutaImagen);
	sprite.setTexture(spriteTexture);
}
void MapaViewer::mostrarMapa(sf::RenderWindow& window) {
	window.draw(sprite);
}
