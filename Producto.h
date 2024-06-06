#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
private:
    std::string nombre;
    int precio;
    int peso;

public:
    Producto();
    Producto(const std::string& _nombre, int _precio, int _peso);
    
    void setNombre(const std::string& _nombre);
    void setPrecio(int _precio);
    void setPeso(int _peso);
    
    std::string getNombre() const;
    int getPrecio() const;
    int getPeso() const;
    
    virtual std::string str() const;
    virtual int calculaTotalPagar() const;
};

#endif // PRODUCTO_H
