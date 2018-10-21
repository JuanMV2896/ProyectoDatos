#ifndef TREE_H
#define TREE_H
#include"Tools.h"
#include <sstream>
#include <fstream>

typedef struct Node* NodePtr;
///Estructura de un Nodo, donde va a tener dos apuntadores, uno a un nodo a la derecha y el otro apuntaria
///a un nodo a la izquierda. Estas estructuras van a ser capaces de almacenar un dato de tipo string.
struct Node {
	std::string data;
	NodePtr left;
	NodePtr right;
};
///variables staticas que seran utiles para los calculos que se hacen en el juego.
static std::string saveData = "";
static std::string path = "";

///Clase representativa de un arbol de busqueda binaria.
class Tree {	
public:
	///Constructor del arbol
	Tree();
	///Destructor del arbol
	~Tree();
	///Metodo que devuelve el nodo raiz del arbol binario de busqueda.
	NodePtr getRoot();
	///Metodo que recibe por parametro un Nodo, el cual va a ser seteado en el atributo raiz(root).
	void setRoot(NodePtr);
	NodePtr insert(NodePtr, std::string);
	bool ask(NodePtr/*, std::istream&*/);
	void save(NodePtr, std::ostream&);
	NodePtr recover(std::ifstream&);
	///Metodo que imprime el arbol en pre-orden
	void toString(NodePtr); 
	/// Metodo encargado de realizar la manipulacion de los punteros para las referencias y lograr la reubicacion de los niveles, que se desean cambiar.
	bool changeLevel(std::string,std::string);
	/// Metodo encargado buscar un nodo espesifico y devolver el anterior a ese. Recibe un parametro del tipo std::string con el nombre el cual 
	/// sera necesario para ubicar el nodo deseado.
	NodePtr searchNodo(std::string);
	bool insertInformation(std::string, std::string);
	NodePtr newAdress();
	///Metodo encargado de mostrar las clases principales de la base de datos(arbol), las cuales son las categorias de los animales.
	std::string showMainClasses();
private:
	NodePtr root;
};
#endif
