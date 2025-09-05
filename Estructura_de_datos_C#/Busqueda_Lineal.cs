using System;
namespace busquedalineal
{
    class Program
    {
        static void Main(string[] args)
        {
            //arreglo de numeros
            int[] numeros = { 30, 40, 70, 50 };
            Console.WriteLine("¿Que numero quiere buscar?");
            int encontrar_numero = Convert.ToInt32(Console.ReadLine());
            bool encontrado = false;
            for (int i = 0; i < numeros.Length; i++)
            {
                //comparacion
                if (numeros[i] == encontrar_numero)
                {
                    Console.WriteLine("numero encontrado en la posicion " + i);
                    encontrado = true;
                    break;   
                }


            }
            //si no se encuentra el numero
            if (!encontrado)
            {
                Console.WriteLine("no existe ese numero");
            }
        }

       
    }
}