#pragma once
#include <iostream>
#include "ExcepcionRango.h"
#include "ExcepcionRangoInferior.h"
#include "ExcepcionRangoSuperior.h"
#include "Usuario.h"
#include "UsuarioAdmin.h"
#include "UsuarioEscuela.h"
#include "UsuarioEstudiante.h"
#include "UsuarioManten.h"
#include "UsuarioProfesor.h"
#include "UsuarioRegistro.h"

using namespace std;
class Excepciones
{
	public:
		int excepcionValor(int,int);
		int validarInfo(int,int);
		bool determinarMayusculasContra(string);
		bool determinarNumeroContra(string);
		string ValContraFormCor();
		string excepcionContra();
		int ExcepcionUsuario(Usuario*);
		int ExcepcionSoloNumeros();
		string infraccionMemoria();
		string NoelementosEnLista();	
		void memoriaInsu();
		void listaVacia();
		string requisitosNoCum();
		string elementoNoEnc();
		void mostrarMensajeElNoEn();
		void mostrarReqNoCum();
		string Elementorepetido(string);
		void imprimirRepetido(string);
		int validarPeriodicidad();
		string darPeriocidad();
		int validadTipoCurso();
		string darTipoCur();
		int validarHoras(int);
		int comparaHoras(int,int);
		int validarSoloNum();
		
};


