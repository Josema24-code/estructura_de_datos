let array = [5, 3, 8, 4, 2];

console.log("Antes de ordenar:", array);

for (let i = 0; i < array.length; i++) {
    let minimo = i;
        for (let j = i + 1; j< array.length; j++) {
            if (array[minimo] > array[j]){
                minimo = j;
            }
        }
        let aux = array [i];
        array[i] = array[minimo];
        array[minimo] = aux;
 }
console.log("Después de ordenar:", array);