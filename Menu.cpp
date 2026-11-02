#include "Menu.h"
#include "ArchivoTexto.h"
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"
#include <iostream>

using namespace std;

Menu::Menu() {
	ArchivoTexto* archivo = new ArchivoTexto();
	ctrl = new ControladorPlanilla(archivo);
	
	ctrl->cargarEmpleados(empleados);
	ctrl->cargarDepartamentos(departamentos);
}

Menu::~Menu() {
	delete ctrl;
	Nodo<Empleado*>* actE = empleados.getCabeza();
	while(actE) { delete actE->dato; actE = actE->siguiente; }
	Nodo<Departamento*>* actD = departamentos.getCabeza();
	while(actD) { delete actD->dato; actD = actD->siguiente; }
}

void Menu::iniciar() {
	int opcion;
	do {
		cout << "\n=== SISTEMA HOSPITALARIO ===\n";
		cout << "1. Registrar Empleado\n";
		cout << "2. Listar Empleados\n";
		cout << "3. Eliminar Empleado\n";
		cout << "4. Gestionar Departamentos\n";
		cout << "5. Procesar Pago\n";
		cout << "0. Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		
		switch(opcion) {
		case 1: registrarEmpleado(); break;
		case 2: listarEmpleados(); break;
		case 3: eliminarEmpleado(); break;
		case 4: menuDepartamentos(); break;
		case 5: procesarPago(); break;
		case 0: cout << "Saliendo...\n"; break;
		default: cout << "Opcion invalida.\n";
		}
	} while(opcion != 0);
}

void Menu::registrarEmpleado() {
	int tipo;
	string c, n, e; double s;
	cout << "Tipo (1.Medico, 2.Enfermero, 3.Administrativo): "; cin >> tipo;
	cout << "Cedula: "; cin >> c;
	cout << "Nombre: "; cin >> n;
	cout << "Salario Base: "; cin >> s;
	
	if(tipo == 1) {
		cout << "Especialidad: "; cin >> e;
		empleados.agregar(new Medico(c, n, s, e));
	} else if(tipo == 2) {
		empleados.agregar(new Enfermero(c, n, s));
	} else {
		empleados.agregar(new Administrativo(c, n, s));
	}
	ctrl->guardarEmpleados(empleados);
	cout << "Empleado guardado con exito.\n";
}

void Menu::listarEmpleados() {
	Nodo<Empleado*>* act = empleados.getCabeza();
	if(!act) cout << "No hay empleados.\n";
	while(act) {
		cout << act->dato->getTipo() << " | " << act->dato->getCedula() 
			<< " | " << act->dato->getNombre() << " | Neto: $" << act->dato->calcularSalarioNeto() << "\n";
		act = act->siguiente;
	}
}

void Menu::eliminarEmpleado() {
	string cedula;
	cout << "Cedula a eliminar: "; cin >> cedula;
	
	Lista<Empleado*> nuevaLista;
	Nodo<Empleado*>* act = empleados.getCabeza();
	bool encontrado = false;
	
	while(act) {
		if(act->dato->getCedula() == cedula) {
			delete act->dato; 
			encontrado = true;
		} else {
			nuevaLista.agregar(act->dato);
		}
		act = act->siguiente;
	}
	
	empleados.limpiarNodos(); 
	empleados = nuevaLista; 
	
	if(encontrado) {
		ctrl->guardarEmpleados(empleados);
		cout << "Empleado eliminado.\n";
	} else {
		cout << "Empleado no encontrado.\n";
	}
}

void Menu::menuDepartamentos() {
	int op;
	cout << "1. Crear Depto | 2. Agregar Puesto | 3. Ver Deptos: "; cin >> op;
	if(op == 1) {
		string nom;
		cout << "Nombre del Depto: "; cin >> nom;
		departamentos.agregar(new Departamento(nom));
	} else if(op == 2) {
		string nomDepto, nomPuesto;
		cout << "Nombre del Depto: "; cin >> nomDepto;
		cout << "Nombre del Puesto: "; cin >> nomPuesto;
		Nodo<Departamento*>* act = departamentos.getCabeza();
		while(act) {
			if(act->dato->getNombre() == nomDepto) {
				act->dato->agregarPuesto(Puesto(nomPuesto));
				cout << "Puesto agregado.\n";
				break;
			}
			act = act->siguiente;
		}
	} else if(op == 3) {
		Nodo<Departamento*>* act = departamentos.getCabeza();
		while(act) {
			cout << "- " << act->dato->getNombre() << "\n";
			act = act->siguiente;
		}
	}
	ctrl->guardarDepartamentos(departamentos);
}

void Menu::procesarPago() {
	string cedula, nombreDepto;
	cout << "Cedula del empleado: "; cin >> cedula;
	cout << "Nombre del departamento: "; cin >> nombreDepto;
	
	Empleado* emp = nullptr;
	Nodo<Empleado*>* act = empleados.getCabeza();
	while(act) {
		if(act->dato->getCedula() == cedula) emp = act->dato;
		act = act->siguiente;
	}
	
	Departamento* depto = nullptr;
	Nodo<Departamento*>* actD = departamentos.getCabeza();
	while(actD) {
		if(actD->dato->getNombre() == nombreDepto) depto = actD->dato;
		actD = actD->siguiente;
	}
	
	if(!emp) { cout << "Empleado no encontrado.\n"; return; }
	if(!depto) { cout << "Departamento no encontrado.\n"; return; }
	
	ctrl->procesarPago(emp, depto);
	cout << "Pago procesado y guardado en planilla.txt\n";
}
