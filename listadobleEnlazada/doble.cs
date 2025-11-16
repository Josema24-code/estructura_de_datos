using System;

class Node {
    public int Data;
    public Node Next;
    public Node Prev;
    public Node(int d) { Data = d; Next = Prev = null; }
}

class Program {
    static Node head = null;

    static void InsertBegin(int v) {
        var n = new Node(v);
        n.Next = head;
        if (head != null) head.Prev = n;
        head = n;
        Console.WriteLine("Nodo insertado");
    }

    static void InsertLast(int v) {
        var n = new Node(v);
        if (head == null) { head = n; Console.WriteLine("Nodo insertado"); return; }
        var t = head;
        while (t.Next != null) t = t.Next;
        t.Next = n; n.Prev = t;
        Console.WriteLine("Nodo insertado");
    }

    static void InsertAfterPos(int pos, int v) {
        var t = head;
        for (int i=0;i<pos;i++) {
            if (t==null) { Console.WriteLine("No se puede insertar"); return; }
            t = t.Next;
        }
        if (t==null) { Console.WriteLine("No se puede insertar"); return; }
        var n = new Node(v) { Next = t.Next, Prev = t };
        if (t.Next != null) t.Next.Prev = n;
        t.Next = n;
        Console.WriteLine("Nodo insertado");
    }

    static void DeleteBegin() {
        if (head==null) { Console.WriteLine("Lista vacía"); return; }
        head = head.Next;
        if (head!=null) head.Prev = null;
        Console.WriteLine("Nodo eliminado");
    }

    static void DeleteLast() {
        if (head==null) { Console.WriteLine("Lista vacía"); return; }
        if (head.Next==null) { head = null; Console.WriteLine("Nodo eliminado"); return; }
        var t = head;
        while (t.Next!=null) t = t.Next;
        t.Prev.Next = null;
        Console.WriteLine("Nodo eliminado");
    }

    static void DeletePos(int pos) {
        if (head==null) { Console.WriteLine("Lista vacía"); return; }
        var t = head;
        for (int i=0;i<pos;i++) {
            t = t.Next;
            if (t==null) { Console.WriteLine("No se puede eliminar"); return; }
        }
        if (t.Prev!=null) t.Prev.Next = t.Next; else head = t.Next;
        if (t.Next!=null) t.Next.Prev = t.Prev;
        Console.WriteLine("Nodo eliminado");
    }

    static void DisplayForward() {
        if (head==null) { Console.WriteLine("Lista vacía"); return; }
        var t = head;
        while (t!=null) { Console.Write(t.Data + "->"); t = t.Next; }
        Console.WriteLine("NULL");
    }

    static void DisplayBackward() {
        if (head==null) { Console.WriteLine("Lista vacía"); return; }
        var t = head;
        while (t.Next!=null) t = t.Next;
        while (t!=null) { Console.Write(t.Data + "->"); t = t.Prev; }
        Console.WriteLine("NULL");
    }

    static void Search(int v) {
        var t = head; int pos=0;
        while (t!=null) {
            if (t.Data==v) { Console.WriteLine("Encontrado en " + pos); return; }
            t = t.Next; pos++;
        }
        Console.WriteLine("No encontrado");
    }

    static void Main() {
        int opt=0;
        while (opt!=10) {
            Console.WriteLine("\n1-InsertBegin 2-InsertLast 3-InsertAfterPos\n4-DelBegin 5-DelLast 6-DelPos\n7-DispFwd 8-DispBwd 9-Search 10-Exit");
            if (!int.TryParse(Console.ReadLine(), out opt)) { Console.WriteLine("Entrada inválida"); continue; }
            int x,p;
            switch(opt){
                case 1: x=int.Parse(Console.ReadLine()); InsertBegin(x); break;
                case 2: x=int.Parse(Console.ReadLine()); InsertLast(x); break;
                case 3: Console.Write("pos val: "); p=int.Parse(Console.ReadLine()); x=int.Parse(Console.ReadLine()); InsertAfterPos(p,x); break;
                case 4: DeleteBegin(); break;
                case 5: DeleteLast(); break;
                case 6: Console.Write("pos: "); p=int.Parse(Console.ReadLine()); DeletePos(p); break;
                case 7: DisplayForward(); break;
                case 8: DisplayBackward(); break;
                case 9: Console.Write("val: "); x=int.Parse(Console.ReadLine()); Search(x); break;
                case 10: Console.WriteLine("Saliendo"); break;
                default: Console.WriteLine("Opción inválida"); break;
            }
        }
    }
}
