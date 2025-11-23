package estructura_de_datos.Pila_Arreglo;

import java.util.Scanner;

public class Pila {
    private static final int MAX_SIZE = 100;
    private int[] stack = new int[MAX_SIZE];
    private int top = -1;

    public void push(int item) {
        if (top == MAX_SIZE - 1) {
            System.out.println("Stack Overflow");
            return;
        }
        stack[++top] = item;
    }

    public int pop() {
        if (top == -1) {
            System.out.println("Stack Underflow");
            return -1;
        }
        return stack[top--];
    }

    public int peek() {
        if (top == -1) {
            System.out.println("Pila vacía");
            return -1;
        }
        return stack[top];
    }

    public boolean isEmpty() { return top == -1; }
    public boolean isFull() { return top == MAX_SIZE - 1; }

    public static void main(String[] args) {
        Pila pila = new Pila();
        Scanner sc = new Scanner(System.in);
        int opcion, valor;

        do {
            System.out.println("\n--- MENU PILA (Java) ---");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. isEmpty");
            System.out.println("5. isFull");
            System.out.println("6. Salir");
            System.out.print("Elige: ");
            opcion = sc.nextInt();

            switch(opcion) {
                case 1:
                    System.out.print("Ingresa un valor: ");
                    valor = sc.nextInt();
                    pila.push(valor); break;
                case 2:
                    valor = pila.pop();
                    if(valor!=-1) System.out.println("Eliminado: " + valor); break;
                case 3:
                    valor = pila.peek();
                    if(valor!=-1) System.out.println("Tope: " + valor); break;
                case 4:
                    System.out.println(pila.isEmpty()? "Pila vacía" : "No está vacía"); break;
                case 5:
                    System.out.println(pila.isFull()? "Pila llena" : "No está llena"); break;
                case 6:
                    System.out.println("Saliendo..."); break;
                default:
                    System.out.println("Opción inválida");
            }
        } while(opcion != 6);
    }
}

