#include <iostream>
using namespace std;

struct Node {
    int data; // Dato del nodo
    Node* next; // Puntero al siguiente nodo
};

Node* top = nullptr;

void push(int item) {
    Node* newNode = new Node(); // Crear un nuevo nodo
    newNode->data = item; // Asignar datos al nodo  
    newNode->next = top; // Apuntar al nodo anterior
    top = newNode; // Actualizar el tope de la pila
    cout << "Elemento " << item << " insertado.\n"; // Confirmación
}

int pop() {
    // Verificar si la pila está vacía
    if (top == nullptr) {
        cout << "Stack Underflow\n";
        return -1;
    }
    // Extraer el dato del nodo superior
    int value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}
// Función para ver el elemento en la cima de la pila
int peek() {
    if (top == nullptr) {
        cout << "Pila vacía\n";
        return -1;
    }
    return top->data;
}
//
bool isEmpty() { return top == nullptr; }

int main() {
    int opcion, valor;
    do {
        cout << "\n--- MENU PILA (C++ Linked List) ---\n"
             << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Salir\nElige: ";
        cin >> opcion;
        switch(opcion) {
            case 1: cout << "Ingresa un valor: "; cin >> valor; push(valor); break;
            case 2: valor = pop(); if(valor!=-1) cout<<"Eliminado: "<<valor<<"\n"; break;
            case 3: valor = peek(); if(valor!=-1) cout<<"Tope: "<<valor<<"\n"; break;
            case 4: cout << (isEmpty()? "Pila vacía\n":"No está vacía\n"); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout<<"Opción inválida\n"; break;
        }
    } while(opcion!=5);
    return 0;
}
