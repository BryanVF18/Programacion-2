#include "GestorCiudad.h"
#include <iomanip>
#include <iostream>


GestorCiudad::GestorCiudad():turnoActual(0) {

}

void GestorCiudad::agregarEntidad(shared_ptr<IEntidad> nuevaentidad) {
	entidades.push_back(nuevaentidad);
}

void GestorCiudad::procesarTurno() {
	turnoActual++;
	double prodTotal = 0, constTotal = 0;
	cout << "\nTurno " << turnoActual << ":\n";
	for (auto& e : entidades) {
		cout << left << setw(20) << e->getNombre() << " | " << e->getDetalleEstado() << endl;

		auto p = dynamic_cast<IProductor*>(e.get());
		if (p)prodTotal += p->producirEnergia();
		auto c = dynamic_cast<IConsumidor*>(e.get());
		if (c)constTotal += c->consumirEnergia();
	}
	mostrarBalance(prodTotal, constTotal);
}

void GestorCiudad::mostrarBalance(double prod, double cons)const {
	cout << "BALANCE: Produccion: " << prod << "kw | Consumo: " << cons << "kw | Estado: " << (prod >= cons ? "Estable" : "Critico") << endl;
}