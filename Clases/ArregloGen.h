#pragma once
#include <iostream>
#include <sstream>
using namespace std;
template<class T>
class Arreglo {
	private:
		T** arreglo;
		int can;
		int tam;
	public:
		Arreglo(int);
		virtual ~Arreglo();
		int getCantidad()const;
		int getTamanio()const;
		T* buscarObj(int);
		void eliminarObj(int);
		T* operator [](int);
		void agregarObj(T*);
		T* buscarObj(string);
		T* recuperarObjeto(int i);
		



};

template<class T>
Arreglo<T>::Arreglo(int ta)
{
	this->tam = ta;
	can = 0;
	arreglo = new T* [tam];
	for (int i = 0; i < tam; i++) {
		arreglo[i] = NULL;
	}
}

template<class T>
Arreglo<T>::~Arreglo()
{
	for (int i = 0; i < can; i++) {
		delete arreglo[i];
	}
	delete[]arreglo;

}

template<class T>
int Arreglo<T>::getCantidad() const
{
	return can;
}

template<class T>
int Arreglo<T>::getTamanio() const
{
	return tam;
}

template<class T>
T* Arreglo<T>::buscarObj(int ind)
{
	for (int i = 0; i < can; i++) {
		if (i == ind) {
			return arreglo[i];
		}
	}
	return NULL;
}

template<class T>
void Arreglo<T>::eliminarObj(int pos)
{
	bool es = false;
	T* aux = NULL;
	for (int i = 0; i < can; i++) {
		if (i == pos) {
			arreglo[i] = NULL;
			es = true;
		}
		if (es == true && can>1) {
			aux = arreglo[i + 1];
			arreglo[i] = aux;
		}
	}
	if (es == true) {
		can--;
	}
}



template<class T>
T* Arreglo<T>::operator[](int ind)
{
	return arreglo[ind];
}

template<class T>
void Arreglo<T>::agregarObj(T* obj)
{
	if (can < tam) {
		arreglo[can++] = obj;
	}
}
template<class T>
T* Arreglo<T>::buscarObj(string NRC)
{
	for (int i = 0; i < can; i++) {
		T* aux = arreglo[i];
		if (*aux == NRC) {
			return aux;
		}
	}
	return NULL;
}
template<class T>
 T* Arreglo<T>::recuperarObjeto(int i)
{
	 return arreglo[i - 1];
}
