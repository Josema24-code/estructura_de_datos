let MAXIMO = 10;
let MINIMO = 1;
let array = new Array(10);
let temporal;

//rellenar arreglo con numeros aleatorios
for (let i = 0; i < array.length; i++){
    array[i] = Math.floor(Math.random() * (MAXIMO - MINIMO + 1)) + MINIMO;
}
console.log("Arreglo desordenado: " + array);
//algoritmo de burbuja
for (let i = 0; i < array.length - 1; i++){
    for (let j = 0; j< array.length - i -1 ; j++){
        if (array[j] > array[j + 1]){
            temporal = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temporal;
        }
    }
}
// mostrar arreglo ordenado
console.log("Arreglo ordenado: " + array);
