public class mergeSort {
    static void merge(int arr[], int inicio, int medio, int fin) {
        int n1 = medio - inicio + 1;
        int n2 = fin - medio;

        int[] L = new int[n1];
        int[] R = new int[n2];

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

    static void mergeSort(int arr[], int inicio, int fin) {
        if (inicio < fin) {
            int medio = (inicio + fin) / 2;
            mergeSort(arr, inicio, medio);
            mergeSort(arr, medio + 1, fin);
            merge(arr, inicio, medio, fin);
        }
    }

    public static void main(String[] args) {
        int arr[] = {34, 5, 62, 32, 23, 78, 1, 56};

        System.out.print("Original: ");
        for (int x : arr) System.out.print(x + " ");
        System.out.println();

        mergeSort(arr, 0, arr.length - 1);

        System.out.print("Ordenado: ");
        for (int x : arr) System.out.print(x + " ");
    }
}


