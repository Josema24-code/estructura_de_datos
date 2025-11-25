const readline = require("readline").createInterface({
    input: process.stdin,
    output: process.stdout
});

class Nodo {
    constructor(dato) {
        this.dato = dato;
        this.sig = null;
    }
}

let frente = null, fin = null;

function insertar() {
    readline.question("\nIngrese el elemento: ", x => {
        let nuevo = new Nodo(parseInt(x));
        if (!frente) frente = fin = nuevo;
        else { fin.sig = nuevo; fin = nuevo; }
        console.log("Elemento insertado correctamente.");
        menu();
    });
}

function eliminar() {
    if (!frente) return console.log("\nSUBDESBORDAMIENTO (UNDERFLOW)");
    let eliminado = frente.dato;
    frente = frente.sig;
    if (!frente) fin = null;
    console.log("\nElemento eliminado:", eliminado);
}

function mostrar() {
    if (!frente) return console.log("\nLa cola está vacía.");
    console.log("\nElementos en la cola:");
    for (let i = frente; i; i = i.sig) console.log(i.dato);
}

function menu() {
    console.log("\n*************** MENÚ PRINCIPAL ***************");
    console.log("1. Insertar un elemento");
    console.log("2. Eliminar un elemento");
    console.log("3. Mostrar la cola");
    console.log("4. Salir");
    readline.question("Ingrese su opción: ", op => {
        switch (parseInt(op)) {
            case 1: return insertar();
            case 2: eliminar(); break;
            case 3: mostrar(); break;
            case 4: console.log("\nSaliendo..."); return readline.close();
            default: console.log("\nOpción inválida."); break;
        }
        menu();
    });
}

menu();
