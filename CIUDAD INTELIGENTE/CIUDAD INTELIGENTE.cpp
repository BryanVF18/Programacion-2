#include <iostream>
#include <memory>
#include "GestorCiudad.h"
#include "PlantaSolar.h"
#include "EdificioResidencial.h"
#include "ComplejoIndustrial.h"
#include "EstrategiaAhorro.h"
#include "SensorConsumoInteligente.h"
#include "BlindajeTermico.h"
#include "ReduccionEmisiones.h"
#include "ExcepcionesCiudad.h"

using namespace std;

int main() {

    cout << "=== SISTEMA CIUDAD INTELIGENTE - PRUEBA DE EXCEPCIONES ===\n";

    // -----------------------------------------------------------------------
    // PRUEBA 1: ErrorConfiguracionInvalida
    // -----------------------------------------------------------------------
    cout << "\n********************************************\n";
    cout << "  PRUEBA 1: ErrorConfiguracionInvalida\n";
    cout << "********************************************\n\n";

    auto centralPrueba = make_shared<CentralEmergencias>("Central-Prueba");
    GestorCiudad motorPrueba(centralPrueba);
    auto distPrueba = make_shared<Distrito>("Zona de Prueba");
    motorPrueba.agregarDistrito(distPrueba);

    try {
        cout << "[P1] Intentando agregar edificio con nombre vacio...\n";
        auto edificioInvalido = make_shared<EdificioResidencial>("", 100, 50);
        distPrueba->agregarEdificio(edificioInvalido);
        cout << "   (no deberia llegar aqui)\n";
    }
    catch (const ExcepcionUrbana& ex) {
        cout << "\n  [!] " << ex.tipoError() << "\n";
        cout << "  Mensaje: " << ex.what() << "\n";
        cout << "  >> Edificio rechazado. Memoria liberada.\n";
    }

    try {
        cout << "\n[P2] Intentando agregar edificio nulo (nullptr)...\n";
        distPrueba->agregarEdificio(nullptr);
    }
    catch (const ExcepcionUrbana& ex) {
        cout << "\n  [!] " << ex.tipoError() << "\n";
        cout << "  Mensaje: " << ex.what() << "\n";
        cout << "  >> Puntero nulo rechazado. Sin fuga de memoria.\n";
    }

    cout << "\n--------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------" << endl << endl;


    // -----------------------------------------------------------------------
    // PRUEBA 2: ErrorRecursosInsuficientes 
    // -----------------------------------------------------------------------

    cout << "\n********************************************\n";
    cout << "  PRUEBA 2: ErrorRecursosInsuficientes\n";
    cout << "********************************************\n\n";

    auto central2 = make_shared<CentralEmergencias>("Central-Alpha");
    GestorCiudad motor2(central2);
    auto dist2 = make_shared<Distrito>("Zona Critica");
    // Se genera un deficit del 700% para fozar la excepcion
    dist2->agregarEdificio(make_shared<PlantaSolar>("Solar-Mini", 100));
    dist2->agregarEdificio(make_shared<EdificioResidencial>("Mega Complejo", 700, 200));
    motor2.agregarDistrito(dist2);

    cout << "Configuracion: Produccion=100 kW, Consumo=800 kW (deficit > 50%)\n";

    try {
        motor2.procesarTurno();
    }
    catch (const ExcepcionUrbana& ex) {
        cout << "\n[MAIN] Excepcion capturada en main\n";
        cout << "  Tipo   : " << ex.tipoError() << "\n";
        cout << "  Detalle: " << ex.what() << "\n";
        if (auto* err = dynamic_cast<const ErrorRecursosInsuficientes*>(&ex)) {
            cout << "  Deficit exacto: " << err->getDeficit() << " kW.\n";
        }
        cout << "  >> Sistema registra el incidente y continua operacion.\n";
    }


    cout << "\n--------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------" << endl << endl;

    // -----------------------------------------------------------------------
    // PRUEBA 3: DesastreExterno (Para la prueba los forzamos) 
    // -----------------------------------------------------------------------
    cout << "\n********************************************\n";
    cout << "  PRUEBA 3: DesastreExterno\n";
    cout << "********************************************\n";

    cout << "\n [NOTA] ESTE ERROR SE FUERZA A PROPOSITO UNICAMENTE PARA LA VERIFICACION" << endl << endl;

    try {
        throw DesastreExterno(42);
    }
    catch (const ExcepcionUrbana& ex) {
        cout << "[!] " << ex.tipoError() << "\n";
        cout << "  Mensaje: " << ex.what() << "\n";
        if (auto* des = dynamic_cast<const DesastreExterno*>(&ex)) {
            cout << "  Codigo de fallo: " << des->getCodigo() << "\n";
        }
        cout << "  >> Sistema activa protocolo de emergencia.\n";
    }


    cout << "\n--------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------" << endl << endl;

    // -----------------------------------------------------------------------
    // PRUEBA 4: Turno normal sin errores
    // -----------------------------------------------------------------------
    cout << "\n********************************************\n";
    cout << "  PRUEBA 4: Turno Normal (Sin Excepciones)\n";
    cout << "********************************************\n";

    auto central4 = make_shared<CentralEmergencias>("Central-Beta");
    GestorCiudad motor4(central4);
    auto dist4 = make_shared<Distrito>("Zona Verde");
    // Produccion generosa, consumo moderado -> balance positivo
    dist4->agregarEdificio(make_shared<PlantaSolar>("Solar-Max", 500));
    dist4->agregarEdificio(make_shared<EdificioResidencial>("Residencial Norte", 100, 50));
    motor4.agregarDistrito(dist4);

    cout << "Configuracion: Produccion=500 kW, Consumo~125 kW (balance positivo)\n";

    try {
        motor4.procesarTurno();
        cout << "[OK] Turno completado sin excepciones.\n";
    }
    catch (const ExcepcionUrbana& ex) {
        cout << "[NOTA] Ocurrio un " << ex.tipoError() << " aleatorio: " << ex.what() << "\n";
    }

    cout << "\n=== Final de la prueba ===\n";
    return 0;
}