using System;

class StackMenu {
    const int MAX_SIZE = 100;
    int[] stack = new int[MAX_SIZE];
    int top = -1;

    void Push(int item) {
        if (top == MAX_SIZE - 1) { Console.WriteLine("Stack Overflow"); return; }
        stack[++top] = item;
    }

    int Pop() {
        if (top == -1) { Console.WriteLine("Stack Underflow"); return -1; }
        return stack[top--];
    }

    int Peek() {
        if (top == -1) { Console.WriteLine("Pila vacía"); return -1; }
        return stack[top];
    }

    bool IsEmpty() => top == -1;
    bool IsFull() => top == MAX_SIZE - 1;

    static void Main() {
        StackMenu pila = new StackMenu();
        int opcion, valor;

        do {
            Console.WriteLine("\n--- MENU PILA (C#) ---");
            Console.WriteLine("1. Push");
            Console.WriteLine("2. Pop");
            Console.WriteLine("3. Peek");
            Console.WriteLine("4. isEmpty");
            Console.WriteLine("5. isFull");
            Console.WriteLine("6. Salir");
            Console.Write("Elige: ");
            opcion = int.Parse(Console.ReadLine());

            switch(opcion) {
                case 1:
                    Console.Write("Ingresa un valor: ");
                    valor = int.Parse(Console.ReadLine());
                    pila.Push(valor);
                    break;
                case 2:
                    valor = pila.Pop();
                    if(valor != -1) Console.WriteLine("Eliminado: " + valor);
                    break;
                case 3:
                    valor = pila.Peek();
                    if(valor != -1) Console.WriteLine("Tope: " + valor);
                    break;
                case 4:
                    Console.WriteLine(pila.IsEmpty()? "Pila vacía" : "No está vacía");
                    break;
                case 5:
                    Console.WriteLine(pila.IsFull()? "Pila llena" : "No está llena");
                    break;
                case 6:
                    Console.WriteLine("Saliendo...");
                    break;
                default:
                    Console.WriteLine("Opción inválida");
                    break;
            }
        } while(opcion != 6);
    }
}
