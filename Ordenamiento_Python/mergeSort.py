def mergeSort(arr):
    if len(arr) > 1:
        medio = len(arr) // 2
        izquierda = arr[:medio]
        derecha = arr[medio:]

        mergeSort(izquierda)
        mergeSort(derecha)

        i = j = k = 0

        while i < len(izquierda) and j < len(derecha):
            if izquierda[i] <= derecha[j]:
                arr[k] = izquierda[i]
                i += 1
            else:
                arr[k] = derecha[j]
                j += 1
            k += 1

        while i < len(izquierda):
            arr[k] = izquierda[i]
            i += 1
            k += 1

        while j < len(derecha):
            arr[k] = derecha[j]
            j += 1
            k += 1

numeros = [34, 7, 23, 32, 5, 62]
print("Original:", numeros)
mergeSort(numeros)
print("Ordenado:", numeros)
