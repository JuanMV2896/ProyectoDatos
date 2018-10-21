#pragma once
#include<iostream>
#include<sstream>
///Este metodo es un metodo definido como global, se encarga de validar las opciones ingresadas desde 
///la clase interfaz. Devuelve un 0 en caso de que la opcion no sea valida.
int validaOpcion(std::string);
///Este metodo modifica el dato que ingresa por parametro y devuelve un PATH que va a ser utilizado en
///otros metodos para recorrer el arbol binario.
std::string direccion(std::string&);
///Este metodo no devuelve ningun valor, recibe por parametro un string por referencia el cual va a ser
///modificado. El objetivo de este metodo es identificar si es una palabra identificada como femenina o
///masculina.
void modificaNombre(std::string&);