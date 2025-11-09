numeros = [40,80,90,20,10]
# Pedir un numero para buscar
numero_Buscar = int(input("ingrese un numero a buscar: "))
encontrado = False
# Recorrer la lista para buscar el numero
for i in range(len(numeros)):
    if numeros[i] == numero_Buscar:
        print("Número encontrado en la posición:", i)
        encontrado = True
        break
    
# Si no se encontró el número
if not encontrado: 
    print("Número no encontrado en la lista.")
