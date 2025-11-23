#include <iostream>
#define MAX_SIZE 100   // Tamaño máximo de la pila (para operaciones de entrada/salida)

int stack[MAX_SIZE];  // Arreglo para almacenar los elementos de la pila
int top = -1;         // Índice del elemento superior de la pila

// Función para agregar un elemento a la pila
void push(int item) {
    if (top == MAX_SIZE - 1) { // Verifica si la pila está llena
        std::cout << "Stack Overflow" << std::endl;  // Mensaje de error
        return; // Sale de la función
    }
    stack[++top] = item; // Incrementa el índice y agrega el elemento
    std::cout << "Elemento " << item << " insertado." << std::endl;
}

// Función para eliminar y retornar el elemento superior de la pila
int pop() {
    if (top == -1) { // Verifica si la pila está vacía
        std::cout << "Stack Underflow" << std::endl; // Mensaje de error
        return -1; // Retorna -1 para indicar que la pila está vacía
    }
    return stack[top--]; // Retorna el elemento superior y decrementa
}

// Función para ver el elemento superior sin eliminarlo
int peek() {
    if (top == -1) { // Verifica si la pila está vacía
        std::cout << "Pila vacía" << std::endl; // Mensaje de error
        return -1;
    }
    return stack[top]; // Retorna el elemento superior sin modificar
}

// Función para verificar si la pila está vacía
bool isEmpty() {
    return top == -1; // Retorna true si está vacía
}

// Función para verificar si la pila está llena
bool isFull() {
    return top == MAX_SIZE - 1; // Retorna true si está llena
}

// Programa principal (opcional con menú)
int main() {
    int opcion, valor;

    do {
        std::cout << "\n--- MENU PILA ---\n"
                  << "1. Push (Insertar)\n"
                  << "2. Pop (Eliminar)\n"
                  << "3. Peek (Ver Tope)\n"
                  << "4. Ver si está vacía\n"
                  << "5. Ver si está llena\n"
                  << "6. Salir\n"
                  << "Selecciona una opcion: ";
        std::cin >> opcion;

        switch(opcion) {
            case 1:
                std::cout << "Ingresa un valor: ";
                std::cin >> valor;
                push(valor);
                break;
            case 2:
                valor = pop();
                if (valor != -1) std::cout << "Elemento eliminado: " << valor << std::endl;
                break;
            case 3:
                valor = peek();
                if (valor != -1) std::cout << "Elemento superior: " << valor << std::endl;
                break;
            case 4:
                std::cout << (isEmpty() ? "La pila está vacía" : "La pila NO está vacía") << std::endl;
                break;
            case 5:
                std::cout << (isFull() ? "La pila está llena" : "La pila NO está llena") << std::endl;
                break;
            case 6:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
        }
    } while (opcion != 6);

    return 0;
}
