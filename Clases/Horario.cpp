#include "Horario.h"
#include "Grupo.h"

Horario::Horario()
{
	matGru = new Grupo **[filas];
	for (int i = 0; i < filas; i++) {
		matGru[i] = new Grupo * [columas];	
	}
	for (int f = 0; f < filas; f++) {
		for (int c = 0; c < columas; c++) {
			matGru[f][c] = NULL;
		}
	}
	

}
Horario::~Horario()
{
	for (int i = 0; i < filas; i++) {
		 delete matGru[i];
	}
	delete[] matGru;

}

bool Horario::agregarGrupo(Grupo* grup)
{
	for (int f = 0; f < filas; f++) {
		for (int c = 0; c < columas; c++) {
			if (matGru[f][c] == NULL) {
				matGru[f][c] = grup;
				return true;
			}
		}
	}
	return false;
}

string Horario::toString()
{
	int contador = 0;
	stringstream m;
	m << endl;
	m << "Horario del Estudiante" << endl;
	for (int i = 0; i < filas; i++) {
		contador = 0;
		for (int j = 0; j < columas; j++) {

			if (matGru[i][j] != NULL) {
				contador++;
				if (contador == 1) {
					m << " [" << determinarDia(i + 1) << "]" << endl;

				}
				int aux = determinarHoraInversa(j);

				m << "[" << determinarHoraInversa(j) << determinaAMPM(aux) << "]";
				m << endl;


				m << matGru[i][j]->toStringForEspe();
				m << "\n";
			}
		}
	}
	return m.str();
}

Grupo* Horario::buscar(int f, int c)
{
	if (matGru[f][c] != NULL) {
		return matGru[f][c];
	}
	return NULL;
}

string Horario::determinarDia(int d)
{
	switch (d) {
	case 1:return "Lunes";
		break;
	case 2:return "Martes";
		break;
	case 3:return "Miercoles";
		break;
	case 4:return "Jueves";
		break;
	case 5:return "Viernes";
		break;
	case 6:return "Sabado";
		break;
	case 7:return "Domingo";
		break;
	default:
		return "El numero no corresponde a ningun mes";


	}

}

int Horario::determinarHora(int d)
{
	switch (d) {
	case 7:return 0;
		break;
	case 8:return 1;
		break;
	case 9:return 2;
		break;
	case 10:return 3;
		break;
	case 11:return 4;
		break;
	case 12:return 5;
		break;
	case 13:return 6;
		break;
	case 14:return 7;
		break;
	case 15:return 8;
		break;
	case 16:return 9;
		break;
	case 17:return 10;
		break;
	case 18:return 11;
		break;
	case 19:return 12;
		break;
	case 20:return 13;
		break;
	case 21:return 14;
		break;
	default:
		return 100;
	}
}

int Horario::determinarHoraInversa(int d)
{
	switch (d) {
	case 0:return 7;
		break;
	case 1:return 8;
		break;
	case 2:return 9;
		break;
	case 3:return 10;
		break;
	case 4:return 11;
		break;
	case 5:return 12;
		break;
	case 6:return 13;
		break;
	case 7:return 14;
		break;
	case 8:return 15;
		break;
	case 9:return 16;
		break;
	case 10:return 17;
		break;
	case 11:return 18;
		break;
	case 12:return 19;
		break;
	case 13:return 20;
		break;
	case 14:return 21;
		break;
	default:
		return 0;
	}
}

Grupo* Horario::buscarGrupo(Grupo* gr)
{
	Grupo* aux = NULL;
	for (int f = 0; f < filas; f++) {
		for (int c = 0; c < columas; c++) {
			aux = matGru[f][c];
			if (aux->getNCR() == gr->getNCR()) {
				return aux;
			}
		}
	}
	return NULL;
}

bool Horario::rellenarMatriz(int i,int f, int d,Grupo* g)
{
	//static int num = i; 3
	//static int num = f; 5

	Grupo* aux = NULL; //6am - 11am   segundo
	int z = determinarHora(i);// 9-11am  //(dia , horaI, horaF)class horarioAuxiliar -> Grupo->Arreglo<HorarioAuxiliar>* (2)
	int m = determinarHora(f);
	if (m != 0 || z != 0) {
		for (int k = z; k <= m; k++) {
			if (matGru[d][k] != NULL) {
				cout << "Horario ocupado." << endl;
				aux = matGru[d][k];
				cout << "El horario choca con el grupo " << endl;
				cout << aux->toStringForEspe() << endl;
				return false;
			}
		}
		for (int k = z; k <= m; k++) {
			if (matGru[d][k] == NULL) {
				matGru[d][k] = g;  //filas horas, columnas - dias 7  8 9 L
				//1 --->2 ---> Funda --> 7--->9--->L // 6-10
			
			}
		}
		return true;
	}
	else {
		cout << "Hora inicial u hora final invalido" << endl;
		return false;
	}

}

string Horario::determinaAMPM(int num)
{
	if (num > 12) {
		return "pm";
	}
	return "am";
}

bool Horario::eliminarGrupoEspecifico(string cod)
{
	Grupo* aux = NULL;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columas; j++) {
			aux = matGru[i][j];
			if (aux != NULL) {
				if (aux->getNCR() == cod) {
					matGru[i][j] = NULL;
					return true;
				}
			}
		}
	}
	return false;
}


//int guardarHoraI(int i){
//static int n = i;
//return n;

