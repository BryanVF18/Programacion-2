#include "Distrito.h"
#include "IProductor.h"
#include "IConsumidor.h"
#include "CentralEmergencias.h" // Aquí SÍ incluimos el .h porque necesitamos usar sus métodos
#include <iostream>

Distrito::Distrito(std::string n) : nombre(n), centralAsignada(nullptr) {}

void Distrito::setCentral(std::shared_ptr<CentralEmergencias> c) {
    this->centralAsignada = c;
}

void Distrito::alertarEmergencia(std::string causa) {
    if (centralAsignada) {
        // DEPENDENCIA MUTUA EN ACCIÓN: El distrito llama a un método de Central
        centralAsignada->recibirAlerta("Emergencia en " + nombre + ": " + causa);
    }
}

void Distrito::agregarEdificio(std::shared_ptr<IEntidad> edificio) {
    edificios.push_back(edificio);
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
    std::cout << "Distrito: " << nombre << " (" << edificios.size() << " edificios)\n";
    for (auto& e : edificios) {
        std::cout << "  - " << e->getNombre() << " [" << e->getDetalleEstado() << "]\n";
    }
}