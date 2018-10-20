#include "Controller.h"

Controller::Controller(Tree *game){
	this->game = game;
}

Controller::~Controller()
{
	delete game;
}

int Controller::control1(){
	return Interface::winPrincipal();
}

void Controller::control2(){
	int op = control1();
	switch (op) {
		case 1: {
			
			break;
		}
	}
}
