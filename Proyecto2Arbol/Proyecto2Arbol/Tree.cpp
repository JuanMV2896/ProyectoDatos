#include "Tree.h"
#include <iostream>

Tree::Tree(){
	root = nullptr;
}

Tree::~Tree(){
	delete root;
}

NodePtr Tree::getRoot(){
	return root;
}

void Tree::setRoot(NodePtr root){
	this->root = root;
}

NodePtr Tree::insert(NodePtr actual, std::string data) {
	std::string dir = direccion(data);
	if (!actual) {
		NodePtr nuevo = new Node;
		nuevo->data = data;
		nuevo->left = nullptr;
		nuevo->right = nullptr;
		actual = nuevo;
	}
	else {
		if (dir[0] == 'N') {
			dir.erase(0,1);
			data += dir;
			actual->left = insert(actual->left, data);
		}
		else if (dir[0] == 'S') {
			dir.erase(0, 1);
			data += dir;
			actual->right = insert(actual->right, data);
		}
	}
	return actual;
}

bool Tree::ask(NodePtr actual/*, std::istream & answer*/) {
	std::string temp;
	std::cout << "Digite (s/n)\n";
	std::cout << "El animal en el que piensa " << actual->data << "?:\n";
	std::cin >> temp;
	path += temp;
	/*std::getline(answer, temp);*/
	if (!actual->left && !actual->right && temp == "n")
		return false;
	if (!actual->left && temp == "n")
		return false;
	else if (!actual->right && temp == "s")
		return true;
	bool response = false;
	if (temp == "n") {
		//system("cls");
		response = ask(actual->left/*, std::cin*/);
	}
	if (temp == "s") {
		//system("cls");
		response = ask(actual->right/*, std::cin*/);
	}
	return response;
}

void Tree::save(NodePtr actual, std::ostream& archS){
	if (actual != nullptr){
		if (actual->right == nullptr && actual->left == nullptr) {
			archS << actual->data + saveData<<std::endl;
		}
		else {
			archS << actual->data + saveData<<std::endl;
			saveData += "S";
			save(actual->right, archS);
			saveData.erase(saveData.size() - 1, 1);
			saveData += "N";
			save(actual->left, archS);
			saveData.erase(saveData.size() - 1, 1);
		}
	}
}

NodePtr Tree::recover(std::ifstream& file) {
	std::string data;
	//std::getline(file, data);
	NodePtr temp = nullptr;
	if (!file)
		return nullptr;
	while (/*file >> */std::getline(file, data))
		temp = this->insert(temp, data);
	return temp;
}

void Tree::toString(NodePtr actual) { //Prueba   -> Recorrido  PreOrden
	if (actual != nullptr) {
		std::cout << actual->data;
		std::cout << ", ";
		toString(actual->left);
		toString(actual->right);
	}
}

bool Tree::insertaInformacion(std::string nombre, std::string caracteristica){
	NodePtr comodin = newAdress();
	try {
		NodePtr nuevo = new Node;
		NodePtr hijo = new Node;
		nuevo->right = hijo;
		nuevo->left = comodin->left;
		comodin->left = nuevo;
		nuevo->data = caracteristica;
		hijo->data = nombre;
		return true;
	}
	catch (...) {
		return false;
	}
}

NodePtr Tree::newAdress(){
	NodePtr comodin = root;
	while (!path.size == 1) {
		if (path[0] == 'n') {
			comodin = comodin->left;
		}
		else {
			comodin = comodin->right;
		}
		path.erase(0, 1);
	}
	return comodin;
}
