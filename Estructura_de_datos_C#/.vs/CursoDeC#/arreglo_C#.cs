using System;

class Program
{
    static void Main(string[] args)
    {
        // Declarar y asignar arreglo
        int[] numeros = { 10, 20, 30, 40 };

        // Leer posicion 0
        Console.WriteLine(numeros[0]); // 10

        // Recorrer con for
        for (int i = 0; i < numeros.Length; i++)
        {
            Console.WriteLine(numeros[i]);
        }

        
    }
}
