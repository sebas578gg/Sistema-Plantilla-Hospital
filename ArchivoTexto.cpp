#include "ArchivoTexto.h"
#include <fstream>
#include <sstream>
// ios::app (append): abre y escribe al final sin borrar los registros anteriores.
void ArchivoTexto::guardar(string ruta, string contenido) {
	ofstream archivo(ruta, ios::app); 
	if(archivo.is_open()) { archivo << contenido << endl; archivo.close(); }
}
// ios::trunc (truncate): borra el contenido previo para guardar la lista actualizada desde cero.
void ArchivoTexto::sobreescribir(string ruta, string contenido) {
	ofstream archivo(ruta, ios::trunc); 
	if(archivo.is_open()) { archivo << contenido; archivo.close(); }
}
// Lee todo el archivo y lo devuelve como string usando el buffer de lectura (rdbuf).
string ArchivoTexto::leer(string ruta) {
	ifstream archivo(ruta);
	stringstream buffer;
	if(archivo.is_open()) { buffer << archivo.rdbuf(); archivo.close(); }
	return buffer.str();
}
