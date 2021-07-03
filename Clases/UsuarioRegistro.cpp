#include "UsuarioRegistro.h"
UsuarioRegistro::UsuarioRegistro(string id, string nom, string tel, string clav) :Usuario(id, nom, tel, clav) {

	this->rol = "Registro";

}
UsuarioRegistro::UsuarioRegistro() : Usuario()
{
	rol = "Registro";
}
UsuarioRegistro::~UsuarioRegistro() {
}


string UsuarioRegistro::toString() {
	stringstream s;
	s << Usuario::toString() << endl;
	return s.str();
}

