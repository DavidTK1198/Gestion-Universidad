#pragma once
#include "Lista.h"
#include "Escuela.h"
#include <iostream>
#include <sstream>
using namespace std;
template<class T>
class Lista;
class Escuela;
class Facultad {
private:
	Lista<Escuela>* ListaEsc;
	string nombre;
public:
	Facultad(string);
	virtual ~Facultad();
	string getNom();
	void setNom(string);
	string toStringFacultad() const;
	Lista<Escuela>* getListaEsc();
	bool agregarEscuela(Escuela*);
	string toStringEscuelas();
	friend ostream& operator <<(ostream&, const Facultad&);
	bool operator==(string&);
};


