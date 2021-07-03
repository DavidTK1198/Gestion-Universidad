#pragma once
#include <iostream>
#include <sstream>
#include "Lista.h"
#include "Curso.h"
using namespace std;
class Estudiante;
class HistorialAcademico
{
	private:
		Estudiante* estudiante;
		Lista<Curso>* list;
	public:	
		HistorialAcademico(Estudiante*);
		virtual ~HistorialAcademico();
		void agregarCurso(Curso*);
		Lista<Curso>* materiasApr();
		Lista<Curso>* materiasRep();
		Lista<Curso>* getListaGeneral();
		bool compararReqMatApr(Lista<Curso>*);
		Estudiante* getEstudiante();
		void setEstudiante(Estudiante*);
		bool buscarCurso(Curso*);
		string toString();
		string toStringEsp();
		
		Lista<Curso>* buscarCursosMisCL(int);

		

};

