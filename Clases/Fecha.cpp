#include "Fecha.h"

Fecha::Fecha(int d, int m , int a)
{
	dia = d;
	mes = m;
	anio = a;
}

Fecha::~Fecha()
{

}

int Fecha::getDia() const
{
	return dia;
}

int Fecha::getMes() const
{
	return mes;
}

int Fecha::getAnio() const
{
	return anio;
}

void Fecha::setDia(int d)
{
	dia = d;
}

void Fecha::setMes(int m)
{
	mes = m;
}

void Fecha::setAnio(int a)
{
	anio = a;
}

string Fecha::toStringFecha() const
{
	stringstream p;
	p<< dia << " / " << mes << " / " << anio;
	return p.str();
}

bool Fecha::compararFechas(Fecha* i,Fecha* f)
{

	if (i->getAnio() <f->getAnio()) {
		return true;
	}
	if (i->getAnio() > f->getAnio()) {
		return false;
	}
	else {
		if (i->getMes() < f->getMes()) {
			return true;
		}
		if (i->getMes() > f->getMes()) {
			return false;
		}
		else {
			if (i->getDia() < f->getDia()) {
				return true;
			}
		}
	}
	return false;
	//int n = comparaFecha(i, f);
	//if (n == 1 || n == 0) {
	//	return true;
	//}
	//return false;

}

int Fecha::comparaFecha(Fecha* i, Fecha* f)
{
	int valor;
	if (i->getAnio() != f->getAnio()) {
		valor = i->getAnio() - f->getAnio();
	}
	else {
		if (i->getMes() != f->getMes()) {
			return i->getMes() - f->getMes();
		}
	}
	valor = i->getDia() - f->getDia();
		return valor;
}

ostream& operator<<(ostream& out, const Fecha& f)
{
	return out << f.toStringFecha() << endl;
}

istream& operator>>(istream& in,Fecha& f)
{
	in >> f.dia >> f.mes >> f.anio;
	return in;
}
