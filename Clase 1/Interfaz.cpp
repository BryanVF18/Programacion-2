#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include<iomanip>
#include<algorithm>
using namespace std;

//===========================================
//1. DEFINICION DE INTERFACES (CONTRATOS)
//Aplica: Principios de segregacion de Interfaz (ISP)

//Interfaz base para represenatr cualquier objeto del mundo real

class IEntidad
{
public:
	virtual ~IEntidad() = default;
	virtual string getNombre() const = 0;
	virtual string getDetalleEstado() const = 0;

};

class IProductor
{
public:
	virtual ~IProductor() = default;
	virtual double producirEnergia() = 0;

};

class IConsumidor
{
	virtual ~IConsumidor() = default;
	virtual double consumirEnergia();
};

//===========================================
//2. CLASE BASE Y CLASES CONCRETAS
//Aplica: Principio de Parras (Ocultamiento) y Abierto/Cerrado (OCP)
//============================================

class EntidadBase : public IEntidad
{
protected:
	string nombre;
	bool activo; //Parnas: El estado iterno esta protegido

public:
	EntidadBase(string n) : nombre(n), activo(true) {}
	string getNombre() const override
	{
		return nombre;
	}

	virtual void alternarEstado()
	{
		activo = !activo;
	}

	bool estaActivo() const
	{
		return activo;
	}

};

//===========================================
//Implementacion concreta: PLANTA SOLAR
//Aplica: Principio de sustitucion de Liskov (LSP)
//Puede sustituir a IEntidad y a IProductor sin alterar la funcionalidad del programa
//===========================================

class PlantaSolar : public EntidadBase, public IProductor
{

private:
	double capacidadMaxima;
	double eficiencia; //0.0 a 1.0

public:
	PlantaSolar(string n, double cap) : EntidadBase(n), capacidadMaxima(cap), eficiencia(0.85)


	{
	}


	//Esta es la logica especifica de como genero energia (encapsulada)
	double producirEnergia() override
	{
		if (!activo) return 0.0; //No produce energia si esta inactiva
		return capacidadMaxima = eficiencia; //Ejemplo simple: produce energia segun su capacidad y eficiencia

	}

	string getDetalleEstado() const override
	{
		return "Tipo: [Productor] | Eficiencia:" + to_string(int(eficiencia * 100)) + "%";
	}

};
