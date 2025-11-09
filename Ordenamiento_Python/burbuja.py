import random
import os
MINIMO = 1
MAXIMO = 10
array = [0]*10
for i in range(len(array)):
    array[i] = random.randrange(MINIMO, MAXIMO)

##antes de ordenar
print("Array antes de ordenar")
print(array)
##ordenamiento burbuja
for i in range(len(array)):
    for j in range(0, len(array)-i-1):
        if array[j] > array[j+1]:
            array[j], array[j+1] = array[j+1], array[j]
##despues de ordenar
print("Array despues de ordenar")
print(array)

