using System;
namespace seleccion
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = { 40, 60, 55, 12, 94 };
            Console.Write("Antes de ordenar: ");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }

            for (int i = 0; i < array.Length; i++)
            {
                int minimo = i;
                for (int j = i + 1; j < array.Length; j++)
                { 
                    if (array[minimo] > array[j])
                    {
                        minimo = j;
                    }
                }
                int aux = array[i];
                array[i] = array[minimo];
                array[minimo] = aux;
            }

            Console.Write("\nDespues de ordenar: ");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }
        }
    }

}