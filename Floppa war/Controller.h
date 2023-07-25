#include <iostream>
#include <vector>
#include "Model.h"
#include "Viewer.h"

class Controller{
	private:

		std::unique_ptr<Model> Modelo = std::make_unique<Model>();
		std::unique_ptr<Viewer> Vista = std::make_unique<Viewer>();
		
	public:
		Controller();
		~Controller() = default;
		void cargarVentana();
		void actualizarModel();
		void actualizarViewer();

		/*
		void verificarCambios();
		void updateParaModelo();
		void updateParaViewer();
		*/
};
