class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.sig = None
        self.ant = None

class ListaCircularDoble:
    def __init__(self):
        self.cabeza = None

    def insertar_inicio(self, dato):
        nuevo = Nodo(dato)
        if self.cabeza is None:
            self.cabeza = nuevo
            nuevo.sig = nuevo
            nuevo.ant = nuevo
            return
        ultimo = self.cabeza.ant
        nuevo.sig = self.cabeza
        nuevo.ant = ultimo
        ultimo.sig = nuevo
        self.cabeza.ant = nuevo
        self.cabeza = nuevo

    def insertar_final(self, dato):
        nuevo = Nodo(dato)
        if self.cabeza is None:
            self.cabeza = nuevo
            nuevo.sig = nuevo
            nuevo.ant = nuevo
            return
        ultimo = self.cabeza.ant
        ultimo.sig = nuevo
        nuevo.ant = ultimo
        nuevo.sig = self.cabeza
        self.cabeza.ant = nuevo

    def insertar_posicion(self, dato, pos):
        if pos == 0:
            self.insertar_inicio(dato)
            return
        if self.cabeza is None:
            print("Lista vacía")
            return
        temp = self.cabeza
        for _ in range(pos - 1):
            if temp.sig == self.cabeza: break
            temp = temp.sig
        nuevo = Nodo(dato)
        siguiente = temp.sig
        nuevo.sig = siguiente
        nuevo.ant = temp
        temp.sig = nuevo
        siguiente.ant = nuevo

    def eliminar_inicio(self):
        if self.cabeza is None: return
        if self.cabeza.sig == self.cabeza:
            self.cabeza = None
            return
        ultimo = self.cabeza.ant
        self.cabeza = self.cabeza.sig
        self.cabeza.ant = ultimo
        ultimo.sig = self.cabeza

    def eliminar_final(self):
        if self.cabeza is None: return
        if self.cabeza.sig == self.cabeza:
            self.cabeza = None
            return
        ultimo = self.cabeza.ant
        nuevo_ultimo = ultimo.ant
        nuevo_ultimo.sig = self.cabeza
        self.cabeza.ant = nuevo_ultimo

    def eliminar_posicion(self, pos):
        if self.cabeza is None: return
        if pos == 0:
            self.eliminar_inicio()
            return
        temp = self.cabeza
        for _ in range(pos):
            temp = temp.sig
            if temp == self.cabeza: return
        anterior = temp.ant
        siguiente = temp.sig
        anterior.sig = siguiente
        siguiente.ant = anterior
        if temp == self.cabeza:
            self.cabeza = siguiente

    def mostrar(self):
        if self.cabeza is None:
            print("Lista vacía")
            return
        temp = self.cabeza
        while True:
            print(f"{temp.dato} <-> ", end="")
            temp = temp.sig
            if temp == self.cabeza: break
        print("(regresa)")

if __name__ == "__main__":
    lista = ListaCircularDoble()
    while True:
        print("\n=== MENÚ LISTA CIRCULAR DOBLE (Python) ===")
        print("1. Insertar al inicio\n2. Insertar al final\n3. Insertar en posición")
        print("4. Eliminar al inicio\n5. Eliminar al final\n6. Eliminar en posición")
        print("7. Mostrar lista\n8. Salir")
        opcion = input("Opción: ")
        if not opcion.isdigit():
            print("Entrada inválida"); continue
        opcion = int(opcion)

        if opcion == 1:
            dato = int(input("Dato: "))
            lista.insertar_inicio(dato)
        elif opcion == 2:
            dato = int(input("Dato: "))
            lista.insertar_final(dato)
        elif opcion == 3:
            dato = int(input("Dato: "))
            pos = int(input("Posición: "))
            lista.insertar_posicion(dato, pos)
        elif opcion == 4:
            lista.eliminar_inicio()
        elif opcion == 5:
            lista.eliminar_final()
        elif opcion == 6:
            pos = int(input("Posición a eliminar: "))
            lista.eliminar_posicion(pos)
        elif opcion == 7:
            lista.mostrar()
        elif opcion == 8:
            print("Saliendo...")
            break
        else:
            print("Opción no válida")
