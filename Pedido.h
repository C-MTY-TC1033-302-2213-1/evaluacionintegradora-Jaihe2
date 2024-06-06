#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "Producto.h"
#include "Verdura.h"
#include "Combo.h"

const int MAX_PROD = 50;

class Pedido {
private:
    Producto* arrPtrProductos[MAX_PROD];
    int cantidad;

public:
    Pedido();
    void leerArchivo(const std::string& nombre);
    void ticketCliente() const;
};

#endif // PEDIDO_H
