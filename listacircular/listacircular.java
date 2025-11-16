package estructura_de_datos.listacircular;

import java.util.Scanner;

class Nodo {
    int dato;
    Nodo sig;

    Nodo(int d){
        dato = d;
        sig = null;
    }
}

public class listacircular {
    Nodo cabeza = null;

    // ------------------------------
    // INSERTAR AL INICIO
    // ------------------------------
    void insertarInicio(int dato){
        Nodo nuevo = new Nodo(dato);
        if (cabeza == null){
            nuevo.sig = nuevo;
            cabeza = nuevo;
            return;
        }
        Nodo temp = cabeza;
        while(temp.sig != cabeza) temp = temp.sig;

        nuevo.sig = cabeza;
        temp.sig = nuevo;
        cabeza = nuevo;
    }

    // ------------------------------
    // INSERTAR AL FINAL
    // ------------------------------
    void insertarFinal(int dato){
        Nodo nuevo = new Nodo(dato);
        if(cabeza == null){
            nuevo.sig = nuevo;
            cabeza = nuevo;
            return;
        }
        Nodo temp = cabeza;
        while(temp.sig != cabeza) temp = temp.sig;

        temp.sig = nuevo;
        nuevo.sig = cabeza;
    }

    // ------------------------------
    // INSERTAR EN POSICIÓN
    // ------------------------------
    void insertarPosicion(int dato, int pos){
        if(pos == 0){
            insertarInicio(dato);
            return;
        }
        if (cabeza == null) {
            System.out.println("La lista está vacía");
            return;
        }

        Nodo nuevo = new Nodo(dato);
        Nodo temp = cabeza;

        for(int i = 1; i < pos && temp.sig != cabeza; i++)
            temp = temp.sig;

        nuevo.sig = temp.sig;
        temp.sig = nuevo;
    }

    // ------------------------------
    // ELIMINAR AL INICIO
    // ------------------------------
    void eliminarInicio(){
        if(cabeza == null) return;

        if(cabeza.sig == cabeza){
            cabeza = null;
            return;
        }

        Nodo fin = cabeza;
        while(fin.sig != cabeza) fin = fin.sig;

        cabeza = cabeza.sig;
        fin.sig = cabeza;
    }

    // ------------------------------
    // ELIMINAR AL FINAL
    // ------------------------------
    void eliminarFinal(){
        if(cabeza == null) return;

        if(cabeza.sig == cabeza){
            cabeza = null;
            return;
        }

        Nodo temp = cabeza;
        Nodo ant = null;

        while(temp.sig != cabeza){
            ant = temp;
            temp = temp.sig;
        }

        ant.sig = cabeza;
    }

    // ------------------------------
    // ELIMINAR EN POSICIÓN
    // ------------------------------
    void eliminarPosicion(int pos){
        if(cabeza == null) return;

        if(pos == 0){
            eliminarInicio();
            return;
        }

        Nodo temp = cabeza;
        Nodo ant = null;

        for(int i = 0; i < pos && temp.sig != cabeza; i++){
            ant = temp;
            temp = temp.sig;
        }

        ant.sig = temp.sig;
    }

    // ------------------------------
    // MOSTRAR LISTA
    // ------------------------------
    void mostrar(){
        if(cabeza == null){
            System.out.println("Lista vacía");
            return;
        }

        Nodo temp = cabeza;
        do {
            System.out.print(temp.dato + " -> ");
            temp = temp.sig;
        } while(temp != cabeza);

        System.out.println("(regresa)");
    }

    // ------------------------------
    // MAIN
    // ------------------------------
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        listacircular lista = new listacircular(); // ← Ahora accesible para todos los cases

        int opcion;

        do {
            System.out.println("\n=== MENÚ LISTA CIRCULAR ===");
            System.out.println("1. Insertar al inicio");
            System.out.println("2. Insertar al final");
            System.out.println("3. Insertar en posición");
            System.out.println("4. Eliminar al inicio");
            System.out.println("5. Eliminar al final");
            System.out.println("6. Eliminar en posición");
            System.out.println("7. Mostrar lista");
            System.out.println("8. Salir");
            System.out.print("Elige una opción: ");
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

        } while(opcion != 8);

        sc.close();
    }
}
