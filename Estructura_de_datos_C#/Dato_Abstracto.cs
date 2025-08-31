using System;

public class Persona
{
    public string Nombre;
    public string Apellido;
    public int Edad;

    public Persona(string n, string a, int e)
    {
        Nombre = n;
        Apellido = a;
        Edad = e;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Persona[] personas = new Persona[3]
        {
            new Persona("Jose", "Aguallo", 30),
            new Persona("Sheila", "Valdez", 25),
            new Persona("Luis", "Ramírez", 40)
        };

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
