#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <string>
#include "Puesto.h"
#include "Lista.h"
using namespace std;

class Departamento {
private:
	string nombre;
	Lista<Puesto> puestos; 
public:
	Departamento(string n);
	void agregarPuesto(Puesto p);
	string getNombre() const;
	string serializar() const;
};
#endif
