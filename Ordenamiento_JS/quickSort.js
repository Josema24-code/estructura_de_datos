function particionar(arr, inicio, fin) {
    let pivote = arr[fin];
    let i = inicio - 1;

    for (let j = inicio; j < fin; j++) {
        if (arr[j] <= pivote) {
            i++;
            [arr[i], arr[j]] = [arr[j], arr[i]]; // swap
        }
    }
    [arr[i + 1], arr[fin]] = [arr[fin], arr[i + 1]];
    return i + 1;
}

function quickSort(arr, inicio, fin) {
    if (inicio < fin) {
        let indicePivote = particionar(arr, inicio, fin);
        quickSort(arr, inicio, indicePivote - 1);
        quickSort(arr, indicePivote + 1, fin);
    }
}

let numeros = [10, 7, 8, 9, 1, 5, 4, 65, 23, 56];
console.log("Original:", numeros);
quickSort(numeros, 0, numeros.length - 1);
console.log("Ordenado:", numeros);
