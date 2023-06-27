#pragma once
#include<iostream>
class Controller{
	float posicionPersonaje;
	std::string nombreMenu;
	
	void verificarCambios();
	void updateParaModelo();
	void updateParaViewer();
};

