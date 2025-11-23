const readline = require("readline");

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class Stack {
    constructor() { this.top = null; }

    push(item) {
        const n = new Node(item);
        n.next = this.top;
        this.top = n;
        console.log(`Elemento ${item} insertado.`);
    }
    pop() {
        if (!this.top) return console.log("Stack Underflow");
        const val = this.top.data;
        this.top = this.top.next;
        return val;
    }
    peek() {
        if (!this.top) return console.log("Pila vacía");
        return this.top.data;
    }
    isEmpty() { return this.top === null; }
}

const pila = new Stack();
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

function menu() {
    console.log("\n--- MENU PILA (JS Linked List) ---");
    console.log("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Salir");
    rl.question("Elige: ", op => {
        switch(parseInt(op)) {
            case 1: rl.question("Ingresa un valor: ", v=>{ pila.push(parseInt(v)); menu(); }); break;
            case 2: console.log("Eliminado:", pila.pop()); menu(); break;
            case 3: console.log("Tope:", pila.peek()); menu(); break;
            case 4: console.log(pila.isEmpty()? "Pila vacía":"No está vacía"); menu(); break;
            case 5: console.log("Saliendo..."); rl.close(); break;
            default: console.log("Opción inválida"); menu(); break;
        }
    });
}
menu();
