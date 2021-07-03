#pragma once
#include "Usuario.h"
class Profesor;
class UsuarioProfesor :
	public Usuario
{
private:
	Profesor* profe;
public:
	UsuarioProfesor(string, string, string, string);
	virtual ~UsuarioProfesor();
	string toString();
	virtual void setProfesor(Profesor*);
	virtual void setEstudiante(Estudiante*) { throw; }
	virtual Estudiante* getEstudiante() { throw; }
	virtual Profesor* getProfesor();
};
