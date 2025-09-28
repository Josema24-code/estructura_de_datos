#include <iostream>
using namespace std;

int particionar(int arr[], int inicio, int fin) {
    int pivote = arr[fin];
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++) {
        if (arr[j] <= pivote) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[fin]);
    return i + 1;
}

void quickSort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int indicePivote = particionar(arr, inicio, fin);
        quickSort(arr, inicio, indicePivote - 1);
        quickSort(arr, indicePivote + 1, fin);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 3, 6, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
