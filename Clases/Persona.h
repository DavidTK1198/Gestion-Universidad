#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Persona
{
	protected:
		string cedula;
		string nombre;
		string telefono;
	public:
		Persona(string, string, string);
		Persona();
		virtual ~Persona();
		string getCedula();
		string getNombre();
		string getTelefono();
		void setNombre(string);
		void setTelefono(string);
		virtual string toString();
};

