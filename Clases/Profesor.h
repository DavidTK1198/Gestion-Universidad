#pragma once
#include "Universidad.h"
#include "Escuela.h"
#include "Carrera.h"
#include "UsuarioProfesor.h"
#include "Horario.h"

using namespace std;
class Carrera;
class Escuela;
class Profesor;
class Universidad;
class Grupo;
class Profesor:public Persona
{
	private:
		Escuela* escuelita;
		Carrera* carr;
		int gradoAcademico;
		Usuario* us;
		Lista<Grupo>* listGru;
		Horario* hor;
		//UsuarioPro* us;
	public:
		Profesor(string, string, string, Escuela*,Carrera*,int);
		virtual ~Profesor();
		Escuela* getEscuela();
		Carrera* getCarrera();
		int getGradoAca();
		string toString();
		string toStringEsp();
		bool agregarGrupo(Grupo*);
		Usuario* getUsuario();
		string toStringActas();
		Lista<Grupo>* getListaGru();
		Horario* getHorario();
		void setUsuarioProfesor(Usuario*);
		void setEscuela(Escuela*);
		void setCarrera(Carrera*);
		void setGradoAca(int);
		string convirtiendoGrado(int);
		friend ostream& operator<<(ostream&, Profesor&);
		bool operator == (string&);

};

