public class Recorrido_Columnas {
    public static void main(String[]args){
        int [][] numeros = new int [3][3];
        //llenado del arreglo
        for (int i = 0; i < numeros.length; i++){
            for (int j = 0; j < numeros[0].length; j++){
                System.out.println("Ingrese un numero para la posicion " + i + "," + j);
                numeros[i][j] = Integer.parseInt(System.console().readLine());
            }
        }
        //recorrido por columnas
        //el ciclo externo recorre las columnas
        //el ciclo interno recorre las filas
        for (int j = 0; j < numeros[0].length; j++){
            for (int i = 0; i < numeros.length; i++){
                System.out.println(numeros[i][j]);
            }

        }
    }
}
    

