package estructura_de_datos.Juegos;

public class Gato {
    public static void main(String[] args){
        char [][] tablero = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };
        char jugador = 'X';
        int turnos = 0;
        boolean winner = false;
        // El juego continua mientras no haya un ganador y queden turnos
        while (turnos < 9 && !winner){
            // Se dibuja el tablero en consola
            System.out.println("  0   1   2");
            for (int i = 0; i < 3; i++){
                // se imprime el numero de fila
                System.out.print(i + " ");
                for (int j = 0; j < 3; j++){
                    System.out.print(tablero[i][j]);
                    if (j < 2){
                        System.out.print(" | ");
                    }
                }
                System.out.println();
                if (i < 2){
                    System.out.println(" ---+---+---");
                }
                
            }
            // Se pide al jugador que ingrese sus coordenadas
            System.out.println("Es turno del jugador: " + jugador);
            System.out.println("Ingrese coordenada fila (0 - 2): ");
            int fila = Integer.parseInt(System.console().readLine());
            System.out.println("Ingrese coordenada columna (0 - 2): ");
            int columna = Integer.parseInt(System.console().readLine());
            // Se valida que las coordenadas sean correctas
            if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' '){
                System.out.println("Coordenadas invalidas, intente de nuevo.");
                // Se vuelve al inicio del ciclo
                continue;
            }
            // Se actualiza el tablero
            tablero[fila][columna] = jugador;
            turnos++;
            // Se verifica si hay un ganador
            for (int i = 0; i < 3; i++){
                if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) {
                    winner = true;
                }
                if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) {
                    winner = true;
                }
                if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) {
                    winner = true;
                }
                if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) {
                    winner = true;
                }
            }

            if (winner){
                System.out.println("Felicidades! El jugador " + jugador + " ha ganado!");
            }
            else if (turnos == 9){
                System.out.println("El juego ha terminado en empate.");
            }
            // Se cambia de jugador
            if (jugador == 'X'){
                jugador = 'O';
            }
            else {
                jugador = 'X';
            }
            
            
        }
    }
 }

