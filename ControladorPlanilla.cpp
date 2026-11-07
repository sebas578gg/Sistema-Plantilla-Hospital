
// Lee empleados.txt, parsea cada linea separada por comas y reconstruye los objetos en memoria con 'new'.

#include "ControladorPlanilla.h"
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"
#include <sstream>

ControladorPlanilla::ControladorPlanilla(IPersistencia* p) : persistencia(p) {}

void ControladorPlanilla::cargarEmpleados(Lista<Empleado*>& lista) {
	string contenido = persistencia->leer("empleados.txt");
	stringstream ss(contenido);
	string linea;
	while(getline(ss, linea)) {
		if(linea.empty()) continue;
		stringstream ls(linea);
		string tipo, ced, nom, esp, salStr;
		getline(ls, tipo, ',');
		getline(ls, ced, ',');
		getline(ls, nom, ',');
		getline(ls, salStr, ',');
		
		double sal = stod(salStr);
		if(tipo == "Medico") {
			getline(ls, esp, ',');
			lista.agregar(new Medico(ced, nom, sal, esp));
		} else if(tipo == "Enfermero") {
			lista.agregar(new Enfermero(ced, nom, sal));
		} else if(tipo == "Administrativo") {
			lista.agregar(new Administrativo(ced, nom, sal));
		}
	}
}

void ControladorPlanilla::cargarDepartamentos(Lista<Departamento*>& lista) {
	string contenido = persistencia->leer("departamentos.txt");
	stringstream ss(contenido);
	string linea;
	while(getline(ss, linea)) {
		if(linea.empty()) continue;
		stringstream ls(linea);
		string nomDepto, puestoNom;
		getline(ls, nomDepto, ',');
		Departamento* d = new Departamento(nomDepto);
		while(getline(ls, puestoNom, ',')) {
			d->agregarPuesto(Puesto(puestoNom));
		}
		lista.agregar(d);
	}
}

void ControladorPlanilla::guardarEmpleados(Lista<Empleado*>& lista) {
	stringstream ss;
	Nodo<Empleado*>* act = lista.getCabeza();
	while(act) {
		Empleado* e = act->dato;
		ss << e->getTipo() << "," << e->getCedula() << "," << e->getNombre() << "," << e->getSalarioBase();
		if(e->getTipo() == "Medico") {
			ss << "," << ((Medico*)e)->getEspecialidad();
		}
		ss << "\n";
		act = act->siguiente;
	}
	persistencia->sobreescribir("empleados.txt", ss.str());
}

void ControladorPlanilla::guardarDepartamentos(Lista<Departamento*>& lista) {
	stringstream ss;
	Nodo<Departamento*>* act = lista.getCabeza();
	while(act) {
		ss << act->dato->serializar() << "\n";
		act = act->siguiente;
	}
	persistencia->sobreescribir("departamentos.txt", ss.str());
}

void ControladorPlanilla::procesarPago(Empleado* emp, Departamento* depto) {
	double neto = emp->calcularSalarioNeto();
	stringstream ss;
	ss << emp->getCedula() << "," << emp->getNombre() << "," << depto->getNombre() << "," << neto;
	persistencia->guardar("planilla.txt", ss.str());
}
