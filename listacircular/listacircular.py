class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.sig = None

class ListaCircular:

    def __init__(self):
        self.cabeza = None

    def insertar_inicio(self, dato):
        nuevo = Nodo(dato)

        if self.cabeza is None:
            nuevo.sig = nuevo
            self.cabeza = nuevo
            return

        temp = self.cabeza
        while temp.sig != self.cabeza:
            temp = temp.sig

        nuevo.sig = self.cabeza
        temp.sig = nuevo
        self.cabeza = nuevo

    def insertar_final(self, dato):
        nuevo = Nodo(dato)

        if self.cabeza is None:
            nuevo.sig = nuevo
            self.cabeza = nuevo
            return

        temp = self.cabeza
        while temp.sig != self.cabeza:
            temp = temp.sig

        temp.sig = nuevo
        nuevo.sig = self.cabeza

    def insertar_posicion(self, dato, pos):
        if pos == 0:
            self.insertar_inicio(dato)
            return

        nuevo = Nodo(dato)
        temp = self.cabeza

        for _ in range(1, pos):
            if temp.sig == self.cabeza:
                break
            temp = temp.sig

        nuevo.sig = temp.sig
        temp.sig = nuevo

    def eliminar_inicio(self):
        if self.cabeza is None:
            return

        temp = self.cabeza

        if temp.sig == temp:
            self.cabeza = None
            return

        fin = self.cabeza
        while fin.sig != self.cabeza:
            fin = fin.sig

        self.cabeza = self.cabeza.sig
        fin.sig = self.cabeza

    def eliminar_final(self):
        if self.cabeza is None:
            return

        temp = self.cabeza

        if temp.sig == temp:
            self.cabeza = None
            return

        ant = None
        while temp.sig != self.cabeza:
            ant = temp
            temp = temp.sig

        ant.sig = self.cabeza

    def eliminar_posicion(self, pos):
        if self.cabeza is None:
            return

        if pos == 0:
            self.eliminar_inicio()
            return

        temp = self.cabeza
        ant = None

        for _ in range(pos):
            ant = temp
            temp = temp.sig
            if temp == self.cabeza:
                break

        ant.sig = temp.sig

    def mostrar(self):
        if self.cabeza is None:
            return

        temp = self.cabeza
        while True:
            print(temp.dato, "->", end=" ")
            temp = temp.sig
            if temp == self.cabeza:
                break

        print("(regresa)")
seguir = True
while seguir:
    lista = ListaCircular()
    print("Lista Circular:")
    print("Elija una opcion:")
    print("1. Insertar al inicio")
    print("2. Insertar al final")
    print("3. Insertar en posicion")
    print("4. Eliminar al inicio")
    print("5. Eliminar al final")
    print("6. Eliminar en posicion")
    print("7. Mostrar lista")
    print("8. Salir")

    opcion = int(input())

    if opcion == 1:
        dato = int(input("Ingrese el dato a insertar al inicio: "))
        lista.insertar_inicio(dato)
    elif opcion == 2:
        dato = int(input("Ingrese el dato a insertar al final: "))
        lista.insertar_final(dato)
    elif opcion == 3:
        dato = int(input("Ingrese el dato a insertar: "))
        pos = int(input("Ingrese la posicion: "))
        lista.insertar_posicion(dato, pos)
    elif opcion == 4:
        lista.eliminar_inicio()
    elif opcion == 5:
        lista.eliminar_final()
    elif opcion == 6:
        pos = int(input("Ingrese la posicion a eliminar: "))
        lista.eliminar_posicion(pos)
    elif opcion == 7:
        lista.mostrar()
    elif opcion == 8:
        seguir = False
    else:
        print("Opcion no valida")