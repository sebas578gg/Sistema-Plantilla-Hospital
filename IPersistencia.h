// INTERFAZ (Contrato de persistencia):
// Clave para la defensa: Principio de Inversion de Dependencias (DIP) y Polimorfismo.
// El sistema no se ata a archivos de texto; si manana se cambia a una base de datos,
// solo se crea otra clase derivada sin alterar el ControladorPlanilla.
#ifndef IPERSISTENCIA_H
#define IPERSISTENCIA_H
#include <string>
using namespace std;

class IPersistencia {
public:
	virtual void guardar(string ruta, string contenido) = 0;
	virtual void sobreescribir(string ruta, string contenido) = 0; 
	virtual string leer(string ruta) = 0;
	virtual ~IPersistencia() {}
};
#endif
