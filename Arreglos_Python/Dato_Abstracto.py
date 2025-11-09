class Persona:
    def __init__(self, nombre, apellido, edad):
        self.nombre = nombre
        self.apellido = apellido
        self.edad = edad

# Lista de objetos Persona
personas = [
    Persona("Sheila", "Valdez", 25),
    Persona("Jose", "Aguallo", 30),
    Persona("Luis", "Ramirez", 40)
]

# Recorrer el arreglo
for i in range(len(personas)):
    print(f"Persona {i + 1}")
    print("Nombre: " + personas[i].nombre)
    print("Apellido: " + personas[i].apellido)
    print("Edad: " + str(personas[i].edad))
    print("------------------")
