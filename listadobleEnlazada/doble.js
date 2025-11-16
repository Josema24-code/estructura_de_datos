const prompt = require('prompt-sync')();

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

let head = null;

function insertBegin(v){
    const n = new Node(v);
    n.next = head;
    if (head) head.prev = n;
    head = n;
    console.log("Nodo insertado");
}

function insertLast(v){
    const n = new Node(v);
    if (!head) { head = n; console.log("Nodo insertado"); return; }
    let t = head;
    while (t.next) t = t.next;
    t.next = n; n.prev = t;
    console.log("Nodo insertado");
}

function insertAfterPos(pos,v){
    let t = head;
    for (let i=0;i<pos;i++){
        if (!t) { console.log("No se puede insertar"); return; }
        t = t.next;
    }
    if (!t) { console.log("No se puede insertar"); return; }
    const n = new Node(v);
    n.next = t.next; n.prev = t;
    if (t.next) t.next.prev = n;
    t.next = n;
    console.log("Nodo insertado");
}

function deleteBegin(){
    if (!head) { console.log("Lista vacía"); return; }
    head = head.next;
    if (head) head.prev = null;
    console.log("Nodo eliminado");
}

function deleteLast(){
    if (!head) { console.log("Lista vacía"); return; }
    if (!head.next) { head = null; console.log("Nodo eliminado"); return; }
    let t = head;
    while (t.next) t = t.next;
    t.prev.next = null;
    console.log("Nodo eliminado");
}

function deletePos(pos){
    if (!head) { console.log("Lista vacía"); return; }
    let t = head;
    for (let i=0;i<pos;i++){
        t = t.next;
        if (!t) { console.log("No se puede eliminar"); return; }
    }
    if (t.prev) t.prev.next = t.next; else head = t.next;
    if (t.next) t.next.prev = t.prev;
    console.log("Nodo eliminado");
}

function displayForward(){
    if (!head) { console.log("Lista vacía"); return; }
    let t=head, out="";
    while (t){ out += t.data + "->"; t = t.next; }
    console.log(out + "NULL");
}

function displayBackward(){
    if (!head) { console.log("Lista vacía"); return; }
    let t=head;
    while (t.next) t = t.next;
    let out="";
    while (t){ out += t.data + "->"; t = t.prev; }
    console.log(out + "NULL");
}

function search(v){
    let t=head, pos=0;
    while (t){
        if (t.data===v) { console.log("Encontrado en " + pos); return; }
        t = t.next; pos++;
    }
    console.log("No encontrado");
}

function menu(){
    let opt=0;
    while(opt!==10){
        console.log("\n1-InsBeg 2-InsLast 3-InsAfterPos\n4-DelBeg 5-DelLast 6-DelPos\n7-DispFwd 8-DispBwd 9-Search 10-Exit");
        opt = parseInt(prompt("Choice: "));
        if (isNaN(opt)) { console.log("Entrada inválida"); continue; }
        let x,p;
        switch(opt){
            case 1: x=parseInt(prompt("val: ")); insertBegin(x); break;
            case 2: x=parseInt(prompt("val: ")); insertLast(x); break;
            case 3: p=parseInt(prompt("pos: ")); x=parseInt(prompt("val: ")); insertAfterPos(p,x); break;
            case 4: deleteBegin(); break;
            case 5: deleteLast(); break;
            case 6: p=parseInt(prompt("pos: ")); deletePos(p); break;
            case 7: displayForward(); break;
            case 8: displayBackward(); break;
            case 9: x=parseInt(prompt("val: ")); search(x); break;
            case 10: console.log("Saliendo"); break;
            default: console.log("Opción inválida");
        }
    }
}

menu();
