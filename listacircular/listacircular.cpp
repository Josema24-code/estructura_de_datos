#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sig;
    Nodo(int d) : dato(d), sig(nullptr) {}
};

void insertarInicio(Nodo*& cabeza, int dato) {
    Nodo* nuevo = new Nodo(dato);
    if (!cabeza) {
        nuevo->sig = nuevo;
        cabeza = nuevo;
        return;
    }
    Nodo* temp = cabeza;
    while (temp->sig != cabeza) temp = temp->sig;

    nuevo->sig = cabeza;
    temp->sig = nuevo;
    cabeza = nuevo;
}

void insertarFinal(Nodo*& cabeza, int dato) {
    Nodo* nuevo = new Nodo(dato);
    if (!cabeza) {
        nuevo->sig = nuevo;
        cabeza = nuevo;
        return;
    }
    Nodo* temp = cabeza;
    while (temp->sig != cabeza) temp = temp->sig;

    temp->sig = nuevo;
    nuevo->sig = cabeza;
}

void insertarPosicion(Nodo*& cabeza, int dato, int pos) {
    if (pos == 0) {
        insertarInicio(cabeza, dato);
        return;
    }

    Nodo* nuevo = new Nodo(dato);
    Nodo* temp = cabeza;

    for (int i = 1; i < pos && temp->sig != cabeza; i++)
        temp = temp->sig;

    nuevo->sig = temp->sig;
    temp->sig = nuevo;
}

void eliminarInicio(Nodo*& cabeza) {
    if (!cabeza) return;

    Nodo* temp = cabeza;

    if (temp->sig == temp) {
        delete temp;
        cabeza = nullptr;
        return;
    }

    Nodo* fin = cabeza;
    while (fin->sig != cabeza) fin = fin->sig;

    cabeza = cabeza->sig;
    fin->sig = cabeza;
    delete temp;
}

void eliminarFinal(Nodo*& cabeza) {
    if (!cabeza) return;

    Nodo* temp = cabeza;
    if (temp->sig == temp) {
        delete temp;
        cabeza = nullptr;
        return;
    }

    Nodo* ant = nullptr;
    while (temp->sig != cabeza) {
        ant = temp;
        temp = temp->sig;
    }

    ant->sig = cabeza;
    delete temp;
}

void eliminarPosicion(Nodo*& cabeza, int pos) {
    if (!cabeza) return;

    if (pos == 0) {
        eliminarInicio(cabeza);
        return;
    }

    Nodo* temp = cabeza;
    Nodo* ant = nullptr;

    for (int i = 0; i < pos && temp->sig != cabeza; i++) {
        ant = temp;
        temp = temp->sig;
    }

    ant->sig = temp->sig;
    delete temp;
}

void mostrar(Nodo* cabeza) {
    if (!cabeza) return;

    Nodo* temp = cabeza;
    do {
        cout << temp->dato << " -> ";
        temp = temp->sig;
    } while (temp != cabeza);
    cout << "(regresa)\n";
}
int main() {
    Nodo* lista = nullptr;
bool seguir = true;
    do{
        cout << "Lista Circular:\n";
        cout << "Elija una opcion:\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Insertar en posicion\n";
        cout << "4. Eliminar al inicio\n";
        cout << "5. Eliminar al final\n";
        cout << "6. Eliminar en posicion\n";
        cout << "7. Mostrar lista\n";
        cout << "8. Salir\n";

        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int dato;
                cout << "Ingrese el dato a insertar:\n";
                cin >> dato;
                insertarInicio(lista, dato);
                break;
            }
            case 2: {
                int dato;
                cout << "Ingrese el dato a insertar:\n";
                cin >> dato;
                insertarFinal(lista, dato);
                break;
            }
            case 3: {
                int dato, pos;
                cout << "Ingrese el dato a insertar:\n";
                cin >> dato;
                cout << "Ingrese la posicion:\n";
                cin >> pos;
                insertarPosicion(lista, dato, pos);
                break;
            }
            case 4:
                eliminarInicio(lista);
                break;
            case 5:
                eliminarFinal(lista);
                break;
            case 6: {
                int pos;
                cout << "Ingrese la posicion a eliminar:\n";
                cin >> pos;
                eliminarPosicion(lista, pos);
                break;
            }
            case 7:
                mostrar(lista);
                break;
            case 8:
                seguir = false;
                break;
            default:
                cout << "Opcion no valida\n";
        }

    }while (seguir);

    return 0;
}