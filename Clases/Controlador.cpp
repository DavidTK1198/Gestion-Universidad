#include "Controlador.h"

Controlador::Controlador()
{
	remove("tipo.txt");
	uni = new Universidad();
	gestion = new GestorDeArchivos("Persona/Usuarios.txt", "Persona/Estudiantes.txt", "Persona/Profesores.txt", "Carreras/Carrera.txt","Carreras/malla.txt");
	uni->setFacultad(Vista::asignarAUniversidad());
	gestion->setUniversiad(uni);
	gestion->cargarDatos();
	control0();

}

Controlador::~Controlador()
{
	gestion->guardardatos();
	delete uni;
	delete gestion;
	remove("tipo.txt");

}

void Controlador::controLogin()
{

	int cont = 0;
	while (Vista::validarUsuario(uni) == NULL) {
		cont++;
		if (cont >= 3) {
			cout << "Ha superado el numero de intentos fallidos." << endl;
			system("pause");
			exit(0);
		}
	}
	control1();

}



void Controlador::control0()
{
	Vista::PresentacionInicial();
	int n = uni->getCantidad();
	if (n == 0) {
		control4();
	}
	else {
		controLogin();
	}
}

void Controlador::control1()
{
	int p = 0;
	do {

		p = Vista::MenuPrincipal();
		switch (p)
		{
		case 0: control12();
			break;
		case 1:
			control2();
			break;
	
		case 2:
			control6();
			break;
		case 3:
			control19();
			break;
		case 4:
			control14();
			break;
		case 5:
			control28();
			break;
		case 6:
			controlDespedida();
			break;
		default:
			break;
		}
	} while (p != 6);
	
}

void Controlador::control2()
{
	int z = 0;
	do {
		z = Vista::AdministracionRoles();
		switch (z)
		{
		case 1:
			control3();
			break;
		case 2:
			control5();
			break;
		default:
			break;
		}

	} while (z != 3);
}

void Controlador::control3()
{
	Vista::creandoCualquierUsua(uni);
}

void Controlador::control4()
{
	Usuario* p = NULL;
	p = Vista::CreandoUsuario(uni);
	uni->ingresarUsuario(p);
	Vista::determineTipoUsuario(p);
	control1();
}

void Controlador::control5()
{
	Vista::mostarUsuarios(uni->getListaUsuar());
}

void Controlador::control6()
{
	int z = 0;
	do {
		z = Vista::mantenimientoNivelRegistro();
		switch (z)
		{
		case 1:
			control7();
			break;
		case 2:
			control10();
			break;
		case 3:
			control17();
			break;
		default:
			break;
		}

	} while (z != 4);
}
void Controlador::control14()
{
	int z = 0;
	do {
		z = Vista::matriculaYhistorial();
		switch (z)
		{
		case 1:
			control26();
			break;
		case 2:
			control27();
			break;
		case 3:
			control23();
			break;
		default:
			break;
		}

	} while (z != 4);
}

void Controlador::control15()
{
	Vista::ingresarCurso(uni);
}

void Controlador::control16()
{
	Vista::Empadronar(uni);
}

void Controlador::control17()
{
	int z = 0;
	do {
		z = Vista::empadronamiento();
		switch (z)
		{
		case 1:
			control16();
			break;
		case 2:
			control18();
			break;
		default:
			break;
		}

	} while (z != 3);
}

void Controlador::control18()
{
	Vista::mostrarEmpadronamientoPorCarrera(uni);
}

void Controlador::control19()
{
	int z = 0;
	do {
		z = Vista::menuMantemientoEscuela();
		switch (z)
		{
		case 1:
			control20();
			break;
		case 2:
			control21();
			break;
		case 3:
			control22();
			break;
		case 4:
			control24();
			break;
		case 5:
			control25();
			break;
		case 6:
			control31();
			break;
		default:
			break;
		}

	} while (z != 7);
}

void Controlador::control20()
{
	Vista::mostrarPlanDeEstudio(uni);
}

void Controlador::control21()
{
	Vista::creacionDeGrupos(uni);
}

void Controlador::control22()
{
	Vista::mostrarConsultaGeneralMatricula(uni);
}

void Controlador::control23()
{
	Vista::mostrarHistorialAcademico(uni);
}

void Controlador::control24()
{
	Vista::ingresarProfesor(uni);
}

void Controlador::control25()
{
	Vista::mostrarProfesores(uni);
}

void Controlador::control26()
{
	Vista::matricular(uni);
}

void Controlador::control27()
{
	Vista::mostrarMatriculaXEst(uni);
}

void Controlador::control28()
{
	int z = 0;
	do {
		z = Vista::MenuRegistroActas();
		switch (z)
		{
		case 1:
			control29();
			break;
		case 2:
			control30();
			break;
		case 3:
			control32();
			break;
		default:
			break;
		}
	} while (z != 4);
}

void Controlador::control29()
{
	Vista::ingresarNotas(uni);
}

void Controlador::control30()
{
	Vista::mostrarCalificacion(uni);
}

void Controlador::control31()
{
	Vista::asignarProfesorAGrupo(uni);
}

void Controlador::control32()
{
	Vista::mostrarCalificacion(uni);
}

void Controlador::controlDespedida()
{
	int z = 0;
	do {
		z = Vista::menuEspecial();
		switch (z)
		{
		case 1:
			controLogin();
			break;
		case 2:
			control13();
			break;
		default:
			break;
		}

	} while (z != 2);
}


void Controlador::control7()
{
	int z = 0;
	do {
		z = Vista::subMenuCiclosLectivos();
		switch (z)
		{
		case 1:
			control9();
			break;
		case 2:
			control8();
			break;
		default:
			break;
		}

	} while (z != 3);
}

void Controlador::control8()
{
	CicloLectivo* ci = Vista::ingresarCiclosLectivos(uni);
	uni->ingresarCicloLec(ci);
}

void Controlador::control9()
{
	Vista::mostrarCiclos(uni);
}

void Controlador::control10()
{
	int z = 0;
	do {
		z = Vista::mantenimientoCarrYCurs();
		switch (z)
		{
		case 1:
			control11();
			break;
		case 2:
			control15();
			break;
		default:
			break;
		}

	} while (z != 3);
}

void Controlador::control11()
{
	Vista::ingresarCarrera(uni);
}

void Controlador::control12()
{
	Vista::infraccion();
}

void Controlador::control13()
{
	Vista::despedida();
}
