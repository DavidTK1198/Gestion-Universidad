#include "Facultad.h"
Facultad::Facultad(string nom) {
	nombre = nom;
	ListaEsc = new Lista<Escuela>;
}
Facultad::~Facultad() {
	delete ListaEsc;
}
string Facultad::getNom() {
	return nombre;
}
void Facultad::setNom(string nom) {

	nombre = nom;

}

string Facultad::toStringFacultad()const
{
	stringstream m;
	m << endl;
	m << "\t\t-------------Datos de la facultad------------\t\t" << endl;
	m << "\t\tNombre: " << nombre << "\t\t" << endl;
	return m.str();
}

Lista<Escuela>* Facultad::getListaEsc()
{
	return ListaEsc;
}


bool Facultad::agregarEscuela(Escuela* es)
{
	return ListaEsc->agregarObj(es);
}

string Facultad::toStringEscuelas()
{
	stringstream s;
	int k = 0;
	ListaEsc->inicializarActual();
	Escuela* esc = NULL;
	while (k < ListaEsc->getCant()) {
		k++;
		esc = ListaEsc->getTipo();
		s <<"#"<< k <<"---->";
		s << esc->getNombre() << endl;
		ListaEsc->siguienteNodo();
	}
	return s.str();
}

bool Facultad::operator==(string& a)
{
	return (this->nombre==a);;
}


ostream& operator<<(ostream& out, const Facultad& fac)
{
	return out << fac.toStringFacultad() << endl;
}
