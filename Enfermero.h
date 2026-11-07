#ifndef ENFERMERO_H
#define ENFERMERO_H
#include "Empleado.h"
// Clase derivada de Empleado. Implementa el calculo con sus propias reglas salariales.
class Enfermero : public Empleado {
public:
	Enfermero(string c, string n, double s);
	double calcularSalarioNeto() const override;
	string getTipo() const override;
};
#endif
