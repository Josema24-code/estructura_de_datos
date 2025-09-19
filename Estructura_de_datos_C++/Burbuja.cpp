#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int array[10];
    int MINIMO = 1;
    int MAXIMO = 10;
    int auxiliar;
    srand(time(NULL));
    for (int i = 0; i < 10; i++){
        array[i] = rand() % (MAXIMO - MINIMO + 1) + MINIMO;
    }
    // mostrar antes de ordenar
    cout << "Antes de ordenar: ";
    for (int i = 0; i < 10; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    //ordenar con metodo burbuja
    for (int i = 0; i < 10 ; i++){
        for (int j = 0; j < 10 - i -1; j++){
            if (array[j] > array[j + 1 ]){
                auxiliar = array[j];
                array[j] = array [j+1];
                array[j+1] = auxiliar;
            }
        }

    }
    // mostrar despues de ordenar
    cout << "Despues de ordenar: ";
    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";

return 0;
}
