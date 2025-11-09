using System;
namespace Estructura_de_datos_C_
{
    class OrdenamientoQuickSort
    {
        static void QuickSort(int[] arr, int inicio, int fin)
        {
            if (inicio < fin)
            {
                int indicePivote = Particionar(arr, inicio, fin);

                // Ordenar recursivamente izquierda y derecha
                QuickSort(arr, inicio, indicePivote - 1);
                QuickSort(arr, indicePivote + 1, fin);
            }
        }

        static int Particionar(int[] arr, int inicio, int fin)
        {
            int pivote = arr[fin]; // Se elige el último como pivote
            int i = inicio - 1;

            for (int j = inicio; j < fin; j++)
            {
                if (arr[j] <= pivote)
                {
                    i++;
                    // Intercambiar arr[i] con arr[j]
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }

            // Colocar el pivote en su posición correcta
            int temp2 = arr[i + 1];
            arr[i + 1] = arr[fin];
            arr[fin] = temp2;

            return i + 1;
        }

        static void Main()
        {
            int[] numeros = { 34, 7, 23, 32, 5, 62 };

            Console.WriteLine("Arreglo original:");
            Console.WriteLine(string.Join(", ", numeros));

            QuickSort(numeros, 0, numeros.Length - 1);

            Console.WriteLine("\nArreglo ordenado:");
            Console.WriteLine(string.Join(", ", numeros));
        }
    }
}
