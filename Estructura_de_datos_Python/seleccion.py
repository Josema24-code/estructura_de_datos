array = [64, 25, 12, 22, 11]
print("Antes de ordenar:", array)

for i in range(len(array)):
    minimo = i
    for j in range (i+1, len(array)):
        if array[minimo] > array[j]:
            minimo = j
    aux = array[i]
    array[i] = array[minimo]
    array[minimo] = aux

print("Después de ordenar:", array)