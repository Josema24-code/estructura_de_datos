using System;

class heapSort
{
    static void HeapSort(int[] arr)
    {
        int n = arr.Length;

        // Construir el heap (montículo máximo)
        for (int i = n / 2 - 1; i >= 0; i--)
            Heapify(arr, n, i);

        // Extraer uno por uno los elementos del heap
        for (int i = n - 1; i >= 0; i--)
        {
            // Mover la raíz (máximo) al final
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Llamar heapify al heap reducido
            Heapify(arr, i, 0);
        }
    }

    static void Heapify(int[] arr, int n, int i)
    {
        int mayor = i;
        int izquierda = 2 * i + 1;
        int derecha = 2 * i + 2;

        if (izquierda < n && arr[izquierda] > arr[mayor])
            mayor = izquierda;

        if (derecha < n && arr[derecha] > arr[mayor])
            mayor = derecha;

        if (mayor != i)
        {
            int temp = arr[i];
            arr[i] = arr[mayor];
            arr[mayor] = temp;

            Heapify(arr, n, mayor);
        }
    }

    static void Main()
    {
        int[] numeros = { 34, 7, 23, 32, 5, 62 };
        Console.WriteLine("Original: " + string.Join(", ", numeros));
        HeapSort(numeros);
        Console.WriteLine("Ordenado: " + string.Join(", ", numeros));
    }
}
