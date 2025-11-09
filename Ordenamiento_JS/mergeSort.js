function mergeSort(arr) {
    if (arr.length <= 1) return arr;

    const medio = Math.floor(arr.length / 2);
    const izquierda = arr.slice(0, medio);
    const derecha = arr.slice(medio);

    return merge(mergeSort(izquierda), mergeSort(derecha));
}

function merge(izquierda, derecha) {
    let resultado = [];
    let i = 0, j = 0;

    while (i < izquierda.length && j < derecha.length) {
        if (izquierda[i] <= derecha[j]) {
            resultado.push(izquierda[i++]);
        } else {
            resultado.push(derecha[j++]);
        }
    }

    return resultado.concat(izquierda.slice(i)).concat(derecha.slice(j));
}

let numeros = [34, 7, 23, 32, 5, 62];
console.log("Original:", numeros);
numeros = mergeSort(numeros);
console.log("Ordenado:", numeros);
