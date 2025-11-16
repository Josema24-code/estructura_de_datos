using System;

class Nodo {
    public int dato;
    public Nodo sig, ant;
    public Nodo(int d){ dato = d; sig = ant = null; }
}

class ListaCircularDoble {
    Nodo cabeza = null;

    // (métodos: InsertarInicio, InsertarFinal, InsertarPosicion, EliminarInicio, EliminarFinal, EliminarPosicion, Mostrar)
    public void InsertarInicio(int dato){
        Nodo nuevo = new Nodo(dato);
        if(cabeza == null){ cabeza = nuevo; nuevo.sig = nuevo; nuevo.ant = nuevo; return; }
        Nodo ultimo = cabeza.ant;
        nuevo.sig = cabeza; nuevo.ant = ultimo;
        ultimo.sig = nuevo; cabeza.ant = nuevo;
        cabeza = nuevo;
    }

    public void InsertarFinal(int dato){
        Nodo nuevo = new Nodo(dato);
        if(cabeza == null){ cabeza = nuevo; nuevo.sig = nuevo; nuevo.ant = nuevo; return; }
        Nodo ultimo = cabeza.ant;
        ultimo.sig = nuevo; nuevo.ant = ultimo;
        nuevo.sig = cabeza; cabeza.ant = nuevo;
    }

    public void InsertarPosicion(int dato, int pos){
        if(pos == 0){ InsertarInicio(dato); return; }
        if(cabeza == null){ Console.WriteLine("Lista vacía"); return; }
        Nodo temp = cabeza;
        for(int i=0; i<pos-1 && temp.sig != cabeza; i++) temp = temp.sig;
        Nodo nuevo = new Nodo(dato);
        Nodo siguiente = temp.sig;
        nuevo.sig = siguiente; nuevo.ant = temp;
        temp.sig = nuevo; siguiente.ant = nuevo;
    }

    public void EliminarInicio(){
        if(cabeza == null) return;
        if(cabeza.sig == cabeza){ cabeza = null; return; }
        Nodo ultimo = cabeza.ant;
        cabeza = cabeza.sig;
        cabeza.ant = ultimo;
        ultimo.sig = cabeza;
    }

    public void EliminarFinal(){
        if(cabeza == null) return;
        if(cabeza.sig == cabeza){ cabeza = null; return; }
        Nodo ultimo = cabeza.ant;
        Nodo nuevoUltimo = ultimo.ant;
        nuevoUltimo.sig = cabeza; cabeza.ant = nuevoUltimo;
    }

    public void EliminarPosicion(int pos){
        if(cabeza == null) return;
        if(pos == 0){ EliminarInicio(); return; }
        Nodo temp = cabeza;
        for(int i=0; i<pos && temp.sig != cabeza; i++) temp = temp.sig;
        Nodo anterior = temp.ant; Nodo siguiente = temp.sig;
        anterior.sig = siguiente; siguiente.ant = anterior;
        if(temp == cabeza) cabeza = siguiente;
    }

    public void Mostrar(){
        if(cabeza == null){ Console.WriteLine("Lista vacía"); return; }
        Nodo temp = cabeza;
        do{
            Console.Write(temp.dato + " <-> ");
            temp = temp.sig;
        } while(temp != cabeza);
        Console.WriteLine("(regresa)");
    }

    static void Main(){
        ListaCircularDoble lista = new ListaCircularDoble();
        int opcion;
        do {
            Console.WriteLine("\n=== MENÚ LISTA CIRCULAR DOBLE (C#) ===");
            Console.WriteLine("1. Insertar al inicio\n2. Insertar al final\n3. Insertar en posición");
            Console.WriteLine("4. Eliminar al inicio\n5. Eliminar al final\n6. Eliminar en posición");
            Console.WriteLine("7. Mostrar lista\n8. Salir");
            Console.Write("Opción: ");
            if(!int.TryParse(Console.ReadLine(), out opcion)){ Console.WriteLine("Entrada inválida"); continue; }

            int dato, pos;
            switch(opcion){
                case 1:
                    Console.Write("Dato: "); dato = int.Parse(Console.ReadLine());
                    lista.InsertarInicio(dato);
                    break;
                case 2:
                    Console.Write("Dato: "); dato = int.Parse(Console.ReadLine());
                    lista.InsertarFinal(dato);
                    break;
                case 3:
                    Console.Write("Dato: "); dato = int.Parse(Console.ReadLine());
                    Console.Write("Posición: "); pos = int.Parse(Console.ReadLine());
                    lista.InsertarPosicion(dato, pos);
                    break;
                case 4:
                    lista.EliminarInicio();
                    break;
                case 5:
                    lista.EliminarFinal();
                    break;
                case 6:
                    Console.Write("Posición a eliminar: "); pos = int.Parse(Console.ReadLine());
                    lista.EliminarPosicion(pos);
                    break;
                case 7:
                    lista.Mostrar();
                    break;
                case 8:
                    Console.WriteLine("Saliendo...");
                    break;
                default:
                    Console.WriteLine("Opción no válida");
                    break;
            }
        } while(opcion != 8);
    }
}
