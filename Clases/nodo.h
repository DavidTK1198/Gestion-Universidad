#pragma once
template <class T>
class nodo
{
private:
	T* Obj;
	nodo<T> *Sig;
public:
	nodo(T*, nodo<T>*);
	virtual ~nodo();
	virtual void setObj(T*);
	virtual T* getObj()const;
	virtual void setSig(nodo<T>*);
	virtual nodo<T>* getSig()const;

};
template<class T>
nodo<T>::nodo(T* ob, nodo<T>* si) {
	Obj = ob;
	Sig = si;
}

template<class T>
nodo<T>::~nodo() {

}
template<class T>
void nodo<T>::setObj(T* ob) {
	Obj = ob;
}

template<class T>
T* nodo<T>::getObj()const {
	return Obj;
}
template<class T>
void nodo<T>::setSig(nodo<T>* si) {
	Sig = si;
}
template<class T>
nodo<T> *nodo<T>::getSig()const{
	return Sig;
}


