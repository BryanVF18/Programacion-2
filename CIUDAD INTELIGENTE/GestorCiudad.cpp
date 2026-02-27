#include "GestorCiudad.h"
#include <iostream>
#include <iomanip>

GestorCiudad::GestorCiudad() : turnoActual(0) {}

void GestorCiudad::agregarEntidad(std::shared_ptr<IEntidad> nuevaEntidad) {
    entidades.push_back(nuevaEntidad);
}

void GestorCiudad::procesarTurno() {
    turnoActual++;
    double prodTotal = 0, consTotal = 0;

    std::cout << "\n>>> TURNO " << turnoActual << " <<<\n";
    for (auto& e : entidades) {
        std::cout << std::left << std::setw(20) << e->getNombre() << " | " << e->getDetalleEstado() << "\n";

        // Usamos dynamic_cast para identificar capacidades en tiempo de ejecución
        auto p = dynamic_cast<IProductor*>(e.get());
        if (p) prodTotal += p->producirEnergia();

        auto c = dynamic_cast<IConsumidor*>(e.get());
        if (c) consTotal += c->consumirEnergia();
    }
    mostrarBalance(prodTotal, consTotal);
}

void GestorCiudad::mostrarBalance(double prod, double cons) const {
    std::cout << "BALANCE: Prod: " << prod << "kW | Cons: " << cons << "kW | Estado: "
        << (prod >= cons ? "ESTABLE" : "CRITICO") << "\n";
}