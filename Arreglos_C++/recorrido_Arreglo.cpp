#include <iostream>
int main() {
    int numeros [4];
    int n;
    int i;
    // pide 4 numeros y los guarda en el arreglo|
    for (n=0; n<4; n++) {
        std::cout << "Ingrese un numero: ";
        std::cin >> numeros[n];
    }
    // muestra los numeros del arreglo
    for (i = 0; i< 4; i++)
    {
        std::cout << numeros[i]<< std::endl;
    }

    return 0;
}