Matriz_numeros = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
# Recorrer las columnas
for j in range(len(Matriz_numeros[1])):
    # Recorrer las filas
    for i in range(len(Matriz_numeros[0])):
        print(Matriz_numeros[i][j])