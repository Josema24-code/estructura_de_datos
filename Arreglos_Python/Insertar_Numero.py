numeros = [40,70,90,20,10]
for i in range(len(numeros)):
    print(numeros[i])
    
# pide un numero 
numero_Ainsertar = int(input("ingrese un numero a insertar: "))

# Recorrer de derecha a izquierda
for i in range(len(numeros)-1, 0, -1):   # desde el último hasta 1
    numeros[i] = numeros[i-1]
    
# Insertar el numero en la primera posicion
numeros[0] = numero_Ainsertar

# Mostrar el array actualizado
print("\nLista después de insertar:")
for i in range(len(numeros)):
    print(numeros[i])