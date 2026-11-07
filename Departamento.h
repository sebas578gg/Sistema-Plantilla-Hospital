#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <string>
#include "Puesto.h"
#include "Lista.h"
using namespace std;

// Representa un departamento del hospital.
// Contiene una lista enlazada de objetos Puesto (relacion de agregacion/composicion).
class Departamento {
private:
	string nombre;
	Lista<Puesto> puestos; 
public:
	Departamento(string n);
	void agregarPuesto(Puesto p);
	string getNombre() const;
		// Convierte los datos del depto y sus puestos a formato CSV para guardarlos en archivo.

	string serializar() const;
};
#endif
