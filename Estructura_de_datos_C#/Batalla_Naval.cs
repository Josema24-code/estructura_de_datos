using System;
namespace Estructura_de_datos_C_
{
    class Program
    {
        static void Main()
        {
            char[,] tablero = new char[10, 10];
            int[] barcos = { 3, 3, 2, 4, 5 }; // tamaños de los barcos

            // Inicializar tablero con agua
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    tablero[i, j] = '-';
                }
            }

            // Colocar barcos
            for (int b = 0; b < barcos.Length; b++)
            {
                int longitud = barcos[b];
                bool colocado = false;

                while (!colocado)
                {
                    // Mostrar tablero 
                    Console.Write("   ");
                    for (char c = 'A'; c <= 'J'; c++)
                    {
                        Console.Write(c + " ");
                    }
                    Console.WriteLine();

                    for (int i = 0; i < 10; i++)
                    {
                        Console.Write((i + 1).ToString().PadLeft(2) + " ");
                        for (int j = 0; j < 10; j++)
                        {
                            Console.Write(tablero[i, j] + " ");
                        }
                        Console.WriteLine();
                    }

                    Console.WriteLine($"\nColoca un barco de {longitud} casillas.");
                    Console.Write("Ingresa la posición inicial: ");
                    string pos = Console.ReadLine().ToUpper();
                    if (pos.Length < 2)
                    {
                        Console.WriteLine("Entrada inválida. Debes poner letra y un número ");
                        continue; // vuelve a pedir la entrada
                    }

                    char letra = pos[0];
                    if (letra < 'A' || letra > 'J')
                    {
                        Console.WriteLine("Letra inválida. Debe ser de A a J.");
                        continue;
                    }

                    int fila;
                    bool filaValida = int.TryParse(pos.Substring(1), out fila);
                    if (!filaValida || fila < 1 || fila > 10)
                    {
                        Console.WriteLine("Número de fila inválido. Debe ser del 1 al 10.");
                        continue;
                    }

                    int col = letra - 'A';
                    fila = fila - 1; // para convertir a índice 0-9

                    Console.Write("Horizontal (H) o Vertical (V): ");
                    string orientacion = Console.ReadLine().ToUpper();
                    bool horizontal = orientacion == "H";

                    bool sePuede = true;

                    // Verificar si cabe y si no choca
                    if (horizontal)
                    {
                        if (col + longitud > 10) sePuede = false;
                        else
                        {
                            for (int j = col; j < col + longitud; j++)
                            {
                                if (tablero[fila, j] != '-') sePuede = false;
                            }
                        }
                    }
                    else
                    {
                        if (fila + longitud > 10) sePuede = false;
                        else
                        {
                            for (int i = fila; i < fila + longitud; i++)
                            {
                                if (tablero[i, col] != '-') sePuede = false;
                            }
                        }
                    }

                    // Verificar si se puede colocar
                    if (sePuede)
                    {
                        if (horizontal)
                        {
                            for (int j = col; j < col + longitud; j++)
                            {
                                tablero[fila, j] = 'B';
                            }
                        }
                        else
                        {
                            for (int i = fila; i < fila + longitud; i++)
                            {
                                tablero[i, col] = 'B';
                            }
                        }
                        colocado = true;
                    }
                    else
                    {
                        Console.WriteLine("No se puede colocar aquí. Intenta otra vez.");
                    }
                }
            }
            Console.WriteLine("\nTodos los barcos han sido colocados.");
        }
    }
}
