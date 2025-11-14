class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

head = None

def begin_insert():
    global head
    item = int(input("Ingrese valor: "))
    node = Node(item)
    node.next = head
    head = node
    print("Nodo insertado")

def last_insert():
    global head
    item = int(input("Ingrese valor: "))
    node = Node(item)

    if head is None:
        head = node
    else:
        temp = head
        while temp.next:
            temp = temp.next
        temp.next = node
    print("Nodo insertado")

def random_insert():
    global head
    item = int(input("Ingrese valor: "))
    loc = int(input("Ingrese posición: "))

    temp = head
    for _ in range(loc):
        if temp is None:
            print("No se puede insertar")
            return
        temp = temp.next

    node = Node(item)
    node.next = temp.next
    temp.next = node
    print("Nodo insertado")

def begin_delete():
    global head
    if head is None:
        print("Lista vacía")
        return
    head = head.next
    print("Nodo eliminado")

def last_delete():
    global head
    if head is None:
        print("Lista vacía")
        return
    if head.next is None:
        head = None
        print("Nodo eliminado")
        return

    temp = head
    prev = None
    while temp.next:
        prev = temp
        temp = temp.next
    prev.next = None
    print("Nodo eliminado")

def random_delete():
    global head
    loc = int(input("Ingrese posición: "))

    if head is None:
        print("Lista vacía")
        return
    if loc == 0:
        head = head.next
        print("Nodo eliminado")
        return

    temp = head
    prev = None
    for _ in range(loc):
        prev = temp
        temp = temp.next
        if temp is None:
            print("No se puede eliminar")
            return

    prev.next = temp.next
    print("Nodo eliminado")

def display():
    if head is None:
        print("Lista vacía")
        return
    temp = head
    while temp:
        print(f"{temp.data}->", end="")
        temp = temp.next
    print("NULL")

def search():
    item = int(input("Ingrese valor a buscar: "))
    temp = head
    pos = 0
    while temp:
        if temp.data == item:
            print(f"Encontrado en posición {pos}")
            return
        temp = temp.next
        pos += 1
    print("No encontrado")

# menú compatible con Python <3.10
def menu():
    choice = 0
    while choice != 9:
        print("""
******* MENU *******
1. Insert beginning
2. Insert last
3. Insert after position
4. Delete beginning
5. Delete last
6. Delete position
7. Display forward
8. Display backward
9. Exit
""")
        try:
            choice = int(input("Choice: "))
        except:
            print("Entrada no válida")
            continue

        if choice == 1:
            begin_insert()
        elif choice == 2:
            last_insert()
        elif choice == 3:
            insert_after_position()
        elif choice == 4:
            begin_delete()
        elif choice == 5:
            last_delete()
        elif choice == 6:
            delete_position()
        elif choice == 7:
            display_forward()
        elif choice == 8:
            display_backward()
        elif choice == 9:
            print("Saliendo...")
        else:
            print("Opción no válida")
