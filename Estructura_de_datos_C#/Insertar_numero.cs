using System;
namespace insertar_numero
{
    class Program
    {
        static void Main(string[] args)
        {
            //arreglo inicial
            int[] numeros = { 30, 40, 70, 50 };
            for (int i = 0; i < numeros.Length; i++)
            {
                Console.WriteLine(numeros[i]);
            }

            Console.WriteLine("ingrese un numero para cambiar");
            int nuevo_numero = Convert.ToInt32(Console.ReadLine());
            //se recorre el arreglo de atras hacia adelante
            for (int i = numeros.Length - 1; i > 0; i--)
            {
                numeros[i] = numeros[i - 1];
            }
            //se inserta el nuevo numero en la primera posicion|
            numeros[0] = nuevo_numero;
            //se muestra el nuevo arreglo
            for (int i = 0; i < numeros.Length; i++)
            {
                Console.WriteLine(numeros[i]);
            }
        }


    }
}