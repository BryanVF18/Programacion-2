#include "SimuladorEstrategiaAmbiental.h"
#include "FabricaSensorAmbiental.h"
#include "EvaluadorPrioridadAmbiental.h"
#include "EstrategiaPrioridadAmbiental.h"

using namespace std;

void simularEstrategiaAmbiental() {

	cout << "==== Estrategia Atencion Ambiental =====" << endl;

	FabricaSensorAire fabricaAire;
	FabricaSensorRuido fabricaRuido;
	FabricaSensorAgua fabricaAgua;

	SensorAmbiental* sensorAire = fabricaAire.crearSensor("Distrito Central");
	SensorAmbiental* sensorRuido = fabricaRuido.crearSensor("Zona Hospitalaria");
	SensorAmbiental* sensorAgua = fabricaAgua.crearSensor("Costa C");

	sensorAire->RegistrarMedicion(85);
	sensorRuido->RegistrarMedicion(78);
	sensorAire->RegistrarMedicion(91);

	PrioridaPorAire estrategiaAire;
	PrioridaPorRuido estrategiaRuido;
	PrioridaPorAgua estrategiaAgua;

	EvaluadorPrioridadAmbiental evaluador(&estrategiaAire);
	evaluador.evaluar(sensorAire);

	EvaluadorPrioridadAmbiental evaluador(&estrategiaRuido);
	evaluador.evaluar(sensorRuido);

	EvaluadorPrioridadAmbiental evaluador(&estrategiaAgua);
	evaluador.evaluar(sensorAgua);

	cout << "===== FIN DE LA EVALUACION=====" << endl;

}