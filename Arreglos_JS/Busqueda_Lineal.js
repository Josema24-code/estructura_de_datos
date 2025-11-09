
const prompt = require("prompt-sync")(); 
let numeros = [10, 20, 30, 40, 50];
let numero_Abuscar = parseInt(prompt("Ingrese un número a buscar: "));

let encontrado = false;
// Busqueda de un número en el array
for (let i = 0; i < numeros.length; i++) {
    // compara cada elemento del array con el número a buscar
    if (numeros[i] === numero_Abuscar) {
        console.log("Número encontrado en la posición " + i);
        encontrado = true;
        break;
    }
}
// Si no se encontró el número, se muestra un mensaje
if (!encontrado) {
    console.log("El número no fue encontrado");
}
