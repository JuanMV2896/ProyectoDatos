#pragma once
#include "Tools.h"
#include"Tree.h"
#include<iostream>

class Interface {
public:
	static int winPrincipal();
	static void winLose();
	static void winNewData();
	static void winWinner();
	static void startGame(Tree* game);
	static void endGame();
};