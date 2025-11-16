#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sig;
    Nodo* ant;
};

Nodo* cabeza = NULL;

// --- (funciones: insertarInicio, insertarFinal, insertarPosicion,
//      eliminarInicio, eliminarFinal, eliminarPosicion, mostrar)
// Reusa las mismas funciones que ya te di antes.
void insertarInicio(int dato){
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    if(cabeza == NULL){
        cabeza = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
        return;
    }
    Nodo* ultimo = cabeza->ant;
    nuevo->sig = cabeza;
    nuevo->ant = ultimo;
    ultimo->sig = nuevo;
    cabeza->ant = nuevo;
    cabeza = nuevo;
}

void insertarFinal(int dato){
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    if(cabeza == NULL){
        cabeza = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
        return;
    }
    Nodo* ultimo = cabeza->ant;
    ultimo->sig = nuevo;
    nuevo->ant = ultimo;
    nuevo->sig = cabeza;
    cabeza->ant = nuevo;
}

void insertarPosicion(int dato, int pos){
    if(pos == 0){
        insertarInicio(dato);
        return;
    }
    if(cabeza == NULL){
        cout << "Lista vacia, usa insertar inicio.\n";
        return;
    }
    Nodo* temp = cabeza;
    for(int i = 0; i < pos - 1 && temp->sig != cabeza; i++) temp = temp->sig;
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    Nodo* siguiente = temp->sig;
    nuevo->sig = siguiente;
    nuevo->ant = temp;
    temp->sig = nuevo;
    siguiente->ant = nuevo;
}

void eliminarInicio(){
    if(cabeza == NULL) return;
    if(cabeza->sig == cabeza){ delete cabeza; cabeza = NULL; return; }
    Nodo* ultimo = cabeza->ant;
    Nodo* temp = cabeza;
    cabeza = cabeza->sig;
    cabeza->ant = ultimo;
    ultimo->sig = cabeza;
    delete temp;
}

void eliminarFinal(){
    if(cabeza == NULL) return;
    if(cabeza->sig == cabeza){ delete cabeza; cabeza = NULL; return; }
    Nodo* ultimo = cabeza->ant;
    Nodo* nuevoUltimo = ultimo->ant;
    nuevoUltimo->sig = cabeza;
    cabeza->ant = nuevoUltimo;
    delete ultimo;
}

void eliminarPosicion(int pos){
    if(cabeza == NULL) return;
    if(pos == 0){ eliminarInicio(); return; }
    Nodo* temp = cabeza;
    for(int i = 0; i < pos && temp->sig != cabeza; i++) temp = temp->sig;
    Nodo* anterior = temp->ant;
    Nodo* siguiente = temp->sig;
    anterior->sig = siguiente;
    siguiente->ant = anterior;
    delete temp;
}

void mostrar(){
    if(cabeza == NULL){ cout << "Lista vacía\n"; return; }
    Nodo* temp = cabeza;
    do{
        cout << temp->dato << " <-> ";
        temp = temp->sig;
    } while(temp != cabeza);
    cout << "(regresa)\n";
}

int main(){
    int opcion;
    do {
        cout << "\n=== MENÚ LISTA CIRCULAR DOBLE (C++) ===\n";
        cout << "1. Insertar al inicio\n2. Insertar al final\n3. Insertar en posición\n";
        cout << "4. Eliminar al inicio\n5. Eliminar al final\n6. Eliminar en posición\n";
        cout << "7. Mostrar lista\n8. Salir\n";
        cout << "Opción: "; cin >> opcion;

        int dato, pos;
        switch(opcion){
            case 1:
                cout << "Dato: "; cin >> dato;
                insertarInicio(dato);
                break;
            case 2:
                cout << "Dato: "; cin >> dato;
                insertarFinal(dato);
                break;
            case 3:
                cout << "Dato: "; cin >> dato;
                cout << "Posición: "; cin >> pos;
                insertarPosicion(dato, pos);
                break;
            case 4:
                eliminarInicio();
                break;
            case 5:
                eliminarFinal();
                break;
            case 6:
                cout << "Posición a eliminar: "; cin >> pos;
                eliminarPosicion(pos);
                break;
            case 7:
                mostrar();
                break;
            case 8:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida\n";
        }
    } while(opcion != 8);

    return 0;
}
