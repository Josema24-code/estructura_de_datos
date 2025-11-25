#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sig;
};

Nodo* frente = nullptr;
Nodo* finalC = nullptr;

void insertar() {
    Nodo* nuevo = new Nodo();
    cout << "\nIngrese el elemento: ";
    cin >> nuevo->dato;
    nuevo->sig = nullptr;

    if (frente == nullptr)
        frente = finalC = nuevo;
    else {
        finalC->sig = nuevo;
        finalC = nuevo;
    }
    cout << "Elemento insertado correctamente.\n";
}

void eliminar() {
    if (frente == nullptr) {
        cout << "\nSUBDESBORDAMIENTO (UNDERFLOW)\n";
        return;
    }
    Nodo* aux = frente;
    int eliminado = aux->dato;
    frente = frente->sig;
    if (frente == nullptr)
        finalC = nullptr;
    delete aux;
    cout << "\nElemento eliminado: " << eliminado << "\n";
}

void mostrar() {
    if (frente == nullptr) {
        cout << "\nLa cola está vacía.\n";
        return;
    }
    cout << "\nElementos en la cola:\n";
    for (Nodo* i = frente; i != nullptr; i = i->sig)
        cout << i->dato << "\n";
}

int main() {
    int op;
    do {
        cout << "\n*************** MENÚ PRINCIPAL ***************\n";
        cout << "1. Insertar un elemento\n";
        cout << "2. Eliminar un elemento\n";
        cout << "3. Mostrar la cola\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> op;

        switch (op) {
            case 1: insertar(); break;
            case 2: eliminar(); break;
            case 3: mostrar(); break;
            case 4: cout << "\nSaliendo...\n"; break;
            default: cout << "\nOpción inválida.\n"; break;
        }
    } while (op != 4);
}
