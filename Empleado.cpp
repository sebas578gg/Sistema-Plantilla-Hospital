#include "Empleado.h"

Empleado::Empleado(string c, string n, double s) : cedula(c), nombre(n), salarioBase(s) {}
Empleado::~Empleado() {}
string Empleado::getCedula() const { return cedula; }
string Empleado::getNombre() const { return nombre; }
double Empleado::getSalarioBase() const { return salarioBase; }
