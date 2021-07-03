#include "UsuarioEscuela.h"
UsuarioEscuela::UsuarioEscuela(string id, string nom, string tel, string cla) : Usuario(id, nom, tel, cla)
{
	rol = "Escuela";
}

UsuarioEscuela::~UsuarioEscuela()
{
}

string UsuarioEscuela::toString()
{
	stringstream m;
	m << Usuario::toString() << endl;
	return m.str();
}
