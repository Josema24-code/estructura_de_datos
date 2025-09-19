import java.util.Random;
public class burbuja {
    public static void main(String[] args) {
        int MAXIMO = 10;
        int MINIMO = 1;
        int temporal;
        int[] array = new int[10];
        Random aleatorio = new Random();
        // rellenar array con numeros aleatorios entre 1 y 10
        for (int i = 0; i < array.length; i++){
            array[i] = aleatorio.nextInt((MAXIMO - MINIMO) + 1) + MINIMO;
        }
        // mostrar array sin ordenar
        System.out.println("Array sin ordenar: ");
        for (int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }
        // ordenar array con metodo burbuja
        for (int i = 0; i < array.length -1 ; i++){
            for (int j = 0; j < array.length - i - 1; j++){
                if (array[j] > array[j+1]){
                    temporal = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temporal;
                }
            }
        }
        // mostrar array ordenado
        System.out.println("\nArray ordenado: ");
        for (int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }
    }
}
