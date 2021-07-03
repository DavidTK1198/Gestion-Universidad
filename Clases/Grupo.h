#pragma once
//#include "ListaEstudiante.h"
#include <iostream>
#include <sstream>
#include "Horario.h"
#include "Profesor.h"
#include <ostream>
#include "ArregloGen.h"
using namespace std;
class Profesor;
class Estudiante;
class Grupo;
class Curso;
class Grupo
{
	private:
		string NCR;
		int numero;
	    Profesor* profe;
		Curso* curso;	
		int capacidad;
		string horario;
		Arreglo<Estudiante>* arr;
	public:
		Grupo(string, int, Profesor*, int);
		virtual ~Grupo();
		string getNCR();
		int getNumeroGrupo();
		Profesor* getProfesor();
		int getCapacidad();
		string toString ();
		string toStringForEspe();
		string toStrinGruPorMat();
		string toStringProEst();
		string toStringActas();
		Curso* getCurso();
		string getHorario();
		void setNCR(string);
		void setNumero(int);
		void setProfesor(Profesor*);
		void setCapacidad(int);
		void setCurso(Curso*);
		void detNCRAutom();
		void MoviendoCapacidad();
		void agregarEstudiante(Estudiante*);
		void setHorario(string);
		Arreglo<Estudiante>* getArreglo();
		char cambiarDia(int);
		string verificaDia(string);
		friend ostream& operator <<(ostream&,Grupo&);
		bool operator == (string&);

};
//Grupo()

