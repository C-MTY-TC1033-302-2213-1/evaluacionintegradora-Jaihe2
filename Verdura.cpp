#include "Verdura.h"

Verdura::Verdura() : Producto(), temporada("Invierno") {}

Verdura::Verdura(const std::string& _nombre, int _precio, int _peso, const std::string& _temporada)
    : Producto(_nombre, _precio, _peso), temporada(_temporada) {}

std::string Verdura::str() const {
    return getNombre() + "-" + "$" + std::to_string(getPrecio()) + "-" + std::to_string(getPeso()) + "-" + "$" + std::to_string(calculaTotalPagar()) + "-" + temporada;
}

int Verdura::calculaTotalPagar() const {
    if (temporada == "Junio") {
        return getPrecio() * getPeso() * 2;
    } else if (temporada == "Regalado") {
        return getPrecio() * getPeso() * 3;
    } else {
        return getPrecio() * getPeso() * 10;
    }
}
