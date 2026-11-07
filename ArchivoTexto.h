#ifndef ARCHIVOTEXTO_H
#define ARCHIVOTEXTO_H
#include "IPersistencia.h"
// Implementacion concreta de IPersistencia para lectura y escritura en archivos planos (.txt).
class ArchivoTexto : public IPersistencia {
public:
	void guardar(string ruta, string contenido) override;
	void sobreescribir(string ruta, string contenido) override;
	string leer(string ruta) override;
};
#endif
