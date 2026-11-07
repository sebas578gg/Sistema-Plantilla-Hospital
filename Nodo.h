
// Template (generico): Permite que el nodo guarde cualquier tipo de dato (T) sin duplicar codigo.
// Es la unidad basica de la lista enlazada: guarda el dato y el puntero al siguiente nodo en memoria.

#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
public:
	T dato;
	Nodo<T>* siguiente;
	Nodo(T d) : dato(d), siguiente(nullptr) {}
};
#endif
