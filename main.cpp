#include <iostream>
#include "Pedido.h"

using namespace std;

int main() {
    Pedido pedido;
    int opcion;

    cin >> opcion;

    switch (opcion) {
        case 1:
            pedido.leerArchivo("Pedido1.csv");
            break;
        case 2:
            pedido.leerArchivo("Pedido2.csv");
            break;
        case 3:
            pedido.leerArchivo("Pedido3.csv");
            break;
        case 4:
            pedido.leerArchivo("Pedido4.csv");
            break;
        default:
            break;
    }

    pedido.ticketCliente();

    return 0;
}

