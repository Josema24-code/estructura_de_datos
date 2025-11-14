#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    struct node  *next;
};

struct node *head;

void begininsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main()
{
    int choice = 0;
    while (choice != 9) {
        cout << "\n*********Main Menu*********\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at last\n";
        cout << "3. Insert at random location\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from last\n";
        cout << "6. Delete from random location\n";
        cout << "7. Display\n";
        cout << "8. Search\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                begininsert();
                break;
            case 2:
                lastinsert();
                break;
            case 3:
                randominsert();
                break;
            case 4:
                begin_delete();
                break;
            case 5:
                last_delete();
                break;
            case 6:
                random_delete();
                break;
            case 7:
                display();
                break;
            case 8:
                search();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}

void begininsert()
{

    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        cout << "OVERFLOW\n";
    }
    else {
        cout << "\ningrese valor:\n ";
        cin >> item;

        ptr->data = item;
        ptr->next = head;
        head = ptr;
        cout << "\nNodo insertado";
    }
}

void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        cout << "OVERFLOW\n";
    }
    else {
        cout << "\ningrese valor:\n ";
        cin >> item;
        ptr->data = item;
        if (head == NULL) {
            ptr->next = NULL;
            head = ptr;
            cout << "\nNodo insertado";
        }
        else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            cout << "\nNodo insertado";
        }
    }
}

void randominsert()
{
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        cout << "OVERFLOW\n";
    }
    else {
        cout << "\ningrese valor:\n ";
        cin >> item;
        ptr->data = item;
        cout << "\ningrese la posicion despues de la cual insertar el nuevo nodo: \n";
        cin >> loc;
        temp = head;
        for (i = 0; i < loc; i++) {
            if (temp == NULL) {
                cout << "\nno se puede insertar\n";
                return;
            }
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
        cout << "\nNodo insertado";
    }
}

void begin_delete()
{
    struct node *ptr;
    if (head == NULL) {
        cout << "La lista esta vacia\n";
    }
    else {
        ptr = head;
        head = ptr->next;
        delete ptr;
        cout << "\nNodo eliminado from the beginning\n";
    }
}

void last_delete()
{
    struct node *ptr, *ptr1;
    if (head == NULL) {
        cout << "La lista esta vacia\n";
    }
    else if (head->next == NULL) {
        head = NULL;
        delete head;
        cout << "\nNodo eliminado from the last\n";
    }
    else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        delete ptr;
        cout << "\nNodo eliminado from the last\n";
    }
}

void random_delete()
{
    struct node *ptr, *ptr1;
    int loc, i;
    cout << "\ningrese la posicion del nodo a eliminar: \n";
    cin >> loc;
    if (head == NULL) {
        cout << "La lista esta vacia\n";
    }
    else if (loc == 0) {
        ptr = head;
        head = ptr->next;
        delete ptr;
        cout << "\nNodo eliminado from location " << loc << "\n";
    }
    else {
        ptr = head;
        for (i = 0; i < loc; i++) {
            ptr1 = ptr;
            ptr = ptr->next;
            if (ptr == NULL) {
                cout << "\nno se puede eliminar\n";
                return;
            }
        }
        ptr1->next = ptr->next;
        delete ptr;
        cout << "\nNodo eliminado from location " << loc << "\n";
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL) {
        cout << "La lista esta vacia\n";
    }
    else {
        cout << "\nLos elementos de la lista son: \n";
        while (ptr != NULL) {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }
        cout << "NULL\n";
    }
}

void search()
{
    struct node *ptr;
    int item, i =0 , flag;
    ptr = head;
    if (ptr == NULL) {
        cout << "La lista esta vacia\n"; }
    else {
        cout << "\ningrese el valor a buscar: \n";
        cin >> item;
        while (ptr != NULL) {
            if (ptr->data == item) {
                cout << "Elemento " << item << " encontrado en la posicion " << i << "\n";
                flag = 0;
            }
            else {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1) {
            cout << "Elemento no encontrado en la lista\n";
        }
    }
}