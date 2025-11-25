const readline = require("readline").createInterface({
    input: process.stdin,
    output: process.stdout
});

const MAXSIZE = 5;
let queue = new Array(MAXSIZE);
let front = -1, rear = -1;

function insertar() {
    if (rear === MAXSIZE - 1) return console.log("\nDESBORDAMIENTO (OVERFLOW)");

    readline.question("\nIngrese el elemento: ", elem => {
        elem = parseInt(elem);

        if (front === -1 && rear === -1) front = rear = 0;
        else rear++;

        queue[rear] = elem;
        console.log("Elemento insertado correctamente.");
        menu();
    });
}

function eliminar() {
    if (front === -1 || front > rear) return console.log("\nSUBDESBORDAMIENTO (UNDERFLOW)");

    const elem = queue[front];
    if (front === rear) front = rear = -1;
    else front++;

    console.log("\nElemento eliminado:", elem);
}

function mostrar() {
    if (front === -1 || front > rear) return console.log("\nLa cola está vacía.");

    console.log("\nElementos en la cola:");
    for (let i = front; i <= rear; i++) console.log(queue[i]);
}

function menu() {
    console.log("\n*************** MENÚ PRINCIPAL ***************");
    console.log("1. Insertar un elemento");
    console.log("2. Eliminar un elemento");
    console.log("3. Mostrar la cola");
    console.log("4. Salir");
    readline.question("Ingrese su opción: ", respuesta => {
        switch (parseInt(respuesta)) {
            case 1: return insertar();
            case 2: eliminar(); break;
            case 3: mostrar(); break;
            case 4: console.log("\nSaliendo..."); return readline.close();
            default: console.log("\nOpción inválida.");
        }
        menu();
    });
}

menu();
