#ifndef MEDICO_H
#define MEDICO_H
#include "Empleado.h"

class Medico : public Empleado {
private:
	string especialidad;
public:
	Medico(string c, string n, double s, string e);
	double calcularSalarioNeto() const override;
	string getTipo() const override;
	string getEspecialidad() const;
};
#endif
