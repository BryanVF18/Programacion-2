#include "Distrito.h"
#include "IProductor.h"
#include "IConsumidor.h"
#include <iostream>
using namespace std;

Distrito::Distrito(string n) : nombre(n) {

}

void Distrito::agregarEdificio(shared_ptr<IEntidad>edificio) {
	edificios.push_back(edificio);
}

double Distrito::obtenerProduccionTotal()const {
	double total = 0;
	for (auto& e : edificios) {
		auto p = dynamic_cast<IProductor*>(e.get());
		if (p)total += p->producirEnergia();

	}
	return total;
}

double Distrito::obtenerComsumoTOtal()const {
	double total = 0;
	for (auto& e : edificios) {
		auto c = dynamic_cast<IConsumidor*>(e.get());
		if (c)total += c->consumirEnergia();

	}
	return total;
}

string Distrito::getNombre()const {
	return nombre;
}

void Distrito::mostrarReporteDistrito()const {
	cout << "Distrito: " << nombre << " (" << edificios.size() << " edificios)\n";
	for (auto& e : edificios) {
		cout << " - " << e->getNombre() << "[ " << e->getDetalleEstado() << "]\n";
	}
}