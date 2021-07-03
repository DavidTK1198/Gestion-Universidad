#pragma once
#include "Universidad.h"
#include <fstream>
#include <iostream>
#include <string> 
#include <sstream>
#include <stdio.h>      
#include <stdlib.h> 
#include "UsuarioAdmin.h"
#include "Lista.h"
#include "UsuarioManten.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "UsuarioEstudiante.h"
#include "UsuarioEscuela.h"
#include "CicloLectivo.h"
#include "HistorialAcademico.h"
#include "ArregloGen.h"
#include "Grupo.h"
using namespace std;
template <class T>
class Lista;
class Universidad;
class Usuario;
class GestorDeArchivos
{
public:
	GestorDeArchivos(string,string,string,string,string);
	virtual ~GestorDeArchivos();
	virtual bool guardarListaUsuarios(Lista<Usuario>*);
	Lista<Usuario>* recuperarListaUsuario();
	virtual bool guardarListaEs(Lista<Estudiante>*);
	virtual bool guardarHistorialA(HistorialAcademico*);
	void recuperarHistorialA();
	Lista<Estudiante>* recuperarListaEs(Carrera*);
	void setUniversiad(Universidad*);
	virtual bool guardarCiclos(Lista<CicloLectivo>*);
	Lista<CicloLectivo>* recuperarListaCiclo();
	bool guardarCarreras(Lista<Carrera>*);
	bool guardarMallas(Lista<mallaCurricular>*);
	Lista<Carrera>* recuperarCarreras();
	Lista<mallaCurricular>* recuperarMallas();
	bool guardarGrupos(Arreglo<Grupo>*);
	void recuperarGrupo(Curso*);
	virtual bool guardarCursosMatriculados();
	void cursosMatriculadosRecuperados(); 
	bool guardarRequisitos(Lista<Curso>*,Curso*,Carrera*);
	void asignarRequisito();
	bool guardarProfesores(Lista<Profesor>*);
	Lista<Profesor>* recuperarProfesores();
	CicloLectivo* mismoAnio(int,int,Lista<CicloLectivo>*);
	bool verificaHorario(string, Horario*, Grupo*);
	virtual void abrirFlujoModoEscritura();
	virtual void abrirFlujoModoLectura();
	virtual void cerrarFlujo();
	bool guardardatos();
	void cargarDatos();


private:
	string usuarios;
	string estudiantes;
	string profesores;
	string carreras;
	string mallas;
	fstream archivo;
	fstream archivo2;
	fstream estudiante;
	fstream historialA;
	string malla = "Carreras/grupos.txt";
	string req = "Carreras/requisitos.txt";
	string est = "Persona/Estudiantes.txt";
	string histA = "Universidad/Historial.txt";
	Universidad* uni;
};

//Recuperar los cursos que estan matriculados de cada estudiante...
//---->