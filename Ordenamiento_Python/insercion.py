array = [12, 11, 13, 5, 6]
print("Antes de la insercion:")
for i in range(len(array)):
    print(array[i], end=" ")
print()

def insercion(arr):
    for i in range(1, len(arr)):
        num_actual = arr[i]
        j = i
        while j > 0 and arr[j - 1] > num_actual:
            arr[j] = arr[j - 1]  
            j -= 1  
        arr[j] = num_actual  
    return arr

insercion(array)
print("Despues de la insercion:")
for i in range(len(array)):
    print(array[i], end=" ")