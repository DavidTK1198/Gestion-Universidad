#include "UsuarioProfesor.h"
#include "Profesor.h"
UsuarioProfesor::UsuarioProfesor(string id, string nom, string tel, string cla) : Usuario(id, nom, tel, cla)
{
	rol = "Profesor";
	profe = NULL;
}

UsuarioProfesor::~UsuarioProfesor()
{
}

string UsuarioProfesor::toString()
{
	stringstream m;
	m << Usuario::toString() << endl;
	return m.str();
}

void UsuarioProfesor::setProfesor(Profesor* pr)
{
	profe = pr;
	profe->setUsuarioProfesor(this); //(Usuario*)
}

Profesor* UsuarioProfesor::getProfesor()
{
	return profe;
}
