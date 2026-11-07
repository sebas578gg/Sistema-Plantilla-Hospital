// Lista simple enlazada generica.
// Maneja memoria dinamica con punteros, creciendo o encogiendose segun se necesite.


#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

template <typename T>
class Lista {
private:
	Nodo<T>* cabeza;
public:
	Lista() : cabeza(nullptr) {}
	
	~Lista() {
		Nodo<T>* actual = cabeza;
		while(actual != nullptr) {
			Nodo<T>* temp = actual;
			actual = actual->siguiente;
			delete temp;
		}
	}
	
	void agregar(T dato) {
		Nodo<T>* nuevo = new Nodo<T>(dato);
		if(!cabeza) {
			cabeza = nuevo;
		} else {
			Nodo<T>* actual = cabeza;
			while(actual->siguiente) actual = actual->siguiente;
			actual->siguiente = nuevo;
		}
	}
	
	Nodo<T>* getCabeza() const { return cabeza; }
	
	void limpiarNodos() {
		Nodo<T>* actual = cabeza;
		while(actual != nullptr) {
			Nodo<T>* temp = actual;
			actual = actual->siguiente;
			delete temp;
		}
		cabeza = nullptr;
	}
};
#endif
