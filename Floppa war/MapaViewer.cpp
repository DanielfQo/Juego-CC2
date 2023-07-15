#include "MapaViewer.h"

MapaViewer::MapaViewer(std::string rutaImagen, std::vector<std::vector<int>> m){
	mapa = m;
	tilesetTexture.loadFromFile(rutaImagen);
	for (int i = 0; i < 2; i++){
		tileSprites[i].setTexture(tilesetTexture);
		tileSprites[i].setTextureRect(sf::IntRect(i * 32,0, 32, 32));
	}
	posicionX = -500.0f;
	posicionY = -500.0f;
}
void MapaViewer::mostrarMapa(sf::RenderWindow& window) {
	for (int y = 0; y < FILAS; y++){
		for (int x = 0; x < COLUM; x++){
            int indice = mapa[y][x];
            if (indice == 0 || indice ==1){
                sf::Sprite& tileSprite = tileSprites[indice];
                tileSprite.setPosition(x * 32+posicionX, y * 32+posicionY);
                window.draw(tileSprite);
            }
		}
	}

}
void MapaViewer::setPosicion(float x, float y) {
	posicionX = x;
	posicionY = y;
}
