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
	size_t tam = valor.size();
	for (int i = 0; i < tam; i++) {
		if (valor[i] == 'S' || valor[i] == 'N') {
			direccion += valor[i];
			valor.erase(i, 1);
			--tam;
			--i;
		}
	}
	return direccion;
}

void modificaNombre(std::string& nombre){
	if (nombre[nombre.size()] != 'a') {
		nombre = "es un " + nombre;
	}
	else
		nombre = "es una " + nombre;
}