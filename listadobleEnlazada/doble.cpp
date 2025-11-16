#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int v): data(v), next(nullptr), prev(nullptr) {}
};

Node* head = nullptr;

void insert_begin(int val) {
    Node* n = new Node(val);
    n->next = head;
    if (head) head->prev = n;
    head = n;
    cout<<"Nodo insertado\n";
}

void insert_last(int val) {
    Node* n = new Node(val);
    if (!head) { head = n; cout<<"Nodo insertado\n"; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
    cout<<"Nodo insertado\n";
}

void insert_after_pos(int pos, int val) {
    if (!head && pos>0) { cout<<"No se puede insertar\n"; return; }
    Node* t = head;
    for (int i=0;i<pos;i++) {
        if (!t) { cout<<"No se puede insertar\n"; return; }
        t = t->next;
    }
    if (!t) { cout<<"No se puede insertar\n"; return; }
    Node* n = new Node(val);
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    t->next = n;
    cout<<"Nodo insertado\n";
}

void delete_begin() {
    if (!head) { cout<<"Lista vacía\n"; return; }
    Node* t = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete t;
    cout<<"Nodo eliminado\n";
}

void delete_last() {
    if (!head) { cout<<"Lista vacía\n"; return; }
    if (!head->next) { delete head; head = nullptr; cout<<"Nodo eliminado\n"; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->prev->next = nullptr;
    delete t;
    cout<<"Nodo eliminado\n";
}

void delete_position(int pos) {
    if (!head) { cout<<"Lista vacía\n"; return; }
    Node* t = head;
    for (int i=0;i<pos;i++) {
        t = t->next;
        if (!t) { cout<<"No se puede eliminar\n"; return; }
    }
    if (t->prev) t->prev->next = t->next;
    else head = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
    cout<<"Nodo eliminado\n";
}

void display_forward() {
    if (!head) { cout<<"Lista vacía\n"; return; }
    Node* t = head;
    while (t) { cout<<t->data<<"->"; t = t->next; }
    cout<<"NULL\n";
}

void display_backward() {
    if (!head) { cout<<"Lista vacía\n"; return; }
    Node* t = head;
    while (t->next) t = t->next;
    while (t) { cout<<t->data<<"->"; t = t->prev; }
    cout<<"NULL\n";
}

void search_val(int v) {
    Node* t = head; int pos = 0;
    while (t) {
        if (t->data==v) { cout<<"Encontrado en "<<pos<<"\n"; return; }
        t = t->next; pos++;
    }
    cout<<"No encontrado\n";
}

int main(){
    int opt=0;
    while (opt!=10) {
        cout<<"\n1-insert begin 2-insert last 3-insert after pos\n4-delete begin 5-delete last 6-delete pos\n7-display fwd 8-display bwd 9-search 10-exit\nChoice: ";
        cin>>opt;
        int x,p;
        switch(opt) {
            case 1: cin>>x; insert_begin(x); break;
            case 2: cin>>x; insert_last(x); break;
            case 3: cout<<"pos val: "; cin>>p>>x; insert_after_pos(p,x); break;
            case 4: delete_begin(); break;
            case 5: delete_last(); break;
            case 6: cout<<"pos: "; cin>>p; delete_position(p); break;
            case 7: display_forward(); break;
            case 8: display_backward(); break;
            case 9: cout<<"val: "; cin>>x; search_val(x); break;
            case 10: cout<<"Saliendo\n"; break;
            default: cout<<"Opción inválida\n";
        }
    }
    return 0;
}
