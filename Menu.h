#ifndef MENU_H
#define MENU_H
#include "Lista.h"
#include "Empleado.h"
#include "Departamento.h"
#include "ControladorPlanilla.h"

class Menu {
private:
	Lista<Empleado*> empleados;
	Lista<Departamento*> departamentos;
	ControladorPlanilla* ctrl;
	
	void registrarEmpleado();
	void listarEmpleados();
	void eliminarEmpleado();
	void menuDepartamentos();
	void procesarPago();
public:
	Menu();
	~Menu();
	void iniciar();
};
#endif
