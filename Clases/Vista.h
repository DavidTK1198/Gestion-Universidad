#pragma once
#include <iostream>
#include <sstream>
#include "Excepciones.h"
#include "Usuario.h"
#include "UsuarioAdmin.h"
#include "UsuarioEscuela.h"
#include "UsuarioEstudiante.h"
#include <Windows.h>
#include "Lista.h"
#include "Universidad.h"
#include <fstream>
#include <string>
#include "CicloLectivo.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "HistorialAcademico.h"
#include "Matricula.h"
using namespace std;
class Vista {
	
	public:
		static void despedida();
		static int menuEspecial();
		static void PresentacionInicial();
		static int MenuPrincipal();
		static int AdministracionRoles();
		static void gotoxy(int, int);
		static int matriculaYhistorial();
		static string tipoUsuario(int);
		static Usuario* CreandoUsuario(Universidad*);
		static Usuario* validarUsuario(Universidad*);
		static void mostarUsuarios(Lista<Usuario>* );
		static Usuario* buscarUsuario(Lista<Usuario>* list);
		static void determineTipoUsuario(Usuario*);
		static int devuelveEntero();
		static int loginfinal();
		static void creandoCualquierUsua(Universidad*);
		static int devolverRolUsuario();
		static int mantenimientoNivelRegistro();
		static CicloLectivo* ingresarCiclosLectivos(Universidad*);
		static int accesoMenu(int,int);
		static Lista<Facultad>* asignarAUniversidad();
		static Estudiante* buscarEst(string,Lista<Estudiante>*);
		static int subMenuCiclosLectivos();
		static void mostrarCiclos(Universidad*);
		static int mantenimientoCarrYCurs();
		static int empadronamiento();
		static void ingresarCarrera(Universidad*);
		static CicloLectivo* validarCicloRepetido(Universidad*,int,int);
		static bool comprobarTresCiclos(Universidad*,int);
		static void infraccion();
		static void ingresarCurso(Universidad*);
		static Curso* buscarCurso(string,Lista<Curso>*);
		static bool buscarCursoPorNombre(string, Lista<Curso>*);
		static Lista<CicloLectivo>* ciclosMismoAnio(Universidad*,int);
		static void Empadronar(Universidad*);
		static void mostrarEmpadronamientoPorCarrera(Universidad*);
		static int menuMantemientoEscuela();
		static void mostrarPlanDeEstudio(Universidad*);
		static void creacionDeGrupos(Universidad*);
		static void asignarProfesorAGrupo(Universidad*);
		static CicloLectivo* buscarCicloXAnYCiclo(Lista<CicloLectivo>*,int,int);
		static void mostrarConsultaGeneralMatricula(Universidad*);
		static int mostrarDia();
		static void mostrarHistorialAcademico(Universidad*);
		static void ingresarProfesor(Universidad*);
		static void mostrarProfesores(Universidad*);
		static void matricular(Universidad*);
		static void mostrarMatriculaXEst(Universidad*);
		static int MenuRegistroActas();
		static void ingresarNotas(Universidad*);
		static void mostrarCalificacion(Universidad*);
		static void modificarNotasExt(Universidad*);
		static bool verificaHorario(string, Horario*, Grupo*);

};