#include"Tools.h"

int validaOpcion(std::string opcion){
	int opcionValida;
	std::stringstream ss(opcion);
	ss >> opcionValida;
	for (int i = 0; i < opcion.size(); i++) {
		if (isalpha(opcion[i]))
			return 0;
	}
	return opcionValida;
}

std::string direccion(std::string& valor) {
	std::string direccion = "";
	int tamano = valor.size();
	for (int i = 0; i < tamano; i++) {
		if (valor[i] == 'S' || valor[i] == 'N') {
			direccion += valor[i];
			valor.erase(i, 1);
		}
	}
	return direccion;
}