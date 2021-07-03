#include "GestorDeArchivos.h"
GestorDeArchivos::GestorDeArchivos(string us,string est,string pro,string car,string ma)
{
    usuarios = us;
    estudiantes = est;
    profesores = pro;
    carreras = car;
    mallas = ma;
  
}

GestorDeArchivos::~GestorDeArchivos()
{
}

bool GestorDeArchivos::guardarListaUsuarios(Lista<Usuario>* x)
{
    int elem;
    Usuario* us = nullptr;
    int n = 0;
    if (x->listaVacia()) {
        return false;
    }
    else {
        elem = x->getCant();
        ofstream out;
        out.open(usuarios, ios::out);
        out << elem << '\n';
        x->inicializarActual();
        while (n < x->getCant()) {
            n++;
            us = x->getTipo();
            out << us->getCedula() << '\t';
            out << us->getNombre() << '\t';
            out << us->getTelefono() << '\t';
            out << us->getClave() << '\t';
            out << us->getRol() << '\n';
            x->siguienteNodo();
        }
        out.close();
        return true;
    }
    return false;
}

Lista<Usuario>* GestorDeArchivos::recuperarListaUsuario() {
    Usuario* us = NULL;
    Profesor* profe = nullptr;
    Estudiante* est=nullptr;
    ifstream in;
    Lista<Usuario>* lista = new Lista<Usuario>;
    string nombre, tele, cedula, clave, tipo, ca;
    int cantidad = 0;
    int contador = 0;
    in.open(usuarios);
    getline(in, ca, '\n');
    lista->inicializarActual();
    stringstream cant(ca);
    cant >> cantidad;
    while (in.good() && cantidad > contador) {
        contador++;
        getline(in, cedula, '\t');
        getline(in, nombre, '\t');
        getline(in, tele, '\t');
        getline(in, clave, '\t');
        getline(in, tipo, '\n');
        if (tipo == "Administrador") {
            Usuario* us2 = new UsuarioAdmin(cedula, nombre, tele, clave);
            lista->agregarObj(us2);
        }
        if (tipo == "Estudiante") {
            Usuario* us = new UsuarioEstudiante(cedula, nombre, tele, clave);
            int n =uni->getCantEst();
            est = uni->buscarEstudiante(cedula);
            us->setEstudiante(est);
            lista->agregarObj(us);

        }
        if (tipo == "Profesor") {
            Usuario* us3 = new UsuarioProfesor(cedula, nombre, tele, clave);
            profe = uni->buscarProfesor(cedula);
            us3->setProfesor(profe);
            lista->agregarObj(us3);
        }
        if (tipo == "Escuela") {
            Usuario* us4 = new UsuarioEscuela(cedula, nombre, tele, clave);
            lista->agregarObj(us4);
        }
        if (tipo == "Mantenimiento") {
            Usuario* us5 = new UsuarioManten(cedula, nombre, tele, clave);
            lista->agregarObj(us5);
        }
        if (tipo == "Registro") {
            Usuario* us6 = new UsuarioRegistro(cedula, nombre, tele, clave);
            lista->agregarObj(us6);
        }
        lista->SiguienteElemento();
    }
    in.close();

    return lista;
}
bool GestorDeArchivos::guardarListaEs(Lista<Estudiante>* x)
{
    int elem;
    Estudiante* us = nullptr;
    HistorialAcademico* ha = nullptr;
    int n = 0;
    if (x->listaVacia()) {
        return false;
    }
    else {
        elem = x->getCant();
        estudiante << elem << '\n';
        x->inicializarActual();
        while (n < x->getCant()) {
            n++;
            us = x->getTipo();
            ha = us->getHistorialA();
            estudiante << us->getCedula() << '\t';
            estudiante << us->getNombre() << '\t';
            estudiante << us->getTelefono() << '\t';
            estudiante << us->getCarrera()->getCodigo()<< '\t';
            estudiante << us->getCarnet() << '\n';
            guardarHistorialA(ha);
            guardarCursosMatriculados();
            x->siguienteNodo();
        }
        return true;
    }
    return false;
}

bool GestorDeArchivos::guardarHistorialA(HistorialAcademico* ha)
{
    Lista<Curso>* lc = ha->getListaGeneral();
    Estudiante* est = ha->getEstudiante();
    historialA << est->getCedula() << '\n';
    historialA << lc->getCant() << '\n';
    if (lc->getCant() == 0) {
        historialA << "vacio" << '\n';
    }
    else {
        historialA << "tiene" << '\n';
    }
    int cont = 0;
    lc->inicializarActual();
    Curso* curso = nullptr;
    Carrera* carr = nullptr;
    while (cont < lc->getCant()) {
        cont++;
        curso = lc->getTipo();
        carr = curso->getCarrera();
        historialA << curso->getCodigo() << '\t';
        historialA << curso->getcali() << '\t';
        historialA << carr->getCodigo() << '\n';
        lc->siguienteNodo();
    }
    return true;
}

void GestorDeArchivos::recuperarHistorialA()//123
{
    ifstream in;
    in.open("Universidad/Historial.txt");
    Lista<Estudiante>* le = uni->getListaEst();
    Estudiante* est = nullptr;
    string codC, codCarr, cant, cedEstud, variable, cali;
    int cantidad = 0;
    int calii = 0;
    int contador = 0;
    int contador1 = 0;
    int contador2 = 0;
    HistorialAcademico* ha = nullptr;
    Curso* cur = nullptr;
    Carrera* carr = nullptr;
    mallaCurricular* malla = nullptr;
    Lista<Curso>* lc = nullptr;
    while (!in.eof()) {
        getline(in, cedEstud, '\n');//154
        if (cedEstud == "") {
            break;
        }
        le->inicializarActual();
        while (contador2 < le->getCant()) {
            contador2++;
            est = le->getTipo();
            ha = est->getHistorialA();
            getline(in, cant, '\n');
            getline(in, variable, '\n');
            if (variable != "vacio") {
                cantidad = stoi(cant);
                while (contador < cantidad) {
                    contador++;
                    getline(in, codC, '\t');
                    getline(in, cali, '\t');
                    getline(in, codCarr, '\n');
                    calii = stoi(cali);
                    carr = uni->buscarCarrera(codCarr);
                    malla = carr->getMalla();
                    lc = malla->getLista();
                    lc->inicializarActual();
                    while (contador1 < lc->getCant()) {
                        contador1++;
                        cur = lc->getTipo();
                        if (cur->getCodigo() == codC) {
                            Curso* nuevo = new Curso(cur->getCodigo(), cur->getNombreO(), cur->getCreditos(), cur->getHorasSemanales(), cur->getEstado(), 0, cur->getCicloL());
                            nuevo->setCarrera(carr);
                            nuevo->setTipoCurso(cur->getTipoCurso());
                            nuevo->setCali(calii);
                            ha->agregarCurso(nuevo);
                        }
                        lc->siguienteNodo();
                    }
                }
            }
            le->siguienteNodo();
        }
    }
    in.close();
}



Lista<Estudiante>* GestorDeArchivos::recuperarListaEs(Carrera* carr)
{
    Estudiante* est = nullptr;
    ifstream in;
    Lista<Estudiante>* lista = new Lista<Estudiante>;
    HistorialAcademico* h = new HistorialAcademico(NULL); //Cambiarlo bien
    string nombre, tele, cedula, carnet, ca, cod;
    int cantidad = 0;
    int contador = 0;
    in.open(estudiantes);
   
    lista->inicializarActual();
    
    while (!in.eof()) {
        getline(in, ca, '\n');
        if (ca == "") {
            break;
        }
        contador++;
        
        stringstream cant(ca);
        cant >> cantidad;
        getline(in, cedula, '\t');
        getline(in, nombre, '\t');
        getline(in, tele, '\t');
        getline(in, cod, '\t');
        getline(in, carnet, '\n');
        if (carr->getCodigo() == cod) {
            est = new Estudiante(cedula, nombre, tele, carnet, carr->getEscuela(), carr, NULL);
            est->setHistorialA(h);
            uni->agregarEstudiante(est);
            lista->agregarObj(est);
        }
        lista->SiguienteElemento();
    }

    in.close();
    return lista;
}
void GestorDeArchivos::setUniversiad(Universidad* x)
{
    uni = x;

}

bool GestorDeArchivos::guardarCiclos(Lista<CicloLectivo>* x)
{
    int elem;
    CicloLectivo* us = nullptr;
    int n = 0;
    Fecha* fe1 = nullptr;
    Fecha* fe2 = nullptr;
    if (x->listaVacia()) {
        return false;
    }
    else {
        elem = x->getCant();
        ofstream out;
        out.open("Universidad/ciclos.txt", ios::out);
        out << elem << '\n';
        x->inicializarActual();
        while (n < x->getCant()) {
            n++;
            us = x->getTipo();
            fe1 = us->getFechaI();
            fe2 = us->getFechaF();
            out << us->getAnio() << '\t';
            out << us->getCiclo() << '\t';
            out << us->getPeriodicidad() << '\t';
            out << fe1->getDia() << '\t';
            out << fe1->getMes() << '\t';
            out << fe1->getAnio() << '\t';
            out << fe2->getDia() << '\t';
            out << fe2->getMes() << '\t';
            out << fe2->getAnio() << '\n';
            x->siguienteNodo();
        }
        out.close();
        return true;
    }
    return false;
}

Lista<CicloLectivo>* GestorDeArchivos::recuperarListaCiclo()
{
    string per;
    int anio;
    int ciclo;
    int di1;
    int me1;
    int an1;
    int di2;
    int me2;
    int an2;
    CicloLectivo* est = nullptr;
    ifstream in;
    Fecha* fe1 = nullptr;
    Fecha* fe2 = nullptr;
    Lista<CicloLectivo>* lista = new Lista<CicloLectivo>;
    string ca,cic,an,dia1,mes1,anio1,dia2,mes2,anio2;
    int cantidad = 0;
    int contador = 0;
    in.open("Universidad/ciclos.txt");
    getline(in, ca, '\n');
    lista->inicializarActual();
    stringstream cant(ca);
    cant >> cantidad;
    while (in.good() && cantidad > contador) {
        contador++;
        getline(in, an, '\t');
        stringstream ann(an);
        ann >> anio;
        getline(in, cic, '\t');
        stringstream cicl(cic);
        cicl >> ciclo;
        getline(in, per, '\t');
        getline(in, dia1, '\t');
        stringstream diaa1(dia1);
        diaa1 >> di1;
        getline(in, mes1, '\t');
        stringstream mees1(mes1);
        mees1 >> me1;
        getline(in, anio1, '\t');
        stringstream annio1(anio1);
        annio1 >> an1;
        getline(in, dia2, '\t');
        stringstream diaa2(dia2);
        diaa2 >> di2;
        getline(in, mes2, '\t');
        stringstream mees2(mes2);
        mees2 >> me2;
        getline(in, anio2, '\n');
        stringstream annio2(anio2);
        annio2 >> an2;
        fe1 = new Fecha(di1, me1, an1);
        fe2 = new Fecha(di2, me2, an2);
        est = new CicloLectivo(anio,fe1,fe2,per,ciclo);
        lista->agregarObj(est);
        lista->SiguienteElemento();
    }

    in.close();
    return lista;
}

bool GestorDeArchivos::guardarCarreras(Lista<Carrera>* x)
{
    int elem;
    int e=0;
    int contador2 = 0;
    Carrera* us = nullptr;
    Facultad* fa = nullptr;
    Escuela* escu = nullptr;
    Estudiante* estu = nullptr;
    mallaCurricular* mallita = nullptr;
    Lista<mallaCurricular>* lism = new Lista<mallaCurricular>;
    Lista<Estudiante>* lis = new Lista<Estudiante>;
    int n = 0;
    if (x->listaVacia()) {
        return false;
    }
    else {
        elem = x->getCant();
        ofstream out;
        out.open(carreras, ios::out);
        out << elem << '\n';
        x->inicializarActual();
        while (n < x->getCant()) {
            
            n++;
            us = x->getTipo();
            mallita = us->getMalla();
            lis = us->getListaEst();
            out << us->getCodigo() << '\t';
            out << us->getDescripcion() << '\t';
            out << us->getEstado() << '\t';
            escu = us->getEscuela();
            out << escu->getNombre()<<'\t';;
            fa = us->getFacultad();
            out << fa->getNom() << '\t';
            
            if (lis->getCant() == 0) {
                out << "vacio" << '\n';
                
            }
            else {
                out << "estudiantes" << '\n';
                guardarListaEs(lis);
                }
            lism->agregarObj(mallita);
            x->siguienteNodo();
            }
        guardarMallas(lism);
        out.close();
        return true;
        }
    return false;
}

Lista<Carrera>* GestorDeArchivos::recuperarCarreras()
{
    Carrera* car = nullptr;
    ifstream in;
    Facultad* fa = nullptr;
    Escuela* escu = nullptr;
    Lista<Estudiante>* listaa = new Lista<Estudiante>;
    Lista<Carrera>* lista = new Lista<Carrera>;
    Lista<Escuela>* escue = new Lista<Escuela>;
    string nombre,escuela,fac,estado,codigo,ca,estudi;
    int cantidad = 0;
    int cant = 0;
    int contador = 0;
    int cant2 = 0;
    int cont2 = 0;
    in.open(carreras);
    getline(in, ca, '\n');
    lista->inicializarActual();
    stringstream cant1(ca);
    cant1 >> cantidad;
    while (in.good() && cantidad > contador) {
        contador++;
        getline(in, codigo, '\t');
        getline(in, nombre, '\t');
        getline(in, estado, '\t');
        getline(in, escuela, '\t');
        getline(in, fac, '\t');
        getline(in, estudi, '\n');
        int x= stoi(estado);
        bool estado = x;
        fa = uni->buscarFacultad(fac);
        escue = fa->getListaEsc();
        escu = escue->buscarstring(escuela);
       
        car = new Carrera(codigo, nombre, x, escu, fa);
       
        if (estudi == "vacio") {
            lista->agregarObj(car);
            escu->agregarCarreras(car);
        }
        else {
            if(estudi=="estudiantes"){
                listaa = recuperarListaEs(car);
                car->setListaest(listaa);
                escu->agregarCarreras(car);
                lista->agregarObj(car);
            }
        }
        lista->SiguienteElemento();
    }

    in.close();
    return lista;
}

bool GestorDeArchivos::guardarMallas(Lista<mallaCurricular>* x)
{

    int n2 = 0;
    int elem;
    int elem2 = 0;
    CicloLectivo* cicloLectivo;
    mallaCurricular* us = nullptr;
    Carrera* car = nullptr;
    Lista<Curso>* cur = nullptr;
    Lista<Curso>* cursi = nullptr;
    Curso* curs = nullptr;
    Curso* me = nullptr;
    Arreglo<Grupo>* atr = nullptr;
    remove("malla.txt");
    remove("requisitos.txt");
    int n = 0;
    if (x->listaVacia()) {
        return false;
    }
    else {
        elem = x->getCant();
        ofstream out;
        out.open(mallas, ios::out);
        out << elem << '\n';
        x->inicializarActual();
        while (n < x->getCant()) {
            n++;
            us = x->getTipo();
            car = us->getCarrera();
            out << car->getCodigo() << '\n';
            cur = us->getLista();
            
            if (cur->listaVacia()) {
                out << "vacio" << '\n';
            }
            else {
                out<<"tiene"<< '\n';
                cur->inicializarActual();
                out << cur->getCant() << '\n';
                while (n2 < cur->getCant()) {
                    n2++;
                    curs = cur->getTipo();
                    cicloLectivo = curs->getCicloL();
                    out << curs->getCodigo() << '\t';
                    out << curs->getNombreO() << '\t';
                    out << curs->getCreditos() << '\t';
                    out << curs->getHorasSemanales() << '\t';
                    out << curs->getEstado() << '\t';
                    out << curs->getArreglo()->getTamanio() << '\t';
                    out << curs->getTipoCurso() << '\t';
                    out << cicloLectivo->getAnio() << '\t';
                    out << cicloLectivo->getCiclo() << '\n';
                    cursi = curs->getlistaRequisitos();
                    atr = curs->getArreglo();
                    if (atr->getCantidad() > 0) {
                        guardarGrupos(atr);
                    }
                    if (cursi->getCant()>0) {
                        guardarRequisitos(cursi, curs,car);
                    }
                    cur->siguienteNodo();
                }
                n2 = 0;
            }
            x->siguienteNodo();
        }
        
        out.close();
        return true;
    }
    return false;
}

CicloLectivo* GestorDeArchivos::mismoAnio(int ci,int an,Lista<CicloLectivo>* list)
{
    int cont = 0;
    list->inicializarActual();
    CicloLectivo* aux = NULL;
    while (cont < list->getCant()) {
        cont++;
        aux = list->getTipo();
        if (aux->getAnio() == an && aux->getCiclo() == ci) {
            return aux;
        }
        list->siguienteNodo();
    }
    return NULL;
}
bool GestorDeArchivos::verificaHorario(string m , Horario* hor, Grupo* grupoo)
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num = 0;
    int cont = 0;
    string aux = "";
    for (int i = 0; i < m.size(); i++) {
        while (m[i] != ',' && m[i] != '\0') {
            if (m[i] != '-') {
                aux += m[i];
            }
            if (cont == 2) {
                num = stoi(aux);//1-3-2,1-4-2
                num3 = num;
                aux = "";
                cont = 0;

            }
            if (m[i] == '-' && cont == 1) {
                num = stoi(aux);
                num2 = num;
                aux = "";
                cont++;

            }
            if (m[i] == '-' && cont == 0) {
                num = stoi(aux);
                num1 = num;
                aux = "";
                cont++;

            }
            i++;
        }
        if (!hor->rellenarMatriz(num1, num2, num3, grupoo)) {
            return false;
        }
    }
    return true;
}
void GestorDeArchivos::abrirFlujoModoEscritura()
{
    archivo2.open(req.c_str(), ios::out);
    estudiante.open(est.c_str(), ios::out);
    archivo.open(malla.c_str(), ios::out | ios::trunc);
    historialA.open(histA.c_str(), ios::out);
    
}
void GestorDeArchivos::abrirFlujoModoLectura()
{
  
    archivo2.open(req.c_str(), ios::in);
    estudiante.open(est.c_str(), ios::in);
    archivo.open(malla.c_str(), ios::in);
    historialA.open(histA.c_str(), ios::in);
}


void GestorDeArchivos::cerrarFlujo()
{
    archivo.close();
    archivo2.close();
    estudiante.close();
    historialA.close();
}



Lista<mallaCurricular>* GestorDeArchivos::recuperarMallas()
{
    int n2 = 0;
    int elem=0;
    int cre = 0;
    int tam1 = 0;
    bool estado;
    int annio = 0;
    int per = 0;
    int hor = 0;
    int con = 0;
    int aux = 0;
    int aux2 = 0;
    int aux4 = 0;
    int fdg = 0;
    CicloLectivo* cicloLectivo;
    mallaCurricular* us = nullptr;
    Carrera* car = nullptr;
    ifstream in;
    Curso* cursito = nullptr;
    Lista<mallaCurricular>* lista = new Lista<mallaCurricular>;
    string nombre, req, ca, cod,cod21,h,cred,esta,tam,an,ciclo,k,tipoCur,Carr;
    int cantidad = 0; 
    int contador = 0;
    in.open(mallas);
    getline(in, ca, '\n');
    lista->inicializarActual();
    stringstream cant(ca);
    cant >> cantidad;
    while (!in.eof()) {
        
        if (con == 0) { 
            getline(in, cod, '\n');
            if (cod == "") {
                break;
            }
            getline(in, req, '\n');
            us = new mallaCurricular(NULL);
            aux4 = 0;
        }
       
        if (req == "vacio") {
            car = uni->buscarCarrera(cod);
            us = new mallaCurricular(car);
            car->setMalla(us);
            lista->agregarObj(us);
        }
        else {
            if (aux4 == 0) {
                getline(in, k, '\n');
            }
            getline(in, cod21, '\t');
            getline(in, nombre, '\t');
            getline(in, cred, '\t');
            getline(in, h, '\t');
            getline(in, esta, '\t');
            getline(in, tam, '\t');
            getline(in, tipoCur, '\t');
            getline(in, an, '\t');
            getline(in, ciclo, '\n');
            tam1 = stoi(tam);
            annio = stoi(an);
            per = stoi(ciclo);
            cre = stoi(cred);
            hor = stoi(h);
            estado = stoi(esta);
            aux2 = stoi(k);
            cicloLectivo = mismoAnio(per, annio, uni->getListaCL());
            car = uni->buscarCarrera(cod);
            car->setMalla(us);
            cursito = new Curso(cod21, nombre, cre, hor, estado, tam1, cicloLectivo);
            cursito->setCarrera(car);
            cursito->setTipoCurso(tipoCur);
            lista->agregarObj(us);
            recuperarGrupo(cursito);
            us->agregarCurso(cursito);
            lista->SiguienteElemento();
            con++; 
            if (aux2 == con) {
                con = 0;
            }
            aux4 = 1;
        }
       
    }
    in.close();
    
    return lista;
}

bool GestorDeArchivos::guardarGrupos(Arreglo<Grupo>* ar)
{
    int n2 = 1;
    Grupo* a = nullptr;
    Arreglo<Estudiante>* est = nullptr;
    Profesor* profe = nullptr;
    Estudiante* estu = nullptr;
    Curso* cur = nullptr;
    int n = ar->getCantidad();
    archivo << n << '\n';
    int i = 1;
    while (i <= n) {
        n2 = 1;
        a = ar->recuperarObjeto(i);//0
        profe = a->getProfesor();
        cur = a->getCurso();
        est = a->getArreglo();
        archivo << a->getNCR() << '\t';
        archivo << a->getNumeroGrupo() << '\t';
        archivo << cur->getCodigo() << '\t';
        archivo << a->getHorario() << '\t';
        if (profe == NULL) {
            archivo << "Nulo" << '\t';
        }
        else {
            archivo << profe->getCedula() << '\t';//agregar una condicion para validar que exista el profesor asignado
        }
        archivo << a->getCapacidad() << '\n';
        if (est->getCantidad() == 0) {
            archivo << "vacio" << '\n';
        }
        else {
            archivo << "tiene" << '\n';
            archivo << est->getCantidad() << '\n';
            while (n2 <= est->getCantidad()) {
                 estu = est->recuperarObjeto(n2);
                 archivo << estu->getCedula() << '\n';
                 n2++;
            }
        }
        i++;
    }
  
    return true;
}

void GestorDeArchivos::recuperarGrupo(Curso* cur)
{
    //PRUEBA ALFA 1
    string cant = "";
    Profesor* pro = nullptr;
    ifstream in;
    in.open("Carreras/grupos.txt");
    string nrc, grupoo, curso, horario, capacidadd, profesor, variable, estudi, var;
    int capacidad, grupo, varcita;
    Arreglo<Grupo>* arr = cur->getArreglo();
    int cantidad = 0;
    Horario* hor = nullptr;
    Horario* horp = nullptr;
    while (!in.eof()) {
        getline(in, cant, '\n');
        if (cant == "") {
            break;
        }
        cantidad = stoi(cant);
        for (int i = 0; i < cantidad; i++) {
            pro = nullptr;
            horp = nullptr;
            getline(in, nrc, '\t');
            getline(in, grupoo, '\t');
            getline(in, curso, '\t');
            getline(in, horario, '\t');
            getline(in, profesor, '\t');
            getline(in, capacidadd, '\n');
            getline(in, variable, '\n');
            capacidad = stoi(capacidadd);
            grupo = stoi(grupoo);

            if (profesor != "Nulo") {
                pro = uni->buscarProfesor(profesor);
            
            }
            Grupo* grupito = new Grupo(nrc, grupo, pro, capacidad);
            grupito->setHorario(horario);
            if (pro != nullptr) {
                horp = pro->getHorario();
            }
            if (curso == cur->getCodigo()) {
                cur->agregarGrupo(grupito);
                if (pro != nullptr) {
                    pro->agregarGrupo(grupito);
                    verificaHorario(horario, horp, grupito);
                }
                Arreglo<Estudiante>* ae = grupito->getArreglo();
                Estudiante* est = nullptr;
                if (variable != "vacio") {
                    getline(in, var, '\n');
                    varcita = stoi(var);
                    for (int k = 0; k < varcita; k++) {
                        est = nullptr;
                        getline(in, estudi, '\n');
                        est = uni->buscarEstudiante(estudi);
                        if (est != NULL) {
                            ae->agregarObj(est);
                            hor = est->getHorario();
                            verificaHorario(horario, hor, grupito);
                        }
                    }
                }
            }
        }
    }
    in.close();
}

bool GestorDeArchivos::guardarCursosMatriculados()
{
    Lista<Estudiante>* le = uni->getListaEst();
    //Cursos matriculados por estudiante
    ofstream out;
    Curso* curso = nullptr;
    out.open("Carreras/EstEmp.txt");
    le->inicializarActual();
    int cont = 0;
    int cont1 = 0;
   
    Estudiante* est = nullptr;
    while (cont < le->getCant()) {
        cont++;
        est = le->getTipo();
        out << est->getCedula() << '\n';
        Lista<Curso>* lc = est->getListaCurso();
        lc->inicializarActual();
        if (lc->getCant() == 0) {
            out << "vacio" << '\n';
        }
        else {
            out << "tiene" << '\n';
            out << lc->getCant() << '\n';
            while (cont1 < lc->getCant()) {
                cont1++;
                curso = lc->getTipo();
                Carrera* carrerita = curso->getCarrera();
                out << carrerita->getCodigo() << '\t';//Sistemas    Ing.Topografica
                out << curso->getCodigo() << '\t';//Fundamentos   Cursito
                lc->siguienteNodo();
            }
            cont1 = 0;
        }
        le->siguienteNodo();
    }
    out.close();
    return true;
}

void GestorDeArchivos::cursosMatriculadosRecuperados()
{
    ifstream in;
    in.open("Carreras/EstEmp.txt");
    string can, codE, codC, codCar, variable;
    int cant = 0;
    Estudiante* est = nullptr;
    Carrera* carr = nullptr;
    Curso* cur = nullptr;
    mallaCurricular* mallita = nullptr;
    Lista<Curso>* lc = nullptr;
    int contador = 0;
    int contador1 = 0;
    while (!in.eof()) {
        getline(in, codE, '\n');
        if (codE == "") {
            break;
        }
        est = uni->buscarEstudiante(codE);
        getline(in, variable, '\n');
        if (variable != "vacio") {
            getline(in, can, '\n');
            cant = stoi(can);
            while (contador < cant) {
                contador++;
                getline(in, codCar, '\t');
                getline(in, codC, '\t');
                carr = uni->buscarCarrera(codCar);
                mallita = carr->getMalla();
                lc = mallita->getLista();
                lc->inicializarActual();
                while (contador1 < lc->getCant()) {
                    contador1++;
                    cur = lc->getTipo();
                    if (cur->getCodigo() == codC) {
                        Curso* nuevo = new Curso(cur->getCodigo(), cur->getNombreO(), cur->getCreditos(), cur->getHorasSemanales(), cur->getEstado(), 0, cur->getCicloL());
                        nuevo->setCarrera(cur->getCarrera());
                        est->agregarCursoMatriculado(nuevo);
                    }
                    lc->siguienteNodo();
                }
                contador1 = 0;
            }
            contador = 0;
        }
    }
    in.close();
}


bool GestorDeArchivos::guardarRequisitos(Lista<Curso>* y, Curso* x,Carrera* car)
{
    int cont = 0;
    Curso* me = nullptr;
    y->inicializarActual();
     archivo2 << y->getCant() << '\n';
     archivo2 << car->getCodigo() << '\t';
     archivo2 << x->getCodigo() << '\n';
        while (cont < y->getCant()) {
            cont++;
            me = y->getTipo();
            archivo2 << me->getCodigo() << '\n';
            y->siguienteNodo();
        }
        return true;
}
void GestorDeArchivos::asignarRequisito()
{
    Carrera* carr = nullptr;
    ifstream in;
    mallaCurricular* mall = nullptr;
    Lista<Curso>* cursi = nullptr;
    Curso* cusrt = NULL;
    string cant,car,curso,req;
    Curso* curr = nullptr;
    int num = 0;
    int con = 0;
    int con2 = 0;
    int cont3 = 0;
    in.open("Carreras/requisitos.txt");
    while (!in.eof()) {
        getline(in, cant, '\n');
        if (cant == "") {
            break;
        }
        num = stoi(cant);
        getline(in, car, '\t');
        getline(in, curso, '\n');
        carr = uni->buscarCarrera(car);
        mall = carr->getMalla();
        cursi = mall->getLista();
        cursi->inicializarActual();
        while (cursi->getCant() > con2) {
            con2++;
            cusrt = cursi->getTipo();
            if (cusrt->getCodigo() == curso) {
                con2 = cursi->getCant();
            }
            cursi->siguienteNodo();
        }
        con2 = 0;
        while (num > con) {
            con++;
            getline(in, req, '\n');
            cursi->inicializarActual();
            while (cursi->getCant() > cont3) {
                cont3++;
                curr = cursi->getTipo();
                if (curr->getCodigo() == req) {
                    cont3 = cursi->getCant();
                    cusrt->agregarCurso(curr);
                }
                cursi->siguienteNodo();
            }
            cont3 = 0;

        }
        con = 0;

    }
    in.close();
   

}

Lista<Profesor>* GestorDeArchivos::recuperarProfesores()
{
    Profesor* est = nullptr;
    ifstream in;
    Lista<Profesor>* lista = new Lista<Profesor>;
    Escuela* esc = nullptr;
    Carrera* car = nullptr;
    int n = 0;
    string nombre, tele, cedula, ca, cod,gra;
    int cantidad = 0;
    int contador = 0;
    in.open(profesores);
    getline(in, ca, '\n');
    lista->inicializarActual();
    stringstream cant(ca);
    cant >> cantidad;
    while (in.good() && cantidad > contador) {
        contador++;
        getline(in, cedula, '\t');
        getline(in, nombre, '\t');
        getline(in, tele, '\t');
        getline(in, gra, '\t');
        getline(in, cod, '\n');
        n = stoi(gra);
        car = uni->buscarCarrera(cod);
        if (car != nullptr) {
            esc = car->getEscuela();
            est = new Profesor(cedula, nombre, tele, esc, car, n);
            esc->agregarProfesor(est);
            lista->agregarObj(est);
        }
        lista->SiguienteElemento();
    }

    in.close();
    return lista;
}

bool GestorDeArchivos::guardardatos()
{
    abrirFlujoModoEscritura();
    guardarCiclos(uni->getListaCL());
    guardarCarreras(uni->getListaCarr());
    guardarProfesores(uni->getListaPro());
    guardarListaUsuarios(uni->getListaUsuar());
    cerrarFlujo();
    


    return true;
 
}

void GestorDeArchivos::cargarDatos()
{
    
    uni->setListaCiclo(recuperarListaCiclo());
    uni->setCarreras(recuperarCarreras());
    uni->setProfesores(recuperarProfesores());
    uni->setListaUsuarios(recuperarListaUsuario());
    uni->setMallas(recuperarMallas());
    cursosMatriculadosRecuperados();
    recuperarHistorialA();
    asignarRequisito();
}

bool GestorDeArchivos::guardarProfesores(Lista<Profesor>* x)
{
    int elem;
    Profesor* us = nullptr;
    int n = 0;
    Carrera* car = nullptr;
    if (x->listaVacia()) {
        return false;
    }
    else {
        elem = x->getCant();
        ofstream out;
        out.open(profesores, ios::out);
        out << elem << '\n';
        x->inicializarActual();
        while (n < x->getCant()) {
            n++;
            us = x->getTipo();
            car = us->getCarrera();
            out << us->getCedula() << '\t';
            out << us->getNombre() << '\t';
            out << us->getTelefono() << '\t';
            out << us->getGradoAca() << '\t';
            out << car->getCodigo() << '\n';
            x->siguienteNodo();
        }
        out.close();
        return true;
    }
    return false;
}

