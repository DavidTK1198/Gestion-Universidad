#pragma once
#include <sstream>
#include <iostream>
#include "Excepciones.h"
using namespace std;
class Grupo;
int const filas = 7;
int const columas = 14;
class Horario {
private:
	Grupo*** matGru;


public:
	Horario();
	virtual ~Horario();
	bool agregarGrupo(Grupo*);
	string toString();
	Grupo* buscar(int, int);
	string determinarDia(int);
	int determinarHora(int);
	int determinarHoraInversa(int);
	Grupo* buscarGrupo(Grupo*);
	bool rellenarMatriz(int,int,int,Grupo*);
	string determinaAMPM(int);
	bool eliminarGrupoEspecifico(string);
	

};

