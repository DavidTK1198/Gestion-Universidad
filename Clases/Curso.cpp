#include "Curso.h"
Curso::Curso(string cod, string nom, int cre, int hse, bool est, int tam,CicloLectivo* cic) {
	codigo = cod;
	nombreOficial = nom;
	creditos = cre;
	tipoCurso = "";
	horasSemanales = hse;
	estado = est;
	arrGru = new Arreglo<Grupo>(tam);
	lista = new Lista<Curso>;//requisitos
	cicloLectivo = cic;
	cali = 0;
	GaPe = false;
	carrera = NULL;

}
Curso:: ~Curso() {
	delete arrGru;
	delete lista;
}
string Curso::getCodigo() {
	return codigo;
}
string Curso::getNombreO() {
	return nombreOficial;
}
string Curso::getTipoCurso() {
	return tipoCurso;
}
Lista<Curso>* Curso::getlistaRequisitos()
{
	return lista;
}
Carrera* Curso::getCarrera()
{
	return carrera;
}
int Curso::getCreditos() {
	return creditos;
}
int Curso::getHorasSemanales() {
	return horasSemanales;
}
bool Curso::getEstado() {
	return estado;
}
bool Curso::getGaPe()
{
	return GaPe;
}
void Curso::setCodigo(string cod) {
	codigo = cod;
}
void Curso::setNombreOficial(string nom) {
	nombreOficial = nom;
}
void Curso::setTipoCurso(string tip) {
	tipoCurso = tip;
}
void Curso::setCreditos(int cre) {
	creditos = cre;
}
void Curso::setHorasSemanales(int hor) {
	horasSemanales = hor;
}
void Curso::setEstado(bool es) {
	estado = es;
}
void Curso::setCali(int n)
{
	cali = n;
}
void Curso::darDatosdelCurso(Grupo* gr)
{
	gr->setCurso(this);
}
void Curso::setGaPe(bool gape)
{
	GaPe = gape;
}
string Curso::toStringMallaCurr() {
	stringstream s;
	s << "\t\t" << "--------------------------------" << "\t\t" << endl;
	s << "\t\t" << "Codigo: " << getCodigo() << "\t\t" << endl;
	s << "\t\t" << "Nombre :" << getNombreO() << "\t\t" << endl;
	s << "\t\t" << "Tipo de curso: " << getTipoCurso() << "\t\t" << endl;
	s << "\t\t" << "Creditos: " << getCreditos() << "\t\t" << endl;
	s << "\t\t" << "Horas semanales: " << getHorasSemanales() << "\t\t" << endl;
	if (estado) {
		s << "\t\t" << "Estado: Activo." << "\t\t" << endl;
	}
	else {
		s << "\t\t" << "Estado: Inactivo." << "\t\t" << endl;
	}
	if (arrGru->getCantidad() > 0) {
		for (int i = 0; i < arrGru->getCantidad(); i++) {
			s << *arrGru->operator[](i) << endl;
		}
	}
	else {
		s << "\t\tNo existen grupos en este curso. \t\t" << endl;
	}
	if (lista->getCant() > 0) {
		s << "\t\t" << "Requisitos" << "\t\t" << endl;
		s << "\t\tDescripcion " << "  -  " << "Codigo del curso\t\t" << endl;
		Curso* a = NULL;
		lista->inicializarActual();
		int cont = 0;
		while (cont < lista->getCant()) {
			cont++;
			a = lista->getTipo();
			s<<"\t\t"<<a->getNombreO()<<"  -  "<< a->getCodigo() <<"\t\t"<< endl;
			lista->siguienteNodo();
		}
	}
	else {
		s << "\t\tRequisito: Ingreso a Carrera\t\t"  << endl;
	}

	return s.str();
}
string Curso::toStringNota()
{
	stringstream s;
	s << "\t\t----------------------\t\t" << endl;
	s << "\t\t|Nombre del curso: " << nombreOficial<< "\t\t|"<< endl;
	s << "\t\t|Nota final del curso: " << cali << "\t\t|" << endl;
	s << "\t\t|Resultado: " << detGaPe() << "\t\t|" << endl;
	s << "\t\t----------------------\t\t" << endl;
	return s.str();
}
string Curso::toStringEspecial()
{
	stringstream s;
	string g = toStringRequisitos();
	s << codigo << "\t\t" << nombreOficial << "\t\t" << creditos << "\t\t" << g << endl;
	return s.str();
}
string Curso::toStringRequisitos()
{
	stringstream s;
	int cont = 0;
	lista->inicializarActual();
	Curso* cursito = NULL;
	if (lista->getCant() == 0) {
		s << "Ingreso a carrera";
	}
	while (cont < lista->getCant()) {
		cont++;
		cursito = lista->getTipo();
		s << cursito->getCodigo();
		if (cont > 1) {
			s << ",";
		}
		lista->siguienteNodo();
	}
	return s.str();
}
string Curso::toStringHistorialA()
{
	stringstream s;
	s << codigo << "\t\t" << nombreOficial << "\t\t" << creditos << "\t\t" << cali << "\t\t" << detGaPe() << endl;
	return s.str();
}
int Curso::getcali()
{
	return cali;
}
string Curso::stringEspecialCali()
{
	stringstream m;
	m << cali << "\t\t" << detGaPe() << endl;
	return m.str();
}

void Curso::setCarrera(Carrera* car)
{
	carrera = car;
}

void Curso::agregarGrupo(Grupo* gr)
{
	arrGru->agregarObj(gr);
	this->darDatosdelCurso(gr);		
}

bool Curso::agregarCurso(Curso* cur)
{
	return lista->agregarObj(cur);
}

CicloLectivo* Curso::getCicloL()
{
	return cicloLectivo;
}

Arreglo<Grupo>* Curso::getArreglo()
{
	return arrGru;
}

string Curso::detGaPe()
{
	if (cali < 6) {
		setGaPe(false);
		return "Reprobado.";
	}
	if (cali >= 6 && cali < 7) {
		return "Extraordinario.";
	}
	if(cali>=7 && cali<=10){
		setGaPe(true);
		return "Aprobado";
	}
	return "";
}

void Curso::setCicloLec(CicloLectivo* ciclo)
{
	cicloLectivo = ciclo;
}

bool Curso::operator==(int i)
{
	return (this->cicloLectivo->getAnio() == i);
}



ostream& operator<<(ostream& out, Curso& c)
{
	return out << c.toStringMallaCurr()<<endl;
}
