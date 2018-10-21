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
///variables estaticas que seran utiles para los calculos que se hacen en el juego.
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
	///Método que recibe por parámetro un Nodo y un dato y los inserta en su respectivo lugar dependiendo del
	///archivo del que se recupera
	NodePtr insert(NodePtr, std::string);
	///Método que pregunta al usuario, para proceder a adivinar cual es el animal que hay que desvelar.
	bool ask(NodePtr/*, std::istream&*/);
	///Método que guarda los datos del árbol en un archivo .txt
	void save(NodePtr, std::ostream&);
	///Método que recupera los datos de un archivo .txt
	NodePtr recover(std::ifstream&);
	///Metodo que imprime el arbol en pre-orden
	void toString(NodePtr); 
	/// Metodo encargado de realizar la manipulacion de los punteros para las referencias y lograr la reubicacion de los niveles, que se desean cambiar.
	bool changeLevel(std::string,std::string);
	/// Metodo encargado buscar un nodo espesifico y devolver el anterior a ese. Recibe un parametro del tipo std::string con el nombre el cual 
	/// sera necesario para ubicar el nodo deseado.
	NodePtr searchNodo(std::string);
	///Método que ingresa los datos del animal al arbol si la aplicacion pierde al adivinar cual debería ser. También los agrega en su
	///respectivo lugar.
	bool insertInformation(std::string, std::string);
	/// Método que identifica cual ruta el usuario escogio mientras se le realizaba las preguntas, y éste método es un apoyo para insertInformation().
	NodePtr newAdress();
	///Metodo encargado de mostrar las clases principales de la base de datos(arbol), las cuales son las categorias de los animales.
	std::string showMainClasses();
private:
	NodePtr root;
};
#endif
