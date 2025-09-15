const prompt = require("prompt-sync")();
let matriz = [
    [' ', ' ', ' ', ' ', ' ', ' ', ' '],
    [' ', ' ', ' ', ' ', ' ', ' ', ' '],
    [' ', ' ', ' ', ' ', ' ', ' ', ' '],
    [' ', ' ', ' ', ' ', ' ', ' ', ' '],
    [' ', ' ', ' ', ' ', ' ', ' ', ' '],
    [' ', ' ', ' ', ' ', ' ', ' ', ' ']
];
let jugador = "jugador 1";
let ficha = "X";
let winner = false;

while (!winner) {
    console.log(" 0 1 2 3 4 5 6");
    for (let i = 0; i < matriz.length; i++) { // Recorre cada fila
        let fila = ""; 
        for (let j = 0; j < matriz[i].length; j++) { // Recorre cada columna
            fila += "|" + matriz[i][j]; // Construye la fila para mostrarla por consola
        }
        fila += "|"; // Cierra la fila con un "|"
        console.log(fila); // Muestra la fila por consola
    }
    
    let colum = parseInt(prompt(jugador + " ingrese la columna (0-6) para colocar su ficha: "));
    for (let i = matriz.length - 1; i >= 0; i--) { // Recorre la columna desde abajo hacia arriba
        if (matriz[i][colum] === ' ') { // Si encuentra un espacio vacío
            matriz[i][colum] = ficha; // Coloca la ficha del jugador
            break;
        }
    }
    if (matriz[0][colum] !== ' ' || colum < 0 || colum > 6){ // Verifica si la columna está llena o es inválida
        console.log("Columna llena o inválida, intente de nuevo.");
        continue;
    }
    // Verificar si hay un ganador horizontal
    for (let i = 0; i < matriz.length; i++) {  // Recorre cada fila
        for (let j = 0; j < matriz[i].length - 3; j++) { // Recorre cada columna hasta la cuarta y última
            if (matriz[i][j] === ficha && matriz[i][j + 1] === ficha && matriz[i][j + 2] === ficha && matriz[i][j + 3] === ficha) { // Verifica si hay 4 fichas iguales en línea
                winner = true;
            }
        }
    }
    // Verifica si hay un ganador vertical
    for (let j = 0; j < matriz[0].length; j++) { // Recorre cada columna
        for (let i = 0; i < matriz.length - 3; i++) { // Recorre cada fila hasta la cuarta y última
            if (matriz[i][j] === ficha && matriz[i + 1][j] === ficha && matriz[i + 2][j] === ficha && matriz[i + 3][j] === ficha) { // Verifica si hay 4 fichas iguales en línea
                winner = true;
            }
        }
    }
    // Verificar si hay un ganador diagonal (de izquierda a derecha)
    for (let i = 0; i < matriz.length - 3; i++) { // Recorre cada fila
        for (let j = 0; j < matriz[i].length - 3; j++) { // Recorre cada columna hasta la cuarta y última
            if (matriz[i][j] === ficha && matriz[i + 1][j + 1] === ficha && matriz[i + 2][j + 2] === ficha && matriz[i + 3][j + 3] === ficha) { // Verifica si hay 4 fichas iguales en línea
                winner = true;
            }
        }
    }
    // Verifica si hay un ganador diagonal (de derecha a izquierda)
    for (let i = 0; i < matriz.length - 3; i++) { // Recorre cada fila
        for (let j = 3; j < matriz[i].length; j++) { // Recorre cada columna desde la cuarta hasta la última
            if (matriz[i][j] === ficha && matriz[i + 1][j - 1] === ficha && matriz[i + 2][j - 2] === ficha && matriz[i + 3][j - 3] === ficha) {
                winner = true;
            }
        }
    }
    if (winner) { // Si hay un ganador, se anuncia y se termina el juego
        console.log(jugador + " ha ganado!"); 
        break;
    }
    // Cambiar de jugador
    if (jugador === "jugador 1") {
        jugador = "jugador 2";
        ficha = "O";
    } else {
        jugador = "jugador 1";
        ficha = "X";
    }
    
}
