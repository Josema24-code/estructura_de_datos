package estructura_de_datos.listacirculardoble;

import java.util.Scanner;

class Nodo {
    int dato;
    Nodo sig;
    Nodo ant;

    Nodo(int d){
        dato = d;
        sig = ant = null;
    }
}

public class listaCirculardoble {
    Nodo cabeza = null;

    // ============================================
    // INSERTAR AL INICIO
    // ============================================
    void insertarInicio(int dato){
        Nodo nuevo = new Nodo(dato);

        if (cabeza == null){
            cabeza = nuevo;
            nuevo.sig = nuevo;
            nuevo.ant = nuevo;
            return;
        }

        Nodo ultimo = cabeza.ant;

        nuevo.sig = cabeza;
        nuevo.ant = ultimo;

        ultimo.sig = nuevo;
        cabeza.ant = nuevo;

        cabeza = nuevo;
    }

    // ============================================
    // INSERTAR AL FINAL
    // ============================================
    void insertarFinal(int dato){
        Nodo nuevo = new Nodo(dato);

        if (cabeza == null){
            cabeza = nuevo;
            nuevo.sig = nuevo;
            nuevo.ant = nuevo;
            return;
        }

        Nodo ultimo = cabeza.ant;

        ultimo.sig = nuevo;
        nuevo.ant = ultimo;

        nuevo.sig = cabeza;
        cabeza.ant = nuevo;
    }

    // ============================================
    // INSERTAR EN POSICIÓN
    // ============================================
    void insertarPosicion(int dato, int pos){
        if (pos == 0){
            insertarInicio(dato);
            return;
        }

        if (cabeza == null){
            System.out.println("La lista está vacía");
            return;
        }

        Nodo temp = cabeza;
        for (int i = 0; i < pos - 1 && temp.sig != cabeza; i++)
            temp = temp.sig;

        Nodo nuevo = new Nodo(dato);
        Nodo siguiente = temp.sig;

        nuevo.sig = siguiente;
        nuevo.ant = temp;

        temp.sig = nuevo;
        siguiente.ant = nuevo;
    }

    // ============================================
    // ELIMINAR AL INICIO
    // ============================================
    void eliminarInicio(){
        if (cabeza == null) return;

        if (cabeza.sig == cabeza){
            cabeza = null;
            return;
        }

        Nodo ultimo = cabeza.ant;
        cabeza = cabeza.sig;

        cabeza.ant = ultimo;
        ultimo.sig = cabeza;
    }

    // ============================================
    // ELIMINAR AL FINAL
    // ============================================
    void eliminarFinal(){
        if (cabeza == null) return;

        if (cabeza.sig == cabeza){
            cabeza = null;
            return;
        }

        Nodo ultimo = cabeza.ant;
        Nodo nuevoUltimo = ultimo.ant;

        nuevoUltimo.sig = cabeza;
        cabeza.ant = nuevoUltimo;
    }

    // ============================================
    // ELIMINAR EN POSICIÓN
    // ============================================
    void eliminarPosicion(int pos){
        if (cabeza == null) return;

        if (pos == 0){
            eliminarInicio();
            return;
        }

        Nodo temp = cabeza;

        for (int i = 0; i < pos && temp.sig != cabeza; i++)
            temp = temp.sig;

        Nodo anterior = temp.ant;
        Nodo siguiente = temp.sig;

        anterior.sig = siguiente;
        siguiente.ant = anterior;

        // Si eliminan la cabeza real
        if (temp == cabeza)
            cabeza = siguiente;
    }

    // ============================================
    // MOSTRAR LISTA
    // ============================================
    void mostrar(){
        if (cabeza == null){
            System.out.println("Lista vacía");
            return;
        }

        Nodo temp = cabeza;

        do {
            System.out.print(temp.dato + " <-> ");
            temp = temp.sig;
        } while (temp != cabeza);

        System.out.println("(regresa)");
    }

    // ============================================
    // MAIN CON MENÚ
    // ============================================
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        listaCirculardoble lista = new listaCirculardoble();

        int opcion;

        do {
            System.out.println("\n=== MENÚ LISTA CIRCULAR DOBLE ===");
            System.out.println("1. Insertar al inicio");
            System.out.println("2. Insertar al final");
            System.out.println("3. Insertar en posición");
            System.out.println("4. Eliminar al inicio");
            System.out.println("5. Eliminar al final");
            System.out.println("6. Eliminar en posición");
            System.out.println("7. Mostrar lista");
            System.out.println("8. Salir");
            System.out.print("Opción: ");
            opcion = sc.nextInt();

            switch(opcion){
                case 1:
                    System.out.print("Dato: ");
                    lista.insertarInicio(sc.nextInt());
                    break;

                case 2:
                    System.out.print("Dato: ");
                    lista.insertarFinal(sc.nextInt());
                    break;

                case 3:
                    System.out.print("Dato: ");
                    int datoPos = sc.nextInt();
                    System.out.print("Posición: ");
                    int pos = sc.nextInt();
                    lista.insertarPosicion(datoPos, pos);
                    break;

                case 4:
                    lista.eliminarInicio();
                    break;

                case 5:
                    lista.eliminarFinal();
                    break;

                case 6:
                    System.out.print("Posición a eliminar: ");
                    lista.eliminarPosicion(sc.nextInt());
                    break;

                case 7:
                    lista.mostrar();
                    break;

                case 8:
                    System.out.println("Saliendo...");
                    break;

                default:
                    System.out.println("Opción no válida");
            }

        } while (opcion != 8);

        sc.close();
    }
}
