public class insercion {

    public static void main(String[] args) {
        int[] arr = {5, 2, 9, 1, 5, 6};
        System.out.println("Antes de ordenar:");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        insercion(arr);
        System.out.println("\nDespués de ordenar:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    static void insercion(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int numActual = arr[i];
            int j = i;
            // Mover los elementos del arreglo que son mayores que numActual
            while (j > 0 && arr[j - 1] > numActual) {
                arr[j] = arr[j - 1];// Mover el elemento hacia la derecha
                j--;// Decrementar j para seguir comparando con los elementos anteriores
            }
            arr[j] = numActual;//refresca el numero actual en su posicion correcta
        }
    }
}