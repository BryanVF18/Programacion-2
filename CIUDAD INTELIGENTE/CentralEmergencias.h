#pragma once
#include <string>
#include <vector>
#include <memory>

using namespace std;

//Principio de parnas: Ocultamos la implementación interna del distrito
//Declaración adelantada: Avisamos que la clase distrito existe sin incluir lo que hace su .h
//Esto resuelve la dependencia mutua inicial

class Distrito;

class CentralEmergencias
{
private: 
	//YAGNI: No creamos una lista con el historial de llamadas de emergencias ni los detalles, solo de almacena el conteo hasta tener una situacion que resolver

	string nombre;
	int reportesRecibidos;

public:
	CentralEmergencias(string n);
	void recibirAlerta(string mensaje);

		//Metodo que solo se ejecuta en caso de que la emergencia se realice y se debe conocer el distrito para referenciarlo

	void realizarInspeccion(shared_ptr<Distrito>(d));
};

