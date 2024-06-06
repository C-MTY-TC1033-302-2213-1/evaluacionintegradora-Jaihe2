#ifndef COMBO_H
#define COMBO_H

#include "Producto.h"

class Combo : public Producto {
private:
    int clave;

public:
    Combo();
    Combo(const std::string& _nombre, int _precio, int _peso, int _clave);
    
    std::string str() const override;
    int calculaTotalPagar() const override;
};

#endif // COMBO_H
