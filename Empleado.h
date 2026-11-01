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
