#pragma once
#include <string>
using namespace std;

class IProductor
{
public:
	virtual ~IProductor() = default;
	virtual double producirEnergia() = 0;

};