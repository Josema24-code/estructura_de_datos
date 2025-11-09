public class seleccion {
    public static void main(String[] args){
        int[] array = {64, 25, 12, 22, 11};
        System.out.println("Antes de ordenar:");
        for(int i=0; i<array.length; i++){
            System.out.print(array[i] + " ");
        }
        
        for (int i = 0; i < array.length; i++) {
            int minimo = i; // indice del elemento minimo
            for (int j = i + 1; j< array.length; j++) { // buscar el elemento minimo en el arreglo no ordenado
                if (array[minimo] > array[j]){ // si el elemento actual es mayor que el elemento j
                    minimo = j; // actualizar el indice del elemento minimo
                }
            }
            int aux = array [i]; // intercambiar el elemento minimo con el primer elemento
            array[i] = array[minimo]; // poner el elemento minimo en su posicion correcta
            array[minimo] = aux; // poner el elemento mayor en la posicion del elemento minimo
        }
        System.out.println("\nDespués de ordenar:");
        for(int i=0; i<array.length; i++){
            System.out.print(array[i] + " ");
        }
    }
    
}
