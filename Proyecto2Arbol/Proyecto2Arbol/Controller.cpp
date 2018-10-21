#include "Controller.h"

Controller::Controller(){
	this->game = new Tree;
	std::ifstream handle;
	try {
		handle.open("../MundoAnimal.txt", std::ios::in);
		game->setRoot(game->recover(handle));
		handle.close();
		control2();
	}
	catch (...) {
		handle.close();
	}
}

Controller::~Controller(){
	std::ofstream archS;
	try {
		archS.open("../MundoAnimal.txt", std::ios::out);
		game->save(game->getRoot(), archS);
		archS.close();
	}
	catch (...) {
		archS.close();
	}
	delete game;
}

int Controller::control1(){
	return Interface::winPrincipal();
}

void Controller::control2(){
	int op = control1();
	switch (op) {
		case 1: {
			Interface::startGame(game);
			break;
		}
		case 2: {
			//modificar pisos
			break;
		}
		case 3: {
			Interface::endGame();
			break;
		}
	}
}
