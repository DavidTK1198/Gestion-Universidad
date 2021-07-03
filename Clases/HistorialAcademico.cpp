#include "HistorialAcademico.h"
#include "Estudiante.h"

HistorialAcademico::HistorialAcademico(Estudiante* es)
{
	estudiante = es;
	list = new Lista<Curso>;

}

HistorialAcademico::~HistorialAcademico()
{
	delete list;

}

void HistorialAcademico::agregarCurso(Curso* cur)
{
	list->agregarObj(cur);
}

Lista<Curso>* HistorialAcademico::materiasApr()
{
	int contador = 0;
	int numerito = list->getCant();
	Lista<Curso>* aux = new Lista<Curso>;
	Curso* malla = NULL;
	list->inicializarActual();
	while (contador < numerito) {
		contador++;
		malla = list->getTipo();
		if (malla->getGaPe() == true) {
			aux->agregarObj(malla);
		}
		list->siguienteNodo();
	}
	return aux;
}

Lista<Curso>* HistorialAcademico::materiasRep()
{
	int contador = 0;
	int numerito = list->getCant();
	Lista<Curso>* aux = new Lista<Curso>;
	Curso* malla = NULL;
	list->inicializarActual();
	while (contador < numerito) {
		contador++;
		malla = list->getTipo();
		if (malla->getGaPe() == false) {
			aux->agregarObj(malla);
		}
		list->siguienteNodo();
	}
	return aux;
}

Lista<Curso>* HistorialAcademico::getListaGeneral()
{
	return list;
}

bool HistorialAcademico::compararReqMatApr(Lista<Curso>* list)
{
	Lista<Curso>* aux = materiasApr();
	int cont = 0;
	int cont2 = 0;
	int cant = aux->getCant();
	int cont1 = 0;
	int cant1 = list->getCant();
	Curso* curAux1 = NULL;
	Curso* curAux2 = NULL;

	list->inicializarActual();
	aux->inicializarActual();
	while (cont1 < cant1) {
		cont1++;
		curAux2 = list->getTipo();
		while (cont < cant) {
			cont++;
			curAux1 = aux->getTipo();
			if (curAux2->getNombreO() == curAux1->getNombreO()) {
				cont2++;
				break;
			}
			aux->siguienteNodo();
		}
		cont = 0;
		list->siguienteNodo();
	}
	if (cont2 == cant1) {
		return true;
	}
	return false;
}

Estudiante* HistorialAcademico::getEstudiante()
{
	return estudiante;
}

void HistorialAcademico::setEstudiante(Estudiante* es)
{
	estudiante = es;
}

bool HistorialAcademico::buscarCurso(Curso* cursito)
{
	Lista<Curso>* cur = materiasApr();//fundamentos y mat.infor
	int con = 0;
	cur->inicializarActual();
	Curso* cursitoo = NULL;
	while (con < cur->getCant()) {
		con++;
		cursitoo = cur->getTipo();
		if (cursitoo->getCodigo() == cursito->getCodigo()) {
			return true;
		}
		cur->siguienteNodo();
	}
	return false;
}

string HistorialAcademico::toString()
{
	stringstream s;
	s << "--------------Mostrando Historial academico del estudiante----------" << endl;
	if (estudiante) {
		s << "Estudiante asociado: " << estudiante->getNombre() << endl;
	}
	else {
		s << "Sin estudiante asociado." << endl;
	}
	s << "-----------Materias Aprobadas------------" << endl;
	Lista<Curso>* aux = materiasApr();
	s << aux->toStringLista() << endl;
	s << endl;
	s << "-----------Materias Reprobadas------------" << endl;
	Lista<Curso>* auxx = materiasRep();
	s << auxx->toStringLista() << endl;
	s << endl;
	return s.str();
}

string HistorialAcademico::toStringEsp()
{
	stringstream m;
	int contador = 0;
	int numerito = list->getCant();	
	Curso* malla = NULL;
	list->inicializarActual();
	m << "Codigo" << "\t\t" << "Curso" << "\t\t" << "Creditos" << "\t\t" << "Nota final" << "\t\t" << "Estado" << endl;
	while (contador < numerito) {
		contador++;
		malla = list->getTipo();
		m << malla->toStringHistorialA();
		list->siguienteNodo();
	}
	return m.str();
}

Lista<Curso>* HistorialAcademico::buscarCursosMisCL(int ani)
{
	Lista<Curso>* lc = new Lista<Curso>;
	Curso* aux = NULL;
	lc = list->BuscarListaCompletaPInt(ani);
	if (!lc) {
		return NULL;
	}
	return lc;
}
