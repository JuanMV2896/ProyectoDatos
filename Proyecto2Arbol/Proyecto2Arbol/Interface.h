#pragma once
#include "Tools.h"
#include"Tree.h"
#include<iostream>


/// La clase interfaz es la encargada de todos los procesos de visualizacion del juego, para que haya facil comprension por parte de los usuarios
/// con respecto a las funcionalidades que este programa brinda.
class Interface {
public:
	/// Metodo encargado de la visualizacion del menu principal, el cual muestra las opciones principales del juego.
	static int winPrincipal();
	///Metodo encargado de hacerle saber al usuario que a perdido el juego. 
	static void winLose();
	///Metodo encargado de mostrar informacion para guiar al usuario a la hora de crear e ingresar nuevos datos al sistema.
	static void winNewData(Tree* game);
	///Metodo encargado de hacerle saber al usuario que a gando el juego.
	static void winWinner();
	///Metodo que muestra el encabezado inicial del juego.
	static void startGame(Tree* game);
	///Metodo que muestra el los creditos y mensajes finales del juego.
	static void endGame();
	///Metodo encargado de mostrar informacion para guiar al usuario a la hora de querer cambiar los niveles.
	static void changeFloor(Tree* game);
};