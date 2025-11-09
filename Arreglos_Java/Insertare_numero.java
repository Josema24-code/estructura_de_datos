public class Insertare_numero {
    public static void main(String[] args){
        int [] numeros = {30, 40, 70, 50};
        for (int i = 0; i < numeros .length; i++){
            System.out.println(numeros[i]);

        }
        System.out.print("Ingrese un número para cambiar: ");
        int nuevo_Numero = Integer.parseInt(System.console().readLine());
        //se recorre el arreglo de atras hacia adelante
        for (int i = numeros.length - 1; i > 0; i--){
            numeros[i] = numeros[i - 1];

        }
        //se inserta el nuevo numero en la primera posicion
        numeros[0] = nuevo_Numero;
        //se muestra el nuevo arreglo
        for (int i = 0 ; i < numeros.length; i++){
            System.out.println(numeros[i]);
        }
    }
    
}
