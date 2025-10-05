using System;
namespace Estructura_de_datos_C_
{
    class OrdenamientoBurbuja
    {
        public static void Main(string[] args)
        {
            int MAX = 10;
            int MIN = 1;
            int[] array = new int[10];
            Random random = new Random();
            for (int i = 0; i < array.Length; i++)
            {
                array[i] = random.Next(MIN, MAX);
            }
            Console.WriteLine("Array sin ordenar:");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }
            // Algoritmo de ordenamiento burbuja
            for (int i = 0; i < array.Length - 1; i++)
            {
                for (int j = 0; j < array.Length - i - 1; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        // Intercambiar
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
            Console.WriteLine("\nArray ordenado:");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }
        }
    }

}
