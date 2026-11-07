//Clse Derivada de Empleado.H
#include "Administrativo.h"

Administrativo::Administrativo(string c, string n, double s) : Empleado(c, n, s) {}
double Administrativo::calcularSalarioNeto() const { return salarioBase; }
string Administrativo::getTipo() const { return "Administrativo"; }
