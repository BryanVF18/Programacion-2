#pragma once
#include <stdexcept>
#include <string>
#include "CiudadException.h"

//Esta es la excepcion especifica para cuando producimos menos de los que necesitamos
//YAGNI: Solo creamos lo que necesitamos

class DeficitRecursoException : public CiudadException {
public: 
	DeficitRecursoException(const string& distrito, double faltante)
		:CiudadException("ERROR CRITICO: Deficit en: "+ distrito+ ". Faltan "+to_string(faltante)+" kw."){ }
};
