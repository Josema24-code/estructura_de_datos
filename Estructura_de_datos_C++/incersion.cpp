#include <iostream>
using namespace std;
void insercion (int arr[]){
    for (int i = 1 ; i < 5; i++){
        int numActual = arr[i];
        int j = i;

        while (j>0 && arr[j-1] > numActual){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = numActual;
    }
}

int main(){
    int array[5] = {5,2,4,6,1};
    cout << "Antes de ordenar: ";
    for (int i = 0; i < 5; i++){
        cout << array[i] << " ";
    }
    insercion(array);
    cout << "\nDespues de ordenar: ";
    for (int i = 0; i < 5; i++){
        cout << array[i] << " ";
    }
    return 0;
}