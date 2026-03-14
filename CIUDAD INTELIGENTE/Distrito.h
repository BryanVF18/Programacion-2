#pragma once
#include <vector>
#include <memory>
#include <string>
#include "IEntidad.h"
#include "IEstrategiaEnergia.h"

// FORWARD DECLARATION (Declaración Adelantada):
// Resolvemos la DEPENDENCIA MUTUA. No incluimos el .h aquí para evitar 
// recursividad infinita, solo avisamos que la clase existe.
class CentralEmergencias;

class Distrito {
private:
    std::string nombre;
    std::vector<std::shared_ptr<IEntidad>> edificios;

    // El distrito tiene una referencia a la central (Agregación)
    std::shared_ptr<CentralEmergencias> centralAsignada;
    std::shared_ptr<IEstrategiaEnergia> delegadoEnergia;

public:
    Distrito(std::string n);

    // Inyectamos la dependencia de la central
    void setCentral(std::shared_ptr<CentralEmergencias> c);

    void agregarEdificio(std::shared_ptr<IEntidad> edificio);
    double obtenerProduccionTotal() const;
    double obtenerConsumoTotal() const;
    std::string getNombre() const;
    void mostrarReporteDistrito() const;

    // Método que gatilla la comunicación hacia la Central
    void alertarEmergencia(std::string causa);
    //Generamos los métodos para delegar el control de la energia
    void setDelegado(std::shared_ptr<IEstrategiaEnergia> del)
    {
        delegadoEnergia = del;
    }

    void gestionarCrisis()
    {
        if (delegadoEnergia)
        {
            delegadoEnergia->ejecutarAccion(this);
        }
    }
};

