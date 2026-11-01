#include "Enfermero.h"

Enfermero::Enfermero(string c, string n, double s) : Empleado(c, n, s) {}
double Enfermero::calcularSalarioNeto() const { return salarioBase * 0.95; }
string Enfermero::getTipo() const { return "Enfermero"; }
