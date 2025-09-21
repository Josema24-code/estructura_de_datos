using System;

class Program
{
    static void Main()
    {
        int[] arr = { 5, 2, 9, 1, 5, 6 };

        Console.WriteLine("Antes de ordenar");
        for (int i = 0; i < arr.Length; i++)
        {
            Console.Write(arr[i] + " ");
        }
        Insercion(arr);
        Console.WriteLine();


        Console.WriteLine("Despues de ordenar");
        for (int i = 0; i < arr.Length; i++)
        {
            Console.Write(arr[i]+ " ");
        }
    }

    static void Insercion (int[] arr)
    {
        
        for (int i = 1; i < arr.Length; i++)
        {
            int numActual = arr[i];
            int j = i ;
            // Mover los elementos del arreglo que son mayores que numActual
            while (j > 0 && arr[j-1] > numActual)
            {
                arr[j] = arr[j-1];// Mover el elemento hacia la derecha
                j--;// Decrementar j para seguir comparando con los elementos anteriores
            }

            arr[j] = numActual;//refresca el numero actual en su posicion correcta
        }
    }
}
