#include "CicloLectivo.h"

CicloLectivo::CicloLectivo(int a, Fecha* i, Fecha* f, string per, int cic)
{
	anio = a;
	fechaI = i;
	fechaF = f;
	periodicidad = per;
	ciclo = cic;
}

CicloLectivo::~CicloLectivo()
{
}

int CicloLectivo::getAnio()
{
	return anio;
}

Fecha* CicloLectivo::getFechaI()
{
	return fechaI;
}

Fecha* CicloLectivo::getFechaF()
{
	return fechaF;
}

string CicloLectivo::getPeriodicidad()
{
	return periodicidad;
}

int CicloLectivo::getCiclo()
{
	return ciclo;
}

void CicloLectivo::setAnio(int i)
{
	anio = i;
}

void CicloLectivo::setFechaI(Fecha* f)
{
	fechaI = f;
}

void CicloLectivo::setFechaF(Fecha* f)
{
	fechaF = f;
}

void CicloLectivo::setPeriodicidad(string p)
{
	periodicidad = p;
}

void CicloLectivo::setCiclo(int c)
{

	ciclo = c;
}

string CicloLectivo::toString() const
{
	stringstream s;
	s << "\t\t--------------------CICLO LECTIVO-------------------------\t\t" << endl;
	s << "\t\tAnio: " << anio << "\t\t" << endl;
	s << "\t\tPeriodicidad: " << periodicidad << "\t\t" << endl;
	s << "\t\tCiclo Lectivo: " << ciclo << "\t\t" << endl;
	if (fechaI) {
		s << "\t\tFecha de inicio del curso lectivo: " << fechaI->toStringFecha() <<"\t\t"<< endl;
	}
	else {
		s << "\t\tSin fecha de inicio ingresada.\t\t" << endl;
	}
	if (fechaF) {
		s << "\t\tFecha de finalizacion del curso lectivo: " << fechaF->toStringFecha() <<"\t\t"<< endl;
	}
	else {
		s << "\t\tSin fecha de finalizacion ingresada.\t\t" << endl;
	}
	return s.str();
}

bool CicloLectivo::operator==(int& a)
{
	return (this->anio == a);
}

ostream& operator<<(ostream& out, const CicloLectivo& cl)
{
	return out << cl.toString() << endl;

}
