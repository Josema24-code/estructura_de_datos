
public class Tres_EnRaya {
    public static void main(String[] args) {
        char [][] gato = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };
        char jugador = 'X';
        int turnos = 0;
        boolean ganador = false;
         while (turnos < 9 && !ganador) {

            System.out.println(" 0   1   2");
            for (int i = 0; i < 3; i++){
                System.out.print(i + " "); 
                for (int j = 0; j < 3; j++){
                    System.out.print(gato[i][j]);
                    if (j < 2){
                        System.out.print(" | ");
                    }
                }
                System.out.println();
                if (i < 2 ) {
                    System.out.println(" ---+---+---");
                }
            }
        
            System.out.println("Turno del jugador: " + jugador);
            System.out.println("Ingrese fila (0 - 2): ");
            int fila = Integer.parseInt(System.console().readLine());
            System.out.println("Ingrese columna (0 - 2): ");
            int columna = Integer.parseInt(System.console().readLine());
            if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || gato[fila][columna] != ' '){
            System.out.println("Movimiento invalido, intente de nuevo.");
            continue;
            }
                gato[fila][columna] = jugador;
                turnos++;
                
                // Revisar fila
                int count = 0;
                for (int j = 0; j < 3; j++) {
                    if (gato[fila][j] == jugador) count++;
                }
                if (count == 3) ganador = true;

                // Revisar columna
                count = 0;
                for (int i = 0; i < 3; i++) {
                    if (gato[i][columna] == jugador) count++;
                }
                if (count == 3) ganador = true;

                // Revisar diagonal principal
                count = 0;
                for (int i = 0; i < 3; i++) {
                    if (gato[i][i] == jugador) count++;
                }
                if (count == 3) ganador = true;

                // Revisar diagonal secundaria
                count = 0;
                for (int i = 0; i < 3; i++) {
                    if (gato[i][2 - i] == jugador) count++;
                }
                if (count == 3) ganador = true;

                if (ganador) {
                    System.out.println("¡Jugador " + jugador + " ha ganado!");
                    break;
}
            // Cambiar turno
            if (jugador == 'X'){
                jugador = 'O';
            } else {
                jugador = 'X';
            }
        
            if (!ganador) {
                System.out.println("¡Empate!");
            }
        }
    }   
}
