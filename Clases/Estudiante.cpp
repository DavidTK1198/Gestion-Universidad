#include "Estudiante.h"
#include "HistorialAcademico.h"
Estudiante::Estudiante(string id, string nom,string tel,string carn,Escuela* esc, Carrera* car,HistorialAcademico* h):Persona(id,nom,tel) {
	escuela = esc;
	carrera = car;
	carnet = carn;
	h_a = h;
	horario = new Horario();
	CursosMatriculados = new Lista<Curso>;//Cursos que ya matriculo
	usE = NULL;
	
}
Estudiante:: ~Estudiante() {
	delete horario;
	delete CursosMatriculados;
}
string Estudiante::toString() {
	stringstream m;
	m << "\n\t\t" << "--------------------Datos del estudiante---------------" << "\t\t" << endl;
	m << "\t\t" << "Cedula de identidad....." << getCedula() << endl;
	m << "\t\t" << "Nombre completo..." << getNombre() << "\t\t" << endl;
	m << "\t\t" << "Telefono celular..." << getTelefono() << "\t\t" << endl;
	m << "\t\t" << "Carnet Asignado...." << getCarnet() << "\t\t" << endl;
	if (escuela) {
		m << "\t\t" << "Escuela a la que pertenece: " << "\t\t" << endl;
	}
	else {
		m << "\t\t" << "El estudiante no ha sido asignado a ninguna escuela." << "\t\t" << endl;
	}
	if (carrera) {
		m << "\t\t" << "Carrera: " << "\t\t" << endl;
	}
	else {
		m << "\t\t" << "Carrera no asignada." << "\t\t" << endl;
	}
	if (h_a) {
		m <<h_a->toString()<< endl;
	}
	if (usE) {
		m << "\t\t" << "Usuario: " << usE->getNombre()<<"\t\t" << endl;
	}
	else {
		m << "\t\tEste estudiante no tiene un usuario asignado." << endl;
	}
	if (CursosMatriculados->getCant() > 0) {
		int cont = 0;
		Curso* aux = NULL;
		CursosMatriculados->inicializarActual();
		while (cont < CursosMatriculados->getCant()) {
			cont++;
			aux = CursosMatriculados->getTipo();
			m << "\t\t--------------\t\t" << endl;
			m << "\t\tCursos matriculados\t\t" << endl;
			m << "\t\tCodigo del curso: " << aux->getCodigo() << endl;
			m << "\t\tNombre del curso: " << aux->getNombreO() << endl;
			m << "\t\t--------------\t\t" << endl;
			CursosMatriculados->siguienteNodo();
		}
	}
	else {
		m << "\t\tNo tiene ningun curso matriculado\t\t." << endl;
	}
	return m.str();
}
Escuela* Estudiante::getEscuela() {
	return escuela;
}
Carrera* Estudiante::getCarrera() {
	return carrera;
}
string Estudiante::getCarnet() {
	return carnet;
}
Horario* Estudiante::getHorario()
{
	return horario;
}
Usuario* Estudiante::getUsuarioEst()
{
	return usE;
}
HistorialAcademico* Estudiante::getHistorialA()
{
	return h_a;
}
Lista<Curso>* Estudiante::getListaCurso()
{
	return CursosMatriculados;
}
void Estudiante::setHistorialA(HistorialAcademico* h)
{
	h_a = h;
	h_a->setEstudiante(this);
}
void Estudiante::setEscuela(Escuela* esc) {
	escuela = esc;
}
void Estudiante::setCarrera(Carrera* car) {
	carrera = car;
}
void Estudiante::setCarnet(string carn) {
	carnet = carn;
}

void Estudiante::setUsuarioEstudiante(Usuario* us)
{
	usE = us;
}

bool Estudiante::matricular(CicloLectivo* cic, Curso* lista)
{
	return false;

}

void Estudiante::rellenarMatriz(int i, int f, int d, Grupo* gr)
{
	horario->rellenarMatriz(i, f, d, gr);
}

bool Estudiante::agregarCursoMatriculado(Curso* cur)
{
	return CursosMatriculados->agregarObj(cur);
}

string Estudiante::toStringEspecial()
{
	stringstream m;
	m << "\t\t-----------------------------" << endl;
	m << "\t\tCedula" << "\t\t" << "Nombre completo" << endl;
	m<<"\t\t"<<cedula <<"\t\t"<< nombre << endl;
	m << "\t\t-----------------------------" << endl;
	return m.str();
}

Curso* Estudiante::buscarCur(Curso* cur)
{
	if (CursosMatriculados->buscar(cur)) {
		return cur;
	}
	return NULL;
}
//
bool Estudiante::operator==(string& a)
{
	return (this->cedula == a);
}


ostream& operator<<(ostream& out, Estudiante& est)
{
	return out << est.toStringEspecial()<< endl;
}

