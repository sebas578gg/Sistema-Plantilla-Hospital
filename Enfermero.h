#ifndef ENFERMERO_H
#define ENFERMERO_H
#include "Empleado.h"

class Enfermero : public Empleado {
public:
	Enfermero(string c, string n, double s);
	double calcularSalarioNeto() const override;
	string getTipo() const override;
};
#endif
