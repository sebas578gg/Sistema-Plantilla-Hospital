#include "Departamento.h"
#include <sstream>

Departamento::Departamento(string n) : nombre(n) {}
void Departamento::agregarPuesto(Puesto p) { puestos.agregar(p); }
string Departamento::getNombre() const { return nombre; }

// Genera una linea de texto tipo "Depto,Puesto1,Puesto2..." recorriendo la lista de puestos.
string Departamento::serializar() const {
	stringstream ss;
	ss << nombre;
	Nodo<Puesto>* act = puestos.getCabeza();
	while(act) {
		ss << "," << act->dato.getNombre();
		act = act->siguiente;
	}
	return ss.str();
}
