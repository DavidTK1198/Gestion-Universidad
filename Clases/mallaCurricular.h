#pragma once
#include <iostream>
#include <sstream>
#include "Excepciones.h"
#include "ArregloGen.h"
#include "Curso.h"

using namespace std;
class Carrera;
class Curso;
class mallaCurricular
{
	private:
		Carrera* carre;
		Lista<Curso>* listC;
	public:
		mallaCurricular(Carrera*);
		virtual ~mallaCurricular();
		Carrera* getCarrera();
		void setCarrera(Carrera*);
		string toString();
		Lista<Curso>* getLista();
		void agregarCurso(Curso*);
		string toStringEspecial();
		void asignarCodCurAuto();



};

