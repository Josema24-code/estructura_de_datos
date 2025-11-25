using System;

class Nodo {
    public int dato;
    public Nodo sig;
    public Nodo(int d) { dato = d; sig = null; }
}

class ColaLista {
    static Nodo frente = null, fin = null;

    static void Insertar() {
        Console.Write("\nIngrese el elemento: ");
        int elem = int.Parse(Console.ReadLine());
        Nodo nuevo = new Nodo(elem);

        if (frente == null) frente = fin = nuevo;
        else {
            fin.sig = nuevo;
            fin = nuevo;
        }
        Console.WriteLine("Elemento insertado correctamente.");
    }

    static void Eliminar() {
        if (frente == null) {
            Console.WriteLine("\nSUBDESBORDAMIENTO (UNDERFLOW)");
            return;
        }
        int e = frente.dato;
        frente = frente.sig;
        if (frente == null) fin = null;
        Console.WriteLine("\nElemento eliminado: " + e);
    }

    static void Mostrar() {
        if (frente == null) {
            Console.WriteLine("\nLa cola está vacía.");
            return;
        }
        Console.WriteLine("\nElementos en la cola:");
        for (Nodo i = frente; i != null; i = i.sig)
            Console.WriteLine(i.dato);
    }

    static void Main() {
        int op;
        do {
            Console.WriteLine("\n*************** MENÚ PRINCIPAL ***************");
            Console.WriteLine("1. Insertar un elemento");
            Console.WriteLine("2. Eliminar un elemento");
            Console.WriteLine("3. Mostrar la cola");
            Console.WriteLine("4. Salir");
            Console.Write("Ingrese su opción: ");
            op = int.Parse(Console.ReadLine());

            switch(op) {
                case 1: Insertar(); break;
                case 2: Eliminar(); break;
                case 3: Mostrar(); break;
                case 4: Console.WriteLine("\nSaliendo..."); break;
                default: Console.WriteLine("\nOpción inválida."); break;
            }
        } while (op != 4);
    }
}
