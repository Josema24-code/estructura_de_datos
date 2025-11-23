using System;

class Node {
    public int data;
    public Node next;
    public Node(int d) { data = d; }
}

class StackLinked {
    Node top = null;

    void Push(int item) {
        Node n = new Node(item);
        n.next = top;
        top = n;
        Console.WriteLine($"Elemento {item} insertado.");
    }

    int Pop() {
        if (top == null) { Console.WriteLine("Stack Underflow"); return -1; }
        int value = top.data;
        top = top.next;
        return value;
    }

    int Peek() {
        if (top == null) { Console.WriteLine("Pila vacía"); return -1; }
        return top.data;
    }

    bool IsEmpty() => top == null;

    static void Main() {
        StackLinked pila = new StackLinked();
        int opcion, valor;

        do {
            Console.WriteLine("\n--- MENU PILA (C# Linked List) ---");
            Console.WriteLine("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Salir");
            Console.Write("Elige: ");
            opcion = int.Parse(Console.ReadLine());

            switch(opcion) {
                case 1: Console.Write("Ingresa un valor: "); valor = int.Parse(Console.ReadLine()); pila.Push(valor); break;
                case 2: valor = pila.Pop(); if(valor!=-1) Console.WriteLine("Eliminado: "+valor); break;
                case 3: valor = pila.Peek(); if(valor!=-1) Console.WriteLine("Tope: "+valor); break;
                case 4: Console.WriteLine(pila.IsEmpty()? "Pila vacía":"No está vacía"); break;
                case 5: Console.WriteLine("Saliendo..."); break;
                default: Console.WriteLine("Opción inválida"); break;
            }
        } while(opcion != 5);
    }
}
