#pragma once
#include"Tree.h"
#include"Interface.h"
///Esta clase se encarga de inicializar y poner en practica las funcionalidades del proyecto.
class Controller {
private:
	Tree* game;
public:
	///Constructor sin parametros, se inicializa el atributo game y se carga los datos del juego 
	///desde un archivo.
	Controller();
	///Destructor de la clase, se elimina la memoria dinamica.
	~Controller();
	///Metodo que se encarga de invocar el menu principal del juego y devuelve la opcion dada por el usuario.
	int control1();
	///Metodo que se encarga de manipular las interfaces del juego. Segun la opcion que el usuario ingrese
	///va a comunicarse con la interfaz.
	void control2();
};