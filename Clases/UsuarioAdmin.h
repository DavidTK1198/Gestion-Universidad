#pragma once
#include "Usuario.h"
#include <iostream>

using namespace std;
class Universidad;
class Usuario;
class UsuarioAdmin :
	public Usuario
{
	
	public:
		UsuarioAdmin(string,string, string, string);
		UsuarioAdmin();
		virtual ~UsuarioAdmin();
		virtual string toString();
		virtual void setProfesor(Profesor*) { throw; }
		virtual void setEstudiante(Estudiante*) { throw; }
		virtual Estudiante* getEstudiante() { throw; }
		virtual Profesor* getProfesor(){ throw; }
};

