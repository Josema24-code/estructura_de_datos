MAX_SIZE = 100
stack = []


def push(item):
    if len(stack) == MAX_SIZE:
        print("Stack Overflow")
        return
    stack.append(item)
    print(f"Elemento {item} insertado.")

def pop():
    if len(stack) == 0:
        print("Stack Underflow")
        return None
    return stack.pop()

def peek():
    if len(stack) == 0:
        print("Pila vacía")
        return None
    return stack[-1]

def isEmpty():
    return len(stack) == 0

def isFull():
    return len(stack) == MAX_SIZE


opcion = 0
while opcion != 6:
    print("\n--- MENU PILA (Python) ---")
    print("1. Push (Insertar)")
    print("2. Pop (Eliminar)")
    print("3. Peek (Ver Tope)")
    print("4. isEmpty (¿Vacía?)")
    print("5. isFull (¿Llena?)")
    print("6. Salir")

    try:
        opcion = int(input("Elige una opción: "))
    except ValueError:
        print("Opción inválida")
        continue

    if opcion == 1:
        try:
            valor = int(input("Ingresa un valor: "))
            push(valor)
        except ValueError:
            print("Valor inválido. Debe ser entero.")
    elif opcion == 2:
        resultado = pop()
        if resultado is not None:
            print("Eliminado:", resultado)
    elif opcion == 3:
        resultado = peek()
        if resultado is not None:
            print("Tope:", resultado)
    elif opcion == 4:
        print("Pila vacía" if isEmpty() else "No está vacía")
    elif opcion == 5:
        print("Pila llena" if isFull() else "No está llena")
    elif opcion == 6:
        print("Saliendo...")
    else:
        print("Opción inválida")
