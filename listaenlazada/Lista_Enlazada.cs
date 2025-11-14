using System;

class Node {
    public int Data;
    public Node Next;
}

class Program {
    static Node head;

    static void Main() {
        int choice = 0;
        while (choice != 9) {
            Console.WriteLine("\n*********Main Menu*********");
            Console.WriteLine("1. Insert at beginning");
            Console.WriteLine("2. Insert at last");
            Console.WriteLine("3. Insert at random location");
            Console.WriteLine("4. Delete from beginning");
            Console.WriteLine("5. Delete from last");
            Console.WriteLine("6. Delete from random location");
            Console.WriteLine("7. Display");
            Console.WriteLine("8. Search");
            Console.WriteLine("9. Exit");
            Console.Write("Enter your choice: ");

            choice = int.Parse(Console.ReadLine());

            switch (choice) {
                case 1: BeginInsert(); break;
                case 2: LastInsert(); break;
                case 3: RandomInsert(); break;
                case 4: BeginDelete(); break;
                case 5: LastDelete(); break;
                case 6: RandomDelete(); break;
                case 7: Display(); break;
                case 8: Search(); break;
            }
        }
    }

    static void BeginInsert() {
        Console.Write("Ingrese valor: ");
        int item = int.Parse(Console.ReadLine());
        Node newNode = new Node { Data = item, Next = head };
        head = newNode;
        Console.WriteLine("Nodo insertado");
    }

    static void LastInsert() {
        Console.Write("Ingrese valor: ");
        int item = int.Parse(Console.ReadLine());
        Node newNode = new Node { Data = item };

        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.Next != null)
                temp = temp.Next;
            temp.Next = newNode;
        }
        Console.WriteLine("Nodo insertado");
    }

    static void RandomInsert() {
        Console.Write("Ingrese valor: ");
        int item = int.Parse(Console.ReadLine());
        Console.Write("Ingrese posicion: ");
        int loc = int.Parse(Console.ReadLine());

        Node temp = head;
        for (int i = 0; i < loc; i++) {
            if (temp == null) {
                Console.WriteLine("No se puede insertar");
                return;
            }
            temp = temp.Next;
        }

        Node newNode = new Node { Data = item, Next = temp.Next };
        temp.Next = newNode;
        Console.WriteLine("Nodo insertado");
    }

    static void BeginDelete() {
        if (head == null) {
            Console.WriteLine("Lista vacía");
            return;
        }
        head = head.Next;
        Console.WriteLine("Nodo eliminado");
    }

    static void LastDelete() {
        if (head == null) { Console.WriteLine("Lista vacía"); return; }
        if (head.Next == null) { head = null; Console.WriteLine("Nodo eliminado"); return; }

        Node temp = head, prev = null;
        while (temp.Next != null) {
            prev = temp;
            temp = temp.Next;
        }
        prev.Next = null;
        Console.WriteLine("Nodo eliminado");
    }

    static void RandomDelete() {
        Console.Write("Ingrese posición: ");
        int loc = int.Parse(Console.ReadLine());

        if (head == null) { Console.WriteLine("Lista vacía"); return; }

        if (loc == 0) {
            head = head.Next;
            Console.WriteLine("Nodo eliminado");
            return;
        }

        Node temp = head, prev = null;
        for (int i = 0; i < loc; i++) {
            prev = temp;
            temp = temp.Next;
            if (temp == null) {
                Console.WriteLine("No se puede eliminar");
                return;
            }
        }

        prev.Next = temp.Next;
        Console.WriteLine("Nodo eliminado");
    }

    static void Display() {
        if (head == null) {
            Console.WriteLine("Lista vacía");
            return;
        }

        Node temp = head;
        while (temp != null) {
            Console.Write(temp.Data + "->");
            temp = temp.Next;
        }
        Console.WriteLine("NULL");
    }

    static void Search() {
        Console.Write("Ingrese valor a buscar: ");
        int item = int.Parse(Console.ReadLine());

        Node temp = head;
        int pos = 0;
        while (temp != null) {
            if (temp.Data == item) {
                Console.WriteLine($"Elemento {item} encontrado en {pos}");
                return;
            }
            temp = temp.Next;
            pos++;
        }
        Console.WriteLine("Elemento no encontrado");
    }
}
