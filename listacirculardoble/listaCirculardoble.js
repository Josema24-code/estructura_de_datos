const prompt = require('prompt-sync')({sigint: true});

class Nodo {
    constructor(dato){ this.dato = dato; this.sig = null; this.ant = null; }
}

class ListaCircularDoble {
    constructor(){ this.cabeza = null; }

    insertarInicio(dato){
        const nuevo = new Nodo(dato);
        if(!this.cabeza){ this.cabeza = nuevo; nuevo.sig = nuevo; nuevo.ant = nuevo; return; }
        const ultimo = this.cabeza.ant;
        nuevo.sig = this.cabeza; nuevo.ant = ultimo;
        ultimo.sig = nuevo; this.cabeza.ant = nuevo;
        this.cabeza = nuevo;
    }

    insertarFinal(dato){
        const nuevo = new Nodo(dato);
        if(!this.cabeza){ this.cabeza = nuevo; nuevo.sig = nuevo; nuevo.ant = nuevo; return; }
        const ultimo = this.cabeza.ant;
        ultimo.sig = nuevo; nuevo.ant = ultimo;
        nuevo.sig = this.cabeza; this.cabeza.ant = nuevo;
    }

    insertarPosicion(dato, pos){
        if(pos === 0){ this.insertarInicio(dato); return; }
        if(!this.cabeza){ console.log("Lista vacía"); return; }
        let temp = this.cabeza;
        for(let i=0;i<pos-1 && temp.sig !== this.cabeza;i++) temp = temp.sig;
        const nuevo = new Nodo(dato);
        const siguiente = temp.sig;
        nuevo.sig = siguiente; nuevo.ant = temp;
        temp.sig = nuevo; siguiente.ant = nuevo;
    }

    eliminarInicio(){
        if(!this.cabeza) return;
        if(this.cabeza.sig === this.cabeza){ this.cabeza = null; return; }
        const ultimo = this.cabeza.ant;
        this.cabeza = this.cabeza.sig;
        this.cabeza.ant = ultimo;
        ultimo.sig = this.cabeza;
    }

    eliminarFinal(){
        if(!this.cabeza) return;
        if(this.cabeza.sig === this.cabeza){ this.cabeza = null; return; }
        const ultimo = this.cabeza.ant;
        const nuevoUltimo = ultimo.ant;
        nuevoUltimo.sig = this.cabeza;
        this.cabeza.ant = nuevoUltimo;
    }

    eliminarPosicion(pos){
        if(!this.cabeza) return;
        if(pos === 0){ this.eliminarInicio(); return; }
        let temp = this.cabeza;
        for(let i=0;i<pos;i++){
            temp = temp.sig;
            if(temp === this.cabeza) return;
        }
        const anterior = temp.ant;
        const siguiente = temp.sig;
        anterior.sig = siguiente; siguiente.ant = anterior;
        if(temp === this.cabeza) this.cabeza = siguiente;
    }

    mostrar(){
        if(!this.cabeza){ console.log("Lista vacía"); return; }
        let temp = this.cabeza;
        do {
            process.stdout.write(temp.dato + " <-> ");
            temp = temp.sig;
        } while(temp !== this.cabeza);
        console.log("(regresa)");
    }
}

// Menú
const lista = new ListaCircularDoble();
let opcion;
do {
    console.log("\n=== MENÚ LISTA CIRCULAR DOBLE (JS) ===");
    console.log("1. Insertar al inicio\n2. Insertar al final\n3. Insertar en posición");
    console.log("4. Eliminar al inicio\n5. Eliminar al final\n6. Eliminar en posición");
    console.log("7. Mostrar lista\n8. Salir");
    opcion = parseInt(prompt("Opción: "));
    switch(opcion){
        case 1:
            lista.insertarInicio(parseInt(prompt("Dato: ")));
            break;
        case 2:
            lista.insertarFinal(parseInt(prompt("Dato: ")));
            break;
        case 3:
            lista.insertarPosicion(parseInt(prompt("Dato: ")), parseInt(prompt("Posición: ")));
            break;
        case 4:
            lista.eliminarInicio();
            break;
        case 5:
            lista.eliminarFinal();
            break;
        case 6:
            lista.eliminarPosicion(parseInt(prompt("Posición a eliminar: ")));
            break;
        case 7:
            lista.mostrar();
            break;
        case 8:
            console.log("Saliendo...");
            break;
        default:
            console.log("Opción no válida");
    }
} while(opcion !== 8);
