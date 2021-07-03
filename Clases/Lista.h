#pragma once
#include "nodo.h"
#include <sstream>
#include <iostream>
using namespace std;
template <class T>
class Lista {
	private:
		nodo<T>* pPio;
		nodo<T>* actual;
		int cant;
	public:
		Lista();
		bool agregarObj(T*);
		string toStringLista();
		virtual ~Lista();
		T* buscarObj(int);
		bool eliminarObj(int);
		bool eliminarObjEspecifico(T*);
		int getCant();
		void setCant(int);
		void inicializarActual();
		void siguienteNodo();
		void SiguienteElemento();
		T* getTipo();
		bool verificaVacio();
		bool buscar(T*);
		bool listaVacia();
		T* buscarGenerico(int);
		T* buscarstring(string);
		Lista<T>* BuscarListaCompletaPInt(int);

}; 

template<class T>
Lista<T>::Lista() {
	pPio = NULL;
	actual = NULL;
	cant = 0;
}
template<class T>
bool Lista<T>::agregarObj(T* obj) {
	pPio = new nodo<T>(obj, pPio);
	cant++;
	return true;
}

template<class T>
string Lista<T>::toStringLista()
{
	nodo<T>* p = pPio;
	int cont = 1;
	stringstream s;
	if (p == NULL) {
		s << "\t\tNO HAY ELEMENTOS EN LA LISTA\t\t" << endl;
	}
	else {
		while (p != NULL) {
			s <<" #. " << cont << " -----> " << endl;
			s<<*(p->getObj()) << endl;
			p = p->getSig();
			cont++;
		}
	}
	return s.str();

}

template<class T>
Lista<T>::~Lista() {
	nodo<T>* p = pPio;
	nodo<T>* aux = NULL;
	while (p!=NULL) {
		aux = p->getSig();
		delete p;
		p = aux;
	}
	pPio = NULL;
}

template<class T>
T* Lista<T>::buscarObj(int pos)
{
	int cont = 1;
	nodo<T>* p = pPio;
	while (p != NULL && cont <pos) {
		p = p->getSig();
		cont++;
	}
	if (cont == pos) {
		if (p != NULL) {
			return p->getObj();
		}
	}
	return NULL;
}

template<class T>
bool Lista<T>::eliminarObj(int lug)
{
	int numerito = 1;
	nodo<T>* p = pPio;
	nodo<T>* aux = NULL;
	while (p != NULL && numerito < lug) {
		aux = p;//aux ---> 1 -----> p ---->2
		p = p->getSig();//antes del que va a eliminar ----> 
		numerito++;
	}
	if (numerito == lug) {
		aux->setSig(p->getSig());
		delete p->getObj();
		p = NULL;
		return true;
	}
	return false;

}

template<class T>
bool Lista<T>::eliminarObjEspecifico(T* dato)
{
	actual = pPio;
	T* aux = nullptr;
	nodo<T>* nodito = nullptr;
	// Si la lista no está vacía:
	if (!listaVacia()) {
		while (actual!=NULL) {
			nodito = actual;
			if (cant == 1) {
				pPio = NULL;
				actual = NULL;
				cant--;
				return true;
			}
			actual = actual->getSig();
			if (actual->getObj() == dato) {
				nodito->setSig(actual->getSig());
				actual = NULL;
				cant--;
				return true;
			}
			
		}
	}
	// Si el nodo es válido, se ha encontrado el valor:
	return false;
}

template<class T>
int Lista<T>::getCant()
{
	return cant;
}

template<class T>
void Lista<T>::setCant(int can)
{
	cant = can;
}

template<class T>
void Lista<T>::inicializarActual()
{
	actual = pPio;
}

template<class T>
void Lista<T>::siguienteNodo()
{

	if (actual->getSig() != NULL) {
		actual = actual->getSig();
	}

}

template<class T>
T* Lista<T>::getTipo()
{
	T* p = actual->getObj();
	//actual = actual->getSig();
	return p;
}

template<class T>
bool Lista<T>::verificaVacio()
{
	return pPio == NULL;
}

template<class T>
bool Lista<T>::buscar(T* dato)
{
	actual = pPio;

	// Si la lista no está vacía:
	if (!listaVacia()) {
		while (actual && actual->getObj()!= dato) {
			actual = actual->getSig();
		}
	}
	// Si el nodo es válido, se ha encontrado el valor:
	return actual != NULL;
}

template<class T>
bool Lista<T>::listaVacia()
{
	return pPio == NULL;
}
template<class T>
T* Lista<T>::buscarGenerico(int p)
{
	actual = pPio;
	T* aux = NULL;
	while (actual != NULL) {
		aux = actual->getObj();
		if (*aux == p) {
			return aux;
		}
		actual = actual->getSig();
	}
	return NULL;
}
template<class T>
 T* Lista<T>::buscarstring(string p)
{
	 actual = pPio;
	 T* aux = NULL;
	 while (actual != NULL) {
		 aux = actual->getObj();
		 if (*aux == p) {
			 return aux;
		 }
		 actual = actual->getSig();
	 }
	 return NULL;
}
template<class T>
Lista<T>* Lista<T>::BuscarListaCompletaPInt(int p)
{
	Lista<T>* listaux = new Lista<T>;
	actual = pPio;
	T* aux = NULL;
	while (actual != NULL) {
		aux = actual->getObj();
		if (*aux == p) {
			listaux->agregarObj(aux);
		}
		actual = actual->getSig();
	}
	if (listaux->getCant() == 0) {
		return NULL;
	}
	return listaux;
}
template<class T>
void Lista<T>::SiguienteElemento()
{
	if (actual) {
		actual = actual->getSig();
	}
}

