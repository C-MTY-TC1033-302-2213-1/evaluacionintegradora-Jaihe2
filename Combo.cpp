#include "Combo.h"

Combo::Combo() : Producto(), clave(0) {}

Combo::Combo(const std::string& _nombre, int _precio, int _peso, int _clave)
    : Producto(_nombre, _precio, _peso), clave(_clave) {}

std::string Combo::str() const {
    return getNombre() + "-" + "$" + std::to_string(getPrecio()) + "-" + std::to_string(getPeso()) + "-" + "$" + std::to_string(calculaTotalPagar()) + "-" + std::to_string(clave);
}

int Combo::calculaTotalPagar() const {
    int total = getPrecio() * getPeso() * clave;
    
    if (clave == 1) {
        total -= (total / 100) * 25;
    } else if (clave == 2) {
        total -= (total / 100) * 30;
    }
    
    return total;
}
