let numeros = [30, 20, 10, 40, 50];
// muestra los elementos del array
for (let i = 0; i < numeros.length; i ++) {
    console.log(numeros[i]);

}
// pide un número al usuario
const prompt = require("prompt-sync")(); 
let numero_Ainsertar = parseInt(prompt("Ingrese un número a insertar: "));

for (let i = numeros.length - 1; i > 0; i--) {
    numeros[i] = numeros[i - 1];

}
// inserta el número al inicio del array
numeros[0] = numero_Ainsertar;
console.log("Array después de insertar el número:");
for (let i = 0; i < numeros.length; i ++) {
    console.log(numeros[i]);

}