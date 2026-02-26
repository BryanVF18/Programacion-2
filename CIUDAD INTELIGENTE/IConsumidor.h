#pragma once
#include <string>
using namespace std;

class IConsumidor
{
public:
	virtual ~IConsumidor() = default;
	virtual double consumirEnergia() = 0;
};