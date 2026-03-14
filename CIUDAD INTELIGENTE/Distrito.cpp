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