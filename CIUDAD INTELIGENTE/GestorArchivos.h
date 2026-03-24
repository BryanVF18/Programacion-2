#pragma once
#ifndef GESTORARCHIVOS_H	
#define GESTORARCHIVOS_H
#include "Distrito.h"
#include <string>
#include <map>

#include <functional>

using namespace std;

class GestorArchivos
{
public:
	static void guardarEstadoBinario(const Distrito& dist, string ruta);
	static void cargarEstadoBinario(Distrito& dist, string ruta);


};

#endif