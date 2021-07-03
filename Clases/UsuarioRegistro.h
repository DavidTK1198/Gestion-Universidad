#pragma once
#include "Usuario.h"
class UsuarioRegistro :
	public Usuario
{

public:
	UsuarioRegistro(string, string, string, string);
	UsuarioRegistro();
	virtual ~UsuarioRegistro();
	virtual string toString();
	virtual void setProfesor(Profesor*) { throw; }
	virtual void setEstudiante(Estudiante*) { throw; }
	virtual Estudiante* getEstudiante() { throw; }
	virtual Profesor* getProfesor() { throw; }
};

