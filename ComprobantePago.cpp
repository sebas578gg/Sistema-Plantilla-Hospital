// Vincula las instancias existentes del empleado y depto con el monto neto a cobrar.
#include "ComprobantePago.h"

ComprobantePago::ComprobantePago(Empleado* e, Departamento* d, double m) : empleado(e), departamento(d), montoNeto(m) {}
double ComprobantePago::getMonto() const { return montoNeto; }
string ComprobantePago::getCedulaEmpleado() const { return empleado->getCedula(); }
string ComprobantePago::getNombreDepartamento() const { return departamento->getNombre(); }
