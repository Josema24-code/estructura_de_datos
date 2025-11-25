class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.sig = None

frente = None
fin = None

def insertar():
    global frente, fin
    elem = int(input("\nIngrese el elemento: "))
    nuevo = Nodo(elem)

    if frente is None:
        frente = fin = nuevo
    else:
        fin.sig = nuevo
        fin = nuevo
    print("Elemento insertado correctamente.")

def eliminar():
    global frente, fin
    if frente is None:
        print("\nSUBDESBORDAMIENTO (UNDERFLOW)")
        return

    elem = frente.dato
    frente = frente.sig
    if frente is None:
        fin = None
    print("\nElemento eliminado:", elem)

def mostrar():
    if frente is None:
        print("\nLa cola está vacía.")
        return

    print("\nElementos en la cola:")
    aux = frente
    while aux:
        print(aux.dato)
        aux = aux.sig

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
    elif op == 4: print("\nSaliendo...")
    else: print("\nOpción inválida.")
