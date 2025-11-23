const readline = require("readline");
class Stack {
    constructor() {
        this.MAX_SIZE = 100;
        this.stack = [];
    }
    push(item) {
        if (this.stack.length === this.MAX_SIZE) return console.log("Stack Overflow");
        this.stack.push(item);
    }
    pop() {
        if (this.stack.length === 0) return console.log("Stack Underflow");
        return this.stack.pop();
    }
    peek() {
        if (this.stack.length === 0) return console.log("Pila vacía");
        return this.stack[this.stack.length - 1];
    }
    isEmpty() { return this.stack.length === 0; }
    isFull() { return this.stack.length === this.MAX_SIZE; }
}

const pila = new Stack();
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

function menu() {
    console.log("\n--- MENU PILA (JS) ---");
    console.log("1. Push");
    console.log("2. Pop");
    console.log("3. Peek");
    console.log("4. isEmpty");
    console.log("5. isFull");
    console.log("6. Salir");
    rl.question("Elige: ", opcion => {
        switch(parseInt(opcion)) {
            case 1:
                rl.question("Ingresa un valor: ", v => { pila.push(parseInt(v)); menu(); });
                break;
            case 2:
                console.log("Eliminado:", pila.pop()); menu(); break;
            case 3:
                console.log("Tope:", pila.peek()); menu(); break;
            case 4:
                console.log(pila.isEmpty()? "Pila vacía" : "No está vacía"); menu(); break;
            case 5:
                console.log(pila.isFull()? "Pila llena" : "No está llena"); menu(); break;
            case 6:
                console.log("Saliendo..."); rl.close(); break;
            default:
                console.log("Opción inválida"); menu(); break;
        }
    });
}
menu();
