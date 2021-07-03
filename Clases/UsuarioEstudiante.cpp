#include "UsuarioEstudiante.h"
#include "Estudiante.h"

UsuarioEstudiante::UsuarioEstudiante(string id, string nom, string tel, string cla) : Usuario(id, nom, tel, cla)
{
	rol = "Estudiante";
	estudi = NULL;
}

UsuarioEstudiante::~UsuarioEstudiante()
{
}

string UsuarioEstudiante::toString()
{
	stringstream m;
	m << Usuario::toString() << endl;
	return m.str();
}

void UsuarioEstudiante::setEstudiante(Estudiante* es)
{
	estudi = es;
	estudi->setUsuarioEstudiante(this);
}

Estudiante* UsuarioEstudiante::getEstudiante()
{
	return estudi;
}

