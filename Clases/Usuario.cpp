#include "Usuario.h"
#include "Profesor.h"
#include "Estudiante.h"
Usuario::Usuario(string id, string nom, string tel,string contra):Persona(id,nom,tel) {
	clave = contra;
	estadoU = true;
	rol = "";

}
Usuario::Usuario():Persona() {
	clave = "";
	estadoU = true;
}
Usuario::~Usuario() {
}
string Usuario::toString()const{
	stringstream s;
	s << "\t\t-----------------------Datos del Usuario----------------\t\t" << endl;
	s << "\t\t" << "Nombre de Usuario: " << nombre<< "\t\t" << endl;
	s << "\t\t" << "Numero de Cedula: " << cedula << "\t\t" << endl;
	s << "\t\t" << "Numero de Telefono: " <<telefono << "\t\t" << endl;
	s << "\t\t" << "Rol del usuario: " << rol << "\t\t" << endl;
	if (estadoU) {
		s << "\t\t" << "Estado de usuario: " << "Activo" << "\t\t" << endl;
	}
	else {
		s << "\t\t" << "Estado de usuario: " << "Inactivo" << "\t\t" << endl;
	}
	return s.str();
}

string Usuario::getClave() {
	return clave;
}

string Usuario::getRol()
{
	return rol;
}

bool Usuario::getEstadoU() {
	return estadoU;
}

void Usuario::setContra(string contraa) {
	clave = contraa;
}

bool Usuario::operator==(string& id)
{
	return (this->cedula == id);
}

ostream& operator<<(ostream& out , const Usuario& us)
{
	return out << us.toString() << endl;

}

