#pragma once
#include <iostream>
#include "Persona.h"
using namespace std;
class Persona;
class Usuario;
class Estudiante;
class Profesor;
class Usuario:public Persona
{
	protected:
		string rol;
		string clave;
		bool estadoU;
	public:
		Usuario(string, string, string, string);
		Usuario();
		virtual ~Usuario();
		virtual Estudiante* getEstudiante() = 0;
		virtual Profesor* getProfesor() = 0;
		string toString() const;
		string getClave();
		string getRol();
		bool getEstadoU();
		void setContra(string);
		virtual void setProfesor(Profesor*) = 0;
		virtual void setEstudiante(Estudiante*) = 0;
		friend ostream& operator<<(ostream&, const Usuario&);
		bool operator == (string&);
		
};
