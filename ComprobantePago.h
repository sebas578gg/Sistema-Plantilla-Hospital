#ifndef COMPROBANTEPAGO_H
#define COMPROBANTEPAGO_H
#include "Empleado.h"
#include "Departamento.h"
using namespace std;

// Relaciona a un Empleado con su Departamento para registrar el pago emitido.
// Ojo para la defensa: Usa punteros (asociacion) para referenciar los objetos sin duplicarlos en memoria.
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
