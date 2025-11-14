class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

let head = null;
const prompt = require("prompt-sync")();

function beginInsert() {
    let item = parseInt(prompt("Ingrese valor: "));
    let node = new Node(item);
    node.next = head;
    head = node;
    console.log("Nodo insertado");
}

function lastInsert() {
    let item = parseInt(prompt("Ingrese valor: "));
    let node = new Node(item);

    if (!head) {
        head = node;
    } else {
        let temp = head;
        while (temp.next)
            temp = temp.next;
        temp.next = node;
    }
    console.log("Nodo insertado");
}

function randomInsert() {
    let item = parseInt(prompt("Ingrese valor: "));
    let loc = parseInt(prompt("Ingrese posición: "));

    let temp = head;
    for (let i = 0; i < loc; i++) {
        if (!temp) {
            console.log("No se puede insertar");
            return;
        }
        temp = temp.next;
    }

    let node = new Node(item);
    node.next = temp.next;
    temp.next = node;

    console.log("Nodo insertado");
}

function beginDelete() {
    if (!head) return console.log("Lista vacía");
    head = head.next;
    console.log("Nodo eliminado");
}

function lastDelete() {
    if (!head) return console.log("Lista vacía");
    if (!head.next) {
        head = null;
        return console.log("Nodo eliminado");
    }

    let temp = head, prev = null;
    while (temp.next) {
        prev = temp;
        temp = temp.next;
    }
    prev.next = null;
    console.log("Nodo eliminado");
}

function randomDelete() {
    let loc = parseInt(prompt("Ingrese posición: "));

    if (!head) return console.log("Lista vacía");

    if (loc === 0) {
        head = head.next;
        return console.log("Nodo eliminado");
    }

    let temp = head, prev = null;
    for (let i = 0; i < loc; i++) {
        prev = temp;
        temp = temp.next;
        if (!temp) return console.log("No se puede eliminar");
    }

    prev.next = temp.next;
    console.log("Nodo eliminado");
}

function display() {
    if (!head) return console.log("Lista vacía");

    let temp = head;
    let out = "";
    while (temp) {
        out += temp.data + "->";
        temp = temp.next;
    }
    console.log(out + "NULL");
}

function search() {
    let item = parseInt(prompt("Ingrese valor: "));
    let temp = head, pos = 0;

    while (temp) {
        if (temp.data === item) {
            console.log("Encontrado en posición " + pos);
            return;
        }
        temp = temp.next;
        pos++;
    }
    console.log("No encontrado");
}

function menu() {
    let choice = 0;
    while (choice !== 9) {
        console.log(`
*******MENU*******
1. Insert beginning
2. Insert last
3. Insert random
4. Delete beginning
5. Delete last
6. Delete random
7. Display
8. Search
9. Exit
`);
        choice = parseInt(prompt("Choice: "));

        switch (choice) {
            case 1: beginInsert(); break;
            case 2: lastInsert(); break;
            case 3: randomInsert(); break;
            case 4: beginDelete(); break;
            case 5: lastDelete(); break;
            case 6: randomDelete(); break;
            case 7: display(); break;
            case 8: search(); break;
        }
    }
}

menu();
