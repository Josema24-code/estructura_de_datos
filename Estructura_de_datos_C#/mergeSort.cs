using System;
namespace Estructura_de_datos_C_
{


    class Program
    {
        static void MergeSort(int[] arr, int inicio, int fin)
        {
            if (inicio < fin)
            {
                int medio = (inicio + fin) / 2;

                MergeSort(arr, inicio, medio);
                MergeSort(arr, medio + 1, fin);

                Merge(arr, inicio, medio, fin);
            }
        }

        static void Merge(int[] arr, int inicio, int medio, int fin)
        {
            int n1 = medio - inicio + 1;
            int n2 = fin - medio;

            int[] izquierda = new int[n1];
            int[] derecha = new int[n2];

            for (int i = 0; i < n1; i++)
                izquierda[i] = arr[inicio + i];
            for (int j = 0; j < n2; j++)
                derecha[j] = arr[medio + 1 + j];

            int k = inicio, i1 = 0, j1 = 0;

            while (i1 < n1 && j1 < n2)
            {
                if (izquierda[i1] <= derecha[j1])
                    arr[k++] = izquierda[i1++];
                else
                    arr[k++] = derecha[j1++];
            }

            while (i1 < n1) arr[k++] = izquierda[i1++];
            while (j1 < n2) arr[k++] = derecha[j1++];
        }

        static void Main()
        {
            int[] numeros = { 34, 7, 56, 23, 32, 5, 62 };
            Console.WriteLine("Original: " + string.Join(", ", numeros));
            MergeSort(numeros, 0, numeros.Length - 1);
            Console.WriteLine("Ordenado: " + string.Join(", ", numeros));
        }
    }
}
