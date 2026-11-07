#include "Enfermero.h"

// Logica propia: deduccion o retencion del 5% sobre el salario base (* 0.95).

Enfermero::Enfermero(string c, string n, double s) : Empleado(c, n, s) {}
double Enfermero::calcularSalarioNeto() const { return salarioBase * 0.95; }
string Enfermero::getTipo() const { return "Enfermero"; }
