package estructura_de_datos.listadobleEnlazada;

import java.util.Scanner;

class Node {
    int data;
    Node next, prev;
    Node(int d){ data=d; next=prev=null; }
}

public class doble {
    static Node head = null;
    static Scanner sc = new Scanner(System.in);

    static void insertBegin(int v){
        Node n = new Node(v);
        n.next = head;
        if (head != null) head.prev = n;
        head = n;
        System.out.println("Nodo insertado");
    }

    static void insertLast(int v){
        Node n = new Node(v);
        if (head==null){ head = n; System.out.println("Nodo insertado"); return; }
        Node t = head;
        while (t.next!=null) t = t.next;
        t.next = n; n.prev = t;
        System.out.println("Nodo insertado");
    }

    static void insertAfterPos(int pos, int v){
        Node t = head;
        for (int i=0;i<pos;i++){
            if (t==null){ System.out.println("No se puede insertar"); return; }
            t = t.next;
        }
        if (t==null){ System.out.println("No se puede insertar"); return; }
        Node n = new Node(v);
        n.next = t.next; n.prev = t;
        if (t.next!=null) t.next.prev = n;
        t.next = n;
        System.out.println("Nodo insertado");
    }

    static void deleteBegin(){
        if (head==null){ System.out.println("Lista vacía"); return; }
        head = head.next;
        if (head!=null) head.prev = null;
        System.out.println("Nodo eliminado");
    }

    static void deleteLast(){
        if (head==null){ System.out.println("Lista vacía"); return; }
        if (head.next==null){ head=null; System.out.println("Nodo eliminado"); return; }
        Node t = head;
        while (t.next!=null) t = t.next;
        t.prev.next = null;
        System.out.println("Nodo eliminado");
    }

    static void deletePos(int pos){
        if (head==null){ System.out.println("Lista vacía"); return; }
        Node t = head;
        for (int i=0;i<pos;i++){
            t = t.next;
            if (t==null){ System.out.println("No se puede eliminar"); return; }
        }
        if (t.prev!=null) t.prev.next = t.next; else head = t.next;
        if (t.next!=null) t.next.prev = t.prev;
        System.out.println("Nodo eliminado");
    }

    static void displayForward(){
        if (head==null){ System.out.println("Lista vacía"); return; }
        Node t = head;
        while (t!=null){ System.out.print(t.data + "->"); t = t.next; }
        System.out.println("NULL");
    }

    static void displayBackward(){
        if (head==null){ System.out.println("Lista vacía"); return; }
        Node t = head;
        while (t.next!=null) t = t.next;
        while (t!=null){ System.out.print(t.data + "->"); t = t.prev; }
        System.out.println("NULL");
    }

    static void search(int v){
        Node t = head; int pos=0;
        while (t!=null){
            if (t.data==v){ System.out.println("Encontrado en " + pos); return; }
            t = t.next; pos++;
        }
        System.out.println("No encontrado");
    }

    public static void main(String[] args){
        int opt=0;
        while (opt!=10){
            System.out.println("\n1-InsBeg 2-InsLast 3-InsAfterPos\n4-DelBeg 5-DelLast 6-DelPos\n7-DispFwd 8-DispBwd 9-Search 10-Exit");
            opt = sc.nextInt();
            int x,p;
            switch(opt){
                case 1: x=sc.nextInt(); insertBegin(x); break;
                case 2: x=sc.nextInt(); insertLast(x); break;
                case 3: p=sc.nextInt(); x=sc.nextInt(); insertAfterPos(p,x); break;
                case 4: deleteBegin(); break;
                case 5: deleteLast(); break;
                case 6: p=sc.nextInt(); deletePos(p); break;
                case 7: displayForward(); break;
                case 8: displayBackward(); break;
                case 9: x=sc.nextInt(); search(x); break;
                case 10: System.out.println("Saliendo"); break;
                default: System.out.println("Opción inválida");
            }
        }
    }
}
