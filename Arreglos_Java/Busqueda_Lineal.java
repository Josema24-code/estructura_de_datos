
public class Busqueda_Lineal {
    public static void main(String[] args) {
        // Arreglo de números
        int[] numeros = {30, 40, 70, 50};
        
        
        System.out.print("¿Qué número quiere buscar? ");
        int encontrar_Numero = Integer.parseInt(System.console().readLine());
        // Variable para indicar si se encontró el número
        
        boolean encontrado = false;
        // Recorrer el arreglo para buscar el número
        for (int i = 0; i < numeros.length; i++) {
            if (numeros[i] == encontrar_Numero) {
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
