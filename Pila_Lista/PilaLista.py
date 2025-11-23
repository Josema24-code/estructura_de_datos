class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

top = None

def push(item):
    global top
    newNode = Node(item)
    newNode.next = top
    top = newNode
    print(f"Elemento {item} insertado.")

def pop():
    global top
    if top is None:
        print("Stack Underflow")
        return None
    value = top.data
    top = top.next
    return value

def peek():
    if top is None:
        print("Pila vacía")
        return None
    return top.data

def isEmpty():
    return top is None

# ------- MENÚ -------
opcion = 0
while opcion != 5:
    print("\n--- MENU PILA (Python Linked List) ---")
    print("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Salir")
    try:
        opcion = int(input("Elige: "))
    except ValueError:
        print("Opción inválida"); continue

    if opcion == 1:
        try:
            valor = int(input("Ingresa un valor: "))
            push(valor)
        except ValueError:
            print("Debe ser número entero.")
    elif opcion == 2:
        r = pop()
        if r is not None: print("Eliminado:", r)
    elif opcion == 3:
        r = peek()
        if r is not None: print("Tope:", r)
    elif opcion == 4:
        print("Pila vacía" if isEmpty() else "No está vacía")
    elif opcion == 5:
        print("Saliendo...")
    else:
        print("Opción inválida")
