public class ordenar_Buscar {
    public static void main(String[] args){
        int[] array = {8 ,23, 64, 87, 34, 95, 12, 54, 44, 5};
        int temporal;

        System.out.println("Array sin ordenar: ");
        for (int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }
        System.out.println(" ");
        // ordenar arreglo
        System.out.println("Arreglo ordenado :");
        for (int i = 0; i < array.length -1 ; i++){
            for (int j = 0; j < array.length - i - 1; j++){
                if (array[j] > array[j+1]){
                    temporal = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temporal;
                }
            }
        }
        for (int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }
        System.out.println(" ");

        System.out.println("¿Qué número quiere buscar? ");
        int encontrar_Numero = Integer.parseInt(System.console().readLine());
        // Variable para indicar si se encontró el número
        
        boolean encontrado = false;
        // Recorrer el arreglo para buscar el número
        for (int i = 0; i < array.length; i++) {
            if (array[i] == encontrar_Numero) {
                System.out.println("Número encontrado en la posición " + i);
                encontrado = true;
                break; 
            }
        }
        // Si no se encuentra el número
        if (!encontrado) {
            System.out.println("No existe ese número");
        }
    }
}
