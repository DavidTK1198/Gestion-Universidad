#pragma once
#include <sstream>
#include <iostream>
#include "Universidad.h"
#include "Curso.h"
#include "Estudiante.h"

#include <Windows.h>
using namespace std;


class Matricula
{
	private:
		Universidad* uni;
		Estudiante* est;
	public:
		Matricula(Universidad*,Estudiante*);
		virtual ~Matricula();
		bool matricular(CicloLectivo*);
		mallaCurricular* buscarCarrera();
		Lista<Curso>* retornaCurMisCL(CicloLectivo*,mallaCurricular*,int);
		Estudiante* buscarEstudiante(string,Arreglo<Estudiante>*);
		int mostrarDias();
		bool compararHistAcaReq(HistorialAcademico*,Lista<Curso>*);
		bool verificaHorario(string,Horario*,Grupo*);
		void setEstudiante(Estudiante*);
};

