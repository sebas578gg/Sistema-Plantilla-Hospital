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
