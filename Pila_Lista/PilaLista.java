package estructura_de_datos.Pila_Lista;


import java.util.Scanner;

class Node {
    int data;
    Node next;
    Node(int d) { data = d; } // Constructor
}

public class PilaLista {
    private Node top = null;

    public void push(int item) {
        Node n = new Node(item);
        n.next = top;
        top = n;
        System.out.println("Elemento " + item + " insertado.");
    }

    public int pop() {
        if (top == null) {
            System.out.println("Stack Underflow");
            return -1;
        }
        int value = top.data;
        top = top.next;
        return value;
    }

    public int peek() {
        if (top == null) {
            System.out.println("Pila vacía");
            return -1;
        }
        return top.data;
    }

    public boolean isEmpty() { return top == null; }

    public static void main(String[] args) {
        PilaLista pila = new PilaLista();
        Scanner sc = new Scanner(System.in);
        int opcion, valor;

        do {
            System.out.println("\n--- MENU PILA (Java Linked List) ---");
            System.out.println("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Salir");
            System.out.print("Elige: ");
            opcion = sc.nextInt();

            switch(opcion) {
                case 1: System.out.print("Ingresa un valor: "); valor = sc.nextInt(); pila.push(valor); break;
                case 2: valor = pila.pop(); if(valor!=-1) System.out.println("Eliminado: "+valor); break;
                case 3: valor = pila.peek(); if(valor!=-1) System.out.println("Tope: "+valor); break;
                case 4: System.out.println(pila.isEmpty() ? "Pila vacía":"No está vacía"); break;
                case 5: System.out.println("Saliendo..."); break;
                default: System.out.println("Opción inválida");
            }
        } while(opcion != 5);
    }
}

