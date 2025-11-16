class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

head = None

def insert_begin(val):
    global head
    n = Node(val)
    n.next = head
    if head: head.prev = n
    head = n
    print("Nodo insertado")

def insert_last(val):
    global head
    n = Node(val)
    if not head:
        head = n
        print("Nodo insertado"); return
    t = head
    while t.next: t = t.next
    t.next = n; n.prev = t
    print("Nodo insertado")

def insert_after_pos(pos, val):
    global head
    t = head
    for _ in range(pos):
        if not t:
            print("No se puede insertar"); return
        t = t.next
    if not t:
        print("No se puede insertar"); return
    n = Node(val)
    n.next = t.next; n.prev = t
    if t.next: t.next.prev = n
    t.next = n
    print("Nodo insertado")

def delete_begin():
    global head
    if not head:
        print("Lista vacía"); return
    head = head.next
    if head: head.prev = None
    print("Nodo eliminado")

def delete_last():
    global head
    if not head:
        print("Lista vacía"); return
    if not head.next:
        head = None; print("Nodo eliminado"); return
    t = head
    while t.next: t = t.next
    t.prev.next = None
    print("Nodo eliminado")

def delete_pos(pos):
    global head
    if not head:
        print("Lista vacía"); return
    t = head
    for _ in range(pos):
        t = t.next
        if not t:
            print("No se puede eliminar"); return
    if t.prev: t.prev.next = t.next
    else: head = t.next
    if t.next: t.next.prev = t.prev
    print("Nodo eliminado")

def display_forward():
    if not head:
        print("Lista vacía"); return
    t = head
    while t:
        print(f"{t.data}->", end="")
        t = t.next
    print("NULL")

def display_backward():
    if not head:
        print("Lista vacía"); return
    t = head
    while t.next: t = t.next
    while t:
        print(f"{t.data}->", end="")
        t = t.prev
    print("NULL")

def search(val):
    t = head; pos = 0
    while t:
        if t.data == val:
            print(f"Encontrado en {pos}"); return
        t = t.next; pos += 1
    print("No encontrado")

# menú usando if/elif (compatible con cualquier Python 3.x)
def menu():
    choice = 0
    while choice != 10:
        print("""
1-InsertBegin 2-InsertLast 3-InsertAfterPos
4-DelBegin 5-DelLast 6-DelPos
7-DispFwd 8-DispBwd 9-Search 10-Exit
""")
        try:
            choice = int(input("Choice: "))
        except:
            print("Entrada inválida"); continue

        if choice == 1:
            insert_begin(int(input("val: ")))
        elif choice == 2:
            insert_last(int(input("val: ")))
        elif choice == 3:
            insert_after_pos(int(input("pos: ")), int(input("val: ")))
        elif choice == 4:
            delete_begin()
        elif choice == 5:
            delete_last()
        elif choice == 6:
            delete_pos(int(input("pos: ")))
        elif choice == 7:
            display_forward()
        elif choice == 8:
            display_backward()
        elif choice == 9:
            search(int(input("val: ")))
        elif choice == 10:
            print("Saliendo...")
        else:
            print("Opción no válida")

if __name__ == "__main__":
    menu()
