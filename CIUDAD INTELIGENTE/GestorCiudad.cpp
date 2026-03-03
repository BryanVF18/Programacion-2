#include "GestorCiudad.h"
#include <iostream>
#include <iomanip>

GestorCiudad::GestorCiudad(shared_ptr<CentralEmergencias>central) : turnoActual(0), centralUrbana(central) {}

void GestorCiudad::agregarDistrito(std::shared_ptr<Distrito> nuevoDistrito) {
    distritos.push_back(nuevoDistrito);
    //Principio de inversion de control: El gestor vincula al distrito una central de emergencias
    nuevoDistrito->setCentral(centralUrbana);
}


void GestorCiudad::procesarTurno() {
    turnoActual++;
    double prodTotal = 0, consTotal = 0;

    std::cout << "\n>>> TURNO " << turnoActual << " <<<\n";
    for (auto& dist : distritos) {
      /*  std::cout << std::left << std::setw(20) << e->getNombre() << " | " << e->getDetalleEstado() << "\n";

        // Usamos dynamic_cast para identificar capacidades en tiempo de ejecución
        auto p = dynamic_cast<IProductor*>(e.get());
        if (p) prodTotal += p->producirEnergia();

        auto c = dynamic_cast<IConsumidor*>(e.get());
        if (c) consTotal += c->consumirEnergia();*/

        dist->mostrarReporteDistrito();
        prodTotal += dist->obtenerProduccionTotal();
        consTotal += dist->obtenerComsumoTOtal();

        if (consTotal > prodTotal) {
            dist->generarAlerta("Deficit energetico critico");
            //Downcast / upcast: La central inspecciona el distrito
            //Se pasa el shared_ptr de distrito ( y se mantiene anomino)
            centralUrbana->realizarInspeccion(dist);
        }
    }
    cout << "------------------------------------\n";
    cout << "REPORTE GLOBAL DE LA CIUDAD POR DISTRITO\n";
    cout << "Energia generada: " << prodTotal << "kw\n";
    cout << "Emergia consumida: " << consTotal << "kw\n";
    cout << "Balance: " << (prodTotal - consTotal) << "kw\n";
    cout << "------------------------------------\n";

    //Logica de alerta: si hay un deficit el distrito reporta a la central de emergencias

    
}

/*void GestorCiudad::mostrarBalance(double prod, double cons) const {
    std::cout << "BALANCE: Prod: " << prod << "kW | Cons: " << cons << "kW | Estado: "
        << (prod >= cons ? "ESTABLE" : "CRITICO") << "\n";
}*/