#include "Distrito.h"
#include "IProductor.h"
#include "IConsumidor.h"
#include "CentralEmergencias.h" // Aquí SÍ incluimos el .h porque necesitamos usar sus métodos
#include "ExcepcionesCiudad.h"
#include <iostream>

Distrito::Distrito(std::string n) : nombre(n), centralAsignada(nullptr) {}

void Distrito::setCentral(std::shared_ptr<CentralEmergencias> c) {
    this->centralAsignada = c;
}


// Si el nombre esta vacio o el puntero es nulo, lanzamos ErrorConfiguracionInvalida.
// RAII: Al usar shared_ptr, si la excepcion ocurre aqui, no hay fuga de memoria;

void Distrito::agregarEdificio(std::shared_ptr<IEntidad> edificio) {
    if (!edificio) {
        throw ErrorConfiguracionInvalida(
            "No se puede agregar un edificio nulo al distrito '" + nombre + "'.",
            "puntero");
    }
    if (edificio->getNombre().empty()) {
        throw ErrorConfiguracionInvalida(
            "El nombre del edificio no puede estar vacio en el distrito '" + nombre + "'.",
            "nombre");
    }
    edificios.push_back(edificio);
}

void Distrito::alertarEmergencia(std::string causa) const {

    if (centralAsignada) {
        // DEPENDENCIA MUTUA EN ACCIÓN: El distrito llama a un método de Central
        centralAsignada->recibirAlerta("Emergencia en " + nombre + ": " + causa);
    }
}

double Distrito::obtenerProduccionTotal() const {
    double total = 0;
    for (auto& e : edificios) {
        auto p = dynamic_cast<IProductor*>(e.get());
        if (p) total += p->producirEnergia();
    }
    return total;
}

double Distrito::obtenerConsumoTotal() const {
    double total = 0;
    for (auto& e : edificios) {
        auto c = dynamic_cast<IConsumidor*>(e.get());
        if (c) total += c->consumirEnergia();
    }
    return total;
}

std::string Distrito::getNombre() const { return nombre; }

void Distrito::mostrarReporteDistrito() const {
    std::cout << "  Distrito: " << nombre << " (" << edificios.size() << " edificios)\n";
    for (auto& e : edificios) {
        std::cout << "    - " << e->getNombre() << " [" << e->getDetalleEstado() << "]\n";
    }
}


// Este metodo es el ORIGEN de ErrorRecursosInsuficientes.
// No la captura aqui; deja que suba hasta GestorCiudad::procesarTurno().

void Distrito::verificarBalance() const {
    double prod = obtenerProduccionTotal();
    double cons = obtenerConsumoTotal();

    if (prod == 0 && cons == 0) return; // Sin datos, no se puede evaludar

    // Condicion critica: consumo supera la produccion por mas del 50%

    if (cons > prod * 1.5) {
        // Alertamos a la central antes de propagar la excepcion
        alertarEmergencia("Deficit energetico critico (>" +
            std::to_string((int)((cons / prod - 1) * 100)) + "%)");
        // LANZAMOS la excepcion: sube por la pila hasta el Motor
        throw ErrorRecursosInsuficientes(nombre, prod, cons);
    }
}

void Distrito::guardarReporteTexto(string nombreArchivo)const {
    //1. Creamos el archivo
    ofstream archivo(nombreArchivo); //Esto por defecto esta en modo texto
    //2. Verificamos que el archivo se haya creado
    if (!archivo) throw runtime_error("No se pudo crear el reporte");
    
    //Si el archivo se creo, comenzamos la escrituras de los datos
    archivo << "-----Reporte de Distrito -----" << endl;
    archivo << nombre << endl;
    for (auto& e : edificios)
    {
        e->serializarTexto(archivo);
    }

    //4. Tenemos que cerrar el archivo, de lo contrario queda 
    // abierto para siempre provocando el colapso de memoria inminente
    archivo.close();

}


void Distrito::guardarEstadoBinario(string nombreArchivo)const {

    //1. Vamos a escribir en modo binario
    ofstream archivo(nombreArchivo, ios::binary);

    //2. Verificamos que el archivo exista
    if (!archivo)throw runtime_error("Error al escribir el archivo binario?\n");
    
    //3. Guardamos los datos en el archivo
    //Iniciamos por la cantidad de edificios
    size_t cantidad = edificios.size();
    archivo.write(reinterpret_cast<const char*>(&cantidad), sizeof(cantidad));

    for (auto& e : edificios)
    {
        e->serializarBinario(archivo);
    }

    //4. Cerramos el archivo

    archivo.close();
}

void Distrito::cargarDesdeTexto(string nombreArchivo) {

    //1. Abrir el archivo y definir un espacio para almacenar las lineas
    ifstream archivo(nombreArchivo);
    string linea;

    //2. Tenemos que verificar que existe el archivo
    if (!archivo.is_open())throw runtime_error("No se pudo abrir el reporte\n");

    //Limpiamos los edificios actuales para cargar los nuevos

    this->edificios.clear();
    while (getline(archivo, linea)) 
    {
        //Ignoramos lineas de encabezado que no inicien con 
        if (linea.find("RESIDENCIAL") == string::npos && linea.find("INDUSTRIAL") == string::npos)continue;

        stringstream ss(linea);
        string tipo, nombreEdificio, habString, consumoString;

        //Separamos por comas, TIPO, NOMBRE, HABITANTES Y CONSUMO

        getline(ss, tipo, ", ");
        getline(ss, nombreEdificio, ", ");
        getline(ss, consumoString, ", ");
        getline(ss, habString, ", ");

        //Por el momento solo tenemos edificios redidenciales
        //Entonces solo leemos edificios residenciales

        if (tipo == "1") {
            auto respuesta = make_shared<EdificioResidencial>(nombreEdificio,
                stod(consumoString), stoi(habString));

                this->agregarEdificio(respuesta);
        }
    }
    archivo.close();
}
