#include "Universidad.h"
#include "mallaCurricular.h"
#include "Usuario.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Carrera.h"


Universidad::Universidad()
{
	listU = new Lista<Usuario>;
	listaCL = new Lista<CicloLectivo>;
	malla = new Lista<mallaCurricular>;
	listaFacul = new Lista<Facultad>;
	ListaEstudiante = new Lista<Estudiante>;
	ListaProfesor = new Lista<Profesor>;   
	ListaCar = new Lista<Carrera>;
}

void Universidad::ingresarUsuario(Usuario* us) {
	listU->agregarObj(us);
}

string Universidad::imprimirUsuarios()
{
	return listU->toStringLista();
}

Universidad::~Universidad()
{
	delete listU;
	delete listaCL;
	delete malla;
	delete listaFacul;
	delete ListaEstudiante;
	delete ListaProfesor;
	delete ListaCar;
}

Usuario* Universidad::buscarUsuario(int pos)
{
	return listU->buscarObj(pos);
}

Usuario* Universidad::buscarUsuarioPorString(string r)
{
	return listU->buscarstring(r);
}

Lista<Usuario>* Universidad::getListaUsuar()
{
	return listU;
}

int Universidad::getCantidad()
{
	return listU->getCant();
}

void Universidad::ingresarCicloLec(CicloLectivo* le)
{
	listaCL->agregarObj(le);
}

string Universidad::toStringCL() const
{
	return listaCL->toStringLista();
}

Lista<CicloLectivo>* Universidad::getListaCL()
{
	return listaCL;
}

int Universidad::getCantCL()
{
	return listaCL->getCant();
}

Lista<mallaCurricular>* Universidad::getListMalla()
{
	return malla;
}

void Universidad::ingresarMalla(mallaCurricular* m)
{
	malla->agregarObj(m);
}

int Universidad::getCantMalla()
{
	return malla->getCant();
}


void Universidad::setListaUsuarios(Lista<Usuario>* list)
{
	this->listU = list;
}

bool Universidad::agregarFacultad(Facultad* f)
{
	return listaFacul->agregarObj(f);
}

string Universidad::toStringFacul()
{
	return listaFacul->toStringLista();
}

int Universidad::getCantFacul()
{
	return listaFacul->getCant();
}

Lista<Facultad>* Universidad::getListaFacul()
{
	return listaFacul;
}

void Universidad::setFacultad(Lista<Facultad>* f)
{
	listaFacul = f;
}

bool Universidad::agregarEstudiante(Estudiante* es)
{
	return ListaEstudiante->agregarObj(es);
}

string Universidad::toStringEst()
{
	return ListaEstudiante->toStringLista();
}

int Universidad::getCantEst()
{
	return ListaEstudiante->getCant();
}

Lista<Estudiante>* Universidad::getListaEst()
{
	return ListaEstudiante;
}

bool Universidad::agregarProfesor(Profesor* pro)
{
	return ListaProfesor->agregarObj(pro);
}

string Universidad::toStringPro()
{
	return ListaProfesor->toStringLista();
}

int Universidad::getCantPro()
{
	return ListaProfesor->getCant();
}

Lista<Profesor>* Universidad::getListaPro()
{
	return ListaProfesor;
}

bool Universidad::agregarCarrera(Carrera* ca)
{
	return ListaCar->agregarObj(ca);
}

string Universidad::toStringCarr()
{
	return ListaCar->toStringLista();
}

int Universidad::getCantCarr()
{
	return ListaCar->getCant();
}

void Universidad::setEstudiantes(Lista<Estudiante>* x)
{
	ListaEstudiante = x;
}

Lista<Carrera>* Universidad::getListaCarr()
{
	return ListaCar;
}

Estudiante* Universidad::buscarEstudiante(string x)
{
	return ListaEstudiante->buscarstring(x);
}

Profesor* Universidad::buscarProfesor(string x)
{
	return ListaProfesor->buscarstring(x);
}

Carrera* Universidad::buscarCarrera(string x)
{
	return ListaCar->buscarstring(x);
}

mallaCurricular* Universidad::buscarMalla()
{
	return nullptr;
}

CicloLectivo* Universidad::buscarCicloLectivo(int n)
{
	return listaCL->buscarGenerico(n);
}



Facultad* Universidad::buscarFacultad(string x)
{
	return listaFacul->buscarstring(x);
}

void Universidad::setCarreras(Lista<Carrera>* x)
{
	ListaCar = x;
}



void Universidad::setListaCiclo(Lista<CicloLectivo>* x)
{
	listaCL = x;
}

void Universidad::setProfesores(Lista<Profesor>* x)
{
	ListaProfesor = x;
}

void Universidad::setMallas(Lista<mallaCurricular>* x)
{
	malla = x;
}



