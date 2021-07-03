#include "Escuela.h"
Escuela::Escuela(string nom) {
	nombre = nom;
	listaCar = new Lista<Carrera>;
	listPro = new Lista<Profesor>;
}
Escuela::~Escuela() {
	delete listaCar;
	delete listPro;
}
string Escuela::getNombre() {
	return nombre;
}
void Escuela::setNombre(string nom) {
	nombre = nom;
}
Lista<Carrera>* Escuela::getLista() {
	return listaCar;
}
Lista<Profesor>* Escuela::getListaPro()
{
	return listPro;
}
string Escuela::toStringEscuela() const{
	stringstream m;
	m << "\t\t-----------Datos de la escuela------\t\t" << endl;
	m << "\t\tNombre: " << nombre << "\t\t" << endl;
	if (listaCar->getCant() > 0) {
		m << "\t\t-----Carreras disponibles en la escuela---\t\t" << endl;
		int cont = 0;
		listaCar->inicializarActual();
		Carrera* carrerita = NULL;
		while (cont < listaCar->getCant()) {
			cont++;
			carrerita = listaCar->getTipo();
			m << carrerita->toStringForEspecial();
			listaCar->siguienteNodo();
		}
		m << endl;
		m << "\t\t------------------------------------------\t\t" << endl;
	}
	else {
		m << "\t\tNo hay carreras ingresadas en la escuela.\t\t" << endl;
	}
	m << endl;
	if (listPro->getCant() > 0) {
		m << listPro->toStringLista() << endl;
		m << "\t\t------------------------------------------\t\t" << endl;
	}
	else {
		m << "\t\tNo hay profesores ingresados en la escuela.\t\t" << endl;
	}
	return m.str();
}

bool Escuela::agregarCarreras(Carrera* car)
{
	return listaCar->agregarObj(car);
}

bool Escuela::agregarProfesor(Profesor* prof)
{
	return listPro->agregarObj(prof);
}

void Escuela::asignarCodigoA()
{
	int con = 0;
	int cont = 0;
	int cont2 = 1;
	string m = nombre; //Como hacemos ----> EIF01---> MAT05----> 02---->06
	string aux = "";
	stringstream s;
	for (int i = 0; i < m.size(); i++) {
		if (isupper(m[i])) {
			aux = aux + m[i];
		}
	}
	listaCar->inicializarActual();
	Carrera* car = NULL;
	while (con < listaCar->getCant()) {
		con++;//1
		car = listaCar->getTipo();
		cont2 = listaCar->getCant();//20
		if (cont2 > 9) {
			cont2 = (cont2 % 10);//10->0
			if(cont2 == 0)
				cont++;//2
		}
		s << aux << cont << cont2;//
		if (car->getCodigo() == "") {//EIF03       
			car->setCodigo(s.str());
		}
		listaCar->siguienteNodo();
	}
}

bool Escuela::operator==(string& a)
{
	return (this->nombre==a);
}


ostream& operator<<(ostream& out, const Escuela& p)
{
	return out << p.toStringEscuela() << endl;
}
