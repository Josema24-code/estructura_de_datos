using System;

namespace Recorrido
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] numeros = { 10, 20, 30, 40 };

            // Recorrer con for el arreglo
            for (int i = 0; i < numeros.Length; i++)
            {
                Console.WriteLine(numeros[i]);
            }
        }
    }
}