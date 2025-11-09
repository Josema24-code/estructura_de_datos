#include <iostream>
using namespace std;

int main(){
    int array[5] = {75, 84, 69, 90, 72};
    cout << "Antes de ordenar: ";
    for (int i = 0; i < 5; i++) {
        cout << array[i] << " ";
    }

    for (int i = 0; i < 5; i++) {
            int minimo = i;
            for (int j = i + 1; j< 5; j++) {
                if (array[minimo] > array[j]){
                    minimo = j;
                }
            }
            int aux = array [i];
            array[i] = array[minimo];
            array[minimo] = aux;
    }
    cout << "\nDespues de ordenar: ";
    for (int i = 0; i < 5; i++) {
        cout << array[i] << " ";
    }
}