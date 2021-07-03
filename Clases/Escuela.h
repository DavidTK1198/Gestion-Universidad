#pragma once
#include <iostream>
#include <sstream>
#include "Carrera.h"
#include "Lista.h"
#include "Profesor.h"
using namespace std;
template<class T>
class lista;
class Carrera;
class Profesor;
class Escuela
{
	private:
		string nombre;
		Lista<Carrera>* listaCar;
		Lista<Profesor>* listPro;//Caammanio...->Busca--->Muestran las carreras de  
	public:
		Escuela(string);
		virtual ~Escuela();
		string getNombre();
		void setNombre(string);
		Lista<Carrera>* getLista();
		Lista<Profesor>* getListaPro();
		string toStringEscuela() const;
		bool agregarCarreras(Carrera*);
		bool agregarProfesor(Profesor*);
		void asignarCodigoA();
		friend ostream& operator <<(ostream&, const Escuela&);
		bool operator==(string&);


};


