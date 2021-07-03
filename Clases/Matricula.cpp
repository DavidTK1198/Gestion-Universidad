#include "Matricula.h"
#include "HistorialAcademico.h"
Matricula::Matricula(Universidad* un,Estudiante* estt)
{
	uni = un;
	est = estt;
}

Matricula::~Matricula()
{
}

bool Matricula::matricular(CicloLectivo* ciclo)
{
	Excepciones exc;
	int num = 0;
	int opc = 0;
	string cod;
	mallaCurricular* aux = buscarCarrera();
	Curso* cur = NULL;
	Grupo* gru = NULL;
	if (!aux) {
		exc.memoriaInsu();
		return false;
	}
	opc = ciclo->getCiclo();
	Lista<Curso>* listita = retornaCurMisCL(ciclo,aux,opc); //Lista de cursos 
	if (listita->getCant() == 0) {
		exc.listaVacia();
		return false;
	}
	cout << "---------------------Mostrando Cursos disponibles----------------" << endl;
	int cont = 0;
	Curso* cursito = NULL;
	listita->inicializarActual();
	cout << "\t\tCodigo" << "\t\t" << "Nombre Completo" << "\t\t" << "Creditos" << "\t\t" << "Requisitos" << endl;
	while (cont < listita->getCant()) {
		cont++;
		cout << "Curso # " << cont << endl;
		cursito = listita->getTipo();
		cout <<"\t\t"<< cursito->toStringEspecial();
		listita->siguienteNodo();
	}
	
	cout << endl;
	cout << "Ingrese la posicion del curso que desea matricular. " << endl;
	Excepciones e;
	num = e.ExcepcionSoloNumeros();
	cur = listita->buscarObj(num);
	if (!cur) {
		exc.memoriaInsu();
		system("pause");
		return false;
	}
	int cont1 = 0;
	Lista<Curso>* lcest = est->getListaCurso();
	Curso* cur2 = NULL;
	lcest->inicializarActual();
	while (cont1 < lcest->getCant()) {
		cont1++;
		cur2 = lcest->getTipo();
		if (cur2->getCodigo() == cur->getCodigo()) {
			cout << "El curso de " << cur2->getNombreO() << " ya ha sido matriculado anteriormente." << endl;
			system("pause");
			return false;
		}
		lcest->siguienteNodo();
	}
	Arreglo<Grupo>* arr = cur->getArreglo();
	if (arr->getCantidad() == 0) {
		cout << "El curso " << cur->getNombreO() << " no tiene grupos creados." << endl;
		cout << "Imposible seguir avanzando con el proceso de matricula." << endl;
		cout << "Regresando a menu anterior." << endl;
		system("pause");
		return false;
	}
	cout << "\t\tMostrando Grupos disponibles" << endl << endl;
	for (int i = 0; i < arr->getCantidad(); i++) {
		Grupo* a = arr->operator[](i);
		cout << a->toStringForEspe() << endl;
	}
	cout << "Ingrese el codigo del Grupo que desea matricular: ";
	cin.clear();
	cin.ignore(255, '\n');
	getline(cin, cod);
	gru = arr->buscarObj(cod);
	if (!gru) {
		exc.mostrarMensajeElNoEn();
		cout << "Regresando a menu anterior." << endl;
		system("pause");
		return false;
	}
	cout << gru->toStringForEspe() << endl;
	if (gru->getCapacidad() == 0) {
		cout << "El grupo esta en su maxima capacidad" << endl;
		cout << "Imposible matricular en este grupo." << endl;
		cout << "Regresando a menu anterior." << endl;
		system("pause");
		return false;
	}
	if (!buscarEstudiante(est->getCedula(), gru->getArreglo()) == NULL) {
		exc.imprimirRepetido(est->getCedula());
		system("pause");
		return false;
	}
	HistorialAcademico* ha = est->getHistorialA();
	if (!compararHistAcaReq(ha, cur->getlistaRequisitos())) {
		exc.mostrarReqNoCum();
		system("pause");
		return false;
	}
	//Progra

	if (ha->buscarCurso(cur)) {
		cout << "El curso " << cur->getNombreO() << " ya ha sido ganado por el estudiante." << endl;
		cout << "No es posible matricularlo nuevamente." << endl;
		system("pause");
		return false;
	}

	Horario* hor = est->getHorario();
	string m = gru->getHorario();
	if (verificaHorario(m, hor, gru)) {
		gru->agregarEstudiante(est);
		gru->MoviendoCapacidad();
		cout << "El estudiante: " << est->getNombre() << " ha sido matriculado correctamente ";
		cout << "al grupo # " << gru->getNumeroGrupo() << endl;
		Curso* cr = new Curso(cur->getCodigo(), cur->getNombreO(), cur->getCreditos(), cur->getHorasSemanales(), cur->getEstado(), 0, cur->getCicloL());
		cr->setTipoCurso(cur->getTipoCurso());
		Carrera* car = cur->getCarrera();
		cr->setCarrera(car);
		est->agregarCursoMatriculado(cr);
		system("pause");
		return true;
	}
	else {
		cout << "Imposible matricular curso en ese horario. " << endl;
		system("pause");
	}
	return false;
}
mallaCurricular* Matricula::buscarCarrera()
{
	string cod;
	int cont = 0;
	int cant;
	mallaCurricular* mallita = NULL;
	Lista<mallaCurricular>* auxList = uni->getListMalla(); //ejemplo mallita 1 con puntero a carrera ingieneria
	cant = auxList->getCant();
	Carrera* auxCarM = NULL;
	Carrera* auxCar = est->getCarrera();
	cod = auxCar->getCodigo();
	auxList->inicializarActual();
	while (cont < cant) {
		cont++;
		mallita = auxList->getTipo();
		auxCarM = mallita->getCarrera();
		if (auxCarM->getCodigo() == cod) {
			return mallita;
		}
		auxList->siguienteNodo();
	}
	return NULL;
}

Lista<Curso>* Matricula::retornaCurMisCL(CicloLectivo* cl,mallaCurricular* malla,int per)
{
	Lista<Curso>* aux = NULL;
	Lista<Curso>* CursosMisAn = new Lista<Curso>;
	aux = malla->getLista();
	int cant = aux->getCant();
	int cont = 0;
	Curso* auxx = NULL;
	CicloLectivo* clec = NULL;
	aux->inicializarActual();
	while (cont < cant) {
		cont++;
		auxx = aux->getTipo();
		clec = auxx->getCicloL();
		if (clec->getAnio() == cl->getAnio() && clec->getCiclo() == per) {
			CursosMisAn->agregarObj(auxx);
		}
		aux->siguienteNodo();
	}
	if (CursosMisAn->getCant() > 0) {
		return CursosMisAn;
	}
	return NULL;
}

Estudiante* Matricula::buscarEstudiante(string cod,Arreglo<Estudiante>* ar)
{
	Estudiante* est = NULL;
	for (int i = 0; i < ar->getCantidad(); i++) {
		est = ar->operator[](i);
		if (est->getCedula() == cod) {
			return est;
		}
	}
	return NULL;
}

int Matricula::mostrarDias()
{
	int num = 0;
	Excepciones e;
	cout << "-------------Elija un dia de la semana------------" << endl;
	cout << "1-)Lunes." << endl;
	cout << "2-)Martes." << endl;
	cout << "3-)Miercoles." << endl;
	cout << "4-)Jueves." << endl;
	cout << "5-)Viernes." << endl;
	cout << "6-)Sabado." << endl;
	cout << "7-)Domingo." << endl;
	num = e.validarInfo(1, 7);
	return num;
}

bool Matricula::compararHistAcaReq(HistorialAcademico* his, Lista<Curso>* li)
{

	Lista<Curso>* curs = his->materiasApr();
	if (his->compararReqMatApr(li)) {
		return true;
	}
	else {
		return false;
	}
}

bool Matricula::verificaHorario(string m,Horario* hor,Grupo* grupoo)
{
	//7-9-1
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

void Matricula::setEstudiante(Estudiante* estt)
{
	est = estt;
}
