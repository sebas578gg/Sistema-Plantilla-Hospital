#ifndef CONTROLADORPLANILLA_H
#define CONTROLADORPLANILLA_H
#include "Lista.h"
#include "Empleado.h"
#include "Departamento.h"
#include "IPersistencia.h"

class ControladorPlanilla {
private:
	IPersistencia* persistencia; 
public:
	ControladorPlanilla(IPersistencia* p);
	void cargarEmpleados(Lista<Empleado*>& lista);
	void cargarDepartamentos(Lista<Departamento*>& lista);
	void guardarEmpleados(Lista<Empleado*>& lista);
	void guardarDepartamentos(Lista<Departamento*>& lista);
	void procesarPago(Empleado* emp, Departamento* depto);
};
#endif
