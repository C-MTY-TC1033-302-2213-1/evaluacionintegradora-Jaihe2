#include "Pedido.h"
#include <fstream>
#include <sstream>

using namespace std;

Pedido::Pedido() : cantidad(0) {
    for (int i = 0; i < MAX_PROD; ++i) {
        arrPtrProductos[i] = nullptr;
    }
}

void Pedido::leerArchivo(const std::string& nombre) {
    fstream archivo;
    string row[5];
    string line, word;

    archivo.open(nombre, ios::in);
    cantidad = 0;

    while (getline(archivo, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }

        stringstream s(line);
        int iR = 0;

        while (getline(s, word, ',')) {
            row[iR++] = word;
        }

        // Check if the row has the correct number of columns for "P"
        if (row[0] == "P" && iR == 4) {
            arrPtrProductos[cantidad] = new Producto(row[1], stoi(row[2]), stoi(row[3]));
            cantidad++;
        } else if (row[0] == "V" && iR == 5) {
            arrPtrProductos[cantidad] = new Verdura("", 0, 0, row[1]);
            arrPtrProductos[cantidad]->setNombre(row[2]);
            arrPtrProductos[cantidad]->setPrecio(stoi(row[3]));
            arrPtrProductos[cantidad]->setPeso(stoi(row[4]));
            cantidad++;
        } else if (row[0] == "C" && iR == 5) {
            arrPtrProductos[cantidad] = new Combo(row[1], stoi(row[2]), stoi(row[3]), stoi(row[4]));
            cantidad++;
        } else if (row[0] == "P" && iR == 3) { // Handle incomplete P product
            arrPtrProductos[cantidad] = new Producto(row[1], stoi(row[2]), 0); // Default peso to 0
            cantidad++;
        }
    }
    archivo.close();
}

void Pedido::ticketCliente() const {
    if (cantidad == 0) {
        return; // No produce ninguna salida si no hay productos válidos
    }

    int total = 0;
    for (int i = 0; i < cantidad; ++i) {
        if (arrPtrProductos[i] != nullptr) {
            std::cout << arrPtrProductos[i]->str() << std::endl;
            total += arrPtrProductos[i]->calculaTotalPagar();
        }
    }
    std::cout << cantidad << " articulos" << std::endl;
    std::cout << "Total a pagar $" << total << std::endl;
}
