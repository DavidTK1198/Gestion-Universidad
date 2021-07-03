#pragma once
#include <iostream>
#include <sstream>
#include "Grupo.h"
#include "Escuela.h"
#include "Facultad.h"
#include "mallaCurricular.h"
#include "Lista.h"
#include "Estudiante.h"
using namespace std;
class Grupo;
class Escuela;
class Facultad;
class mallaCurricular;
class Carrera
{
	private:
		string codigo;
		string descripcion;
		bool estado;
		Escuela* escue;
		Facultad* facul;
		mallaCurricular* mallaC;
		Lista<Estudiante>* empadronados;
		
	public:
		Carrera(string, string, bool, Escuela*,Facultad*);
		virtual ~Carrera();
		string getCodigo();
		string getDescripcion();
		bool getEstado();
		Escuela* getEscuela();
		Facultad* getFacultad();
		mallaCurricular* getMalla();
		string toString()const;
		string toStringForEspecial();
		string toStringEstudiantesXcarr();
		Lista<Estudiante>* getListaEst();
		void setCodigo(string);
		void setDescripcion(string);
		void setEstado(bool);
		void setEscuela(Escuela*);
		void setFacultad(Facultad*);
		void setMalla(mallaCurricular*);
		void AsignarCodigoCarr();
		void agregarEstudiante(Estudiante*);
		void setListaest(Lista<Estudiante>*);
		friend ostream& operator <<(ostream&, Carrera&);
		bool operator == (string&);
};

