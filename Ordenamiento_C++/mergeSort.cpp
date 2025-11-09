#include <iostream>
using namespace std;

void merge(int arr[], int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++) R[j] = arr[medio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        mergeSort(arr, inicio, medio);
        mergeSort(arr, medio + 1, fin);
        merge(arr, inicio, medio, fin);
    }
}

int main() {
    int arr[] = {34, 7, 56, 23, 32, 5, 62};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
