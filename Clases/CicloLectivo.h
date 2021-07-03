#pragma once
#include <sstream>
#include<iostream>
#include "Fecha.h"
using namespace std;
class Fecha;
class CicloLectivo
{
	private:
		int anio; 
		Fecha* fechaI;
		Fecha* fechaF;
		string periodicidad;
		int ciclo;
	public:
		CicloLectivo(int, Fecha*, Fecha*, string, int);
		virtual ~CicloLectivo();
		int getAnio();
		Fecha* getFechaI();
		Fecha* getFechaF();
		string getPeriodicidad();
		int getCiclo();
		void setAnio(int);
		void setFechaI(Fecha*);
		void setFechaF(Fecha*);
		void setPeriodicidad(string);
		void setCiclo(int);
		string toString() const;
		friend ostream& operator << (ostream&, const CicloLectivo&);
		bool operator == (int&);
};


