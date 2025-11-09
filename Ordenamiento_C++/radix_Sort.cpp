#include <iostream>
#include <vector>
using namespace std;

// Obtener el valor máximo del arreglo
int getMax(vector<int>& arr) {
    int max = arr[0];
    for (int num : arr)
        if (num > max) max = num;
    return max;
}

// Ordenar por un dígito específico (exp = 1, 10, 100...)
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Ordenamiento principal
void radixSort(vector<int>& arr) {
    int max = getMax(arr);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);

    cout << "Ordenado: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}
