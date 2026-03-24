#include "GestorArchivos.h"
#include "EdificioResidencial.h"
#include "PlantaSolar.h"
#include <fstream>

//Vamos a definir una frabrica de objetos
//Un mapa que asocia los ID de los edificios con una funcion que construye el objeto,
// esto suprime la necesidad de hacer un metodo de escritura o lectura 
// por cada edificio que existe en la ciudad

map<int, function< shared_ptr<EntidadBase>()>>fabrica = 
{

	{1,[]() {
		return make_shared<EdificioResidencial>("", 0,0); }
	},
	{2, []() {return make_shared<PlantaSolar>("", 0); }
	}
	//Si hay 600 edificios los agrego a mi mapa y no me preocupo nunca más por los tipos

};

void GestorArchivos::guardarEstadoBinario(const Distrito& dist, string ruta)
{
	ofstream archivo(ruta, ios::binary); 
	if (!archivo)return;//Manejo de excepciones

	auto& edificios = dist.getEntidades();
	size_t total = edificios.size();
	archivo.write(reinterpret_cast<const char*>(&total), sizeof(total));
	for (const auto& e : edificios) {
		e->escribirBinario(archivo)
	}
	archivo.close();

}

void GestorArchivos::cargarEstadoBinario(Distrito& dist, string ruta) {
	ifstream archivo(ruta, ios::binary);

	if (!archivo)return; //Manejo de excepciones

	dist.limpiarEntidades();
	size_t total;
	archivo.read(reinterpret_cast<char*>(&total), sizeof(total));

	for (size_t i = 0; i < total; i++)
	{
		int tipo;
		archivo.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));

		//Ya tenemos el tipo, usamos la fabrica para leer los elementos en el archivo y categorizarlos

		if (fabrica.count(tipo))
		{
			//1. Creamos un cascarón del objeto usando el mapa
			auto nuevaEntidad = fabrica[tipo]();

			//2. El objeto (sea cual sea se lee a si mismo (Delegación)
			nuevaEntidad->leerBinario(archivo);

			//3. Le pasamos la información a Distrito 
			dist.agregarEntidad(nuevaEntidad);
		}
		else {
			std::cerr << "Tipo de edificio desconocido: " << tipo << ". Nos saltamos el registro"<<endl;
		}
	}
}