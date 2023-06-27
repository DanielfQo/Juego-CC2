#include<iostream>
#include "Model.h"


class Controller{
	private:
		float posicionPersonaje;
		std::string nombreMenu;
		Model* Modelo;
		
	public:
		void cargarModel();
		/*
		void verificarCambios();
		void updateParaModelo();
		void updateParaViewer();
		*/
};
void Controller::cargarModel(){
	Model aux;
	Modelo = &aux;
    Modelo->cargarMapa();

}