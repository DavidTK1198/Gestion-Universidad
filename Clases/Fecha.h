#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Fecha
{
	private:
		int dia;
		int mes;
		int anio;
	public:
		Fecha(int, int, int);
		virtual ~Fecha();
		int getDia()const;
		int getMes()const;
		int getAnio()const;
		void setDia(int);
		void setMes(int);
		void setAnio(int);
		string toStringFecha()const;
		bool compararFechas(Fecha*,Fecha*);
		int comparaFecha(Fecha*, Fecha*);
		friend ostream& operator << (ostream&, const Fecha&);
		friend istream& operator >> (istream&,Fecha&);


};
