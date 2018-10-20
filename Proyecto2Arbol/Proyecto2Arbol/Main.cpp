#include "Tree.h"
#include "Interface.h"
#include <iostream>
int main() {
	Tree* t = new Tree;
	std::ifstream handle("../MundoAnimal.txt", std::ios::in);

	t->setRoot(t->recover(handle));
	handle.close();
	
	//t->toString(t->getRoot());
	if (t->ask(t->getRoot()))
		std::cout << "He Adivinado\n\n";
	else
		std::cout << "He Perdido\n\n";
	std::ofstream archS("../MundoAnimal.txt", std::ios::out);
	t->save(t->getRoot(), archS);
	archS.close();
	delete t;

	system("pause");
	return 0;
}