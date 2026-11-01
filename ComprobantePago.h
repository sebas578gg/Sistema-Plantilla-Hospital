#ifndef COMPROBANTEPAGO_H
#define COMPROBANTEPAGO_H
#include "Empleado.h"
#include "Departamento.h"
using namespace std;

class ComprobantePago {
private:
	Empleado* empleado; 
	Departamento* departamento;
	double montoNeto;
public:
	ComprobantePago(Empleado* e, Departamento* d, double m);
	double getMonto() const;
	string getCedulaEmpleado() const;
	string getNombreDepartamento() const;
};
#endif
