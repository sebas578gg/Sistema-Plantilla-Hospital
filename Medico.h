#ifndef MEDICO_H
#define MEDICO_H
#include "Empleado.h"

// Clase derivada: hereda de Empleado y agrega el atributo especifico de especialidad.
class Medico : public Empleado {
private:
	string especialidad;
public:
	Medico(string c, string n, double s, string e);

	// 'override': sobreescribe los metodos virtuales de Empleado (Polimorfismo).
	double calcularSalarioNeto() const override;
	string getTipo() const override;
	string getEspecialidad() const;
};
#endif
