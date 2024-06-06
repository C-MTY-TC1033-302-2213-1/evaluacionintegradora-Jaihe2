#ifndef VERDURA_H
#define VERDURA_H

#include "Producto.h"

class Verdura : public Producto {
private:
    std::string temporada;

public:
    Verdura();
    Verdura(const std::string& _nombre, int _precio, int _peso, const std::string& _temporada);
    
    std::string str() const override;
    int calculaTotalPagar() const override;
};

#endif // VERDURA_H
