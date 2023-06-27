#pragma once
#include "Imagen.h"
class EntidadViewer :public Imagen{
private:
	sf::Vector2f velocidad;
public:
	EntidadViewer(std::string);
	~EntidadViewer()=default;
	void movimientoEntidad();
	void updateImagen() override;
};

