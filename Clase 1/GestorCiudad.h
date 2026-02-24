#pragma once
#include <vector>
#include <memory>
#include "IEntidad.h"
#include "IProductor.h"
#include "IConsumidor.h"

using namespace std;
class GestorCiudad
{
	private:
		vector<shared_ptr<IEntidad>> entidades;
};

