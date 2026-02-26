#include "EntidadBase.h"

EntidadBase::EntidadBase(string n) : nombre(n), activo(true) {


}

string EntidadBase::getNombre()const {

}

void EntidadBase::alternarEstado() {
	activo != activo;
}

bool EntidadBase::estaActivo()const {
	return activo;
}
