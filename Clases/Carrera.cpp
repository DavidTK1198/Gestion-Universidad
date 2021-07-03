#include "Carrera.h"
#include "mallaCurricular.h"	
Carrera::Carrera(string codi, string nom, bool est, Escuela* es , Facultad* facultt) {
	codigo = codi;
	descripcion = nom;
	estado = est;
	escue = es;
	facul = facultt;
	mallaC = new mallaCurricular(this);
	mallaC->setCarrera(this);
	empadronados = new Lista<Estudiante>;
}
Carrera::~Carrera(){
	delete empadronados;
}
string Carrera::getCodigo() {
	return codigo;
}
string Carrera::getDescripcion() {
	return descripcion;
}
bool Carrera::getEstado() {
	return estado;
}
Escuela* Carrera::getEscuela() {
	return escue;
}
Facultad* Carrera::getFacultad() {
	return facul;
}
mallaCurricular* Carrera::getMalla()
{
	return mallaC;
}
string Carrera::toString()const{
	stringstream s;
	s << "\t\t" << "------------Datos de la carrera-------------------" << "\t\t" << endl;
	s << "\t\t" << "Codigo de la carrera..." << codigo << "\t\t" << endl;
	s << "\t\t" << "Nombre de la carrera: " << descripcion << "\t\t" << endl;
	if (estado) {
		s << "\t\t" << "Estado: " << " Activo" << "\t\t" << endl;
	}
	else {
		s << "\t\t" << "Estado: " << "Inactivo" << "\t\t" << endl;
	}
	if (escue) {
		s << "\t\t" << "Escuela a la que pertenece: " <<escue->getNombre()<< "\t\t" << endl;
	}
	else {
		s << "\t\t" << "La carrera no ha sido asignadad a ninguna escuela." << "\t\t" << endl;
	}
	if (facul) {
		s<< "\t\t" << "Facultad: " <<facul->getNom()<< "\t\t" << endl;
	}
	else {
		s << "\t\t" << "Facultad no asignada." << "\t\t" << endl;
	}
	if (empadronados->getCant() > 0) {
		s << "\t\t---Estudiantes empadronados----\t\t" << endl;
		int cont = 0;
		Estudiante* estt = NULL;
		empadronados->inicializarActual();
		while (cont < empadronados->getCant()) {
			cont++;
			estt = empadronados->getTipo();
			s << "\t\t|Nombre : " << estt->getNombre() << "\t\t|" << endl;
			s << "\t\t|Cedula: " << estt->getCedula() << "\t\t|" << endl;
			s << "\t\t|-----------------------------------\t\t|" << endl;
			empadronados->siguienteNodo();
		}
	}
	else {
		s<<"\t\tNo hay estudiantes empadronados\t\t" << endl;
	}
	return s.str();
}

string Carrera::toStringForEspecial()
{
	stringstream m;
	m << "\t\t--------------------------" << endl;
	m << "\t\tNombre de la carrera: " << descripcion << endl;
	m << "\t\tCodigo de la carrera: " << codigo << endl;
	m << "\t\t--------------------------" << endl;
	return m.str();
}

string Carrera::toStringEstudiantesXcarr()
{
	stringstream s;
	s << "\t\t------------------------------------------" << endl;
	s << "\t\t---------- " << descripcion << " ---------" << endl;
	int cont = 0;
	Estudiante* car = NULL;
	empadronados->inicializarActual();
	while (cont < empadronados->getCant()) {
		cont++;
		car = empadronados->getTipo();
		s << car->toStringEspecial()<< endl;
		empadronados->siguienteNodo();
	}
	s << "\t\t------------------------------------------" << endl;
	return s.str();
}

Lista<Estudiante>* Carrera::getListaEst()
{
	return empadronados;
}

void Carrera::setCodigo(string cod) {
	codigo = cod;
}
void Carrera::setDescripcion(string des) {
	descripcion = des;
}
void Carrera::setEstado(bool esta) {
	estado = esta;
}
void Carrera::setEscuela(Escuela* es) {
	escue = es;
}
void Carrera::setFacultad(Facultad* fa) {
	facul = fa;
}
void Carrera::setMalla(mallaCurricular* malla)
{
	mallaC = malla;
	mallaC->setCarrera(this);
}
void Carrera::AsignarCodigoCarr()//int ---> codigo del ultimo que se creo EIF06
{
}

void Carrera::agregarEstudiante(Estudiante* est)
{
	empadronados->agregarObj(est);

}
void Carrera::setListaest(Lista<Estudiante>* x)
{
	empadronados = x;
}
bool Carrera::operator==(string& cod)
{
	return (this->codigo == cod);
}
ostream& operator<<(ostream& out, Carrera& car)
{
	return out << car.toStringForEspecial() << endl;
}
