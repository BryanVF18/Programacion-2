#include "CentralEmergencias.h"
#include "Distrito.h"
#include <iostream>
using namespace std;

CentralEmergencias::CentralEmergencias(string n) :nombre(n), reportesRecibidos(0) {

}

void CentralEmergencias::recibirAlerta(string mensaje) {

	reportesRecibidos++;
	cout << "[CENTRAL " << nombre << " ] ALERTA RECIBIDA: " << mensaje << endl;

}

void CentralEmergencias::realizarInspeccion(shared_ptr<Distrito>d) {
	
	cout << "[CENTRAL] Inspeccionando distrito " << d->getNombre() << endl;
}