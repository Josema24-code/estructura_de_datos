public class quickSort {
    static int particionar(int arr[], int inicio, int fin) {
        int pivote = arr[fin];
        int i = inicio - 1;
        for (int j = inicio; j < fin; j++) {
            if (arr[j] <= pivote) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp2 = arr[i + 1];
        arr[i + 1] = arr[fin];
        arr[fin] = temp2;
        return i + 1;
    }

    static void quickSort(int arr[], int inicio, int fin) {
        if (inicio < fin) {
            int indicePivote = particionar(arr, inicio, fin);
            quickSort(arr, inicio, indicePivote - 1);
            quickSort(arr, indicePivote + 1, fin);
        }
    }

    public static void main(String args[]) {
        int arr[] = {34, 32, 5, 89, 1, 4, 8, 7, 6, 3, 2};
        System.out.print("Original: ");
        for (int x : arr) System.out.print(x + " ");
        System.out.println();

        quickSort(arr, 0, arr.length - 1);

        System.out.print("Ordenado: ");
        for (int x : arr) System.out.print(x + " ");
    }

}
