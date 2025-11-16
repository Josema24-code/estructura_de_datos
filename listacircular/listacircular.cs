using System;

class Nodo {
    public int dato;
    public Nodo sig;

    public Nodo(int d){
        dato = d;
        sig = null;
    }
}

class ListaCircular
{

    Nodo cabeza = null;

    public void InsertarInicio(int dato)
    {
        Nodo nuevo = new Nodo(dato);

        if (cabeza == null)
        {
            nuevo.sig = nuevo;
            cabeza = nuevo;
            return;
        }

        Nodo temp = cabeza;
        while (temp.sig != cabeza) temp = temp.sig;

        nuevo.sig = cabeza;
        temp.sig = nuevo;
        cabeza = nuevo;
    }

    public void InsertarFinal(int dato)
    {
        Nodo nuevo = new Nodo(dato);

        if (cabeza == null)
        {
            nuevo.sig = nuevo;
            cabeza = nuevo;
            return;
        }

        Nodo temp = cabeza;
        while (temp.sig != cabeza) temp = temp.sig;

        temp.sig = nuevo;
        nuevo.sig = cabeza;
    }

    public void InsertarPosicion(int dato, int pos)
    {
        if (pos == 0)
        {
            InsertarInicio(dato);
            return;
        }

        Nodo nuevo = new Nodo(dato);
        Nodo temp = cabeza;

        for (int i = 1; i < pos && temp.sig != cabeza; i++)
            temp = temp.sig;

        nuevo.sig = temp.sig;
        temp.sig = nuevo;
    }

    public void EliminarInicio()
    {
        if (cabeza == null) return;

        if (cabeza.sig == cabeza)
        {
            cabeza = null;
            return;
        }

        Nodo fin = cabeza;
        while (fin.sig != cabeza) fin = fin.sig;

        cabeza = cabeza.sig;
        fin.sig = cabeza;
    }

    public void EliminarFinal()
    {
        if (cabeza == null) return;

        if (cabeza.sig == cabeza)
        {
            cabeza = null;
            return;
        }

        Nodo temp = cabeza;
        Nodo ant = null;

        while (temp.sig != cabeza)
        {
            ant = temp;
            temp = temp.sig;
        }

        ant.sig = cabeza;
    }

    public void EliminarPosicion(int pos)
    {
        if (cabeza == null) return;

        if (pos == 0)
        {
            EliminarInicio();
            return;
        }

        Nodo temp = cabeza;
        Nodo ant = null;

        for (int i = 0; i < pos && temp.sig != cabeza; i++)
        {
            ant = temp;
            temp = temp.sig;
        }

        ant.sig = temp.sig;
    }

    public void Mostrar()
    {
        if (cabeza == null) return;

        Nodo temp = cabeza;
        do
        {
            Console.Write(temp.dato + " -> ");
            temp = temp.sig;
        } while (temp != cabeza);

        Console.WriteLine("(regresa)");
    }
    public static void Main(string[] args)
    {
        seguir = true;
        
        do
        {
            ListaCircular lista = new ListaCircular();
            Console.WriteLine("Lista Circular:");
            Console.WriteLine("Elija una opcion:");
            Console.WriteLine("1. Insertar al inicio");
            Console.WriteLine("2. Insertar al final");
            Console.WriteLine("3. Insertar en posicion");
            Console.WriteLine("4. Eliminar al inicio");
            Console.WriteLine("5. Eliminar al final");
            Console.WriteLine("6. Eliminar en posicion");
            Console.WriteLine("7. Mostrar lista");
            Console.WriteLine("8. Salir");
            int opcion = Convert.ToInt32(Console.ReadLine());
            switch (opcion)
            {
                case 1:
                    insertarInicio();
                    break;
                case 2:
                    insertarFinal();
                    break;
                case 3:
                Console.WriteLine("Ingrese el dato a insertar:");
                    int dato = Convert.ToInt32(Console.ReadLine());
                    Console.WriteLine("Ingrese la posicion:");
                    int pos = Convert.ToInt32(Console.ReadLine());
                    insertarPosicion(dato, pos);
                    break;
                case 4:
                    eliminarInicio();
                    break;
                case 5:
                    eliminarFinal();
                    break;
                case 6:
                    Console.WriteLine("Ingrese la posicion a eliminar:");
                    int posicion = Convert.ToInt32(Console.ReadLine());
                    eliminarPosicion(posicion); 
                    break;
                case 7:
                    mostrarLista();
                    break;
                case 8:
                    seguir = false;
                    break;
                default:
                    Console.WriteLine("Opcion no valida");
                    break;
            }
        } while (seguir);

        
    }
}