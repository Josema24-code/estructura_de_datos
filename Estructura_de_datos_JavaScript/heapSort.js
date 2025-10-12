function heapify(arr, n, i) {
    let mayor = i;
    let izq = 2 * i + 1;
    let der = 2 * i + 2;

    if (izq < n && arr[izq] > arr[mayor])
        mayor = izq;

    if (der < n && arr[der] > arr[mayor])
        mayor = der;

    if (mayor != i) {
        [arr[i], arr[mayor]] = [arr[mayor], arr[i]];
        heapify(arr, n, mayor);
    }
}

function heapSort(arr) {
    let n = arr.length;

    for (let i = Math.floor(n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (let i = n - 1; i > 0; i--) {
        [arr[0], arr[i]] = [arr[i], arr[0]];
        heapify(arr, i, 0);
    }
}

let numeros = [34, 7, 23, 32, 5, 62];
console.log("Original:", numeros);
heapSort(numeros);
console.log("Ordenado:", numeros);
