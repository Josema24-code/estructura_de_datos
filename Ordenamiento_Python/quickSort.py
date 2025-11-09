def particionar(arr, inicio, fin):
    pivote = arr[fin]
    i = inicio - 1
    for j in range(inicio, fin):
        if arr[j] <= pivote:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[fin] = arr[fin], arr[i + 1]
    return i + 1

def quickSort(arr, inicio, fin):
    if inicio < fin:
        indicePivote = particionar(arr, inicio, fin)
        quickSort(arr, inicio, indicePivote - 1)
        quickSort(arr, indicePivote + 1, fin)

numeros = [3, 6, 8, 10, 1, 2, 1]
print("Original:", numeros)
quickSort(numeros, 0, len(numeros) - 1)
print("Ordenado:", numeros)
