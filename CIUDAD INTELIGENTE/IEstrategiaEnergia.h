#pragma once
#include <string>
using namespace std;

//Esta clase va a tener una clase delegada

//Forward declaration: Para evitar dependencias multiples

class Distrito;

//PATRON DELEGATE: Esta interfaz define el contrato para quien quiera
//ayudar al distrito a recuperar o gestionar su energia

class IEstrategiaEnergia 
{
public:
	virtual  ~IEstrategiaEnergia() = default;
	virtual void ejecutarAccion(Distrito* contexto) = 0;
	virtual string getTipoEstrategia()const = 0;

};
