#pragma once
#include "Usuario.h"
#include <sstream>
#include <iostream>
using namespace std;
class Estudiante;
class UsuarioEstudiante :
	public Usuario
{
private:
	Estudiante* estudi;
public:
	UsuarioEstudiante(string, string, string, string);
	virtual ~UsuarioEstudiante();
	string toString();
	virtual void setProfesor(Profesor*){ throw; }
	virtual void setEstudiante(Estudiante*);
	virtual Estudiante* getEstudiante();
	virtual Profesor* getProfesor() { throw; }
};

