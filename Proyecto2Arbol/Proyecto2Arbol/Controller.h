#pragma once
#include"Tree.h"
#include"Interface.h"

class Controller {
private:
	Tree* game;
public:
	Controller();
	~Controller();
	int control1();
	void control2();
};