#include "Profesor.h"
#include "Grupo.h"
Profesor::Profesor(string id, string nom, string tel, Escuela* es, Carrera* carri, int grado) :Persona(id, nom, tel) {
	escuelita = es;
	carr = carri;
	gradoAcademico = grado;
	listGru = new Lista<Grupo>;
	us = NULL;
	hor = new Horario();
}
Profesor::~Profesor() {
	delete listGru;
	delete hor;
}
Escuela* Profesor::getEscuela() {
	return escuelita;
}
Carrera* Profesor::getCarrera() {
	return carr;
}
int Profesor::getGradoAca() {
	return gradoAcademico;
}
string Profesor::toString() {
	stringstream m;
	m << "\n\t\t" << "--------------------Datos del Profesor---------------" << "\t\t" << endl;
	m << "\t\t" << "Cedula de identidad....." << getCedula() << endl;
	m << "\t\t" << "Nombre completo..." << getNombre() << "\t\t" << endl;
	m << "\t\t" << "Telefono celular..." << getTelefono() << "\t\t" << endl;
	if (escuelita) {
		m << "\t\t" << "Escuela a la que pertenece: " << escuelita->getNombre() << endl;
	}
	else {
		m << "\t\t" << "El profesor no ha sido asignado a ninguna escuela." << "\t\t" << endl;
	}
	if (carr) {
		m << "\t\t" << "Carrera: " <<carr->getDescripcion()<< endl;
	}
	else {
		m << "\t\t" << "Carrera no asignada." << "\t\t" << endl;
	}
	if (listGru->getCant() > 0) {
		int cont = 0;
		Grupo* gr = NULL;
		listGru->inicializarActual();
		while (cont > listGru->getCant()) {
			cont++;
			gr = listGru->getTipo();
			Curso* cur = gr->getCurso();
			m << "\t\tCurso:  " << cur->getNombreO() << endl;
			m << "\t\tGrupo # " << gr->getNumeroGrupo() << endl;
			m << "------------------------" << endl;
			listGru->siguienteNodo();
		}
	}
	else {
		m << "\t\tNo tiene ningun grupo asignado.\t\t" << endl;
	}
	return m.str();
}
string Profesor::toStringEsp()
{
	stringstream s;
	s << cedula << "\t\t" << nombre << "\t\t" << telefono << "\t\t" << convirtiendoGrado(this->gradoAcademico);
	return s.str();
}

bool Profesor::agregarGrupo(Grupo* gr)
{
	return listGru->agregarObj(gr);
}
Usuario* Profesor::getUsuario()
{
	return us;
}
string Profesor::toStringActas()
{
	stringstream s;
	int cont = 0;
	Grupo* aux = NULL;
	listGru->inicializarActual();
	while (cont < listGru->getCant()) {
		cont++;
		aux = listGru->getTipo();
		s << aux->toStringActas();
		listGru->siguienteNodo();
	}
	return s.str();
}
Lista<Grupo>* Profesor::getListaGru()
{
	return listGru;
}
Horario* Profesor::getHorario()
{
	return hor;
}
void Profesor::setUsuarioProfesor(Usuario* uss)
{
	us = uss;
}
void Profesor::setEscuela(Escuela* es) {
	escuelita = es;
}
void Profesor::setCarrera(Carrera* carre) {
	carr = carre;
}
void Profesor::setGradoAca(int grad) {
	gradoAcademico = grad;
}

string Profesor::convirtiendoGrado(int num)
{
	switch (num)
	{
	case 1:
		return "Licenciatura";
	case 2:
		return "Maestria";
	case 3:
		return "Doctorado";
	default:
		return "Sin grado academico";
		break;
	}
}

bool Profesor::operator==(string& a)
{
	
   return (this->cedula == a);
	
}

ostream& operator<<(ostream& out, Profesor& pr)
{
	return out << pr.toString() << endl;
}
