#include "MapaViewer.h"

MapaViewer::MapaViewer(std::string rutaImagen, std::vector<std::vector<int>> m){
	mapa = m;
	tilesetTexture.loadFromFile(rutaImagen);
	for (int i = 0; i < 2; i++){
		tileSprites[i].setTexture(tilesetTexture);
		tileSprites[i].setTextureRect(sf::IntRect(i * 32,0, 32, 32));
	}
}
void MapaViewer::mostrarMapa(sf::RenderWindow& window) {

    for (int y = 0; y < FILAS; y++) {
        for (int x = 0; x < COLUM; x++) {
            // calcular las posiciones de los tiles en el mapa
            float posX = x * 32 + posicionX;
            float posY = y * 32 + posicionY;
            // verificar si el tile está dentro de la ventana visible
            if (posX >= -32 && posX <= 1056 && posY >= -32 && posY <= 672) {
                int indice = mapa[y][x];
                if (indice == 0 || indice == 1) {
                    sf::Sprite& tileSprite = tileSprites[indice];
                    tileSprite.setPosition(posX, posY);
                    window.draw(tileSprite);
                }
            } 
        }
    }
}
void MapaViewer::setPosicion(float x, float y) {
	posicionX = x;
	posicionY = y;
}
