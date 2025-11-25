package estructura_de_datos.Cola_Lista;

import java.util.Scanner;

class Nodo {
    int dato;
    Nodo sig;
    Nodo(int d) { dato = d; sig = null; }
}

public class ColaLista {
    static Nodo frente = null, fin = null;
    static Scanner sc = new Scanner(System.in);

    static void insertar() {
        System.out.print("\nIngrese el elemento: ");
        int elem = sc.nextInt();
        Nodo nuevo = new Nodo(elem);

        if (frente == null) frente = fin = nuevo;
        else {
            fin.sig = nuevo;
            fin = nuevo;
        }
        System.out.println("Elemento insertado correctamente.");
    }

    static void eliminar() {
        if (frente == null) {
            System.out.println("\nSUBDESBORDAMIENTO (UNDERFLOW)");
            return;
        }
        int e = frente.dato;
        frente = frente.sig;
        if (frente == null) fin = null;
        System.out.println("\nElemento eliminado: " + e);
    }

    static void mostrar() {
        if (frente == null) {
            System.out.println("\nLa cola está vacía.");
            return;
        }
        System.out.println("\nElementos en la cola:");
        for (Nodo i = frente; i != null; i = i.sig)
            System.out.println(i.dato);
    }

    public static void main(String[] args) {
        int op;
        do {
            System.out.println("\n*************** MENÚ PRINCIPAL ***************");
            System.out.println("1. Insertar un elemento");
            System.out.println("2. Eliminar un elemento");
            System.out.println("3. Mostrar la cola");
            System.out.println("4. Salir");
            System.out.print("Ingrese su opción: ");
            op = sc.nextInt();

            switch (op) {
                case 1: insertar(); break;
                case 2: eliminar(); break;
                case 3: mostrar(); break;
                case 4: System.out.println("\nSaliendo..."); break;
                default: System.out.println("\nOpción inválida."); break;
            }
        } while (op != 4);
    }
}
