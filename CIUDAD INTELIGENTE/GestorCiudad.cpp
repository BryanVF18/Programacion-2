#include "GestorCiudad.h"
#include "CiudadException.h"
#include "DeficitRecursosException.h"
#include <iostream>

GestorCiudad::GestorCiudad(std::shared_ptr<CentralEmergencias> central)
    : centralUrbana(central), turnoActual(0) {
}

void GestorCiudad::agregarDistrito(std::shared_ptr<Distrito> d) {
    distritos.push_back(d);
    // PRINCIPIO DE INVERSIÓN DE CONTROL: El motor vincula al distrito con la central
    d->setCentral(centralUrbana);
}

void GestorCiudad::procesarTurno() {
    turnoActual++;
    double ciudadProd = 0;
    double ciudadCons = 0;

    std::cout << "\n========== TURNO SIMULADO: " << turnoActual << " ==========\n";

    std::cout << "--------------------------------------------\n";
    std::cout << "REPORTE CIUDAD GLOBAL:\n";
    std::cout << "Energia Generada: " << ciudadProd << " kW\n";
    std::cout << "Energia Demandada: " << ciudadCons << " kW\n";
    std::cout << "Balance: " << (ciudadProd - ciudadCons) << " kW\n";
    std::cout << "============================================\n";

    for (auto& dist : distritos) {
        dist->mostrarReporteDistrito();
        ciudadProd += dist->obtenerProduccionTotal();
        ciudadCons += dist->obtenerConsumoTotal();

        // Lógica de alerta: Si hay déficit, el distrito reporta a la central
        if (ciudadCons > ciudadProd) {
            dist->alertarEmergencia("Deficit energetico critico");
            // DOWNCAST / UPCAST: La central inspecciona el distrito
            // Aquí se pasa el shared_ptr de Distrito (se trata como tal)
            centralUrbana->realizarInspeccion(dist);
            throw new DeficitRecursoException(dist->getNombre(), ciudadCons - ciudadProd);
        }
    }

}