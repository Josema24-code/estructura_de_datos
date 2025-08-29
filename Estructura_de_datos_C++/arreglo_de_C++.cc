#include <iostream>
using namespace std;

int main() {
    // Declarar y asignar
    int numeros[4] = {10, 20, 30, 40};

    // Leer elemento en la posición 0
    cout << numeros[0] << endl; // 10

    // leer con un for todo el areglo
    for (int i = 0; i < 4; i++) {
        cout << numeros[i] << endl;
    }

    return 0;
}