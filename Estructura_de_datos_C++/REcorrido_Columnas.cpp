#include <iostream>
using namespace std;

int main() {
    int numeros[3][3];

    // Calcular número de filas y columnas con sizeof
    int filas = sizeof(numeros) / sizeof(numeros[0]);
    int columnas = sizeof(numeros[0]) / sizeof(numeros[0][0]);

    // Ingresar los datos
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Ingrese un numero [" << i << "," << j << "]: ";
            cin >> numeros[i][j];
        }
    }

    // Mostrar por columnas
    cout << "\nRecorrido por columnas:\n";
    for (int j = 0; j < columnas; j++) {
        for (int i = 0; i < filas; i++) {
            cout << numeros[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
