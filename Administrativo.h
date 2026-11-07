//Clase Derivada
#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Empleado.h"

class Administrativo : public Empleado {
public:
	Administrativo(string c, string n, double s);
	double calcularSalarioNeto() const override;
	string getTipo() const override;
};
#endif
