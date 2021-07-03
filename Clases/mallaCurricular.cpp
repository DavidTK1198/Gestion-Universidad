#include "mallaCurricular.h"
#include "Carrera.h"
mallaCurricular::mallaCurricular(Carrera* carr)
{
	carre = carr;
	listC = new Lista<Curso>;
}

mallaCurricular::~mallaCurricular()
{
	delete listC;
}

Carrera* mallaCurricular::getCarrera()
{
	return carre;
}

void mallaCurricular::setCarrera(Carrera* carr)
{
	carre = carr;
}

string mallaCurricular::toString()
{
	stringstream s;
	s << "-------------Datos de la malla curricular---------------" << endl;
	if (carre != NULL) {
		s << "Nombre de la carrera asociada: " << carre->getDescripcion() << endl;
	}
	else {
		s << "No hay carrera asociada a esta malla." << endl;
	}
	s << "-----------------Grupos Ingresados-----------------------" << endl;
	s << listC->toStringLista() << endl;
	return s.str();
}

Lista<Curso>* mallaCurricular::getLista()
{
	return listC;
}

void mallaCurricular::agregarCurso(Curso* cur)
{
	listC->agregarObj(cur);
}

string mallaCurricular::toStringEspecial()
{
	stringstream m;
	int cont = 0;
	listC->inicializarActual();
	Curso* aux = NULL;
	while (cont < listC->getCant()) {
		cont++;
		aux = listC->getTipo();
		m << "\t\tNombre del curso: " << aux->getNombreO() << endl;
		m << "\t\tCodigo del curso: " << aux->getCodigo() << endl;
		m << "\t\t------------------------------" << endl;
		listC->siguienteNodo();
	}
	return m.str();
}

void mallaCurricular::asignarCodCurAuto()
{
	int ciclo = 0;
	int cont1 = 0;
	int cont2 = 1;
	string aux = carre->getCodigo();
	string aux2 = "";
	for (int i = 0; i < aux.size(); i++) {
		if (!isdigit(aux[i])) {
			aux2 += aux[i]; //EIF01  ---> aux2 = EIF 
		}
	}
	stringstream x;
	int cont = 0;
	Curso* cursito = NULL;
	listC->inicializarActual();
	while (cont < listC->getCant()) {
		cont++;
		cursito = listC->getTipo();
		CicloLectivo* ciclito = cursito->getCicloL();
		ciclo = ciclito->getCiclo();
		cont2 = listC->getCant();
		if (cont2 > 9) {
			cont2 = cont2 % 10;
			if (cont2 == 0) {
				cont1++;
			}
		}
		if (cursito->getCodigo() == "") {
			x << aux2 << ciclo << cont1 << cont2; //
			cursito->setCodigo(x.str());
		}
		listC->siguienteNodo();
	}
}