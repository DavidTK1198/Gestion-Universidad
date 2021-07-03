#pragma once
#include "Usuario.h"
class UsuarioManten:public Usuario
{
	public:
		UsuarioManten(string, string, string, string);
		virtual ~UsuarioManten();
		string toString();
		virtual void setProfesor(Profesor*) { throw; }
		virtual void setEstudiante(Estudiante*) { throw; }
		virtual Estudiante* getEstudiante() { throw; }
		virtual Profesor* getProfesor() { throw; }
};

