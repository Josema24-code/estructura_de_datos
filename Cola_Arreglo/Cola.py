MAXSIZE = 5
queue = [None] * MAXSIZE
front = -1
rear = -1

def insertar():
    global front, rear
    if rear == MAXSIZE - 1:
        print("\nDESBORDAMIENTO (OVERFLOW)")
        return
    
    elem = int(input("\nIngrese el elemento: "))
    
    if front == -1 and rear == -1:
        front = rear = 0
    else:
        rear += 1
    
    queue[rear] = elem
    print("Elemento insertado correctamente.")

def eliminar():
    global front, rear
    if front == -1 or front > rear:
        print("\nSUBDESBORDAMIENTO (UNDERFLOW)")
        return
    
    elem = queue[front]
    if front == rear:
        front = rear = -1
    else:
        front += 1
    
    print("\nElemento eliminado:", elem)

def mostrar():
    if front == -1 or front > rear:
        print("\nLa cola está vacía.")
        return
    
    print("\nElementos en la cola:")
    for i in range(front, rear + 1):
        print(queue[i])

# -------- Menú ---------
op = 0
while op != 4:
    print("\n*************** MENÚ PRINCIPAL ***************")
    print("1. Insertar un elemento")
    print("2. Eliminar un elemento")
    print("3. Mostrar la cola")
    print("4. Salir")
    op = int(input("Ingrese su opción: "))

    if op == 1: insertar()
    elif op == 2: eliminar()
    elif op == 3: mostrar()
    elif op == 4: print("\nSaliendo del programa...")
    else: print("\nOpción inválida. Intente nuevamente.")
