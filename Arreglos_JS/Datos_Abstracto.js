// Definición de la clase Persona
class Persona {
    constructor(nombre, apellido, edad) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.edad = edad;
    }
}
// Creacion de las instancias de la clase Persona
let personas = [
    new Persona("Jose", "Aguallo", 18),
    new Persona("Jazmin", "López", 19),
    new Persona("Luis", "Ramírez", 35)
];
// Mostrar la información de cada persona
personas.forEach((p, i) => {
    console.log(`Persona ${i+1}`);
    console.log(`Nombre: ${p.nombre}`);
    console.log(`Apellido: ${p.apellido}`);
    console.log(`Edad: ${p.edad}`);
    console.log("------------------");
});
