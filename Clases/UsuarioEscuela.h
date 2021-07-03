#pragma once
#include "Usuario.h"
class UsuarioEscuela :
	public Usuario
{
public:
	UsuarioEscuela(string, string, string, string);
	virtual ~UsuarioEscuela();
	string toString();
	virtual void setProfesor(Profesor*) { throw; }
	virtual void setEstudiante(Estudiante*) { throw; }
	virtual Estudiante* getEstudiante() { throw; }
	virtual Profesor* getProfesor() { throw; }
};

