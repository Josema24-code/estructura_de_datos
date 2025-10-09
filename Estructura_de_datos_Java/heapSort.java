public class heapSort {
    static void heapify(int arr[], int n, int i) {
        int mayor = i;
        int izq = 2 * i + 1;
        int der = 2 * i + 2;

        if (izq < n && arr[izq] > arr[mayor])
            mayor = izq;

        if (der < n && arr[der] > arr[mayor])
            mayor = der;

        if (mayor != i) {
            int temp = arr[i];
            arr[i] = arr[mayor];
            arr[mayor] = temp;

            heapify(arr, n, mayor);
        }
    }

    static void heapSort(int arr[]) {
        int n = arr.length;

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i >= 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {
        int arr[] = {34, 7, 23, 32, 5, 62};

        System.out.print("Original: ");
        for (int x : arr) System.out.print(x + " ");
        System.out.println();

        heapSort(arr);

        System.out.print("Ordenado: ");
        for (int x : arr) System.out.print(x + " ");
    }
}

