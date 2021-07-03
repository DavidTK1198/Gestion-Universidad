#include "Excepciones.h"
#define _SALTO_LINEA_ '\n'

int Excepciones::excepcionValor(int min, int max)
{
	int p = 0;
	if (cin >> p) {
		if (p < min) {
			throw new ExcepcionRangoInferior(min, max, p);
		}
		if (p > max) {
			throw new ExcepcionRangoSuperior(min, max, p);
		}
	}
	else {
		string k;
		throw k ;
	}
	return p;
}

int Excepciones::validarInfo(int m,int max)
{
	bool finalizado = false;
	int n = 0;
	while (!finalizado) {
		try {
			cout << "Digite un numero: ";
			n = excepcionValor(m,max);
			cout << "El valor " << n << " es correcto y aceptado." << endl;
			finalizado = true;
		}
		catch (string m) {
			cout << "Error: El valor ingresado no es un numero." << endl;
			
		}
		catch (ExcepcionRango* m) {
			cout << m->toString() << endl;
		}
		
		if (!finalizado) {
			cin.clear();
			cin.ignore(255, '\n');
		}
	}
	return n;
}

bool Excepciones::determinarMayusculasContra(string contra) {
	int cont = 0;
	for (int i = 0; i < contra.size(); i++) {
		if (isupper(contra[i])) {
			cont++;
		}
	}
	if (cont < 1) {
		return false;
	}
	else {
		return true;
	}
}

bool Excepciones::determinarNumeroContra(string contra)
{
	int cont = 0;
	for (int i = 0; i < contra.size(); i++) {
		if (isdigit(contra[i])) {
			cont++;
		}
	}
	if (cont == 0) {
		return false;
	}
	else {
		return true;
	}
}

string Excepciones::ValContraFormCor()
{
	bool fina = false;
	string g = "";
	while (!fina) {
		try {
			cout << "Digite la contrasenia.";
			g = excepcionContra();
			fina = true;
		}
		catch (string z) {
			cout << "La contrasenia "<<z<<" es invalida." << endl;
			cout << "La contrasenia debe de ser de al menos 6 caracteres ";
			cout << "incluir al menos una letra mayuscula y incluir un numero como minimo." << endl;
			cout << "Vuelva a intentarlo." << endl;
		}
		if (!fina) {
			cin.clear();
			cin.ignore(255,_SALTO_LINEA_);
		}
	}
	return g;
}

string Excepciones::excepcionContra()
{
	string m = "";
	cin >> m;
	if (m.size() < 6 || determinarMayusculasContra(m) == false || determinarNumeroContra(m) == false) {
		throw m;
	}
	else {
		return m;
	}
}

int Excepciones::ExcepcionUsuario(Usuario* us)
{
	
		UsuarioAdmin* p = dynamic_cast<UsuarioAdmin*>(us);
		if (p) {
			return 1;
		}
		
		UsuarioManten* k = dynamic_cast<UsuarioManten*>(us);
		if (k) {
			return 2;
		}
		
		UsuarioEscuela* f = dynamic_cast<UsuarioEscuela*>(us);
		if (f) {
			return 3;
		}
	
		UsuarioEstudiante* r = dynamic_cast<UsuarioEstudiante*>(us);
		if (r) {
			return 4;
		}
	
		UsuarioProfesor* kf = dynamic_cast<UsuarioProfesor*>(us);
		if (kf) {
			return 5;
		}
	
		UsuarioRegistro* kf4 = dynamic_cast<UsuarioRegistro*>(us);
		if (kf4) {
			return 6;
		}
	
	return 0;
}

int Excepciones::ExcepcionSoloNumeros()
{
	bool f = false;
	int m = 0;
	while (!f)
	{
		try {
			cout << "Digite un numero: ";
			m = validarSoloNum();
			f = true;
			
		}
	
		catch (string n) {
			
			cout << "Error: Caracteres invalidos." << endl;
			cout << "Solo se permiten numeros." << endl;
		}
		if (!f) {
			cin.clear();
			cin.ignore(255, '\n');
		}
	}
	return m;
}

string Excepciones::infraccionMemoria()
{
	return "No se puede acceder a la funcionalidad porque no existe.\n";
}

string Excepciones::NoelementosEnLista()
{
	return "No existen elementos en la lista\n";
}

void Excepciones::memoriaInsu()
{
	try {
		throw Excepciones();
	}
	catch (Excepciones & e) {
		cout << e.infraccionMemoria() << endl;
	}
}

void Excepciones::listaVacia()
{
	try {
		throw Excepciones();

	}
	catch (Excepciones & e) {
		cout << e.NoelementosEnLista() << endl;
	}
}

string Excepciones::requisitosNoCum()
{
	return "No cumple los requisitos necesarios para matricular el curso.";
}

string Excepciones::elementoNoEnc()
{
	return "El elemento no ha sido encontrado";
}

void Excepciones::mostrarMensajeElNoEn()
{
	try {
		throw Excepciones();
	}
	catch (Excepciones& w) {
		cout << w.elementoNoEnc() << endl;
	}
}

void Excepciones::mostrarReqNoCum()
{
	try {
		throw Excepciones();
	}
	catch (Excepciones& w) {
		cout << w.requisitosNoCum() << endl;
	}
}

string Excepciones::Elementorepetido(string e)
{
	stringstream s;
	s << "Error: El Elemento" << e << " esta repetido." << endl;
	return s.str();
}

void Excepciones::imprimirRepetido(string a)
{
	try {
		throw Excepciones();
	}
	catch (Excepciones& e) {
		cout<<e.Elementorepetido(a);
	}

}

int Excepciones::validarPeriodicidad()
{
	int opc = 0;
	cout << "1-)Semestral." << endl;
	cout << "2-)Trimestral." << endl;
	cout << "3-Cuatrimestral." << endl;
	cout << "4-)Anual." << endl;
	opc = validarInfo(1, 4);
	return opc;
}

string Excepciones::darPeriocidad()
{
	int num = validarPeriodicidad();
	switch (num)
	{
	case 1:
		return "Semestral";
	case 2:
		return "Trimestral";
	case 3:
		return "Cuatrimestral";
	case 4:
		return "Anual";
	default:
		return "Sin periodicidad";
		break;
	}
}

int Excepciones::validadTipoCurso()
{
	int num = 0;
	cout << "----------Tipo de Cursos disponibles------" << endl;
	cout << "1-)LAB (Curso de laboratorio)" << endl;
	cout << "2-)CUR (Curso regular)" << endl;
	cout << "3-)SEM (Seminario)" << endl;
	cout << "4-)PRA (Practica Profesional)" << endl;
	cout << "5-)TES (Tesis)" << endl;
	num = validarInfo(1, 5);
	return num;
}

string Excepciones::darTipoCur()
{
	int num = validadTipoCurso();
	switch (num)
	{
	case 1:
		return "LAB";
	case 2:
		return "CUR";
	case 3:
		return "SEM";
	case 4:
		return "PRA";
	case 5:
		return "TES";
	default:
		return "Sin tipo de curso";
		break;
	}
}

int Excepciones::validarHoras(int i)
{
	int k = 0;
	bool f = false;
	while (!f)
	{
		try {
			cout << "Hora: ";
			k = ExcepcionSoloNumeros();
			k = comparaHoras(i, k);
			f = true;
		
		}
		catch (int& t) {
			cout << "El numero " << t << " es menor que " << i << endl;
			cout << "Ingresar una hora de finalizacion mayor que la de inicio." << endl;
		}
	}
	return k;
}

int Excepciones::comparaHoras(int i, int f)
{
	if (f > i) {
		return f;
	}
	else {
		throw f;
	}
}

int Excepciones::validarSoloNum()
{
	int p = 0;
	if (cin >> p) {
		return p;
	}
	string k;
	throw k;
}





