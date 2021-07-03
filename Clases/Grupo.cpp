#include "Grupo.h"
#include "Estudiante.h"
#include "Curso.h"
Grupo::Grupo(string ncr, int num,Profesor* pr, int capa) {
	NCR = ncr;
	numero = num;
	profe = pr;
	capacidad = capa;
	horario = "";//
	arr = new Arreglo<Estudiante>(capa);
	curso = NULL;
}
Grupo::~Grupo() {
	delete arr;
}
string Grupo::getNCR() {
	return NCR;
}
int Grupo::getNumeroGrupo() {
	return numero;
}
Profesor* Grupo::getProfesor() {
	return profe;
}

int Grupo::getCapacidad() {
	return capacidad;
}
string Grupo::toString(){
	stringstream s;
	s << "\t\t" << "---------Datos del grupo---------" << "\t\t" << endl;
	s << "\t\t" << "NCR: " << NCR << "\t\t" << endl;
	s << "\t\t" << "Numero de grupo: " << numero << "\t\t" << endl;
	s << "\t\t" << "Capacidad: " << capacidad << " estudiante(s)" << "\t\t" << endl;
	if (profe) {
		s << "\t\t" << "Profesor asignado: " << profe->getNombre() << endl;
	}
	else {
		s << "\t\t" << "Este grupo no tiene profesor asignado." << "\t\t" << endl;
	}
	if (curso) {
		s << "\t\tEl curso asociado a este grupo es: " << curso->getNombreO() << endl;
	}
	else {
		s << "\t\tEste grupo no tiene ningun curso asociado." << endl;
	}
	string m = verificaDia(horario);
	s << "\t\tHorario del grupo: " << m << endl;
	s << endl;
	if (arr->getCantidad() > 0) {
		Estudiante* estu = NULL;
		for (int i = 0; i < arr->getCantidad(); i++) {
			estu = arr->operator[](i);
			s << "\t\t------Estudiantes matriculados------\t\t" << endl;
			s <<"\t\tCedula----->"<< estu->getCedula()<<"\t\t" << endl;
			s <<"\t\tNombre----->"<< estu->getNombre() <<"\t\t"<< endl;
			s << "\t\t------------------------------------\t\t" << endl;
		}
	}
	else {
		s << "\t\tNo existen estudiantes en este grupo\t\t"  << endl;
	}

	return s.str();
}
string Grupo::toStringForEspe()
{
	stringstream s;

	s << "\t\t----------------------------" << endl;
	s << "\t\tCurso asociado: " << curso->getNombreO() << endl;
	s << "\t\tNCR: " << NCR << endl;
	s << "\t\tGrupo # " << numero << endl;
	if (profe) {
		s << "\t\tProfesor: " << profe->getNombre() << endl;
	}
	else {
		s << "\t\tProfesor no asignado." << endl;
	}
	string m = verificaDia(horario);
	s << "\t\tHorario del grupo: " << m << endl;
	s << "\t\t----------------------------" << endl;
	return s.str();
}

string Grupo::toStrinGruPorMat()
{
	stringstream s;
	string m = verificaDia(horario);
	s << "NRC" << "\t\t#Grupo" << "\t\tCurso" << "\t\tProfesor" << "\t\tCupo" << "\t\tInscritos" << "\t\tHorario" << endl;
	if (profe) {
		s << NCR << "\t\t" << numero << "\t\t" << curso->getNombreO() << "\t\t" << profe->getNombre() << "\t\t" << capacidad << "\t\t" << arr->getCantidad() << "\t\t" << m << endl;
	}
	else {
		s << NCR << "\t\t" << numero << "\t\t" << curso->getNombreO() << "\t\t" << "Sin profesor asignado" << "\t\t" << capacidad << "\t\t" << arr->getCantidad() << "\t\t" << m << endl;
	}
	return s.str();
}

string Grupo::toStringProEst()
{
	stringstream s;
	s << "\t\t------------Profesor-----------" << endl;
	if (profe) {
		s << "\t\t" << profe->getNombre() << endl << endl;
	}
	else {
		s << "\t\t" << "Sin profesor asignado" << endl << endl;
	}
	s << "\t\t" << "Estudiantes" << endl;
	for (int i = 0; i < arr->getCantidad(); i++) {
		Estudiante* aux = arr->operator[](i);
		s << aux->toStringEspecial() << endl;
	}
	s << "\t\t----------------------------------" << endl;
	return s.str();
}

string Grupo::toStringActas()
{
	stringstream k;
	k << "\t\t" << NCR << "\t\t" << curso->getCodigo() << "\t\t" << curso->getNombreO() << endl;
	return k.str();
}


Curso* Grupo::getCurso()
{
	return curso;
}

string Grupo::getHorario()
{
	return horario;
}
void Grupo::setNCR(string ncr) {
	NCR = ncr;
}
void Grupo::setNumero(int num) {
	numero = num;
}
void Grupo::setProfesor(Profesor* p) {
	profe = p;
}
void Grupo::setCapacidad(int ca) {
	capacidad = ca;
}


void Grupo::setCurso(Curso* cur)
{
	curso = cur;
}

void Grupo::detNCRAutom() {
	stringstream x;
	int a[5];
	int b, c;
	int n = 0;
	while (n != 5) {
		c = 0;
		srand(time(NULL));
		a[n] = (rand() % 5 + 1);
		for (b = 0; b <= n; b++)
			if (a[n] != a[b])
				c++;
		if (c == n) {
			x << (a[n]);
			n++;
		}
	}
	setNCR(x.str());
}

void Grupo::MoviendoCapacidad()
{
	capacidad--;

}

void Grupo::agregarEstudiante(Estudiante* est)
{
	arr->agregarObj(est);
}

void Grupo::setHorario(string stri)
{
	horario = stri;

}

Arreglo<Estudiante>* Grupo::getArreglo()
{
	return arr;
}

char Grupo::cambiarDia(int num)
{
	switch (num)
	{
	case 1:return 'L';
		break;
	case 2:return 'K';
		break;
	case 3:return 'M';
		break;
	case 4:return 'J';
		break;
	case 5:return 'V';
		break;
	case 6:return 'S';
		break;
	case 7:return 'D';
		break;
	default:
		break;
	}
	return 0;
}
//3,5,L =>String horario (3,5,1)

string Grupo::verificaDia(string m)
{
	int num = 0;
	int num2 = m.size();
	string aux = "";
	for (int i = 0; i < num2; i++) {
		if (m[i] == ',') {
			aux = m[i-1];
			num = stoi(aux);
			cambiarDia(num);
			m[i-1] = cambiarDia(num);
		}
		if ((i + 1) == num2) {
			aux = m[i];
			num = stoi(aux);
			cambiarDia(num);
			m[i] = cambiarDia(num);
		}
	}
	return m;
}

bool Grupo::operator==(string& num)
{
	return (this->NCR == num);
}

ostream& operator<<(ostream& out, Grupo& p)
{
	return out << p.toString() << endl;

}
