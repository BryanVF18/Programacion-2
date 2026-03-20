#include "EdificioResidencial.h"

EdificioResidencial::EdificioResidencial(std::string n, double base, int hab)
    : EntidadBase(n), consumoBase(base), habitantes(hab) {
}

double EdificioResidencial::consumirEnergia() {
    if (!activo) return 0.0;
    return consumoBase + (habitantes * 0.5);
}

std::string EdificioResidencial::getDetalleEstado() const {
    return "Tipo: [Consumidor] | Habitantes: " + std::to_string(habitantes);
}

void EdificioResidencial::serializarTexto(ostream& os) const {

    //vamos a escribir un archivo para que sea facil de leer despues
    //vamos a generar un archivo en formato CSV
    os << "RESIDENCIAL, " << nombre << ", Consumo base: " << consumoBase << ", Habitantes: " << habitantes <<endl;

}
void EdificioResidencial::serializarBinario(ofstream& os) const {

  //1. Escribir un identificador del tipo (para saber que es lo que estamos construyendo)
    int tipo=1; //1 = Edificio Residencial

    os.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));

    //2. Escribir los datos de texto (el nombre del edificio )
    // (Longitud del nombre + de caracteres en el nombre)

    size_t tamNombre = nombre.size();
    os.write(reinterpret_cast<const char*>(&tamNombre), sizeof(tamNombre));
    os.write(nombre.c_str(), tamNombre);

    //3. Escribir los datos númericos que no son texto

    os.write(reinterpret_cast<const char*>(&consumoBase), sizeof(consumoBase));
    os.write(reinterpret_cast<const char*>(&habitantes), sizeof(habitantes));


}