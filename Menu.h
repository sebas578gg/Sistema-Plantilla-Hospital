#ifndef MENU_H
#define MENU_H
#include "Lista.h"
#include "Empleado.h"
#include "Departamento.h"
#include "ControladorPlanilla.h"

// Clase de Vista / Interfaz:
// Gestiona la memoria en ejecucion (listas dinamicas) e interactua con el usuario por consola.
class Menu {
private:
// Listas genericas de punteros: permiten almacenar clases derivadas polimorficamente
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
