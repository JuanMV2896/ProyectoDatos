#include "Interface.h"
#include <Windows.h>

int Interface::winPrincipal(){
	std::string opcion = 0;
	int op = 0;
	do {
		system("cls");
		std::cout << "====================================================" << std::endl;
		std::cout << "				EL MUNDO DE LOS ANIMALES			  " << std::endl;
		std::cout << "====================================================" << std::endl;
		std::cout << "====================================================" << std::endl;
		std::cout << "  1) Iniciar Partida								  " << std::endl;
		std::cout << "  2) Modificar Niveles								  " << std::endl;
		std::cout << "  3) Salir									      " << std::endl;
		std::cout << "====================================================" << std::endl;
		std::cout << " Digite una opcion: "; std::cin >> opcion;
		std::cout << "====================================================" << std::endl;
		op = validaOpcion(opcion);
	} while (op != 3);
	return op;
}

void Interface::winLose(){
	system("cls");
	std::cout << "******************************************************" << std::endl;
	std::cout << "*====================================================*" << std::endl;
	std::cout << "*				LAMENTABLEMENTE HAS PERDIDO!           *" << std::endl;
	std::cout << "*====================================================*" << std::endl;
	std::cout << "******************************************************" << std::endl << std::endl;
	std::cout << " Cargando" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << ".";
		Sleep(1000);
	}
}

void Interface::winNewData(){
	std::string nombre, caracteristica, opcion;
	do {
		system("cls");
		std::cout << "====================================================" << std::endl;
		std::cout << "	      		ACTUALIZANDO LA BASE DE DATOS         " << std::endl;
		std::cout << "====================================================" << std::endl;
		std::cout << " Nombre del animal: "; std::cin >> nombre;
		std::cout << " Fuerte caracteristica: "; std::cin >> caracteristica;
		std::cout << "====================================================" << std::endl;
		std::cout << "Esta seguro de los datos que ingreso? (si/no) : "; std::cin >> opcion;
		
	} while (opcion != "si");
}

void Interface::winWinner(){
	system("cls");
	std::cout << "******************************************************" << std::endl;
	std::cout << "*====================================================*" << std::endl;
	std::cout << "*				EN HORABUENA, HAS GANADO...!            *" << std::endl;
	std::cout << "*====================================================*" << std::endl;
	std::cout << "******************************************************" << std::endl << std::endl;
	std::cout << " Cargando" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << ".";
		Sleep(1000);
	}
}

void Interface::startGame(Tree* game){
	std::string temp;
	system("cls");
	std::cout << "====================================================" << std::endl;
	std::cout << "				EL MUNDO DE LOS ANIMALES			  " << std::endl;
	std::cout << "====================================================" << std::endl;
	if (game->ask(game->getRoot())) {
		winWinner();
		winNewData();
	}
	else {
		winLose();
	}
	//validar que no tenga ningun numero...
}

void Interface::endGame(){
	system("cls");
	std::cout << "====================================================" << std::endl;
	std::cout << "				   GRACIAS POR JUGAR			      " << std::endl;
	std::cout << "====================================================" << std::endl;
	Sleep(1000);
	std::cout << "   CREADORES: Rodrigo Melendez Sibaja               " << std::endl;
	Sleep(1000);
	std::cout << "              Heison Navarro Castillo               " << std::endl;
	Sleep(1000);
	std::cout << "              Juan Carlos Madrigal Vasquez          " << std::endl;
	Sleep(1000);
	std::cout << "====================================================" << std::endl;
}
