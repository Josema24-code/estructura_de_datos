using System;

class Batalla_Naval
{
    static void Main()
    {
        // Tableros de los jugadores y disparos
        char[,] tablero1 = new char[10, 10];
        char[,] tablero2 = new char[10, 10];
        char[,] disparos1 = new char[10, 10];
        char[,] disparos2 = new char[10, 10];
        int[] barcos = { 3, 3, 2, 4, 5 };

        InicializarTablero(tablero1);
        InicializarTablero(tablero2);
        InicializarTablero(disparos1);
        InicializarTablero(disparos2);

        Console.WriteLine("Jugador 1 coloca sus barcos");
        ColocarBarcos(tablero1, barcos);
        Console.Clear();

        Console.WriteLine("Jugador 2 coloca sus barcos");
        ColocarBarcos(tablero2, barcos);
        Console.Clear();

        while (true)
        {
            Console.WriteLine("Turno del Jugador 1");
            Mostrar(disparos1);
            Atacar(tablero2, disparos1);

            if (TodosDestruidos(tablero2))
            {
                Console.WriteLine("¡Jugador 1 ganó!");
                break;
            }

            Console.WriteLine("Presiona una tecla para continuar...");
            Console.ReadKey();
            Console.Clear();

            Console.WriteLine("Turno del Jugador 2");
            Mostrar(disparos2);
            Atacar(tablero1, disparos2);

            if (TodosDestruidos(tablero1))
            {
                Console.WriteLine("¡Jugador 2 ganó!");
                break;
            }

            Console.WriteLine("Presiona una tecla para continuar...");
            Console.ReadKey();
            Console.Clear();
        }
    }

    static void InicializarTablero(char[,] t)
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                t[i, j] = '-';
    }

    static void Mostrar(char[,] t)
    {
        Console.Write("   ");
        for (char c = 'A'; c <= 'J'; c++) Console.Write(c + " ");
        Console.WriteLine();
        for (int i = 0; i < 10; i++)
        {
            Console.Write((i + 1).ToString().PadLeft(2) + " "); // muestra números de fila
            for (int j = 0; j < 10; j++)
                Console.Write(t[i, j] + " "); // muestra el contenido de la celda
            Console.WriteLine();
        }
    }

    static void ColocarBarcos(char[,] tablero, int[] barcos)
    {
        for (int b = 0; b < barcos.Length; b++)
        {
            bool colocado = false;
            while (!colocado)
            {
                Mostrar(tablero);
                Console.WriteLine($"Coloca un barco de {barcos[b]} casillas.");

                int fila = -1, col = -1;
                while (true)
                {
                    Console.Write("Ingresa la posición para colocar el barco : ");
                    string pos = Console.ReadLine().ToUpper();
                    if (pos.Length < 2) continue;

                    char letra = pos[0];
                    if (letra < 'A' || letra > 'J') continue;

                    if (!int.TryParse(pos.Substring(1), out fila)) continue;
                    fila -= 1; // Convierte a índice 0-9
                    col = letra - 'A'; // Convierte letra a índice 0-9

                    if (fila >= 0 && fila < 10) break; // Valida la fila
                }

                bool horizontal = true;
                while (true)
                {
                    Console.Write("Horizontal (H) o Vertical (V): ");
                    string orientacion = Console.ReadLine().ToUpper();
                    if (orientacion == "H") { horizontal = true; break; } 
                    if (orientacion == "V") { horizontal = false; break; } 
                }
                // Verifica si el barco cabe y no se superpone
                bool sePuede = true;
                for (int i = 0; i < barcos[b]; i++)
                {
                    int f = fila;
                    int c = col;
                    if (!horizontal) f += i; else c += i;

                    if (f >= 10 || c >= 10 || tablero[f, c] != '-')
                    {
                        sePuede = false;
                        break;
                    }
                }
                // Coloca el barco si es posible
                if (sePuede)
                {
                    for (int i = 0; i < barcos[b]; i++)
                    {
                        int f = fila;
                        int c = col;
                        if (!horizontal) f += i; else c += i;
                        tablero[f, c] = 'B';
                    }
                    colocado = true;
                }
                else
                {
                    Console.WriteLine("No se puede colocar ahí. Intenta otra posición.");
                }

                Console.Clear();
            }
        }
    }

    static void Atacar(char[,] tableroEnemigo, char[,] tableroDisparos)
    {
        int fila = -1, col = -1;
        while (true)
        {
            Console.Write("Ingresa la posición para atacar : ");
            string pos = Console.ReadLine().ToUpper();
            if (pos.Length < 2) continue;

            char letra = pos[0];
            if (letra < 'A' || letra > 'J') continue;

            if (!int.TryParse(pos.Substring(1), out fila)) continue; // Convierte a índice 0-9
            fila -= 1;
            col = letra - 'A';

            if (fila >= 0 && fila < 10) break;
        }

        if (tableroDisparos[fila, col] != '-')
        {
            Console.WriteLine("Ya atacaste ahí. Intenta otra posición.");
            Atacar(tableroEnemigo, tableroDisparos);
            return;
        }

        char celda = tableroEnemigo[fila, col];

        if (celda == 'B')
        {
            Console.WriteLine("¡Impacto!");
            tableroEnemigo[fila, col] = 'X';
            tableroDisparos[fila, col] = 'X';
        }
        else
        {
            Console.WriteLine("Agua...");
            tableroEnemigo[fila, col] = 'O';
            tableroDisparos[fila, col] = 'O';
        }
    }
    // Verifica si todos los barcos han sido destruidos
    static bool TodosDestruidos(char[,] tablero)
    {
        for (int i = 0; i < 10; i++) 
            for (int j = 0; j < 10; j++)
                if (tablero[i, j] == 'B') 
                    return false; // Aún quedan barcos
        return true; // Todos los barcos han sido destruidos
    }
}
