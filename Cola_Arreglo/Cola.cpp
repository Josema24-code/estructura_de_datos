#include <iostream>
using namespace std;

#define MAXSIZE 5

int queueArr[MAXSIZE];
int frontIndex = -1;
int rearIndex = -1;

void insertar() {
    if (rearIndex == MAXSIZE - 1) { // cola llena (no circular)
        cout << "\nDESBORDAMIENTO (OVERFLOW)\n";
        return;
    }

    int elemento;
    cout << "\nIngrese el elemento: ";
    cin >> elemento;

    if (frontIndex == -1 && rearIndex == -1) { // cola vacía
        frontIndex = rearIndex = 0;
    } else {
        rearIndex++;
    }

    queueArr[rearIndex] = elemento;
    cout << "Elemento insertado correctamente.\n";
}

void eliminar() {
    if (frontIndex == -1 || frontIndex > rearIndex) { // cola vacía
        cout << "\nSUBDESBORDAMIENTO (UNDERFLOW)\n";
        return;
    }

    int elemento = queueArr[frontIndex];
    if (frontIndex == rearIndex) { // quedó vacía después de eliminar
        frontIndex = rearIndex = -1;
    } else {
        frontIndex++;
    }

    cout << "\nElemento eliminado: " << elemento << "\n";
}

void mostrar() {
    if (frontIndex == -1 || frontIndex > rearIndex) {
        cout << "\nLa cola está vacía.\n";
        return;
    }

    cout << "\nElementos en la cola:\n";
    for (int i = frontIndex; i <= rearIndex; ++i) {
        cout << queueArr[i] << "\n";
    }
}

int main() {
    int opcion = 0;

    do {
        cout << "\n*************** MENÚ PRINCIPAL ***************\n";
        cout << "1. Insertar un elemento\n";
        cout << "2. Eliminar un elemento\n";
        cout << "3. Mostrar la cola\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertar();
                break;
            case 2:
                eliminar();
                break;
            case 3:
                mostrar();
                break;
            case 4:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "\nOpción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 4);

    return 0;
}
