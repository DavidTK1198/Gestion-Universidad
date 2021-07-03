#include "UsuarioAdmin.h"
UsuarioAdmin::UsuarioAdmin(string id, string nom, string tel, string clav) :Usuario(id,nom,tel,clav) {
	
	this->rol = "Administrador";

}
UsuarioAdmin::UsuarioAdmin():Usuario()
{
	rol = "Administrador";
}
UsuarioAdmin::~UsuarioAdmin() {
}


string UsuarioAdmin::toString() {
	stringstream s;
	s << Usuario::toString()<< endl;
	return s.str();
}

