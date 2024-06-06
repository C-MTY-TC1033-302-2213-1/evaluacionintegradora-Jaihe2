#include "Producto.h"

Producto::Producto() : nombre("TuNombre"), precio(123456), peso(25) {}

Producto::Producto(const std::string& _nombre, int _precio, int _peso)
    : nombre(_nombre), precio(_precio), peso(_peso) {}

void Producto::setNombre(const std::string& _nombre) {
    nombre = _nombre;
}

void Producto::setPrecio(int _precio) {
    precio = _precio;
}

void Producto::setPeso(int _peso) {
    peso = _peso;
}

std::string Producto::getNombre() const {
    return nombre;
}

int Producto::getPrecio() const {
    return precio;
}

int Producto::getPeso() const {
    return peso;
}

std::string Producto::str() const {
    return nombre + "-" + "$" + std::to_string(precio) + "-" + std::to_string(peso) + "-" + "$" + std::to_string(calculaTotalPagar());
}

int Producto::calculaTotalPagar() const {
    return precio * peso;
}
