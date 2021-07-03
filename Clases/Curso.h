#pragma once
#include <iostream>
#include <sstream>
//#include "Excepciones.h"
#include "ArregloGen.h"
#include "Grupo.h"
#include "CicloLectivo.h"
#include "Carrera.h"
#include <time.h>
#include <stdlib.h>
using namespace std;
class Carrera;
class Grupo;
class Curso
{
private:
	string codigo;
	string nombreOficial;
	string tipoCurso;
	int creditos;
	int horasSemanales;
	bool estado;
	bool GaPe;
	int cali;
	Arreglo<Grupo>* arrGru;
	Lista<Curso>* lista;
	CicloLectivo* cicloLectivo;
	Carrera* carrera;
public:
	Curso(string, string, int, int, bool, int, CicloLectivo*);
	virtual ~Curso();
	string getCodigo();
	string getNombreO();
	string getTipoCurso();
	Lista<Curso>* getlistaRequisitos();
	Carrera* getCarrera();
	string toStringMallaCurr();
	string toStringNota();
	string toStringEspecial();
	string toStringRequisitos();
	string toStringHistorialA();
	int getcali();
	int getCreditos();
	int getHorasSemanales();
	bool getEstado();
	bool getGaPe();
	void setCodigo(string);
	void setNombreOficial(string);
	void setTipoCurso(string);
	void setCreditos(int);
	void setHorasSemanales(int);
	void setEstado(bool);
	void setCali(int);
	void darDatosdelCurso(Grupo*);
	void setGaPe(bool);
	string stringEspecialCali();
	void setCarrera(Carrera*);
	void agregarGrupo(Grupo*);
	bool agregarCurso(Curso*);
	CicloLectivo* getCicloL();
	Arreglo<Grupo>* getArreglo();
	string detGaPe();
	void setCicloLec(CicloLectivo*);
	friend ostream& operator<<(ostream&, Curso&);
	bool operator == (int);
};

