// Representa un puesto o cargo asignable a un departamento.

#ifndef PUESTO_H
#define PUESTO_H
#include <string>
using namespace std;

class Puesto {
private:
	string nombrePuesto;
public:
	Puesto(string n);
	string getNombre() const;
};
#endif
