def bucket_sort(arr):
    n = len(arr)
    buckets = [[] for _ in range(n)]

    # Colocar en cubetas
    for num in arr:
        index = int(n * num)
        buckets[index].append(num)

    # Ordenar cada cubeta
    for bucket in buckets:
        bucket.sort()

    # Unir todo
    resultado = []
    for bucket in buckets:
        resultado.extend(bucket)
    return resultado

arr = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68]
ordenado = bucket_sort(arr)
print("Arreglo ordenado:", ordenado)
