using System;
namespace Estructura_de_datos_C_
{
public class Persona
{
    // Atributos
    public string Nombre;
    public string Apellido;
    public int Edad;
// Constructor
    public Persona(string n, string a, int e)
    {
        Nombre = n;
        Apellido = a;
        Edad = e;
    }
}
    // Función principal
    class Dato_Abstracto
    {
        static void Main(string[] args)
        {
            // Crear un arreglo de personas
            Persona[] personas = new Persona[3]
            {
            new Persona("Jose", "Aguallo", 30),
            new Persona("Sheila", "Valdez", 25),
            new Persona("Luis", "Ramírez", 40)
            };
            // Mostrar los datos de las personas
            for (int i = 0; i < personas.Length; i++)
            {
                Console.WriteLine($"Persona {i + 1}");
                Console.WriteLine("Nombre: " + personas[i].Nombre);
                Console.WriteLine("Apellido: " + personas[i].Apellido);
                Console.WriteLine("Edad: " + personas[i].Edad);
                Console.WriteLine("------------------");
            }
        }
    }
}
