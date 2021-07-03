#include "Persona.h"
Persona::Persona(string id, string nom, string tel) {
	cedula = id;
	nombre = nom;
	telefono = tel;
}
Persona::Persona() {
	cedula = "";
	nombre = "";
	telefono = "";
}
Persona::~Persona() {

}

string Persona::getCedula() {
	return cedula;
}
string Persona::getNombre() {
	return nombre;
}
string Persona::getTelefono() {
	return telefono;
}
void Persona::setNombre(string nom) {
	nombre = nom;
}
void Persona::setTelefono(string tel) {
	telefono = tel;
}

string Persona::toString()
{
	return string();
}
