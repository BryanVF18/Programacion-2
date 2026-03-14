#pragma once
#include <vector>
#include <memory>
#include <string>
#include "IEntidad.h"
#include "IEstrategiaEnergia.h"

using namespace std;

// FORWARD DECLARATION (Declaracion Adelantada):
// Resolvemos la DEPENDENCIA MUTUA. No incluimos el .h aqui para evitar
// recursividad infinita, solo avisamos que la clase existe.
class CentralEmergencias;

class Distrito {
private:
    string nombre;
    vector< shared_ptr<IEntidad>> edificios;

    // El distrito tiene una referencia a la central (Agregacion)
    shared_ptr<CentralEmergencias> centralAsignada;
    shared_ptr<IEstrategiaEnergia> delegadoEnergia;

public:
    Distrito(string n);

    // Inyectamos la dependencia de la central
    void setCentral(shared_ptr<CentralEmergencias> c);

    // Ahora valida que el edificio sea valido antes de agregarlo.
    // Lanza ErrorConfiguracionInvalida si el nombre es vacio o el ptr es nulo.
    void agregarEdificio(shared_ptr<IEntidad> edificio);

    double obtenerProduccionTotal() const;
    double obtenerConsumoTotal() const;
    string getNombre() const;
    void mostrarReporteDistrito() const;


    // Si el consumo es mayor que la produccion por un margen del 50%, se lanza una excepcion
    // ErrorRecursosInsuficientes, que sube hasta ser capturada en el Motor.
    void verificarBalance() const;

    // Metodo que gatilla la comunicacion hacia la Central
    void alertarEmergencia(string causa) const;

    void setDelegado(shared_ptr<IEstrategiaEnergia> del) {
        delegadoEnergia = del;
    }

    void gestionarCrisis() {
        if (delegadoEnergia) {
            delegadoEnergia->ejecutarAccion(this);
        }
    }
};

