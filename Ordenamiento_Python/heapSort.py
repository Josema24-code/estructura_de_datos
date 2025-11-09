def heapify(arr, n, i):
    mayor = i
    izq = 2 * i + 1
    der = 2 * i + 2

    if izq < n and arr[izq] > arr[mayor]:
        mayor = izq

    if der < n and arr[der] > arr[mayor]:
        mayor = der

    if mayor != i:
        arr[i], arr[mayor] = arr[mayor], arr[i]
        heapify(arr, n, mayor)

def heapSort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

numeros = [34, 7, 23, 32, 5, 62]
print("Original:", numeros)
heapSort(numeros)
print("Ordenado:", numeros)
