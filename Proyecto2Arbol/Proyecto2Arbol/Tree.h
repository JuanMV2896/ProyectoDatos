#ifndef TREE_H
#define TREE_H
#include"Tools.h"
#include <sstream>
#include <fstream>

typedef struct Node* NodePtr;

struct Node {
	std::string data;
	NodePtr left;
	NodePtr right;
};
static std::string saveData = "";
static std::string path = "";

class Tree {	
public:
	Tree();
	~Tree();
	NodePtr getRoot();
	void setRoot(NodePtr);
	NodePtr insert(NodePtr, std::string);
	bool ask(NodePtr/*, std::istream&*/);
	void save(NodePtr, std::ostream&);
	NodePtr recover(std::ifstream&);
	void toString(NodePtr);  //PRUEBA    -> Recorrido  PreOrden
	bool changeLevel(std::string,std::string);
	/// Metodo encargado buscar un nodo espesifico y devolver el anterior a ese.
	NodePtr searchNodo(std::string);
	bool insertInformation(std::string, std::string);
	NodePtr newAdress();
	///Metodo encargado de mostrar las clases principales de la base de datos(arbol), las cuales son las categorias de los animales.
	std::string showMainClasses();
private:
	NodePtr root;
};
#endif
