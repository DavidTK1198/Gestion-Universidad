#pragma once
#include "Persona.h"
#include "Escuela.h"
#include "Carrera.h"
#include "Curso.h"
#include "Usuario.h"
#include "Horario.h"
using namespace std;

class Escuela;
class Carrera;
class HistorialAcademico;
class Universidad;
class Curso;
class Estudiante :public Persona
{
	private:
		string carnet;
		Escuela* escuela;
		Carrera* carrera;
		HistorialAcademico* h_a;
		Usuario* usE;
		Horario* horario;
		Lista<Curso>* CursosMatriculados;

	public:
		Estudiante(string, string,string,string, Escuela*, Carrera*,HistorialAcademico*);
		virtual ~Estudiante();
		virtual string toString();
		Escuela* getEscuela();
		Carrera* getCarrera();
		string getCarnet();
		Horario* getHorario();
		Usuario* getUsuarioEst();
		HistorialAcademico* getHistorialA();
		Lista<Curso>* getListaCurso();
		void setHistorialA(HistorialAcademico*);
		void setEscuela(Escuela*);
		void setCarrera(Carrera*);
		void setCarnet(string);
		void setUsuarioEstudiante(Usuario*);
		bool matricular(CicloLectivo*, Curso*);
		void rellenarMatriz(int, int, int, Grupo*);
		bool agregarCursoMatriculado(Curso*);
		string toStringEspecial();
	
		Curso* buscarCur(Curso*);
		friend ostream& operator <<(ostream&, Estudiante&);
		bool operator == (string&);

};

