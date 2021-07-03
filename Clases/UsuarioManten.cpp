#include "UsuarioManten.h"

UsuarioManten::UsuarioManten(string id, string nom, string tel, string cla): Usuario(id,nom,tel,cla)
{
	rol = "Mantenimiento";
}

UsuarioManten::~UsuarioManten()
{
}

string UsuarioManten::toString()
{
	stringstream m;
	m << Usuario::toString() << endl;
	return m.str();
}
