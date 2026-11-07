
// CLASE BASE ABSTRACTA:
// No se puede instanciar directamente porque tiene metodos virtuales puros (= 0).
// Sirve como molde comun para que Medico, Enfermero y Administrativo hereden sus atributos.

#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
using namespace std;

class Empleado {
protected:
	string cedula;
	string nombre;
	double salarioBase;
public:
	Empleado(string c, string n, double s);
	virtual ~Empleado();
	
	virtual double calcularSalarioNeto() const = 0; 
	virtual string getTipo() const = 0;
	
	string getCedula() const;
	string getNombre() const;
	double getSalarioBase() const;
};
#endif
