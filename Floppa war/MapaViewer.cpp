#include "MapaViewer.h"

MapaViewer::MapaViewer(std::string rutaImagen, std::vector<std::vector<int>> m){
	mapa = m;
	tilesetTexture.loadFromFile(rutaImagen);
	for (int i = 0; i < 2; i++){
		tileSprites[i].setTexture(tilesetTexture);
		tileSprites[i].setTextureRect(sf::IntRect(i * 64,0, 64, 64));
	}
}
void MapaViewer::mostrarMapa(sf::RenderWindow& window) {

    for (int y = 0; y < FILAS; y++) {
        for (int x = 0; x < COLUM; x++) {
            // calcular las posiciones de los tiles en el mapa
            float posX = x * 64 + posicionX;
            float posY = y * 64 + posicionY;
            // verificar si el tile está dentro de la ventana visible
            if (posX >= -64 && posX <= 1088 && posY >= -64 && posY <= 704) {//-64 1088 -64 704
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
