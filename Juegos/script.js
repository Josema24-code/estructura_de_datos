const filas = 12;
const columnas = 12;
const tablero = document.getElementById("tablero");
const nivelTxt = document.getElementById("nivel");
const tamanoTxt = document.getElementById("tamano");
const puntajeTxt = document.getElementById("puntaje");
const top5Lista = document.getElementById("top5");

// Crear celdas del tablero
for (let i = 0; i < filas * columnas; i++) {
  const celda = document.createElement("div");
  celda.classList.add("celda");
  tablero.appendChild(celda);
}
const celdas = Array.from(document.getElementsByClassName("celda"));

// Estado inicial
let snake = [
  { x: 5, y: 5 },
  { x: 4, y: 5 },
  { x: 3, y: 5 },
  { x: 2, y: 5 },
  { x: 1, y: 5 }
]; // Lista de nodos del cuerpo

let direccion = { x: 0, y: 0 }; // No se mueve hasta presionar tecla
let comida = [];
let trampas = [];
let nivel = 1;
let puntaje = 0;
let velocidad = 400;
let intervalo;
let jugando = false;

// Función para obtener índice de celda
function indice(x, y) {
  return y * columnas + x;
}

// Generar una posición aleatoria
function generarPosicion() {
  return {
    x: Math.floor(Math.random() * columnas),
    y: Math.floor(Math.random() * filas)
  };
}

// Generar comida o trampa aleatoria sin superponer con la serpiente
function generarElemento() {
  let pos;
  do {
    pos = generarPosicion();
  } while (
    snake.some(n => n.x === pos.x && n.y === pos.y) ||
    comida.some(f => f.x === pos.x && f.y === pos.y) ||
    trampas.some(t => t.x === pos.x && t.y === pos.y)
  );
  return pos;
}

// Inicializa comida y trampas al inicio
function generarInicio() {
  comida = [];
  trampas = [];
  for (let i = 0; i < 3; i++) comida.push(generarElemento()); // más comida al inicio
  for (let i = 0; i < 2; i++) trampas.push(generarElemento());
}

function dibujar() {
  celdas.forEach(c => c.className = "celda");
  snake.forEach(nodo => {
    celdas[indice(nodo.x, nodo.y)].classList.add("snake");
  });
  comida.forEach(f => celdas[indice(f.x, f.y)].classList.add("comida"));
  trampas.forEach(t => celdas[indice(t.x, t.y)].classList.add("trampa"));

  nivelTxt.textContent = nivel;
  tamanoTxt.textContent = snake.length;
  puntajeTxt.textContent = puntaje;
}

// Movimiento
function mover() {
  let cabeza = { ...snake[0] };
  cabeza.x += direccion.x;
  cabeza.y += direccion.y;

  // Teletransporte por bordes
  if (cabeza.x < 0) cabeza.x = columnas - 1;
  if (cabeza.x >= columnas) cabeza.x = 0;
  if (cabeza.y < 0) cabeza.y = filas - 1;
  if (cabeza.y >= filas) cabeza.y = 0;

  // Verificar colisión consigo mismo
  if (snake.some(n => n.x === cabeza.x && n.y === cabeza.y)) {
    perder();
    return;
  }

  snake.unshift(cabeza);

  // Comer comida
  const indiceComida = comida.findIndex(f => f.x === cabeza.x && f.y === cabeza.y);
  if (indiceComida !== -1) {
    puntaje += 10;
    comida.splice(indiceComida, 1); // eliminar comida comida
    // siempre que haya espacio, genera nueva
    if (comida.length < Math.max(1, Math.floor(3 * Math.pow(0.9, nivel - 1)))) {
      comida.push(generarElemento());
    }
  }
  // Tocar trampa
  else if (trampas.some(t => t.x === cabeza.x && t.y === cabeza.y)) {
    snake.pop();
    snake.pop(); // pierde 2 nodos
    puntaje -= 5;
    trampas = trampas.map(() => generarElemento()); // reposiciona trampas
    if (snake.length <= 0) {
      perder();
      return;
    }
  } else {
    snake.pop();
  }

  // Subir de nivel
  if (snake.length >= 15) {
    nivel++;
    velocidad *= 0.85;

    // Aumenta trampas un 3%
    let nuevasTrampas = Math.max(1, Math.floor(trampas.length * 1.03));
    trampas = [];
    for (let i = 0; i < nuevasTrampas; i++) trampas.push(generarElemento());

    // Disminuye comida un 10%, pero mínimo 1
    let nuevaComida = Math.max(1, Math.floor(3 * Math.pow(0.9, nivel - 1)));
    comida = [];
    for (let i = 0; i < nuevaComida; i++) comida.push(generarElemento());

    // Reinicia tamaño
    snake = snake.slice(0, 5);
    clearInterval(intervalo);
    intervalo = setInterval(mover, velocidad);
  }

  dibujar();
}

// Manejar dirección
document.addEventListener("keydown", e => {
  if (!jugando && ["ArrowUp", "ArrowDown", "ArrowLeft", "ArrowRight"].includes(e.key)) {
    // Comienza el juego con la primera dirección
    jugando = true;
    if (e.key === "ArrowUp") direccion = { x: 0, y: -1 };
    if (e.key === "ArrowDown") direccion = { x: 0, y: 1 };
    if (e.key === "ArrowLeft") direccion = { x: -1, y: 0 };
    if (e.key === "ArrowRight") direccion = { x: 1, y: 0 };
    intervalo = setInterval(mover, velocidad);
  } else if (jugando) {
    // Cambiar dirección si ya está en movimiento
    if (e.key === "ArrowUp" && direccion.y === 0) direccion = { x: 0, y: -1 };
    if (e.key === "ArrowDown" && direccion.y === 0) direccion = { x: 0, y: 1 };
    if (e.key === "ArrowLeft" && direccion.x === 0) direccion = { x: -1, y: 0 };
    if (e.key === "ArrowRight" && direccion.x === 0) direccion = { x: 1, y: 0 };
  }
});

function perder() {
  clearInterval(intervalo);
  alert(" Has perdido.\nPuntuación final: " + puntaje);
  guardarPuntaje(puntaje);
  reiniciar();
}

function reiniciar() {
  snake = [
    { x: 5, y: 5 },
    { x: 4, y: 5 },
    { x: 3, y: 5 },
    { x: 2, y: 5 },
    { x: 1, y: 5 }
  ];
  direccion = { x: 0, y: 0 };
  nivel = 1;
  puntaje = 0;
  velocidad = 400;
  jugando = false;
  clearInterval(intervalo);
  generarInicio();
  dibujar();
}

function guardarPuntaje(p) {
  let top = JSON.parse(localStorage.getItem("top5") || "[]");
  top.push(p);
  top.sort((a, b) => b - a);
  top = top.slice(0, 5);
  localStorage.setItem("top5", JSON.stringify(top));
  mostrarTop5();
}

function mostrarTop5() {
  let top = JSON.parse(localStorage.getItem("top5") || "[]");
  top5Lista.innerHTML = "";
  top.forEach(p => {
    const li = document.createElement("li");
    li.textContent = p;
    top5Lista.appendChild(li);
  });
}

// Iniciar juego
generarInicio();
mostrarTop5();
dibujar();
