#pragma once
#include "Lista.h"
#include <sstream>
#include <iostream>
#include "CicloLectivo.h"
#include "mallaCurricular.h"
#include "Facultad.h"
using namespace std;
template<class T>
class Lista;
class Facultad;
class Usuario;
class mallaCurricular;
class Profesor;
class Estudiante;
class Carrera;
class Universidad
{
	private:
		Lista<Usuario>* listU;
		Lista<CicloLectivo>* listaCL;
		Lista<mallaCurricular>* malla;
		Lista<Facultad>* listaFacul;
		Lista<Estudiante>* ListaEstudiante; 
		Lista<Profesor>* ListaProfesor;
		Lista<Carrera>* ListaCar;


	public:
		Universidad();
		virtual void ingresarUsuario(Usuario*);
		virtual string imprimirUsuarios();
		virtual ~Universidad();
		virtual Usuario* buscarUsuario(int);
		virtual Usuario* buscarUsuarioPorString(string);
		virtual Lista<Usuario>* getListaUsuar();
		virtual int getCantidad();
		virtual void ingresarCicloLec(CicloLectivo*);
		virtual string toStringCL()const;
		virtual Lista<CicloLectivo>* getListaCL();
		virtual int getCantCL();
		virtual Lista<mallaCurricular>* getListMalla();
		virtual void ingresarMalla(mallaCurricular*);
		virtual int getCantMalla();
		virtual void setListaUsuarios(Lista<Usuario>*);
		virtual bool agregarFacultad(Facultad*);
		virtual string toStringFacul();
		virtual int getCantFacul();
		virtual Lista<Facultad>* getListaFacul();
		virtual void setFacultad(Lista<Facultad>*);
		virtual bool agregarEstudiante(Estudiante*);
		virtual string toStringEst();
		virtual int getCantEst();
		virtual Lista<Estudiante>* getListaEst();
		virtual bool agregarProfesor(Profesor*);
		virtual string toStringPro();
		virtual int getCantPro();
		virtual Lista<Profesor>* getListaPro();
		virtual bool agregarCarrera(Carrera*);
		virtual string toStringCarr();
		virtual int getCantCarr();
		void setEstudiantes(Lista<Estudiante>*);
		virtual Lista<Carrera>* getListaCarr();
		Estudiante* buscarEstudiante(string);
		Profesor* buscarProfesor(string);
		Carrera* buscarCarrera(string);
		mallaCurricular* buscarMalla();
		CicloLectivo* buscarCicloLectivo(int);
		Facultad* buscarFacultad(string);
		virtual void setCarreras(Lista<Carrera>*);
		virtual void setListaCiclo(Lista<CicloLectivo>*);
		void setProfesores(Lista<Profesor>*);
		void setMallas(Lista<mallaCurricular>*);
		




};

