public class subArreglo {
    public static void main(String[] args) {
        // Matriz 5x5x5 (ejemplo con algunos valores desordenados)
        int[][][] arr = {
            { {5, 2, 9, 1, 3}, {8, 6, 7, 4, 0}, {10, 14, 12, 11, 13}, {15, 18, 16, 17, 19}, {21, 20, 22, 23, 24} },
            { {30, 25, 29, 26, 28}, {33, 32, 31, 35, 34}, {37, 36, 39, 38, 40}, {42, 41, 44, 43, 45}, {47, 46, 48, 49, 50} },
            { {55, 51, 52, 53, 54}, {57, 56, 59, 58, 60}, {61, 63, 64, 62, 65}, {67, 66, 68, 70, 69}, {72, 71, 74, 73, 75} },
            { {80, 76, 78, 77, 79}, {82, 81, 84, 83, 85}, {87, 86, 89, 88, 90}, {92, 91, 93, 95, 94}, {97, 96, 99, 98, 100} },
            { {101, 102, 103, 104, 105}, {106, 107, 108, 109, 110}, {111, 112, 113, 114, 115}, {116, 117, 118, 119, 120}, {121, 122, 123, 124, 125} }
        };

        // Recorremos las capas
        for (int i = 0; i < arr.length; i++) {
            System.out.println("Subarreglo " + i + ":");
            for (int j = 0; j < arr[i].length; j++) {

                // Ordenar cada fila con burbuja
                for (int x = 0; x < arr[i][j].length - 1; x++) {
                    for (int y = 0; y < arr[i][j].length - 1 - x; y++) {
                        if (arr[i][j][y] > arr[i][j][y + 1]) {
                            int temp = arr[i][j][y];
                            arr[i][j][y] = arr[i][j][y + 1];
                            arr[i][j][y + 1] = temp;
                        }
                    }
                }

                // Si la capa es impar la invertimos
                if (i % 2 == 1) {
                    for (int k = 0; k < arr[i][j].length / 2; k++) {
                        int temp = arr[i][j][k];
                        arr[i][j][k] = arr[i][j][arr[i][j].length - 1 - k];
                        arr[i][j][arr[i][j].length - 1 - k] = temp;
                    }
                }

                // Imprimir la fila ordenada
                System.out.print(" ");
                for (int k = 0; k < arr[i][j].length; k++) {
                    System.out.print(arr[i][j][k] + " ");
                }
                System.out.println(" ");
            }
            System.out.println("Fin de subarreglo " + i + " ");
        }
    }
}
