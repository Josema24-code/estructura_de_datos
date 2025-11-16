class Nodo {
    constructor(dato){
        this.dato = dato;
        this.sig = null;
    }
}

class ListaCircular {

    constructor(){
        this.cabeza = null;
    }

    insertarInicio(dato){
        const nuevo = new Nodo(dato);

        if(!this.cabeza){
            nuevo.sig = nuevo;
            this.cabeza = nuevo;
            return;
        }

        let temp = this.cabeza;
        while(temp.sig !== this.cabeza)
            temp = temp.sig;

        nuevo.sig = this.cabeza;
        temp.sig = nuevo;
        this.cabeza = nuevo;
    }

    insertarFinal(dato){
        const nuevo = new Nodo(dato);

        if(!this.cabeza){
            nuevo.sig = nuevo;
            this.cabeza = nuevo;
            return;
        }

        let temp = this.cabeza;
        while(temp.sig !== this.cabeza)
            temp = temp.sig;

        temp.sig = nuevo;
        nuevo.sig = this.cabeza;
    }

    insertarPosicion(dato, pos){
        if(pos === 0){
            this.insertarInicio(dato);
            return;
        }

        const nuevo = new Nodo(dato);
        let temp = this.cabeza;

        for(let i = 1; i < pos && temp.sig !== this.cabeza; i++)
            temp = temp.sig;

        nuevo.sig = temp.sig;
        temp.sig = nuevo;
    }

    eliminarInicio(){
        if(!this.cabeza) return;

        if(this.cabeza.sig === this.cabeza){
            this.cabeza = null;
            return;
        }

        let fin = this.cabeza;
        while(fin.sig !== this.cabeza)
            fin = fin.sig;

        this.cabeza = this.cabeza.sig;
        fin.sig = this.cabeza;
    }

    eliminarFinal(){
        if(!this.cabeza) return;

        if(this.cabeza.sig === this.cabeza){
            this.cabeza = null;
            return;
        }

        let temp = this.cabeza;
        let ant = null;

        while(temp.sig !== this.cabeza){
            ant = temp;
            temp = temp.sig;
        }

        ant.sig = this.cabeza;
    }

    eliminarPosicion(pos){
        if(!this.cabeza) return;

        if(pos === 0){
            this.eliminarInicio();
            return;
        }

        let temp = this.cabeza;
        let ant = null;

        for(let i = 0; i < pos && temp.sig !== this.cabeza; i++){
            ant = temp;
            temp = temp.sig;
        }

        ant.sig = temp.sig;
    }

    mostrar(){
        if(!this.cabeza) return;

        let temp = this.cabeza;
        let out = "";
        do {
            out += temp.dato + " -> ";
            temp = temp.sig;
        } while(temp !== this.cabeza);

        console.log(out + "(regresa)");
    }
}

let seguir = true;
do {
    const lista = new ListaCircular();
    console.log("Lista Circular:");
    console.log("Elija una opcion:");
    console.log("1. Insertar al inicio");
    console.log("2. Insertar al final");
    console.log("3. Insertar en posicion");
    console.log("4. Eliminar al inicio");
    console.log("5. Eliminar al final");
    console.log("6. Eliminar en posicion");
    console.log("7. Mostrar lista");
    console.log("8. Salir");

    const opcion = parseInt(prompt("Opcion: "));

    switch(opcion){
        case 1:
            const datoInicio = prompt("Dato a insertar al inicio: ");
            lista.insertarInicio(datoInicio);
            break;
        case 2:
            const datoFinal = prompt("Dato a insertar al final: ");
            lista.insertarFinal(datoFinal);
            break;
        case 3:
            const datoPos = prompt("Dato a insertar: ");
            const posInsertar = parseInt(prompt("Posicion: "));
            lista.insertarPosicion(datoPos, posInsertar);
            break;
        case 4:
            lista.eliminarInicio();
            break;
        case 5:
            lista.eliminarFinal();
            break;
        case 6:
            const posEliminar = parseInt(prompt("Posicion a eliminar: "));
            lista.eliminarPosicion(posEliminar);
            break;
        case 7:
            lista.mostrar();
            break;
        case 8:
            seguir = false;
            break;
        default:
            console.log("Opcion no valida");
    }
} while(seguir);
            
  

