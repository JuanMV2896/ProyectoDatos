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

bool Tree::ask(NodePtr actual) {
	std::string temp;
	std::cout << "Digite (s/n)\n";
	std::cout << "El animal en el que piensa " << actual->data << "?:\n";
	std::cin >> temp;
	path += temp;
	if (!actual->left && !actual->right && temp == "n")
		return false;
	if (!actual->left && temp == "n")
		return false;
	else if (!actual->right && temp == "s")
		return true;
	bool response = false;
	if (temp == "n") {
		response = ask(actual->left);
	}
	if (temp == "s") {
		response = ask(actual->right);
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
	NodePtr temp = nullptr;
	if (!file)
		return nullptr;
	while (std::getline(file, data))
		temp = this->insert(temp, data);
	return temp;
}

void Tree::toString(NodePtr actual) { 
	if (actual != nullptr) {
		std::cout << actual->data;
		std::cout << ", ";
		toString(actual->left);
		toString(actual->right);
	}
}

bool Tree::insertInformation(std::string nombre, std::string caracteristica){
	NodePtr comodin = newAdress();
	try {
		NodePtr nuevo = new Node;
		NodePtr hijo = new Node;
		hijo->left = nullptr;
		hijo->right = nullptr;
		nuevo->data = caracteristica;
		hijo->data = nombre;
		if (path[0] == 's') {
			nuevo->right = hijo;
			nuevo->left = comodin->right;
			comodin->right = nuevo;		
		}
		else {
			nuevo->left = comodin->left;
			nuevo->right = hijo;
			comodin->left = nuevo;
		}
		return true;
	}
	catch (...) {
		return false;
	}
}



bool Tree::changeLevel(std::string changeClass1,std::string changeClass2) {
	if (!root) {
		return false;
	}
	modificaNombre(changeClass1);
	modificaNombre(changeClass2);
	NodePtr nodoA = nullptr;
	NodePtr nodoB = nullptr;
	NodePtr auxA = nullptr;  
	NodePtr auxB = nullptr;
	//NodePtr auxRoot = nullptr;
	nodoA = searchNodo(changeClass1); // anterior del nodo a cambiar A
	nodoB = searchNodo(changeClass2);//  anterior del nodo a cambiar B
	if (nodoA != nullptr && nodoB != nullptr) {  // Si son diferentes de null
		// hay que validar cuando se le ingresa los datos que no sean los mismos
			// estos son los nodos que realmente se quieren mover
			auxA = nodoA->left; 
			auxB = nodoB->left;
			if (changeClass1 == root->data) {  // quiere cambiar la raiz por otra posicion
				root = auxA;
				nodoA->left = auxB->left;
				auxB->left = nodoA;
				return true;
			}
			if (changeClass2== root->data) { // quiere cambiar un nodo por la raiz
				nodoA->left = auxA->left;// elimino el el A de la posicion en que estaba
				auxA->left = nodoB;
				root = auxA;
				return true;
			}
			// Para los demas casos
			nodoA->left = auxA->left;  // elimina el primer elemento del arbol
			auxA->left = auxB->left;
			auxB->left = auxA;
			return true;
	}
	return false;
}

NodePtr Tree::searchNodo(std::string name) { 
	NodePtr aux = root;
	if (!aux) {  
		return nullptr;
	}
	if (aux->data == name) {  
		return aux;
	}
	while (aux->left!=nullptr){
		if (aux->left->data == name) {
			return aux;
		}
		aux = aux->left;
	}
	return nullptr;
}


NodePtr Tree::newAdress() {
	NodePtr comodin = root;
	while (path.size() != 2) {
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

std::string Tree::showMainClasses() {
	NodePtr aux;
	int cont = 1;
	aux = root;
	std::stringstream s;
	while (aux->left!=nullptr)
	{
		s << aux->data<<" nivel "<<cont++<<"\n";
		aux = aux->left;
	}
	return s.str();
}
