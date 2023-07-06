#include <iostream>
#include <vector>
#include "Model.h"
#include "Viewer.h"

class Controller{
	private:
		float posicionPersonaje;
		std::string nombreMenu;
		std::unique_ptr<Model> Modelo;
		std::unique_ptr<Viewer> Vista;
		
	public:
		void cargarModel();
		/*
		void verificarCambios();
		void updateParaModelo();
		void updateParaViewer();
		*/
};
