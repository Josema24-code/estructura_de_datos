using System;

class Cola {
    const int MAXSIZE = 5;
    static int[] queue = new int[MAXSIZE];
    static int front = -1, rear = -1;

    static void Insertar() {
        if (rear == MAXSIZE - 1) {
            Console.WriteLine("\nDESBORDAMIENTO (OVERFLOW)");
            return;
        }

        Console.Write("\nIngrese el elemento: ");
        int elem = int.Parse(Console.ReadLine());

        if (front == -1 && rear == -1)
            front = rear = 0;
        else
            rear++;

        queue[rear] = elem;
        Console.WriteLine("Elemento insertado correctamente.");
    }

    static void Eliminar() {
        if (front == -1 || front > rear) {
            Console.WriteLine("\nSUBDESBORDAMIENTO (UNDERFLOW)");
            return;
        }

        int elem = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;

        Console.WriteLine("\nElemento eliminado: " + elem);
    }

    static void Mostrar() {
        if (front == -1 || front > rear) {
            Console.WriteLine("\nLa cola está vacía.");
            return;
        }

        Console.WriteLine("\nElementos en la cola:");
        for (int i = front; i <= rear; i++)
            Console.WriteLine(queue[i]);
    }

    static void Main() {
        int opcion;
        do {
            Console.WriteLine("\n*************** MENÚ PRINCIPAL ***************");
            Console.WriteLine("1. Insertar un elemento");
            Console.WriteLine("2. Eliminar un elemento");
            Console.WriteLine("3. Mostrar la cola");
            Console.WriteLine("4. Salir");
            Console.Write("Ingrese su opción: ");
            opcion = int.Parse(Console.ReadLine());

            switch(opcion) {
                case 1: Insertar(); break;
                case 2: Eliminar(); break;
                case 3: Mostrar(); break;
                case 4: Console.WriteLine("\nSaliendo del programa..."); break;
                default: Console.WriteLine("\nOpción inválida. Intente nuevamente."); break;
            }
        } while (opcion != 4);
    }
}
