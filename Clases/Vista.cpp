#include "Vista.h"
#include <conio.h>

void Vista::gotoxy(int valor, int valor2) { //Coloca el texto en determinados lugares de la pantalla.
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = valor;
	dwPos.Y = valor2;
	SetConsoleCursorPosition(hcon, dwPos);
}

int Vista::matriculaYhistorial()
{
		int opcion = 0;
		system("cls");
		Excepciones exc;
		cout << " _________________________________________________________" << endl;
		cout << "|                                                         |" << endl;
		cout << "|               MATRICULA Y HISTORIALES                   |" << endl;
		cout << "|                                                         |" << endl;
		cout << "|1-)Proceso de Matricula.                                 |" << endl;
		cout << "|2-)Consulta de matricula  por Estudiante.                |" << endl;
		cout << "|3-)Historial Académico por Estudiante.                   |" << endl;
		cout << "|4-)Regresar al menu anterior                             |" << endl;
		cout << "|_________________________________________________________|" << endl;
		opcion = exc.validarInfo(1, 4);
		return opcion;
	
}

void Vista::despedida()
{
		system("cls");
		cout << " _______________________________________" << endl;
		cout << "|                                       |" << endl;
		cout << "|    Gracias por usar el sistema        |" << endl;
		cout << "|                de                     |" << endl;
		cout << "|              Gestion                  |" << endl;
		cout << "|     Digite enter para Salir           |" << endl;
		cout << "|_______________________________________|" << endl;
		system("pause");

}

int Vista::menuEspecial()
{
	int num = 0;
	Excepciones e;
	cout << "Que desea hacer..." << endl;
	cout << "1-)Login" << endl;
	cout << "2-)Salir" << endl;
	num = e.validarInfo(1, 2);
	return num;

}

void Vista::PresentacionInicial()
{

	string saludo[11] = { "B","I","E","N","V","E","N","I","D","O" };
	gotoxy(40, 8);
	for (int i = 0; i < 11; i++) {
		 cout << saludo[i];
		Sleep(150);
	}
	string sl[20] = { "A","L " ,"S","I","S","T","E","M","A ","D","E " ,"G","E","S","T","I","O","N" };
	gotoxy(40, 9);
	for (int i = 0; i < 18; i++) {
		 cout << sl[i];
		Sleep(150);
	}
	string u[26] = { "D","E " ,"L","A ","U","N","I","V","E","R","S","I","D","A","D ","N","A","C","I","O","N","A","L" };
	gotoxy(40, 10);
	for (int i = 0; i < 25; i++) {
		cout << u[i];
		Sleep(150);
	}

	Sleep(1000);
	
}

string Vista::tipoUsuario(int n)
{

	if (n == 1) {
		return  "Tipo de usuario: Administrador ";
	}
	if (n == 2) {
		return  "Tipo de usuario: Mantenimiento ";
	}
	if (n == 3) {
		return  "Tipo de usuario: Escuela       ";
	}
	if (n == 4) {
		return  "Tipo de usuario: Estudiante    ";
	}
	if (n == 5) {
		return  "Tipo de usuario: Profesor      ";
	}
	if (n == 6) {
		return  "Tipo de usuario: Registro      ";
	}

	return "Saliendo del sistema";
}

int Vista::MenuPrincipal()
{
	int n = loginfinal();
	int opcion;
	int aux;
	system("cls");
	gotoxy(1, 12);cout << "| "<<tipoUsuario(n) <<"                                        |" <<endl;
	gotoxy(1, 1);cout << " ________________________________________________________________________" << endl;
	gotoxy(1, 2);cout << "|                                                                        |" << endl;
	gotoxy(1, 3); cout << "|         BIENVENIDO AL MENU PRINCIPAL DE LA UNIVERSIDAD NACIONAL        |" << endl;
	gotoxy(1, 4); cout << "|                                                                        |" << endl;
	gotoxy(1, 5); cout << "|	DISPONE DE LAS SIGUIENTES OPCIONES                                |" << endl;
	gotoxy(1, 6); cout << "|**1-)Seguridad y administracion de roles                                |" << endl;
	gotoxy(1, 7); cout << "|**2-)Mantenimiento General a nivel de registro                          |" << endl;
	gotoxy(1, 8); cout << "|**3-)Mantenimiento por escuela                                          |" << endl;
	gotoxy(1, 9); cout << "|**4-)Matricula y Historiales                                            |" << endl;
	gotoxy(1, 10); cout << "|**5-)Registro de Actas                                                  |" << endl;
	gotoxy(1, 11); cout << "|**6-)Salir                                                              |" << endl;
	gotoxy(1, 13); cout << "|________________________________________________________________________|" << endl;
	cout << endl << endl;
	Excepciones a;
	opcion = a.validarInfo(1, 6);

	if (opcion == 6) {
		system("cls");
		return opcion;
	}

	aux = accesoMenu(opcion, n);
	return  aux;

}

int Vista::AdministracionRoles()
{

	int opcion;
	system("cls");
	cout << " _________________________________________________________" << endl;
	cout << "|                                                         |" << endl;
	cout << "|        SEGURIDAD Y ADMINISTRACION DE ROLES              |" << endl;
	cout << "|                                                         |" << endl;
	cout << "|1-)Crear Usuario.                                        |" << endl;
	cout << "|2-)Mostrar Usuarios                                      |" << endl;
	cout << "|3-)Regresar al menu principal.                           |" << endl;
	cout << "|_________________________________________________________|" << endl;
	Excepciones k;
	opcion = k.validarInfo(1, 3);
	return opcion;
}

Usuario* Vista::CreandoUsuario(Universidad* uni)
{
	system("cls");
	Sleep(3000);
	cout << " _________________________________________________________" << endl;
	cout << "|                                                         |" << endl;
	cout << "|            CREANDO USUARIO ADMINISTRADOR                |" << endl;
	cout << "|_________________________________________________________|" << endl;
	string ced, nom, tel, clave;
	cout << "Ingrese su cedula de identidad: ";
	getline(cin, ced);
	cout << endl;
	cout << "Ingrese su nombre de Usuario: ";
	getline(cin, nom);
	cout << endl;
	cout << "Ingrese un telefono celular: ";
	getline(cin, tel);
	cout << "Ingrese su clave (debe contener al menos una mayuscula y ser de 6 caracteres minimo: " << endl;
	Excepciones* ex = new Excepciones();
	clave = ex->ValContraFormCor();
	Usuario* us = new UsuarioAdmin(ced, nom, tel, clave);
	cout << "Usuario administador creado." << endl;
	return us;

}


Usuario* Vista::validarUsuario(Universidad* un)
{
	int i = 0;
	Lista<Usuario>* k = un->getListaUsuar();
	Usuario* aux = NULL;
	system("cls");
	cout << " __________________________________________________________" << endl;
	cout << "|                                                          |" << endl;
	cout << "|                    LOGIN DE USUARIO                      |" << endl;
	cout << "|__________________________________________________________|" << endl;
	aux = buscarUsuario(k);
	if (aux) {
		determineTipoUsuario(aux);
	}
	if (aux) {
		return aux;
		//returna aux ---> capturar al usuario que ingreso
	}
	cout << endl;
	cout << "Usuario o contrasenia incorrecto" << endl;
	cout << "Vuelva a intentarlo" << endl;
	Sleep(2000);
	return NULL;
}



void Vista::mostarUsuarios(Lista<Usuario>* u) //revisar.

{
	system("cls");
	cout << " _________________________________________________________" << endl;
	cout << "|                                                         |" << endl;
	cout << "|                MOSTRANDO USUARIOS                       |" << endl;
	cout << "|_________________________________________________________|" << endl;
	cout << u->toStringLista()<< endl;
	system("pause");
}

Usuario* Vista::buscarUsuario(Lista<Usuario>* list)
{
	char caracter;
	string pass;
	int cont = 0;
	int contador2 = 0;
	int p = list->getCant();
	Usuario* aux;
	string nom;
	if (list->verificaVacio()) {
		return NULL;
	}
	else {
		list->inicializarActual();
		cout << " __________________________________________________________" << endl;
		cout << "|                                                          |" << endl;
		cout << "|   Bienvenido por favor ingrese sus credenciales          |" << endl;
		cout << "|__________________________________________________________|" << endl;

		cout << "\nIngrese su nombre de usuario." << endl;
		cin >> nom;
		cout << "\nIngrese su contrasenia." << endl;
		caracter = _getch();
		pass = "";
		while (caracter != 13) {
			contador2++;

			if (caracter != 8) {
				pass.push_back(caracter);
				cout << "*";
			}
			else {

				if (pass.length() > 0) {
					cout << "\b \b";
					pass = pass.substr(0, pass.length() - 1);

				}
			}

			caracter = _getch();

		}
		while (p > cont) {
			cont++;
			aux = list->getTipo();
			if (aux->getNombre() == nom && aux->getClave() == pass) {
				return aux;

			}
			list->siguienteNodo();
		}
	}
	return NULL;
	
}

void Vista::determineTipoUsuario(Usuario* us)
{
	Excepciones e;
	int iden = e.ExcepcionUsuario(us);
	string num = "tipo.txt";
	ofstream out;
	out.open(num, ios::out);
	out << iden << '\n';
	out << us->getCedula()<< '\n';
	out.close();
}


int Vista::devuelveEntero()
{
	ifstream s;
	s.open("tipo.txt");
	string m;
	int numerito = 0;
	getline(s, m, '\n');
	stringstream cant(m);
	cant >> numerito;
	s.close();
	return numerito;
}
int Vista::loginfinal()
{
	int p = devuelveEntero();
	return p;
}
void Vista::creandoCualquierUsua(Universidad* uni)
{
	system("cls");
	Usuario* c = nullptr;
	Usuario* z = nullptr;
	Excepciones m;
	int p = 0;
	string id, nom, tel, contra;
	int detRol;
	detRol = devolverRolUsuario();
	system("cls");
	switch (detRol)
	{
		case 1:
			cout << " _________________________________________________________" << endl;
			cout << "|                                                         |" << endl;
			cout << "|            CREANDO USUARIO                              |" << endl;
			cout << "|_________________________________________________________|" << endl;
			cout << "Cedula de identidad: ";
			cin >> id;
			cout << endl;
			cout << "Ingrese un numero de telefono: ";
			cin >> tel;
			cout << endl;
			cout << "Ingrese su nombre de usuario: ";
			cin.clear();
			cin.ignore(255, '\n');
			getline(cin, nom);
			cout << endl;
			contra = m.ValContraFormCor();
			cout << endl;
			c = new UsuarioAdmin(id, nom, tel, contra);
			uni->ingresarUsuario(c);
			cout << " _________________________________________________________" << endl;
			cout << "|                                                         |" << endl;
			cout << "|       Usuario Administrador creado exitosamente         |" << endl;
			cout << "|_________________________________________________________|" << endl;
			system("pause");
			break;
		case 2:
			cout << " _________________________________________________________" << endl;
			cout << "|                                                         |" << endl;
			cout << "|            CREANDO USUARIO                              |" << endl;
			cout << "|_________________________________________________________|" << endl;
			cout << "Cedula de identidad: ";
			cin >> id;
			cout << endl;
			cout << "Ingrese un numero de telefono: ";
			cin >> tel;
			cout << endl;
			cout << "Ingrese su nombre de usuario: ";
			cin.clear();
			cin.ignore(255, '\n');
			getline(cin, nom);
			cout << endl;
			contra = m.ValContraFormCor();
			cout << endl;
			z = new UsuarioManten(id, nom, tel, contra);
			uni->ingresarUsuario(z);
			cout << " _________________________________________________________" << endl;
			cout << "|                                                         |" << endl;
			cout << "|       Usuario Mantenimiento creado exitosamente         |" << endl;
			cout << "|_________________________________________________________|" << endl;
			system("pause");
			break;
		case 3: {
		    cout << " _________________________________________________________" << endl;
			cout << "|                                                         |" << endl;
			cout << "|            CREANDO USUARIO                              |" << endl;
			cout << "|_________________________________________________________|" << endl;
			cout << "Cedula de identidad: ";
			cin >> id;
			cout << endl;
			cout << "Ingrese un numero de telefono: ";
			cin >> tel;
			cout << endl;
			cout << "Ingrese su nombre de usuario: ";
			cin.clear();
			cin.ignore(255, '\n');
			getline(cin, nom);
			cout << endl;
			contra = m.ValContraFormCor();
			cout << endl;
			Usuario* us = new UsuarioEscuela(id, nom, tel, contra);
			uni->ingresarUsuario(us);
			cout << " _________________________________________________________" << endl;
			cout << "|                                                         |" << endl;
			cout << "|       Usuario Escuela creado exitosamente               |" << endl;
			cout << "|_________________________________________________________|" << endl;
			system("pause");
			}
			break;
		case 4: {
			Lista<Estudiante>* Le = uni->getListaEst();
			if (Le->getCant() == 0) {
				cout << "Imposible crear el usuario - estudiante antes de que exista un estudiante empadronado" << endl;
				cout << "Debe existir al menos un estudiante empadronado en una carrera al que se le puede asignar el usuario." << endl;
				cout << "Regresando a menu anterior." << endl;
				Sleep(3000);
				return;
			}
			cout << "Mostrando contenedor de estudiantes empadronados." << endl;
			Usuario* usuarioEs = NULL;
			int cont1 = 0;
			Estudiante* est = NULL;
			Le->inicializarActual();
			while (cont1 < Le->getCant()) {
				cont1++;
				cout << "Estudiante # " << cont1 << endl;
				est = Le->getTipo();
				cout << est->toStringEspecial()<<endl;
				Le->siguienteNodo();
			}
			cout << endl;
			cout << endl;
			int cont = 0;
			Le->inicializarActual();
			while (cont < Le->getCant()) {
				cont++;
				est = Le->getTipo();
				if (est->getUsuarioEst() == NULL) {
					cout << "Ingrese el nombre de usuario para " << est->getNombre() << ": ";
					cin >> id;
					contra = m.ValContraFormCor();
					usuarioEs = new UsuarioEstudiante(est->getCedula(),id,est->getTelefono(),contra);
					usuarioEs->setEstudiante(est);
					uni->ingresarUsuario(usuarioEs);
					cout << " _________________________________________________________" << endl;
					cout << "|                                                         |" << endl;
					cout << "|       Usuario Estudiante creado exitosamente            |" << endl;
					cout << "|_________________________________________________________|" << endl;
					system("pause");
				}
				else {
					cout << "El estudiante "<<est->getNombre()<<" ya cuenta con un usuario asignado." << endl;
					system("pause");
					return;
				}
				Le->siguienteNodo();
			}
		}
			break;
		case 5: {
			Lista<Profesor>* Lee = uni->getListaPro();
			if (Lee->getCant() == 0) {
				cout << "Imposible crear el usuario - profesor antes de que exista un profesor" << endl;
				cout << "Debe existir al menos un profesor contratado en la universidad al que se le puede asignar el usuario." << endl;
				cout << "Regresando a menu anterior." << endl;
				Sleep(3000);
				return;
			}
			cout << "Mostrando contenedor de profesores contratados." << endl;
			Usuario* usuarioProf = NULL;
			int cont1 = 0;
			Profesor* pro = NULL;
			Lee->inicializarActual();
			while (cont1 < Lee->getCant()) {
				cont1++;
				cout << "Profesor # " << cont1 << endl;
				pro = Lee->getTipo();
				cout << pro->toStringEsp()<<endl;
				Lee->siguienteNodo();
			}
			cout << endl;
			cout << endl;
			int cont = 0;
			Profesor* prof = NULL;
			Lee->inicializarActual();
			while (cont < Lee->getCant()) {
				cont++;
				prof = Lee->getTipo();
				if (prof->getUsuario() == NULL) {
					cout << "Ingrese el nombre de usuario para  " << prof->getNombre() << ": ";
					cin >> id;
					contra = m.ValContraFormCor();
					usuarioProf = new UsuarioProfesor(prof->getCedula(), id, prof->getTelefono(), contra);
					usuarioProf->setProfesor(prof);
					uni->ingresarUsuario(usuarioProf);
					cout << " _________________________________________________________" << endl;
					cout << "|                                                         |" << endl;
					cout << "|       Usuario Profesor creado exitosamente              |" << endl;
					cout << "|_________________________________________________________|" << endl;
					system("pause");
				}
				else {
					cout << "El profesor "<<prof->getNombre()<<" ya cuenta con un usuario asignado." << endl;
					system("pause");
					return;
				}
				Lee->siguienteNodo();
			}
		}
		break;
		case 6: {
			cout << " _________________________________________________________" << endl;
			cout << "|                                                         |" << endl;
			cout << "|            CREANDO USUARIO                              |" << endl;
			cout << "|_________________________________________________________|" << endl;
			cout << "Cedula de identidad: ";
			cin >> id;
			cout << endl;
			cout << "Ingrese un numero de telefono: ";
			cin >> tel;
			cout << endl;
			cout << "Ingrese su nombre de usuario: ";
			cin.clear();
			cin.ignore(255, '\n');
			getline(cin, nom);
			cout << endl;
			contra = m.ValContraFormCor();
			cout << endl;
			Usuario* us = new UsuarioRegistro(id, nom, tel, contra);
			uni->ingresarUsuario(us);
			cout << " _________________________________________________________" << endl;
			cout << "|                                                         |" << endl;
			cout << "|       Usuario Registro ha sido creado exitosamente      |" << endl;
			cout << "|_________________________________________________________|" << endl;
			system("pause");
		}break;
	default:
		cout << "Nada de nada." << endl;
		break;
	}
	
}

int Vista::devolverRolUsuario()
{
	int m = 0;
	Excepciones k;
	cout << "Los distintos roles existentes son los siguientes: " << endl;
	cout << "1-)Usuario - Administrador." << endl;
	cout << "2-)Usuario - Mantenimiento." << endl;
	cout << "3-)Usuario - Escuela." << endl;
	cout << "4-)Usuario - Estudiante." << endl;
	cout << "5-)Usuario - Profesor." << endl;
	cout << "6-)Usuario - Registro." << endl;
	m = k.validarInfo(1, 6);
	return m;
}

int Vista::mantenimientoNivelRegistro()
{
	int opcion = 0;
	Excepciones exc;
	system("cls");
	cout << " __________________________________________________________" << endl;
	cout << "|                                                          |" << endl;
	cout << "|   MANTENIMIENTO GENERAL A NIVEL DE REGISTRO              |" << endl;
	cout << "|                                                          |" << endl;
	cout << "|1-)Mantenimiento de años y ciclos lectivos.               |" << endl;
	cout << "|2-)Mantenimiento de carreras y cursos.                    |" << endl;
	cout << "|3-)Empadronamiento.                                       |" << endl;
	cout << "|4-)Volver al menu anterior.                               |" << endl;
	cout << "|__________________________________________________________|" << endl;
	opcion = exc.validarInfo(1,4);
	return opcion;
	return 0;
}

CicloLectivo* Vista::ingresarCiclosLectivos(Universidad* uni)
{
	Excepciones e;
	int anio;
	int cicloLec;
	int d, m, a;
	int df, mf, af;
	Fecha* fechaI = NULL;
	Fecha* fechaF = NULL;
	string per;
	string cicloL;
	system("cls");
	cout << " _________________________________________________________" << endl;
	cout << "|                                                         |" << endl;
	cout << "|             Creando ciclos lectivos                     |" << endl;
	cout << "|_________________________________________________________|" << endl;
	cout << "Ingrese el anio del curso lectivo: " << endl;
	anio = e.ExcepcionSoloNumeros();
	if (comprobarTresCiclos(uni, anio)) {
		cout << "Ingrese el periodo lectivo (1,2,3): " << endl;
		cicloLec = e.validarInfo(1, 3);
		CicloLectivo* auxx = validarCicloRepetido(uni, cicloLec, anio);
		if (auxx) {
			cout << "Ya existe un periodo con el numero " << cicloLec << " en el anio "<<anio<<endl;
			cout << "Regresando a menu anterior..." << endl;
			system("pause");
			return NULL;
		}
		cout << "Ingrese la fecha de inicio del ciclo lectivo." << endl;
		cout << "Formato : dd/mm/aa" << endl;
		cout << "Dia:(Solo se permite numeros entre 1 y 31) " << endl;
		d = e.validarInfo(1, 30);
		cout << "Mes:(Solo se permiten numeros entre 1 y 12) " << endl;
		m = e.validarInfo(1, 12);
		fechaI = new Fecha(d, m, anio);
		cout << endl << endl;
		system("cls");
		cout << "Ingrese la fecha de finalizacion del ciclo lectivo." << endl;
		cout << "Formato : dd/mm/aa" << endl;
		cout << "Dia:(Solo se permite numeros entre 1 y 31) " << endl;
		df = e.validarInfo(1, 30);
		cout << "Mes:(Solo se permiten numeros entre 1 y 12)  " << endl;
		mf = e.validarInfo(1, 12);
		cout << "Anio: " << endl;
		int val = anio + 1;
		af = e.validarInfo(anio, val);
		system("cls");
		fechaF = new Fecha(df, mf, af);
		while (fechaI->compararFechas(fechaI, fechaF) == false) {
			system("cls");
			cout << *fechaF << " es menor que " << *fechaI << endl;
			cout << "Por favor ingrese una fecha de finalizacion mayor que la de fecha de inicio." << endl;
			delete fechaF;
			cout << "Dia: " << endl;
			df = e.validarInfo(1, 30);
			cout << "Mes: " << endl;
			mf = e.validarInfo(1, 12);
			cout << "Anio: " << endl;
			af = e.validarInfo(anio, val);
			fechaF = new Fecha(df, mf, af);
		}
		cout << endl;
		system("cls");
		cout << "Ingrese la periodicidad del ciclo lectivo:" << endl;
		string g = e.darPeriocidad();
		CicloLectivo* ciclo = new CicloLectivo(anio, fechaI, fechaF, g, cicloLec);
		cout << "Ciclo lectivo creado satisfactoriamente." << endl;
		system("cls");
		cout << "Mostrando en pantalla el ciclo lectivo recien creado..." << endl;
		cout << ciclo->toString() << endl;
		system("pause");
		system("cls");
		return ciclo;
	}
	else {
		cout << "El anio " << anio << " ya dispone de los tres periodos correspondientes." << endl;
		cout << "Imposible crear un ciclo lectivo en el mismo anio con periodo repetido" << endl;
		cout << "Regresando al menu anterior..." << endl;
		system("pause");
		return NULL;
	}
	return NULL;
}

int Vista::accesoMenu(int opc,int tipo)
{
		if (tipo == 1 && (opc == 1 || opc == 2 || opc == 3 || opc == 4 || opc == 5 || opc == 6)) {
			return opc;
		}
		if (tipo == 2 && (opc == 3)) {
			return opc;
		}
		if (tipo == 3 && (opc == 3 || opc==4)) {
			return opc;
		}
		if (tipo == 4 && (opc == 4)) {
			return opc;
		}
		if (tipo == 5 && (opc == 5)) {
			return opc;
		}
		if (tipo == 8 && (opc == 2||opc==3)) {
			return opc;
		}

		return 0;

}

Lista<Facultad>* Vista::asignarAUniversidad()
{
	Lista<Facultad>* f = new Lista<Facultad>;
	Facultad* facul1 = new Facultad("Exactas y Naturales");
	Facultad* facul2 = new Facultad("Filosofia y Letras");
	Facultad* facul3 = new Facultad("Ciencias Sociales");
	Facultad* facul4 = new Facultad("Tierra y Mar");
	Escuela* esc1 = new Escuela("Escuela de InFormatica");
	Escuela* esc2 = new Escuela("Escuela de Filosofia");
	Escuela* esc3 = new Escuela("Escuela De Matematica");
	Escuela* esc4 = new Escuela("Escuela de Historia");
	Escuela* esc5 = new Escuela("Escuela de Administracion");
	Escuela* esc6 = new Escuela("Escuela de Ciencias AGrarias");
	Escuela* esc7 = new Escuela("Escuela de Literatura y Lenguaje");
	Escuela* esc8 = new Escuela("Escuela de Ciencias Ambientales");
	facul1->agregarEscuela(esc1);
	facul1->agregarEscuela(esc3);
	facul2->agregarEscuela(esc2);
	facul2->agregarEscuela(esc7);
	facul3->agregarEscuela(esc4);
	facul3->agregarEscuela(esc5);
	facul4->agregarEscuela(esc6);
	facul4->agregarEscuela(esc8);
	f->agregarObj(facul1);
	f->agregarObj(facul2);
	f->agregarObj(facul3);
	f->agregarObj(facul4);
	return f;

}

Estudiante* Vista::buscarEst(string nom,Lista<Estudiante>* le)
{
	
	int cont = 0;
	int cant = le->getCant();
	le->inicializarActual();
	Estudiante* aux = NULL;
	while (cont < cant) {
		cont++;
		aux = le->getTipo();
		if (aux->getCedula() == nom) {
			return aux;
		}
		le->siguienteNodo();
	}
	return NULL;
				
}

int Vista::subMenuCiclosLectivos()
{
	int opcion;
	system("cls");
	cout << " _________________________________________________________" << endl;
	cout << "|                                                         |" << endl;
	cout << "|          MANTENIMIENTO DE ANIOS Y CICLOS LECTIVOS       |" << endl;
	cout << "|                                                         |" << endl;
	cout << "|1-)Mostrar ciclos lectivos.                              |" << endl;
	cout << "|2-)Ingresar ciclos lectivos                              |" << endl;
	cout << "|3-)Regresar al menu de administracion de roles.          |" << endl;
	cout << "|_________________________________________________________|" << endl;
	Excepciones k;
	opcion = k.validarInfo(1, 3);
	return opcion;
}

void Vista::mostrarCiclos(Universidad* uni)
{
	system("cls");
	Excepciones p;
	if (uni->getCantCL() == 0) {
		p.listaVacia();
		return;
	}
	cout << "-----------------Mostrando oferta de ciclos----------------" << endl;
	cout << uni->toStringCL() << endl;
	cout << "------------------------------------------------------------" << endl;
	system("pause");
}

int Vista::mantenimientoCarrYCurs()
{
	int opcion;
	Sleep(1000);
	system("cls");
	cout << " _________________________________________________________" << endl;
	cout << "|                                                         |" << endl;
	cout << "|            MANTENIMIENTO DE CARRERAS Y CURSO            |" << endl;
	cout << "|                                                         |" << endl;
	cout << "|1-)Ingresar nuevas carreras.                             |" << endl;
	cout << "|2-)Ingresar cursos                                       |" << endl;
	cout << "|3-)Regresar al menu anterior                             |" << endl;
	cout << "|_________________________________________________________|" << endl;
	Excepciones k;
	opcion = k.validarInfo(1, 3);
	return opcion;
}

int Vista::empadronamiento()
{
	int opcion;
	Sleep(1000);
	system("cls");
	cout << " _________________________________________________________________________" << endl;
	cout << "|                                                                         |" << endl;
	cout << "|                         EMPADRONAMIENTO                                 | " << endl;
	cout << "|                                                                         |" << endl;
	cout << "|1-)Empadronamiento de estudiantes.                                       |" << endl;
	cout << "|2-)Mostrar estudiantes empadronados por carrera                          |" << endl;
	cout << "|3-)Regresar al menu anterior.                                            | " << endl;
	cout << "|_________________________________________________________________________|" << endl;
	Excepciones k;
	opcion = k.validarInfo(1, 3);
	return opcion;
}

void Vista::ingresarCarrera(Universidad* uni)
{
	string nom, codigo;
	int opc = 0;
	Lista<Facultad>* fa = uni->getListaFacul();
	Excepciones e;
	int cant = 0;
	system("cls");
	cout << "Mostrando facultades disponibles en la universidad.";
	cout << endl << endl;
	cout << fa->toStringLista() << endl;
	cout << endl;
	cout << "Ingrese el numero de facultad que desea elegir: " << endl;
	cant = e.validarInfo(0, fa->getCant());
	Facultad* aux = fa->buscarObj(cant);
	system("cls");
	cout << "Mostrando las escuelas de la facultad de: " << aux->getNom() << endl;
	Lista<Escuela>* listE = aux->getListaEsc();
	cout << aux->toStringEscuelas() << endl;
	cout << endl;
	cout << "Ingrese la posicion de la escuela a la cual desea agregar una carrera: " << endl;
	cant = e.validarInfo(0, listE->getCant());
	Escuela* escuela = listE->buscarObj(cant);
	system("cls");
	bool finalizado = false;
	while (!finalizado) {
		cout << "---------------Creando nueva carrera---------" << endl;
		cout << "Ingrese el nombre de la carrera: ";
		cin.clear();
		cin.ignore(255, '\n');
		getline(cin, nom);
		cout << endl;
		Carrera* car = new Carrera("", nom, false, escuela, aux);
		cout << "La carrera " << car->getDescripcion() << " ha sido creado con exito." << endl;
		escuela->agregarCarreras(car);
		escuela->asignarCodigoA();//Reccorrer la lista --->Buscar a cada codigo --->""
		uni->agregarCarrera(car);
		system("pause");
		cout << "Desea crear otra carrera en esta escuela? " << endl;
		cout << "1-)Si. " << endl;
		cout << "2-)No." << endl;
		opc = e.validarInfo(1, 2);
		system("cls");
		if (opc == 2) {
			finalizado = true;
		}
		uni->ingresarMalla(car->getMalla());
	}
}

CicloLectivo* Vista::validarCicloRepetido(Universidad* uni,int ci,int an)
{
	Lista<CicloLectivo>* aux = uni->getListaCL();
	int cont = 0;
	CicloLectivo* ciclo = NULL;
	aux->inicializarActual();
	while (cont < aux->getCant()) {
		cont++;
		ciclo = aux->getTipo();
		if (ciclo->getAnio() == an && ciclo->getCiclo() == ci) {
			return ciclo;
		}
		aux->siguienteNodo();
	}
	return NULL;
}
bool Vista::comprobarTresCiclos(Universidad* uni,int an)
{
	Lista<CicloLectivo>* aux = uni->getListaCL();
	int auxxx = 0;
	int aux1 = 0;
	int aux2 = 0;
	int cont = 0;
	CicloLectivo* ciclo = NULL;
	aux->inicializarActual();
	while (cont < aux->getCant()) {
		cont++;
		ciclo = aux->getTipo();
		if (ciclo->getAnio() == an) {
			if (ciclo->getCiclo() == 1) {
				auxxx++;
			}
			if (ciclo->getCiclo() == 2) {
				aux1++;
			}
			if (ciclo->getCiclo() == 3) {
				aux2++;
			}
		}
		aux->siguienteNodo();
	}
	if (auxxx == 1 && aux1 == 1 && aux2 == 1) {
		return false;
	}
	return true;
}
void Vista::infraccion()
{
	cout << "No cuenta con los permisos para acceder a esta funcion" << endl;
	Sleep(2000);
	system("cls");
	
}

void Vista::ingresarCurso(Universidad* uni)
{
	string opc = "";
	Excepciones ex;
	string nom;
	int creditos, horasSemanales;
	int opcc = 0;
	string tipoCur;
	int au = 0;
	Lista<Carrera>* aux = uni->getListaCarr();
	bool fina = false;
	system("cls");
	if (aux->getCant() == 0) {
		cout << "No existen carreras ingresadas previamente en la universidad." << endl;
		cout << "Debe ingresar al menos una carrera para acceder a esta funcion del sistema." << endl;
		cout << "Desea crear una carrera?" << endl;
		cout << "1-)Si." << endl;
		cout << "2-)No." << endl;
		au = ex.validarInfo(1, 2);
		if (au == 1) {
			ingresarCarrera(uni);
		}
		else {
			cout << "Regresando al menu anterior." << endl;
			Sleep(2000);
			return;
		}
	}
	cout << "Mostrando contenedor de carreras ingresadas en la Universidad." << endl;
	cout << aux->toStringLista() << endl;
	cout << endl;
	cout << "Ingrese el codigo de la carrera a la cual desea crearle un curso: ";
	cin >> opc;
	Carrera* ca = aux->buscarstring(opc);
	if (!ca) {
		ex.mostrarMensajeElNoEn();
		return;
	}
	system("cls");
	cout << "Carrera encontrada!" << endl;
	Sleep(2000);
	cout << "Carrera: " << ca->getDescripcion() << endl << endl;
	mallaCurricular* mallita = ca->getMalla();
	while (!fina) {
		cout << "Ingrese el nombre del curso: ";
		cin.clear();
		cin.ignore(255, '\n');
		getline(cin, nom);
		if (buscarCursoPorNombre(nom, mallita->getLista())) {
			ex.imprimirRepetido(nom);
			cout << "Volviendo al menu anterior..." << endl;
			Sleep(2000);
			return;
		}
		cout << endl;
		cout << "Ingrese la cantidad de creditos del curso: " << endl;
		creditos = ex.validarInfo(1, 4);
		cout << endl;
		cout << "Ingrese la cantidad de horas semanales de estudio del curso: " << endl;
		horasSemanales = ex.validarInfo(1, 10);
		cout << endl;
		tipoCur = ex.darTipoCur();
		cout << endl;
		if (uni->getListaCL()->getCant() == 0) {
			cout << "No hay ciclos lectivos ingresados en el sistema." << endl;
			cout << "Procediendo a la creacion de uno para proseguir." << endl;
			cout << endl;
			CicloLectivo* nuevecito = ingresarCiclosLectivos(uni);
			uni->ingresarCicloLec(nuevecito);
		}
		system("cls");
		cout << "Mostrando todos los cursos lectivos disponibles en la universidad." << endl;
		cout << uni->toStringCL() << endl;
		cout << endl;
		cout << "Ingrese el anio del ciclo lectivo al cual pertenece este curso: " << endl;
		au = ex.ExcepcionSoloNumeros();
		cout << "Ingrese el periodo del ciclo lectivo (1,2,3)" << endl;
		opcc = ex.validarInfo(1, 3);
		CicloLectivo* cL = buscarCicloXAnYCiclo(uni->getListaCL(), au, opcc); //Crear busqueda por anio y ciclo.
		if (!cL) {
			ex.mostrarMensajeElNoEn();
			cout << "Regresando al inicio de la funcion..." << endl;
			Sleep(2000);
			ingresarCurso(uni);
		}
		system("cls");
		cout << "Ciclo lectivo encontrado!" << endl;
		Sleep(2000);
		Lista<Curso>* LisCur = mallita->getLista();
		Curso* nuevo = new Curso("", nom, creditos, horasSemanales, false, 20, cL);
		nuevo->setTipoCurso(tipoCur);
		nuevo->setCarrera(ca);
		if (LisCur->getCant() > 0) {
			mallita->agregarCurso(nuevo);
			mallita->asignarCodCurAuto();
			cout << "Desea agregarle requisitos al curso: " << endl;
			cout << "1-)Si" << endl;
			cout << "2-)No" << endl;//Validar requisitos de otras carreras
			au = ex.validarInfo(1, 2);
			if (au == 1) {
				system("cls");
				//De cual carrera quisiera tomar ese requisito
				cout << "Mostrando cursos disponibles en la carrera." << endl;
				cout << mallita->toStringEspecial() << endl;
				cout << endl;
				bool d = false;
				while (!d) {
					cout << "Ingrese el codigo del curso que desea agregar como requisito: ";
					cin >> opc;
					Curso* curso = buscarCurso(opc, LisCur);
					if (curso == NULL) {
						ex.mostrarMensajeElNoEn();
						cout << "Volviendo a menu anterior." << endl;
						system("pause");
						return;
					}
					if (curso->getCodigo() == nuevo->getCodigo()) {
						cout << "No se permite agregar el mismo curso como requisito." << endl;
						cout << "Error fatal." << endl;
						cout << "Volviendo al menu anterior." << endl;
						Sleep(2000);
						return;
					}
					if (!curso->getlistaRequisitos()->buscar(nuevo)) {
						nuevo->agregarCurso(curso);//fundamentos como requisito de progra 1
						cout << "El curso con el codigo: " << curso->getCodigo() << " ha sido agregado exitosamente a los requisitos" << endl;
						cout << " designados para el curso " << nuevo->getNombreO() << endl;
						system("pause");
					}
					else {
						ex.imprimirRepetido(nuevo->getNombreO());
						cout << "Volviendo a menu anterior..." << endl;
						Sleep(2000);
						return;
					}
					cout << "Desea agregarle otro requisito al curso: " << endl;
					cout << "1-)Si" << endl;
					cout << "2-)No" << endl;
					au = ex.validarInfo(1, 2);
					system("cls");
					if (au == 2) {
						d = true;
						return;
					}
				}
			}
			return;
		}
		system("cls");
		cout << "El curso no tendra requisitos porque no existen cursos disponibles previamente en la carrera." << endl;
		cout << "El curso " << nuevo->getNombreO() << " ha sido creado satisfactoriamente." << endl;
		system("pause");
		mallita->agregarCurso(nuevo);
		mallita->asignarCodCurAuto();
		cout << endl;
		cout << "Desea crear un nuevo curso en esta carrera: " << endl;
		cout << "1-)Si" << endl;
		cout << "2-)No" << endl;
		au = ex.validarInfo(1, 2);
		system("cls");
		if (au == 2) {
			fina = true;
		}
	}
}

Curso* Vista::buscarCurso(string cod,Lista<Curso>* lis)
{
	int cont = 0;
	Curso* cur = NULL;
	lis->inicializarActual();
	while (cont < lis->getCant()) {
		cont++;
		cur = lis->getTipo();
		if (cur->getCodigo() == cod) {
			return cur;
		}
		lis->siguienteNodo();
	}
	return NULL;
}

bool Vista::buscarCursoPorNombre(string nom, Lista<Curso>* lis)
{
	int cont = 0;
	Curso* cur = NULL;
	lis->inicializarActual();
	while (cont < lis->getCant()) {
		cont++;
		cur = lis->getTipo();
		if (cur->getNombreO() == nom) {
			return true;
		}
		lis->siguienteNodo();
	}
	return NULL;
}

Lista<CicloLectivo>* Vista::ciclosMismoAnio(Universidad* uni, int ani)
{
	Lista<CicloLectivo>* nueva = new Lista<CicloLectivo>;
	Lista<CicloLectivo>* aux = uni->getListaCL();
	int cont = 0;
	CicloLectivo* cAux = NULL;
	while (cont < aux->getCant()) {
		cont++;
		cAux = aux->getTipo();
		if (cAux->getAnio() == ani) {
			nueva->agregarObj(cAux);
		}
		aux->siguienteNodo();
	}
	if (nueva->getCant() > 0) {
		return nueva;
	}
	return NULL;
}

void Vista::Empadronar(Universidad* uni)
{
	int au = 0;
	Excepciones m;
	string cod;
	string nom, ced, tel, carnet;
	Lista<Carrera>* list = uni->getListaCarr();
	system("cls");
	if (list->getCant() == 0) {
		cout << "No existen carreras en la universidad" << endl;
		cout << "Debe ingresar al menos una carrera para acceder ";
		cout << "a esta funcionalidad del sistema." << endl;
		cout << "Desea crear una carrera?" << endl;
		cout << "1-)Si." << endl;
		cout << "2-)No." << endl;
		au = m.validarInfo(1, 2);
		if (au == 1) {
			ingresarCarrera(uni);
		}
		else {
			cout << "Regresando al menu anterior." << endl;
			Sleep(2000);
			return;
		}
	}
	cout << "\t\tBienvenido a la funcion de empadronamiento de estudiantes por carrera\t\t" << endl;
	cout << "\t\t------------------Mostrando carreras de la universidad-------------------" << endl;
	int cont = 0;
	Carrera* car = NULL;
	list->inicializarActual();
	while (cont < list->getCant()) {
		cont++;
		car = list->getTipo();
		cout << car->toStringForEspecial() << endl;
		list->siguienteNodo();
	}
	cout << endl;
	cout << "Ingrese el codigo de carrera al cual desea empadronar al estudiante: ";
	cin >> cod;
	car = list->buscarstring(cod);
	if (!car) {
		m.mostrarMensajeElNoEn();
		cout << "Volviendo al menu anterior." << endl;
		return;
	}
	system("cls");
	cout << "Carrera encontrada." << endl;
	Sleep(2000);
	cout << "Carrera: " << car->getDescripcion() << endl << endl;
	bool falso = false;
	while (!falso) {
		cout << "Procediendo a empadronar un nuevo estudiante...." << endl;
		Sleep(2000);
		cout << "Ingrese la cedula del estudiante que desea empadronar: ";
		cin >> ced;
		cout << endl;
		Estudiante* est = car->getListaEst()->buscarstring(ced);
		if (est) {
			cout << "La cedula " << ced << " ya pertenece a un estudiante empadronado." << endl;
			cout << "Pertenece a: " << endl;
			cout << est->toStringEspecial() << endl;
			cout << endl;
			cout << "Volviendo al menu anterior." << endl;
			Sleep(2000);
			return;
		}
		cout << "Ingrese el nombre del estudiante: ";
		cin.clear();
		cin.ignore(255, '\n');
		getline(cin, nom);
		cout << endl;
		cout << "Ingrese un telefono que se pueda asociar al estudiante: ";
		cin >> tel;
		cout << endl;
		cout << "Ingrese el carnet del estudiante: ";
		cin >> carnet;
		cout << endl;
		est = new Estudiante(ced, nom, tel, carnet, car->getEscuela(),car,NULL);
		HistorialAcademico* hi = new HistorialAcademico(NULL);
		est->setHistorialA(hi);
		cout << "Estudiante empadronado correctamente." << endl;
		system("pause");
		car->agregarEstudiante(est);
		Estudiante* eaux = uni->buscarEstudiante(ced);
		if (eaux == NULL) {
			uni->agregarEstudiante(est);
		}
		cout << endl;
		system("cls");
		cout << "Desea empadronar otro estudiante a la carrera de " <<car->getDescripcion()<< endl;
		cout << "1-)Si" << endl;
		cout << "2-)No" << endl;
		au = m.validarInfo(1, 2);
		system("cls");
		if (au == 2) {
			falso = true;
		}
	}
}

void Vista::mostrarEmpadronamientoPorCarrera(Universidad* uni)
{
	system("cls");
	cout << "\t\tMostrando Estudiantes empadronados por carrera." << endl;
	cout << endl;
	Lista<Carrera>* list = uni->getListaCarr();
	int cont = 0;
	int cont1 = 0;
	if (list->getCant() == 0) {
		cout << "No existen carreras creadas en la universidad..." << endl;
		cout << "Favor crear una carrera antes de acceder a esta funcion del sistema." << endl;
		cout << "Volviendo al menu anterior..." << endl;
		Sleep(2000);
		return;
	}
	Carrera* car = NULL;
	list->inicializarActual();
	while (cont < list->getCant()) {
		cont++;
		car = list->getTipo();
		if (car->getListaEst()->getCant() > 0) { 
			cout << car->toStringEstudiantesXcarr() << endl;
			cont1++;
			Sleep(2000);
		}
		list->siguienteNodo();
	}
	if (cont1 == 0) {
		cout << "\t\tNo existen existen estudiantes empadronados en ninguna carrera de la Universidad Nacional" << endl;
		Sleep(2000);
	}
	system("pause");
}

int Vista::menuMantemientoEscuela()
{
	int opcion;
	system("cls");
	cout << " _________________________________________________________________________" << endl;
	cout <<"|                                                                         |"<< endl;
	cout << "|             MANTENIMIENTO GENERAL POR ESCUELA                           |" << endl;
	cout << "|_________________________________________________________________________|" << endl;
	cout << "|1-)Consultar plan de estudios por carrera.                               |" << endl;
	cout << "|2-)Creacion de grupos.                                                   |" << endl;
	cout << "|3-)Consulta General de matricula.                                        |" << endl;
	cout << "|4-)Ingresar Profesores.                                                  |" << endl;
	cout << "|5-)Mostrar Profesores.                                                   |" << endl;
	cout << "|6-)Asignar Profesor a Grupo especifico                                   |" << endl;
	cout << "|7-)Regresar al menu principal.                                           |" << endl;
	cout << "|_________________________________________________________________________|" << endl;
	Excepciones k;
	opcion = k.validarInfo(1, 7);
	return opcion;
}

void Vista::mostrarPlanDeEstudio(Universidad* uni)
{
	Excepciones ex;
	string cod;
	Lista<Carrera>* lis = uni->getListaCarr();
	system("cls");
	if (lis->getCant() == 0) {
		cout << "No existen carreras ingresadas al sistema." << endl;
		cout << "Ingrese una carrera antes de acceder a esta funcion." << endl;
		cout << "Regresando a menu anterior." << endl;
		Sleep(2000);
		return;
	}
	cout << "\t\t-------------Plan de estudio por carrera-------------" << endl;
	cout << "Mostrando carreras disponibles en la Universidad." << endl;
	cout << endl;
	int cont = 0;
	Carrera* car = NULL;
	lis->inicializarActual();
	while (cont < lis->getCant()) {
		cont++;
		car = lis->getTipo();
		cout << car->toStringForEspecial() << endl;
	lis->siguienteNodo();
	}
	cout << endl;
	cout << "Ingrese el codigo de la carrera en la cual desea ver el plan de estudios" << endl;
	cin >> cod;
	Carrera* carre = lis->buscarstring(cod);
	if (!carre) {
		ex.mostrarMensajeElNoEn();
		cout << "Volviendo al menu anterior." << endl;
		Sleep(2000);
		return;
	}
	system("cls");
	cout << "Carrera: " << carre->getDescripcion() << endl << endl;
	mallaCurricular* malla = carre->getMalla();
	Lista<Curso>* listC = malla->getLista();
	if (listC->getCant() == 0) {
		cout << "No se han ingresado cursos a esta carrera." << endl;
		cout << "Imposible mostrar plan de estudio." << endl;
		cout << "Volviendo a menu anterior." << endl;
		Sleep(2000);
		return;
	}
	int conta = 0;
	Curso* cur = NULL;
	listC->inicializarActual();
	cout << "Plan de estudios." << endl;
	while (conta < listC->getCant()) {
		conta++;
		cur = listC->getTipo();
		cout << cur->toStringEspecial()<< endl;
		listC->siguienteNodo();
	}
	cout << endl;
	system("pause");

}

void Vista::creacionDeGrupos(Universidad* uni)
{
	system("cls");
	Excepciones ex;
	int num = 0;
	int ciclo = 0;
	Grupo* nuevo = NULL;
	string cod;
	Lista<Carrera>* lis = uni->getListaCarr();
	if (lis->getCant() == 0) {
		cout << "No existen carreras ingresadas al sistema." << endl;
		cout << "Creando una carrera..." << endl;
		cout << endl;
		ingresarCarrera(uni);
		system("pause");
	}
	system("cls");
	cout << "Mostrando carreras disponibles en la Universidad." << endl;
	cout << endl;
	cout << lis->toStringLista() << endl;
	cout << endl;
	cout << "Ingrese el numero que corresponde a la carrera que se desea agregar grupos: " << endl;
	num = ex.validarInfo(1, lis->getCant());
	Carrera* car = lis->buscarObj(num);
	cout << "Carrera encontrada! " << endl;
	Sleep(2000);
	system("cls");
	cout << "Carrera: " << car->getDescripcion() << endl << endl;
	Lista<CicloLectivo>* lc = uni->getListaCL();
	if (lc->getCant() == 0) {
		cout << "No existen ciclos lectivos creados en el sistema." << endl;
		cout << "Accediendo a la creacion de ciclo lectivo." << endl;
		CicloLectivo* k = ingresarCiclosLectivos(uni);
		uni->ingresarCicloLec(k);
		system("cls");
	}
	cout << "Mostrando los ciclos lectivos disponibles en la universidad." << endl << endl;
	cout << lc->toStringLista() << endl;
	cout << endl;
	cout << "Ingrese el anio del ciclo lectivo donde desea abrir cupos: " << endl;
	num = ex.ExcepcionSoloNumeros();
	cout << endl;
	cout << "Ingrese el ciclo(1,2,3)(solo numeros): " << endl;
	ciclo = ex.validarInfo(1, 3);
	cout << "Procediendo a buscar el ciclo..." << endl;
	Sleep(2000);
	CicloLectivo* cl = buscarCicloXAnYCiclo(lc, num, ciclo);
	if (!cl) {
		ex.elementoNoEnc();
		cout << "Volviendo a menu anterior." << endl;
		Sleep(2000);
		return;
	}
	system("cls");
	cout << "Ciclo lectivo especificado encontrado!" << endl;
	mallaCurricular* malla = car->getMalla();
	Lista<Curso>* listCur = malla->getLista();
	if (listCur->getCant() == 0) {
		cout << "No existen cursos en la carrera." << endl;
		cout << "Regresando al menu anterior." << endl;
		Sleep(2000);
		return;
	}
	cout << "Mostrando cursos disponibles en la carrera " << car->getDescripcion() << endl;
	int cont = 0;
	int cont1 = listCur->getCant();
	listCur->inicializarActual();
	Curso* auxx = NULL;
	CicloLectivo* cc = NULL;
	while (cont < listCur->getCant()) {
		auxx = listCur->getTipo();
		cc = auxx->getCicloL();
		if (cc->getAnio() == cl->getAnio() && cc->getCiclo() == cl->getCiclo()) {
			cout << auxx->toStringEspecial() << endl;
		}
		if (cont == cont1) {
			cout << "No se encontro ningun curso con el ciclo lectivo especificado. " << endl;
			cout << "Volviendo al menu anterior." << endl;
			Sleep(2000);
			return;
		}
		cont++;
		listCur->siguienteNodo();
	} //Revisar bien mas adelante.
	system("pause");
	cout << endl;
	cout << "Digite el codigo del curso al que desea crear grupos." << endl;
	cin >> cod;
	cout << "Buscando curso..." << endl;
	Sleep(2000);
	Curso* cur = buscarCurso(cod, listCur);
	if (!cur) {
		ex.mostrarMensajeElNoEn();
		cout << "Volviendo a menu anterior." << endl;
		Sleep(2000);
		return;
	}
	cout << "Curso encontrado! " << endl;
	Sleep(2000);
	system("cls");
	int k = 0;
	cout << "Curso: " << cur->getNombreO() << endl << endl;
	if (cur->getArreglo()->getCantidad() > 0 && cur->getArreglo()->getCantidad()<=20){
		cout << "Este curso ya posee al menos un grupo." << endl;
		cout << "La cantidad de grupos que posee es de " << cur->getArreglo()->getCantidad() << endl;
		cout << "Desea crear mas grupos? " << endl;
		cout << "1-)Si" << endl;
		cout << "2-)No." << endl;
		num = ex.validarInfo(1, 2);
		if (num == 2) {
			cout << "Regresando a menu anterior..." << endl;
			system("pause");
			return;
		}
		Arreglo<Grupo>* ag = cur->getArreglo();
		k = ag->getCantidad();
		int m = 20 - k;
		int j = 0;
		cout << "No se permite crear mas de 20 grupos por curso." << endl;
		cout << "Solo se le permite crear un adicional de " << 20 - k << " grupos." << endl;
		cout << "Cuantos grupos le gustaria crear: " << endl;
		num = ex.validarInfo(1, m);
		for (int i = 0; i < num; i++) {
			int capacidad;
			int horai, horaf, dia;
			int n = 0;
			j = k + 1;
			cout << "Ingrese la capacidad de estudiantes del grupo # " << j << endl;
			cout << "La capacidad del grupo no puede ser mayor a 35 estudiantes." << endl;
			capacidad = ex.validarInfo(1, 35);
			cout << endl;
			system("cls");
			cout << "Creando el grupo # " << j << endl;
			Sleep(2000);
			nuevo = new Grupo("",0, NULL, capacidad);
			nuevo->setNumero(j);
			cout << "Asignando horario del grupo # " << j << endl;
			cout << "Cuantos horarios diferentes desea crear para este grupo? " << endl;
			cout << "Se permite solo la asignacion de 2 o menos horarios por grupo." << endl;
			int z = 1;
			n = ex.validarInfo(1, 2);
			stringstream a;
			while (z <= n) {
				//7 - 9 - 1, 10 - 12 - 2,
				
				cout << "Ingrese la hora de inicio de lecciones del grupo # " << j<< endl;//7
				cout << "Solo se permiten valores enteros (desde 7 hasta 22)" << endl; //13pm 
				horai = ex.validarInfo(7, 20);
				cout << endl;
				cout << "Ingrese la hora de finalizacion del grupo: " << endl;
				horaf = ex.validarHoras(horai);
				cout << endl;
				cout << "Ingrese el dia en el cual desea asignar este grupo." << endl;
				dia = mostrarDia();//2
				cout << endl;
				
				system("cls");
				cout << "Horario guardado exitosamente..." << endl;
				if (z> 1) {
					a << ",";
				}
				a << horai << "-" << horaf << "-" << dia;//7-9-1,10-12-2
				z++;
			}
			j++;
			nuevo->setHorario(a.str());
			cout << "Creando el NCR del grupo........" << endl;
			nuevo->detNCRAutom();
			cur->agregarGrupo(nuevo);
			cout << "El grupo con el NCR " << nuevo->getNCR() << " ha sido creado y agregado al curso exitosamente." << endl;
			system("pause");
		}
		return;
	}
	cout << "No se permite crear mas de 20 grupos por curso." << endl;
	cout << "Cuantos grupos le gustaria crear: " << endl;
	num = ex.validarInfo(0, 20);
	for (int i = 0; i < num; i++) {
		int capacidad;
		int horai, horaf, dia;
		int n = 0;
		cout << "Ingrese la capacidad de estudiantes del grupo # "<<i+1<< endl;
		cout << "La capacidad del grupo no puede ser mayor a 35 estudiantes." << endl;
		capacidad = ex.validarInfo(1, 35);
		cout << endl;
		//dia = 3;
		//
		system("cls");
		cout << "Creando el grupo # " <<i+1<<endl;
		Sleep(2000);
		nuevo = new Grupo("", (i + 1), NULL, capacidad);
		cout << "Asignando horario del grupo # "<<i+1<< endl;
		cout << "Cuantos horarios diferentes desea crear para este grupo? " << endl;
		cout << "Se permite solo la asignacion de 2 o menos horarios por grupo." << endl;
		int z = 1;
		n = ex.validarInfo(1, 2);
		system("cls");
		stringstream a;
		while (z<=n) {
			cout << "Ingrese la hora de inicio de lecciones del grupo # "<<i+1<< endl;
			cout << "Solo se permiten valores enteros (desde 7 hasta 22)" << endl; //13pm 
			horai = ex.validarInfo(7, 22);
			cout << endl;
			cout << "Ingrese la hora de finalizacion del grupo: " << endl;
			horaf = ex.validarHoras(horai);
			cout << endl;
			cout << "Ingrese el dia en el cual desea asignar este grupo." << endl;
			dia = mostrarDia();//2
			cout << endl;
			system("cls");
			if (z > 1) {
				a << ",";
			}
			cout << "Horario guardado exitosamente..." << endl;
			a << horai << "-" << horaf << "-" << dia;
			z++;
		}
		nuevo->setHorario(a.str());
		nuevo->detNCRAutom();
		cur->agregarGrupo(nuevo);
		cout << "El grupo con el NCR " << nuevo->getNCR() << " ha sido creado y agregado al curso exitosamente." << endl;
		system("pause");
		system("cls");
	}
}

void Vista::asignarProfesorAGrupo(Universidad* uni)
{
	system("cls");
	string cod;
	Lista<Facultad>* lf = uni->getListaFacul();
	Excepciones ex;
	int num = 0;
	cout << "Mostrando las facultades disponibles de la universidad..." << endl;
	cout << lf->toStringLista() << endl;
	cout << endl;
	cout << "Ingrese el numero al que corresponde la facultad a la que desea acceder..." << endl;
	num = ex.validarInfo(1, lf->getCant());
	Facultad* facul = lf->buscarObj(num);
	Sleep(2000);
	system("cls");
	cout << "Facultad encontrada!" << endl;
	cout << "Facultad: " << facul->getNom() << endl;
	Lista<Escuela>* le = facul->getListaEsc();
	cout << "Mostrando contenedor de escuelas de la facultad de " << facul->getNom() << endl << endl;
	cout << facul->toStringEscuelas() << endl << endl;
	cout << "Ingrese el numero al que corresponde la escuela a la que desea acceder..." << endl;
	num = ex.validarInfo(1, le->getCant());
	Escuela* escue = le->buscarObj(num);
	Sleep(2000);
	system("cls");
	cout << "Escuela encontrada!" << endl;
	cout << "Escuela: "<< escue->getNombre() << endl;
	Lista<Profesor>* lp = escue->getListaPro();
	if (lp->getCant() == 0) {
		cout << "No existen profesores ingresados a esta carrera..." << endl;
		cout << "Favor ingresar al menos un profesor antes de acceder a esta funcion..." << endl;
		cout << "Volviendo al menu anterior..." << endl;
		Sleep(2000);
		return;
	}
	cout << "Mostrando en pantalla, contenedor de profesores ingresados en la escuela de: " << escue->getNombre() << endl << endl;
	cout << lp->toStringLista() << endl;
	cout << "Ingrese el numero al que corresponde al profesor al que desea asignarle un grupo..." << endl;
	num = ex.validarInfo(1, le->getCant());
	Profesor* pro = lp->buscarObj(num);
	Sleep(2000);
	system("cls");
	cout << "Profesor(a) encontrado(a)!" << endl;
	cout << "Profesor: " << pro->getNombre() << endl;
	Carrera* car = pro->getCarrera();
	mallaCurricular* mallita = car->getMalla();
	Lista<Curso>* lc = mallita->getLista();
	int cont = 0;
	lc->inicializarActual();
	Curso* cur = NULL;
	cout << "Mostrando en pantalla, los cursos disponibles de la carrera " << car->getDescripcion() << endl;
	cout << "Codigo" << "\t\t" << "Nombre Oficial" << "\t\t" << "Creditos" << "\t\t" << "Requisitos" << endl;
	while (cont < lc->getCant()) {
		cont++;
		cur = lc->getTipo();
		cout << cur->toStringEspecial();
		lc->siguienteNodo();
	}
	cout << endl;
	cout << "Ingrese el codigo del curso al que desea acceder...";
	cin.clear();
	cin.ignore(255, '\n');
	getline(cin, cod);
	Curso* cursito = NULL;
	int cont1 = 0;
	lc->inicializarActual();
	while (cont1 < lc->getCant()) {
		cont1++;
		cursito = lc->getTipo();
		if (cursito->getCodigo() == cod) {
			cont1 = lc->getCant();
		}
		lc->siguienteNodo();
	}
	cout << endl;
	if (!cursito) {
		ex.mostrarMensajeElNoEn();
		cout << "Regresando a menu anterior..." << endl;
		system("pause");
		return;
	}
	Sleep(2000);
	system("cls");
	cout << "Curso encontrado!" << endl;
	cout << "Curso: " << cursito->getNombreO() << endl;
	Arreglo<Grupo>* ag = cursito->getArreglo();
	if (ag->getCantidad() == 0) {
		cout << "No existen grupos creados en este curso." << endl;
		cout << "Favor crear al menos un grupo en este curso, antes de acceder a esta funcion." << endl;
		cout << "Regresando a menu anterior." << endl;
		system("pause");
		return;
	}
	cout << "\t\tMostrando Grupos disponibles" << endl << endl;
	for (int i = 0; i < ag->getCantidad(); i++) {
		Grupo* a = ag->operator[](i);
		cout << a->toStringForEspe() << endl;
	}
	cout << "Digite el NCR del grupo al que desea asignarle al profesor " << pro->getNombre() << " ";
	getline(cin, cod);
	cout << "Buscando NCR..." << endl;
	Sleep(2000);
	Grupo* grupito = ag->buscarObj(cod);
	if (!grupito) {
		ex.mostrarMensajeElNoEn();
		cout << "Regresando a menu anterior..." << endl;
		Sleep(2000);
		return;
	}
	Sleep(2000);
	system("cls");
	cout << "Grupo encontrado!" << endl;
	cout << "Grupo: " << grupito->getNCR() << endl;
	if (grupito->getProfesor() != NULL) {
		cout << "Este grupo ya cuenta con un profesor asignado." << endl;
		cout << "El profesor es..." << grupito->getProfesor()->getNombre();
		cout << "Regresando al menu anterior..." << endl;
		system("pause");
		return;
	}
	Horario* hor = pro->getHorario();
	string m = grupito->getHorario();//7-10-2,12-15-2
	if (verificaHorario(m, hor, grupito)) {
		grupito->setProfesor(pro);
		cout << "El profesor: " << pro->getNombre() << " ha sido asignado";
		cout << "al grupo # " << grupito->getNumeroGrupo() << endl;
		pro->agregarGrupo(grupito);
		system("pause");
	}
	else {
		cout << "Imposible asignar grupo en ese horario. " << endl;
		cout << "Volviendo al menu anterior..." << endl;
		system("pause");
		return;
	}
}


CicloLectivo* Vista::buscarCicloXAnYCiclo(Lista<CicloLectivo>* list, int a, int c)
{
	int cont = 0;
	list->inicializarActual();
	CicloLectivo* aux = NULL;
	while (cont < list->getCant()) {
		cont++;
		aux = list->getTipo();
		if (aux->getAnio() == a && aux->getCiclo() == c) {
			return aux;
		}
		list->siguienteNodo();
	}
	return NULL;
}

void Vista::mostrarConsultaGeneralMatricula(Universidad* uni)
{
	system("cls");
	Excepciones ex;
	int num = 0;
	int ciclo = 0;
	string cod;
	Lista<Carrera>* lis = uni->getListaCarr();
	if (lis->getCant() == 0) {
		cout << "No existen carreras ingresadas al sistema." << endl;
		cout << "Creando una carrera..." << endl;
		cout << endl;
		ingresarCarrera(uni);
	}
	cout << "Mostrando carreras disponibles en la Universidad." << endl;
	cout << endl;
	cout << lis->toStringLista() << endl;
	cout << endl;
	cout << "Ingrese el numero que corresponde a la carrera al que desea consultar: " << endl;
	num = ex.validarInfo(1, lis->getCant());
	Carrera* car = lis->buscarObj(num);
	cout << "Carrera encontrada! " << endl;
	Sleep(2000);
	system("cls");
	cout << "Carrera: " << car->getDescripcion() << endl << endl;
	Lista<CicloLectivo>* lc = uni->getListaCL();
	if (lc->getCant() == 0) {
		cout << "No existen ciclos lectivos creados en el sistema." << endl;
		cout << "Accediendo a la creacion de ciclo lectivo." << endl;
		CicloLectivo* k = ingresarCiclosLectivos(uni);
		uni->ingresarCicloLec(k);
	}
	cout << "Mostrando los ciclos lectivos disponibles en la universidad." << endl << endl;
	cout << lc->toStringLista() << endl;
	cout << endl;
	cout << "Ingrese el anio del ciclo lectivo donde desea visualizar los cursos disponibles: ";
	num = ex.ExcepcionSoloNumeros();
	cout << endl;
	cout << "Ingrese el ciclo(1,2,3)(solo numeros): " << endl;
	ciclo = ex.validarInfo(1, 3);
	cout << "Procediendo a buscar el ciclo especificado..." << endl;
	Sleep(2000);
	CicloLectivo* cl = buscarCicloXAnYCiclo(lc, num, ciclo);
	if (!cl) {
		ex.elementoNoEnc();
		cout << "Volviendo a menu anterior." << endl;
		return;
	}
	system("cls");
	mallaCurricular* malla = car->getMalla();
	Lista<Curso>* listCur = malla->getLista();
	if (listCur->getCant() == 0) {
		cout << "No existen cursos en la carrera." << endl;
		cout << "Regresando al menu anterior." << endl;
		return;
	}
	system("cls");
	cout << "Mostrando cursos disponibles en la carrera '"<< car->getDescripcion() << "' bajo la especificacion de ciclo deseada " << endl;
	int cont = 0;
	int cont1 = listCur->getCant();
	listCur->inicializarActual();
	Curso* auxx = NULL;
	CicloLectivo* cc = NULL;
	Arreglo<Grupo>* arreglo = NULL;
	while (cont < listCur->getCant()) {
		auxx = listCur->getTipo();
		cc = auxx->getCicloL();
		if (cc->getAnio() == cl->getAnio() && cc->getCiclo() == cl->getCiclo()) {
			arreglo = auxx->getArreglo();
			for (int m = 0; m < arreglo->getCantidad(); m++) {
				Grupo* grupito = arreglo->operator[](m);
				cout << grupito->toStrinGruPorMat() << endl;
			}
		}
		if (cont == cont1) {
			cout << "No se encontro ningun curso con el ciclo lectivo especificado. " << endl;
			cout << "Volviendo al menu anterior." << endl;
			return;
		}
		cont++;
		listCur->siguienteNodo();
	} //Revisar bien mas adelante.
	cout << endl;	
	Sleep(2000);
	cout << "Desea visualizar la lista de clase de un grupo?" << endl;
	cout << "1-)Si." << endl;
	cout << "2-)No." << endl;
	num = ex.validarInfo(1, 2);
	if (num == 1) {
		system("cls");
		cout << "Ingrese el NRC del grupo al que desea visualizar..." << endl;
		cout << "NRC: ";
		Grupo* grupp = NULL;
		string m;
		cin >> m;
		cont = 0;
		listCur->inicializarActual();
		while (cont < listCur->getCant()) {
			auxx = listCur->getTipo();
			cc = auxx->getCicloL();
			if (cc->getAnio() == cl->getAnio() && cc->getCiclo() == cl->getCiclo()) {
				arreglo = auxx->getArreglo();
				grupp = arreglo->buscarObj(m);
				if (grupp != NULL) {
					break;
				}
			}
			if (cont == cont1) {
				cout << "No se encontro ningun curso con el ciclo lectivo especificado. " << endl;
				cout << "Volviendo al menu anterior." << endl;
				return;
			}
			cont++;
			listCur->siguienteNodo();
		}
		if (grupp == NULL) {
			ex.mostrarMensajeElNoEn();
			cout << "Volviendo a menu anterior..." << endl;
			system("pause");
			return;
		}
		cout << "Grupo encontrado..." << endl;
		Sleep(2000);
		system("cls");
		if (grupp->getArreglo()->getCantidad() == 0) {
			cout << "No existen estudiantes matriculados en el grupo # "<<grupp->getNumeroGrupo()<<" perteniente al curso de " << grupp->getCurso() << endl;
			cout << "Regresando al menu anterior." << endl;
			return;
		}
		cout << "Mostrando grupo # " << grupp->getNumeroGrupo() << " perteniente al curso de " << grupp->getCurso()->getNombreO() << endl;
		cout << grupp->toStringProEst() << endl;
		system("pause");
	}
	else {
		cout << "Regresando a menu anterior." << endl;
		return;
	}
}
int Vista::mostrarDia()
{
	int num = 0;
	Excepciones e;
	cout << endl;
	cout << " _________________________________________________________________________" << endl;
	cout << "|                                                                         |" << endl;
	cout << "|                    Elija un dia de la semana                            |" << endl;
	cout << "|1-)Lunes.                                                                |" << endl;
	cout << "|2-)Martes.                                                               |" << endl;
	cout << "|3-)Miercoles.                                                            |" << endl;
	cout << "|4-)Jueves.                                                               |" << endl;
	cout << "|5-)Viernes.                                                              |" << endl;
	cout << "|6-)Sabado.                                                               |" << endl;
	cout << "|7-)Domingo.                                                              |" << endl;
	cout << "|_________________________________________________________________________|" << endl;
	num = e.validarInfo(1, 7);
	return num;
}
void Vista::mostrarHistorialAcademico(Universidad* uni)
{
	Excepciones e;
	Usuario* aux4 = nullptr;
	string aux2 = "";
	string aux3 = "";
	string ced;
	ifstream in;
	in.open("tipo.txt");
	Estudiante* est = NULL;
	HistorialAcademico* hist = NULL;
	int aux = devuelveEntero();
	if (aux == 4) {
		while (!in.eof()) {
			getline(in, aux2, '\n');
			getline(in, aux3, '\n');

		}
		aux4 = uni->buscarUsuarioPorString(aux3);
		est = aux4->getEstudiante();
		cout << "Carrera: " << est->getCarrera()->getDescripcion() << endl;
		cout << "Estudiante: " << est->getNombre() << endl;
		cout << endl << endl;
		hist = est->getHistorialA();
		cout << "Mostrando historial academico del estudiante " << est->getNombre() << endl;
		cout << hist->toStringEsp() << endl;
		system("pause");
		return;
	}
	Lista<Estudiante>* le = uni->getListaEst();
	if (le->getCant() == 0) {
		cout << "No existen estudiantes empadronados en ninguna carrera." << endl;
		cout << "Favor empadronar al menos un estudiante antes de acceder a esta funcion." << endl;
		cout << "Volviendo al menu anterior..." << endl;
		Sleep(2000);
		return;
	}
	cout << "Mostrando contenedor de estudiantes empadronados..." << endl;
	cout << le->toStringLista() << endl;
	cout << "Ingrese la cedula del estudiante al que desea acceder al historial academico: ";
	cin.clear();
	cin.ignore(255, '\n');
	getline(cin, ced);
	est = le->buscarstring(ced);
	if (!est) {
		e.mostrarMensajeElNoEn();
		cout << "Volviendo a menu anterior." << endl;
		system("pause");
		return;
	}
	cout << "Mostrando historial academico del estudiante..." << endl;
	hist = est->getHistorialA();
	cout << hist->toStringEsp() << endl;
	system("pause");
}
void Vista::ingresarProfesor(Universidad* uni)
{
	system("cls");
	int num = 0;
	Excepciones p;
	string nom, id, tel;
	int gradoA = 0;
	Lista<Carrera>* lc = uni->getListaCarr();
	if (lc->getCant() == 0) {
		cout << "No existen carreras ingresadas en la universidad." << endl;
		cout << "Procediendo a crear una carrera..." << endl;
		ingresarCarrera(uni);
	}
	cout << "Mostrando carreras disponibles en la Universidad." << endl;
	cout << uni->toStringCarr() << endl;
	cout << endl;
	num = p.validarInfo(1, lc->getCant());
	Carrera* aux = lc->buscarObj(num);
	Escuela* esc = aux->getEscuela();
	system("cls");
	cout << "Carrera: " << aux->getDescripcion() << endl;
	cout << "Escuela: " <<esc->getNombre() << endl;
	cout << endl;
	cout << "Ingresando profesor...." << endl;
	cout << "Ingrese la cedula de identidad del profesor ";
	cin.clear();
	cin.ignore(255, '\n');
	getline(cin,id);
	cout << "Buscando si la cedula " <<id<<" ya corresponde a un profesor ingresado en el sistema..." << endl;
	Sleep(2000);
	Profesor* pro = uni->buscarProfesor(id);
	if (pro) {
		p.imprimirRepetido(id);
		cout << "Regresando al menu anterior." << endl;
		return;
	}
	cout << endl;
	cout << "Ingrese el nombre completo del profesor: ";
	getline(cin, nom);
	cout << endl;
	cout << "Ingrese el telefono del profesor: ";
	getline(cin, tel);
	cout << endl;
	cout << "--------Grados academicos posibles para el profesor-------" << endl;
	cout << "1-)Licenciatura." << endl;
	cout << "2-)Maestria." << endl;
	cout << "3-)Doctorado." << endl;
	num = p.validarInfo(1, 3);
	cout << "Creando profesor..." << endl;
	Sleep(2000);
	Profesor* nuevo = new Profesor(id, nom, tel, esc, aux, num);
	cout << "El profesor con la cedula " << id << " ha sido creado satisfactoriamente" << endl;
	Sleep(2000);
	system("cls");
	cout << "Mostrando en pantalla , el nuevo profesor..." << endl;
	cout << nuevo->toString() << endl;
	esc->agregarProfesor(nuevo);
	uni->agregarProfesor(nuevo);
}

void Vista::mostrarProfesores(Universidad* uni)
{
	system("cls");
	int num = 0;
	Excepciones p;
	string nom, id, tel;
	int gradoA = 0;
	Lista<Carrera>* lc = uni->getListaCarr();
	if (lc->getCant() == 0) {
		cout << "No existen carreras ingresadas en la universidad." << endl;
		cout << "Procediendo a crear una carrera..." << endl;
		ingresarCarrera(uni);
	}
	cout << "Mostrando carreras disponibles en la Universidad." << endl;
	cout << uni->toStringCarr() << endl;
	cout << endl;
	num = p.validarInfo(1, lc->getCant());
	Carrera* aux = lc->buscarObj(num);
	Escuela* esc = aux->getEscuela();
	system("cls");
	cout << "Carrera: " << aux->getDescripcion() << endl;
	cout << "Escuela: " << esc->getNombre() << endl;
	cout << endl;
	int cont = 0;
	Profesor* pro = NULL;
	Lista<Profesor>* a = uni->getListaPro();
	cout << "Lista de Profesores..." << endl << endl;
	a->inicializarActual();
	cout << "ID" << "\t\t" << "Nombre" << "\t\t" << "Telefono" << "\t\t" << "Grado Academico" << endl;
	while (cont < a->getCant()) {
		cont++;
		pro = a->getTipo();
		cout << pro->toStringEsp()<<endl;
		a->siguienteNodo();
	}
	cout << endl << endl;
	system("pause");

}

void Vista::matricular(Universidad* uni)
{
	int num = 0;
	int num1 = 0;
	Matricula* mat = new Matricula(uni,NULL);
	Excepciones m;
	bool fina = false;
	
	system("cls");
	Lista<CicloLectivo>* lc = uni->getListaCL();
	if (lc->getCant() == 0) {
		cout << "No existen ciclos lectivos ingresados al sistema." << endl;
		cout << "Creando un ciclo lectivo..." << endl;
		Sleep(2000);
		CicloLectivo* ciclo = ingresarCiclosLectivos(uni);
		lc->agregarObj(ciclo);
	}
	system("cls");
	cout << "Mostrando ciclos lectivos en la universidad..." << endl << endl;
	cout << lc->toStringLista() << endl;
	cout << endl;
	cout << "Ingrese el anio del ciclo lectivo donde desea matricular..." << endl;
	num = m.ExcepcionSoloNumeros();
	cout << endl;
	cout << "Ingrese el periodo lectivo(1,2,3)(Solo numeros)" << endl;
	num1 = m.ExcepcionSoloNumeros();
	cout << endl;
	cout << "Buscando ciclo lectivo con anio " << num << " y periodo " << num1 << "..." << endl;
	Sleep(2000);
	system("cls");
	CicloLectivo* aux = buscarCicloXAnYCiclo(lc, num, num1);
	if (!aux) {
		m.mostrarMensajeElNoEn();
		cout << "Regresando a menu anterior..." << endl;
		Sleep(2000);
		return;
	}
	Usuario* aux4 = nullptr;
	string aux2 = "";
	string aux3 = "";
	string ced;
	ifstream in;
	in.open("tipo.txt");
	Estudiante* est = NULL;
	int auxxx = devuelveEntero();
	if (auxxx == 4) {
		while (!in.eof()) {
			getline(in, aux2, '\n');
			getline(in, aux3, '\n');
		}
		aux4 = uni->buscarUsuarioPorString(aux3);
		est = aux4->getEstudiante();
		mat->setEstudiante(est);
		in.close();
		while (!fina) {
			if (mat->matricular(aux)) {
				cout << "Se completado correctamente la matricula del curso..." << endl;
			}
			else {
				cout << "Imposible matricular este curso..." << endl;
				return;
			}
			cout << "Desea matricular otro curso? " << endl;
			cout << "1-)Si." << endl;
			cout << "2-)No." << endl;
			num = m.validarInfo(1, 2);
			if (num == 2) {
				fina = true;
			}
		}
		return;
	}
	Lista<Estudiante>* le = uni->getListaEst();
	if (le->getCant() == 0) {
		cout << "No existen estudiantes empadronados en ninguna carrera." << endl;
		cout << "Favor empadronar al menos un estudiante antes de acceder a esta funcion." << endl;
		cout << "Volviendo al menu anterior..." << endl;
		Sleep(2000);
		return;
	}
	cout << "Mostrando contenedor de estudiantes empadronados..." << endl;
	cout << le->toStringLista() << endl;//Cambiar toString....
	cout << "Ingrese la cedula del estudiante al que desea matricular: ";
	cin.clear();
	cin.ignore(255, '\n');
	getline(cin, ced);
	est = le->buscarstring(ced);
	if (!est) {
		m.mostrarMensajeElNoEn();
		cout << "Volviendo a menu anterior." << endl;
		Sleep(2000);
		return;
	}
	mat->setEstudiante(est);
	system("cls");
	cout << "Matriculando estudiante..." << endl;
	Sleep(2000);
	while (!fina) {
		if (mat->matricular(aux)) {
			cout << "Se completado correctamente su matricula..." << endl;
		}
		else {
			cout << "Imposible matricular..." << endl;
			return;
		}
		cout << "Desea matricular otro curso? " << endl;
		cout << "1-)Si." << endl;
		cout << "2-)No." << endl;
		num = m.validarInfo(1, 2);
		if (num == 2) {
			fina = true;
		}
	}
}

void Vista::mostrarMatriculaXEst(Universidad* uni)
{
	system("cls");
	int dev = devuelveEntero();
	if (dev != 4) {
		cout << "Imposible ingresar a esta funcion." << endl;
		cout << "Solo se permite ingresar con un usuario con rol de estudiante" << endl;
		cout << "Regresando a menu anterior" << endl;
		system("pause");
		return;
	}
	int num = 0;
	int num1 = 0;
	Excepciones m;
	bool fina = false;
	Lista<CicloLectivo>* cl = uni->getListaCL();
	if (cl->getCant() == 0) {
		cout << "No existen ciclos lectivos ingresados al sistema." << endl;
		cout << "Creando un ciclo lectivo..." << endl;
		Sleep(2000);
		CicloLectivo* z = ingresarCiclosLectivos(uni);
		uni->ingresarCicloLec(z);
	}
	cout << "Mostrando ciclos lectivos en la universidad..." << endl << endl;
	cout << cl->toStringLista() << endl;
	cout << endl;
	cout << "Ingrese el anio del ciclo lectivo donde desea matricular..." << endl;
	num = m.ExcepcionSoloNumeros();
	cout << endl;
	cout << "Ingrese el periodo lectivo(1,2,3)(Solo numeros)" << endl;
	num1 = m.ExcepcionSoloNumeros();
	cout << endl;
	cout << "Buscando ciclo lectivo con anio " << num << " y periodo " << num1 << "..." << endl;
	Sleep(2000);
	system("cls");
	CicloLectivo* aux = buscarCicloXAnYCiclo(cl, num, num1);
	if (aux == NULL) {
		m.mostrarMensajeElNoEn();
		cout << "Regresando a menu anterior..." << endl;
		system("pause");
		return;
	}
	Usuario* aux4 = nullptr;
	string aux2 = "";
	string aux3 = "";
	string ced;
	ifstream in;
	in.open("tipo.txt");
	Estudiante* est = NULL;
	if (dev == 4) {
		while (!in.eof()) {
			getline(in, aux2, '\n');
			getline(in, aux3, '\n');
			break;
		}
		aux4 = uni->buscarUsuarioPorString(aux3);
		est = aux4->getEstudiante();
		Carrera* car = est->getCarrera();
		Lista<Curso>* listCur = est->getListaCurso();
		in.close();
		if (listCur->getCant() == 0) {
			cout << "No existen cursos matriculador por el estudiante."<<est->getNombre()<< endl;
			cout << "Regresando al menu anterior." << endl;
			return;
		}
		system("cls");
		cout << "\t\t\t\tInforme de Matricula" << endl;
		cout << "Carrera: " << car->getDescripcion() << endl;
		cout << "Estudiante: " << est->getNombre() << endl;
		cout << endl;
		mallaCurricular* malla = car->getMalla();
		Lista<Curso>* listCurGen = malla->getLista();
		int cont = 0;
		int cont1 = listCur->getCant();
		listCur->inicializarActual();
		Curso* auxx = NULL;
		Curso* cursito2 = NULL;
		CicloLectivo* cc = NULL;
		Arreglo<Grupo>* arreglo = NULL;
		while (cont < listCur->getCant()) {
			auxx = listCur->getTipo();
			cc = auxx->getCicloL();
			if (cc->getAnio() == aux->getAnio() && cc->getCiclo() == aux->getCiclo()) {
				int m = 0;
				listCurGen->inicializarActual();
				while (m<listCurGen->getCant()) {
					m++;
					cursito2 = listCurGen->getTipo();
					if (cursito2->getCodigo() == auxx->getCodigo()) {
						break;
					}
					listCurGen->siguienteNodo();
				}
				Arreglo<Grupo>* arreglo = cursito2->getArreglo();
				for (int m = 0; m < arreglo->getCantidad(); m++) {
					Grupo* grupito = arreglo->operator[](m);
					cout << grupito->toStrinGruPorMat() << endl;
				}
			}
			if (cont == cont1) {
				cout << "No se encontro ningun grupo matriculado por el estudiante en este ciclo lectivo " << endl;
				cout << "Volviendo al menu anterior." << endl;
				return;
			}
			cont++;
			listCur->siguienteNodo();
		} //Revisar bien mas adelante.
		system("pause");
		return;
	}
	
}

int Vista::MenuRegistroActas()
{
	int opcion;
	Sleep(1000);
	system("cls");
	cout << " _________________________________________________________________________" << endl;
	cout << "|                                                                         |" << endl;
	cout << "|                        REGISTRO DE ACTAS                                | " << endl;
	cout << "|                                                                         |" << endl;
	cout << "|1-)Ingresar notas                                                        |" << endl;
	cout << "|2-)Visualizar notas                                                      |" << endl;
	cout << "|3-)Cambiar notas                                                         |" << endl;
	cout << "|4-)Regresar al menu anterior.                                            | " << endl;
	cout << "|_________________________________________________________________________|" << endl;
	Excepciones k;
	opcion = k.validarInfo(1, 4);
	return opcion;
}

void Vista::ingresarNotas(Universidad* uni)
{
	HistorialAcademico* his = nullptr;
	string nrc;
	int num = 0;
	int num1 = 0;
	int cali = 0;
	Excepciones m;
	bool fina = false;
	system("cls");
	Lista<CicloLectivo>* cl = uni->getListaCL();
	if (cl->getCant() == 0) {
		cout << "No existen ciclos lectivos ingresados al sistema." << endl;
		cout << "Creando un ciclo lectivo..." << endl;
		Sleep(2000);
		ingresarCiclosLectivos(uni);
	}
	cout << "Mostrando ciclos lectivos en la universidad..." << endl << endl;
	cout << cl->toStringLista() << endl;
	cout << endl;
	cout << "Ingrese el anio del ciclo lectivo donde desea matricular..." << endl;
	num = m.ExcepcionSoloNumeros();
	cout << endl;
	cout << "Ingrese el periodo lectivo(1,2,3)(Solo numeros)" << endl;
	num1 = m.ExcepcionSoloNumeros();
	cout << endl;
	cout << "Buscando ciclo lectivo con anio " << num << " y periodo " << num1 << "..." << endl;
	Sleep(2000);
	system("cls");
	CicloLectivo* aux = buscarCicloXAnYCiclo(cl, num, num1);
	if (!aux) {
		m.mostrarMensajeElNoEn();
		cout << "Regresando a menu anterior..." << endl;
		Sleep(2000);
		return;
	}
	Usuario* aux4 = nullptr;
	string aux2 = "";
	string aux3 = "";
	string ced;
	ifstream in;
	in.open("tipo.txt");
	Profesor* pro = NULL;
	int auxxx = devuelveEntero();
	if (auxxx == 5 || auxxx == 1) {
		if (auxxx == 1) {
			string cualquiercosa = "";
			cout << "Digite la cedula del profesor...";
			cin >> cualquiercosa;
			pro = uni->buscarProfesor(cualquiercosa);
		}
		else {
			while (!in.eof()) {
				getline(in, aux2, '\n');
				getline(in, aux3, '\n');
				if (aux2 == "") {
					break;
				}
			}
			aux4 = uni->buscarUsuarioPorString(aux3);
			pro = aux4->getProfesor();
		}
		
		in.close();
		if (pro == NULL) {
			m.mostrarMensajeElNoEn();
			cout << "Regresando a menu anterior." << endl;
			system("pause");
			return;
		}
		if (pro->getListaGru()->getCant() == 0) {
			cout << "Sin grupos asignados hasta el momento..." << endl;
			cout << "Regresando a menu anterior..." << endl;
			system("pause");
			return;
		}
		system("cls");
		cout << "Sus cursos para este periodo son: " << endl;
		cout << pro->toStringActas() << endl;
		cout << endl;
		cout << "Ingrese el NRC del grupo al que desea acceder...";
		cin.clear();
		cin.ignore(255, '\n');
		getline(cin, nrc);
		cout << "Buscando grupo con el NRC " << nrc << endl;
		Sleep(2000);
		Lista<Grupo>* lg = pro->getListaGru();
		Grupo* gr = lg->buscarstring(nrc);
		if (!gr) {
			m.mostrarMensajeElNoEn();
			cout << "Regresando a menu anterior..." << endl;
			Sleep(2000);
			return;
		}
		system("cls");
		cout << "Grupo encontrado" << endl;
		Arreglo<Estudiante>* arre = gr->getArreglo();
		if (arre->getCantidad() == 0) {
			cout << "No hay estudiantes matriculados en este grupo." << endl;
			cout << "Regresando a menu anterior..." << endl;
			Sleep(2000);
			return;
		}
		cout << "Lista de estudiantes matriculados en el grupo " << gr->getNCR() << endl;
		for (int i = 0; i < arre->getCantidad(); i++) {
			Estudiante* est = arre->operator[](i);
			cout << i+1 << "-";
			cout << est->toStringEspecial();
		}
		cout << endl;
		for (int i = 0; i < arre->getCantidad(); i++) {
			Estudiante* est = arre->operator[](i);/////////
			Lista<Curso>* lc = est->getListaCurso();
			his = est->getHistorialA();
			int cont = 0;
			Curso* c = NULL;
			Curso* nuevo = NULL;
			lc->inicializarActual();
			while(cont<lc->getCant()){
				cont++;
				c = lc->getTipo();
				if (c->getCodigo() == gr->getCurso()->getCodigo()) {
					cont = lc->getCant();
				}
				lc->siguienteNodo();
			}
			if (c->getcali() == 0) {
				cout << "Ingrese la calificacion para el estudiante # " << i + 1 << ": ";
				cali = m.validarInfo(1, 10);
			    nuevo = new Curso(c->getCodigo(), c->getNombreO(), c->getCreditos(), c->getHorasSemanales(), c->getEstado(), 0, c->getCicloL());
				nuevo->setCali(cali);
				string m = nuevo->detGaPe();
				nuevo->setTipoCurso(c->getTipoCurso());
				nuevo->setCarrera(c->getCarrera());
				c->setCali(cali);
				if (nuevo->getcali() < 6 || nuevo->getcali() >= 7) {//Profesor 
					his->agregarCurso(nuevo);
					lc->eliminarObjEspecifico(c);
					arre->eliminarObj(i);
					est->getHorario()->eliminarGrupoEspecifico(gr->getNCR());
					cout << "El historial academico del estudiante " << est->getNombre() << " ha sido actualizado correctamente." << endl;
					cout << "No podra visualizar notas superiores a 7 ni inferiores a 6 en la funcion de mostrar notas." << endl;
				}
			}
			else {
				if (c->getcali() >= 6 && c->getcali() < 7) {
					cout << "Desea modificar la nota del estudiante " << est->getNombre() << endl;
					cout << "1)Si." << endl;
					cout << "2)No." << endl;
					int valor = m.validarInfo(1, 2);
					if (valor == 1) {
						cout << "Ingrese la nueva nota del estudiante" << endl;
						valor = m.validarInfo(7,10);
						c->setCali(valor);
						
						nuevo = new Curso(c->getCodigo(), c->getNombreO(), c->getCreditos(), c->getHorasSemanales(), c->getEstado(), 0, c->getCicloL());
						nuevo->setCali(valor);
						string j = nuevo->detGaPe();
						nuevo->setTipoCurso(c->getTipoCurso());
						nuevo->setCarrera(c->getCarrera());
						his->agregarCurso(nuevo);
						lc->eliminarObjEspecifico(c);
						arre->eliminarObj(i);
						est->getHorario()->eliminarGrupoEspecifico(gr->getNCR());
						cout << "La nota se ha actualizado correctamente" << endl;
						cout << "El historial academico del estudiante " << est->getNombre() << " ha sido actualizado correctamente." << endl;
						cout << "No podra visualizar notas superiores a 7 ni inferiores a 6 en la funcion de mostrar notas." << endl;
						system("pause");
					}
					else {
						his->agregarCurso(nuevo);
						lc->eliminarObjEspecifico(c);
						arre->eliminarObj(i);
						est->getHorario()->eliminarGrupoEspecifico(gr->getNCR());
					}
				}
				else {
					cout << "Imposible modificar la nota del estudiante " << est->getNombre() << endl;
					cout << "Las unicas notas modificables son las que tienen el rango entre 6 y 7" << endl;
					system("pause");
				}
			}

		}
		cout << "Se han registrado correctamente las calificaciones a los estudiantes del grupo " << gr->getNCR() << endl;
		system("pause");
	}

}

void Vista::mostrarCalificacion(Universidad* uni)
{
	system("cls");
	int dev = devuelveEntero();
	if (dev != 5) {
		cout << "Imposible ingresar a esta funcion." << endl;
		cout << "Solo se permite ingresar con un usuario con rol de profesor" << endl;
		cout << "Regresando a menu anterior" << endl;
		system("pause");
		return;
	}
	string nrc;
	int num = 0;
	int num1 = 0;
	int cali = 0;
	Excepciones m;
	bool fina = false;
	system("cls");
	Lista<CicloLectivo>* cl = uni->getListaCL();
	if (cl->getCant() == 0) {
		cout << "No existen ciclos lectivos ingresados al sistema." << endl;
		cout << "Creando un ciclo lectivo..." << endl;
		Sleep(2000);
		ingresarCiclosLectivos(uni);
	}
	cout << "Mostrando ciclos lectivos en la universidad..." << endl << endl;
	cout << cl->toStringLista() << endl;
	cout << endl;
	cout << "Ingrese el anio del ciclo lectivo donde desea matricular..." << endl;
	num = m.ExcepcionSoloNumeros();
	cout << endl;
	cout << "Ingrese el periodo lectivo(1,2,3)(Solo numeros)" << endl;
	num1 = m.ExcepcionSoloNumeros();
	cout << endl;
	cout << "Buscando ciclo lectivo con anio " << num << " y periodo " << num1 << "..." << endl;
	Sleep(2000);
	system("cls");
	CicloLectivo* aux = buscarCicloXAnYCiclo(cl, num, num1);
	if (!aux) {
		m.mostrarMensajeElNoEn();
		cout << "Regresando a menu anterior..." << endl;
		Sleep(2000);
		return;
	}
	Usuario* aux4 = nullptr;
	string aux2 = "";
	string aux3 = "";
	string ced;
	ifstream in;
	in.open("tipo.txt");
	Profesor* pro = NULL;
	if (dev == 5) {
		while (!in.eof()) {
			getline(in, aux2, '\n');
			getline(in, aux3, '\n');
			break;
		}
		aux4 = uni->buscarUsuarioPorString(aux3);
		pro = aux4->getProfesor();
		in.close();
		if (pro->getListaGru()->getCant() == 0) {
			cout << "Sin grupos asignados hasta el momento..." << endl;
			cout << "Regresando a menu anterior..." << endl;
			Sleep(2000);
			return;
		}
		system("cls");
		cout << "Sus cursos para este periodo son: " << endl;
		cout << pro->toStringActas() << endl;
		cout << endl;
		cout << "Ingrese el NRC del grupo al que desea acceder...";
		cin.clear();
		cin.ignore(255, '\n');
		getline(cin, nrc);
		cout << "Buscando grupo con el NRC " << nrc << endl;
		Sleep(2000);
		Lista<Grupo>* lg = pro->getListaGru();
		Grupo* gr = lg->buscarstring(nrc);
		if (!gr) {
			m.mostrarMensajeElNoEn();
			cout << "Regresando a menu anterior..." << endl;
			Sleep(2000);
			return;
		}
		system("cls");
		cout << "Grupo encontrado" << endl;
		Arreglo<Estudiante>* arre = gr->getArreglo();
		if (arre->getCantidad() == 0) {
			cout << "No hay estudiantes matriculados en este grupo." << endl;
			cout << "Regresando a menu anterior..." << endl;
			Sleep(2000);
			return;
		}
		cout << "Curso: " << gr->getCurso()->getNombreO() << endl;
		cout << "NRC: " << gr->getNCR() << ":" << endl;

		cout << "Solo se mostraran las notas de los estudiantes que esten en extraordinario." << endl;
		for (int i = 0; i < arre->getCantidad(); i++) {
			Estudiante* est = arre->operator[](i);
			Lista<Curso>* curest = est->getListaCurso();
			cout << i + 1 << "-";
			Curso* cu = NULL;
			string cod = gr->getCurso()->getCodigo();
			int contador = 0;
			curest->inicializarActual();
			while (contador < curest->getCant()) {
				contador++;
				cu = curest->getTipo();
				if (cu->getCodigo() == cod) {
					contador = curest->getCant();
					break;
				}
				curest->siguienteNodo();
			}
			cout << "\t\t" << est->getCedula() << "\t\t" << est->getNombre() << "\t\t" << cu->stringEspecialCali();
		}
		system("pause");
	}

	
}

void Vista::modificarNotasExt(Universidad* uni)
{
	system("cls");
	int dev = devuelveEntero();
	if (dev != 5) {
		cout << "Imposible ingresar a esta funcion." << endl;
		cout << "Solo se permite ingresar con un usuario con rol de profesor" << endl;
		cout << "Regresando a menu anterior" << endl;
		system("pause");
		return;
	}
	string nrc;
	int num = 0;
	int num1 = 0;
	int cali = 0;
	Excepciones m;
	bool fina = false;
	system("cls");
	Lista<CicloLectivo>* cl = uni->getListaCL();
	if (cl->getCant() == 0) {
		cout << "No existen ciclos lectivos ingresados al sistema." << endl;
		cout << "Creando un ciclo lectivo..." << endl;
		Sleep(2000);
		ingresarCiclosLectivos(uni);
	}
	cout << "Mostrando ciclos lectivos en la universidad..." << endl << endl;
	cout << cl->toStringLista() << endl;
	cout << endl;
	cout << "Ingrese el anio del ciclo lectivo donde desea matricular..." << endl;
	num = m.ExcepcionSoloNumeros();
	cout << endl;
	cout << "Ingrese el periodo lectivo(1,2,3)(Solo numeros)" << endl;
	num1 = m.ExcepcionSoloNumeros();
	cout << endl;
	cout << "Buscando ciclo lectivo con anio " << num << " y periodo " << num1 << "..." << endl;
	Sleep(2000);
	system("cls");
	CicloLectivo* aux = buscarCicloXAnYCiclo(cl, num, num1);
	if (!aux) {
		m.mostrarMensajeElNoEn();
		cout << "Regresando a menu anterior..." << endl;
		Sleep(2000);
		return;
	}
	Usuario* aux4 = nullptr;
	string aux2 = "";
	string aux3 = "";
	string ced;
	ifstream in;
	in.open("tipo.txt");
	Profesor* pro = NULL;
	int auxxx = devuelveEntero();
	if (auxxx == 5 || auxxx == 1) {
		if (auxxx == 1) {
			string cualquiercosa = "";
			cout << "Digite la cedula del profesor...";
			cin >> cualquiercosa;
			pro = uni->buscarProfesor(cualquiercosa);
		}
		else {
			while (!in.eof()) {
				getline(in, aux2, '\n');
				getline(in, aux3, '\n');
				if (aux2 == "") {
					break;
				}
			}
			aux4 = uni->buscarUsuarioPorString(aux3);
			pro = aux4->getProfesor();
		}
		in.close();
		if (pro == NULL) {
			cout << "No se encontro al profesor" << endl;
			system("pause");
			return;
		}
		if (pro->getListaGru()->getCant() == 0) {
			cout << "Sin grupos asignados hasta el momento..." << endl;
			cout << "Regresando a menu anterior..." << endl;
			Sleep(2000);
			return;
		}
		system("cls");
		cout << "Sus cursos para este periodo son: " << endl;
		cout << pro->toStringActas() << endl;
		cout << endl;
		cout << "Ingrese el NRC del grupo al que desea acceder...";
		cin.clear();
		cin.ignore(255, '\n');
		getline(cin, nrc);
		cout << "Buscando grupo con el NRC " << nrc << endl;
		Sleep(2000);
		Lista<Grupo>* lg = pro->getListaGru();
		Grupo* gr = lg->buscarstring(nrc);
		if (!gr) {
			m.mostrarMensajeElNoEn();
			cout << "Regresando a menu anterior..." << endl;
			Sleep(2000);
			return;
		}
		system("cls");
		cout << "Grupo encontrado" << endl;
		Arreglo<Estudiante>* arre = gr->getArreglo();
		if (arre->getCantidad() == 0) {
			cout << "No hay estudiantes matriculados en este grupo." << endl;
			cout << "Regresando a menu anterior..." << endl;
			Sleep(2000);
			return;
		}
		cout << "Lista de estudiantes matriculados en el grupo " << gr->getNCR() << endl;
		for (int i = 0; i < arre->getCantidad(); i++) {
			Estudiante* est = arre->operator[](i);
			cout << i + 1 << "-";
			cout << est->toStringEspecial();
		}
		cout << endl;
		for (int i = 0; i < arre->getCantidad(); i++) {
			system("cls");
			Estudiante* est = arre->operator[](i);
			Lista<Curso>* lc = est->getListaCurso();
			int cont = 0;
			Curso* c = NULL;
			lc->inicializarActual();
			while (cont < lc->getCant()) {
				cont++;
				c = lc->getTipo();
				if (c->getcali()>=6 && c->getcali()<7) {
					cont = lc->getCant();
				}
				lc->siguienteNodo();
			}
			cout << "Desea cambiar la calificacion del estudiante " << est->getNombre() << "? ";
			cout << "1-)Si" << endl;
			cout << "2-)No." << endl;
			cali = m.validarInfo(1, 2);
			if (cali == 1) {
				cout << "Ingrese la nueva calificacion del estudiante " << est->getNombre() << endl;
				cali = m.validarInfo(7, 10);
				cout << "Cambiando calificacion..." << endl;
				Sleep(2000);
				c->setCali(cali);
				cout << "Calificacion cambiada..." << endl;
				system("pause");
			}
		}
		cout << "Se han registrado correctamente las calificaciones a los estudiantes del grupo " << gr->getNCR() << endl;
		system("pause");
	}
}

bool Vista::verificaHorario(string m, Horario* hor, Grupo* grupoo)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num = 0;
	int cont = 0;
	string aux = "";
	for (int i = 0; i < m.size(); i++) {
		while (m[i] != ',' && m[i] != '\0') {
			if (m[i] != '-') {
				aux += m[i];
			}
			if (cont == 2) {
				num = stoi(aux);//1-3-2,1-4-2
				num3 = num;
				aux = "";
				cont = 0;

			}
			if (m[i] == '-' && cont == 1) {
				num = stoi(aux);
				num2 = num;
				aux = "";
				cont++;

			}
			if (m[i] == '-' && cont == 0) {
				num = stoi(aux);
				num1 = num;
				aux = "";
				cont++;

			}
			i++;
		}
		if (!hor->rellenarMatriz(num1, num2, num3, grupoo)) {
			return false;
		}
	}
	return true;
}
