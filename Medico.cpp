#include "Medico.h"

// Llama al constructor base Empleado(c, n, s) y asigna su atributo propio (especialidad).
Medico::Medico(string c, string n, double s, string e) : Empleado(c, n, s), especialidad(e) {}

// Logica propia: bono del 5% sobre el salario base (+5%).
double Medico::calcularSalarioNeto() const { return salarioBase * 1.05; }
string Medico::getTipo() const { return "Medico"; }
string Medico::getEspecialidad() const { return especialidad; }
