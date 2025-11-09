#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(float arr[], int n) {
    vector<float> cubetas[n];

    // Colocar elementos en cubetas
    for (int i = 0; i < n; i++) {
        int indice = n * arr[i];
        cubetas[indice].push_back(arr[i]);
    }

    // Ordenar cada cubeta
    for (int i = 0; i < n; i++)
        sort(cubetas[i].begin(), cubetas[i].end());

    // Unir las cubetas
    int index = 0;
    for (int i = 0; i < n; i++)
        for (float val : cubetas[i])
            arr[index++] = val;
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
