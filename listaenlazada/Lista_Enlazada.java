import java.util.Scanner;

class Node {
    int data;
    Node next;
}

public class Lista_Enlazada {
    static Node head = null;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int choice = 0;

        while (choice != 9) {
            System.out.println("\n******* MENU ********");
            System.out.println("1. Insert beginning");
            System.out.println("2. Insert last");
            System.out.println("3. Insert random");
            System.out.println("4. Delete beginning");
            System.out.println("5. Delete last");
            System.out.println("6. Delete random");
            System.out.println("7. Display");
            System.out.println("8. Search");
            System.out.println("9. Exit");
            System.out.print("Choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1: beginInsert(); break;
                case 2: lastInsert(); break;
                case 3: randomInsert(); break;
                case 4: beginDelete(); break;
                case 5: lastDelete(); break;
                case 6: randomDelete(); break;
                case 7: display(); break;
                case 8: search(); break;
            }
        }
    }

    static void beginInsert() {
        System.out.print("Ingrese valor: ");
        int item = sc.nextInt();

        Node newNode = new Node();
        newNode.data = item;
        newNode.next = head;
        head = newNode;
        System.out.println("Nodo insertado");
    }

    static void lastInsert() {
        System.out.print("Ingrese valor: ");
        int item = sc.nextInt();
        Node newNode = new Node();
        newNode.data = item;

        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null)
                temp = temp.next;
            temp.next = newNode;
        }
        System.out.println("Nodo insertado");
    }

    static void randomInsert() {
        System.out.print("Ingrese valor: ");
        int item = sc.nextInt();
        System.out.print("Ingrese posición: ");
        int loc = sc.nextInt();

        Node temp = head;
        for (int i = 0; i < loc; i++) {
            if (temp == null) {
                System.out.println("No se puede insertar");
                return;
            }
            temp = temp.next;
        }

        Node newNode = new Node();
        newNode.data = item;
        newNode.next = temp.next;
        temp.next = newNode;

        System.out.println("Nodo insertado");
    }

    static void beginDelete() {
        if (head == null) {
            System.out.println("Lista vacía");
            return;
        }
        head = head.next;
        System.out.println("Nodo eliminado");
    }

    static void lastDelete() {
        if (head == null) { System.out.println("Lista vacía"); return; }
        if (head.next == null) { head = null; System.out.println("Nodo eliminado"); return; }

        Node temp = head, prev = null;
        while (temp.next != null) {
            prev = temp;
            temp = temp.next;
        }
        prev.next = null;
        System.out.println("Nodo eliminado");
    }

    static void randomDelete() {
        System.out.print("Ingrese posición: ");
        int loc = sc.nextInt();

        if (head == null) { System.out.println("Lista vacía"); return; }

        if (loc == 0) {
            head = head.next;
            System.out.println("Nodo eliminado");
            return;
        }

        Node temp = head, prev = null;
        for (int i = 0; i < loc; i++) {
            prev = temp;
            temp = temp.next;
            if (temp == null) {
                System.out.println("No se puede eliminar");
                return;
            }
        }

        prev.next = temp.next;
        System.out.println("Nodo eliminado");
    }

    static void display() {
        if (head == null) { System.out.println("Lista vacía"); return; }

        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + "->");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    static void search() {
        System.out.print("Ingrese valor a buscar: ");
        int item = sc.nextInt();

        Node temp = head;
        int pos = 0;
        while (temp != null) {
            if (temp.data == item) {
                System.out.println("Encontrado en posición " + pos);
                return;
            }
            temp = temp.next;
            pos++;
        }
        System.out.println("No encontrado");
    }
}
