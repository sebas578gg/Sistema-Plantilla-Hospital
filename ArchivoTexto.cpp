#include "ArchivoTexto.h"
#include <fstream>
#include <sstream>

void ArchivoTexto::guardar(string ruta, string contenido) {
	ofstream archivo(ruta, ios::app); 
	if(archivo.is_open()) { archivo << contenido << endl; archivo.close(); }
}
void ArchivoTexto::sobreescribir(string ruta, string contenido) {
	ofstream archivo(ruta, ios::trunc); 
	if(archivo.is_open()) { archivo << contenido; archivo.close(); }
}
string ArchivoTexto::leer(string ruta) {
	ifstream archivo(ruta);
	stringstream buffer;
	if(archivo.is_open()) { buffer << archivo.rdbuf(); archivo.close(); }
	return buffer.str();
}
