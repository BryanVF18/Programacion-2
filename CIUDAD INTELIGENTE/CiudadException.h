#pragma once
#include <stdexcept>
#include <string>
using namespace std;

class CiudadException: public runtime_error
//Principio de Parnas (encapsulamos los errores)	

{
public: 
	CiudadException(const string& mensaje): runtime_error(mensaje){}
};

