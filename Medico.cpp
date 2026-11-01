#include "Medico.h"

Medico::Medico(string c, string n, double s, string e) : Empleado(c, n, s), especialidad(e) {}
double Medico::calcularSalarioNeto() const { return salarioBase * 1.05; }
string Medico::getTipo() const { return "Medico"; }
string Medico::getEspecialidad() const { return especialidad; }
