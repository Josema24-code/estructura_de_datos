let array = [5, 2, 9, 1, 5, 6];
console.log("antes de ordenar: " + array);
console.log("despues de ordenar: " + insercion(array));
function insercion(arr) {
    for (let i = 1; i < arr.length; i++) {
        let numActual = arr[i];
        let j = i;
        // Mover los elementos del arreglo que son mayores que numActual
        while (j > 0 && arr[j - 1] > numActual) {
            arr[j] = arr[j - 1]; // Mover el elemento hacia la derecha
            j--; // Decrementar j para seguir comparando con los elementos anteriores
        }
        arr[j] = numActual; //refresca el numero actual en su posicion correcta
    }
    return arr;
}
