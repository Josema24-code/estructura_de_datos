import os
import random
import time

# ----- Tablero base correcto -----
BASE = [
    [5, 3, 4, 6, 7, 8, 9, 1, 2],
    [6, 7, 2, 1, 9, 5, 3, 4, 8],
    [1, 9, 8, 3, 4, 2, 5, 6, 7],
    [8, 5, 9, 7, 6, 1, 4, 2, 3],
    [4, 2, 6, 8, 5, 3, 7, 9, 1],
    [7, 1, 3, 9, 2, 4, 8, 5, 6],
    [9, 6, 1, 5, 3, 7, 2, 8, 4],
    [2, 8, 7, 4, 1, 9, 6, 3, 5],
    [3, 4, 5, 2, 8, 6, 1, 7, 9],
]

# ----- Dificultades -----
DIFICULTADES = {
    "1": ("Muy fácil", 25),
    "2": ("Fácil", 40),
    "3": ("Medio", 50),
    "4": ("Difícil", 55),
    "5": ("Muy Difícil", 60)
}

# ----- Funciones -----
def limpiar_pantalla():
    os.system("clear" if os.name == "posix" else "cls")

def generar_tablero(vacios):
    tablero = [fila[:] for fila in BASE]
    posiciones = [(i, j) for i in range(9) for j in range(9)]
    random.shuffle(posiciones)
    for k in range(vacios):
        i, j = posiciones[k]
        tablero[i][j] = 0
    return tablero

def dibujar_tablero(tablero, nivel, vidas, dificultad, jugador):
    limpiar_pantalla()
    print(f"Jugador: {jugador}")
    print(f"Sudoku - Nivel {nivel+1} ({dificultad}) |  Vidas: {vidas}")
    print("Instrucciones: fila columna número (ej: 3 4 8) | Escribe 'salir' para terminar\n")

    for i in range(9):
        if i % 3 == 0:
            print("+-------+-------+-------+")
        fila = ""
        for j in range(9):
            if j % 3 == 0:
                fila += "| "
            val = tablero[i][j]
            fila += str(val) if val != 0 else "."
            fila += " "
        fila += "|"
        print(fila)
    print("+-------+-------+-------+")

def tablero_completo(tablero):
    return all(all(c != 0 for c in f) for f in tablero)

def guardar_puntaje(nombre, puntaje, tiempo, niveles, vidas):
    with open("puntajes.txt", "a") as f:
        f.write(f"{nombre},{puntaje},{tiempo:.1f},{niveles},{vidas}\n")

def mostrar_puntajes():
    if not os.path.exists("puntajes.txt"):
        print("\nNo hay puntajes registrados todavía.")
        return
    print("\n--- Tabla de Puntajes ---")
    with open("puntajes.txt", "r") as f:
        puntajes = [line.strip().split(",") for line in f]
        puntajes = sorted(puntajes, key=lambda x: float(x[1]), reverse=True)
        print(f"{'Pos':<4}{'Jugador':<15}{'Puntos':<10}{'Tiempo(s)':<12}{'Niveles':<9}{'Vidas':<6}")
        for i, (nombre, p, t, n, v) in enumerate(puntajes[:10], start=1):
            print(f"{i:<4}{nombre:<15}{p:<10}{t:<12}{n:<9}{v:<6}")

# ----- Juego principal -----
def main():
    limpiar_pantalla()
    jugador = input("Ingresa tu nombre de usuario: ").strip().capitalize()
    if not jugador:
        jugador = "Anonimo"

    print("\nSelecciona dificultad:")
    for k, (nombre, _) in DIFICULTADES.items():
        print(f"{k}. {nombre}")
    opcion = input("\nOpción: ").strip()

    if opcion not in DIFICULTADES:
        print("Dificultad inválida.")
        return

    dificultad, vacios = DIFICULTADES[opcion]
    vidas = 3
    nivel = 0
    max_niveles = 3
    inicio_juego = time.time()

    while True:
        tablero = generar_tablero(vacios)
        solucion = [fila[:] for fila in BASE]

        while True:
            dibujar_tablero(tablero, nivel, vidas, dificultad, jugador)
            entrada = input("\n→ Movimiento: ").strip()
            if entrada.lower() == "salir":
                print("\nJuego terminado por el jugador.")
                tiempo_total = time.time() - inicio_juego
                puntaje_final = (nivel * 1000) + (vidas * 100) - (tiempo_total / 2)
                guardar_puntaje(jugador, round(puntaje_final, 1), tiempo_total, nivel, vidas)
                mostrar_puntajes()
                return

            try:
                fila, col, num = map(int, entrada.split())
                if not (1 <= fila <= 9 and 1 <= col <= 9 and 1 <= num <= 9):
                    print("Coordenadas fuera de rango (1-9).")
                    time.sleep(1.5)
                    continue
                fila -= 1
                col -= 1
            except:
                print("Entrada inválida. Usa formato: fila col num")
                time.sleep(1.5)
                continue

            if tablero[fila][col] != 0:
                print("Esa celda ya tiene un número.")
                time.sleep(1.5)
                continue

            # Comparar con la solución
            if solucion[fila][col] == num:
                tablero[fila][col] = num
                print("Movimiento correcto.")
            else:
                vidas -= 1
                print(f"Incorrecto. Pierdes una vida. Vidas restantes: {vidas}")
                if vidas == 0:
                    print("\nTe quedaste sin vidas. Fin del juego.")
                    tiempo_total = time.time() - inicio_juego
                    puntaje_final = (nivel * 1000) + (vidas * 100) - (tiempo_total / 2)
                    guardar_puntaje(jugador, round(puntaje_final, 1), tiempo_total, nivel, vidas)
                    mostrar_puntajes()
                    return
            time.sleep(1)

            if tablero_completo(tablero):
                nivel += 1
                print(f"\nNivel {nivel} completado.")
                if nivel == max_niveles:
                    print(f"\nHas ganado el juego completo, {jugador}.")
                    tiempo_total = time.time() - inicio_juego
                    puntaje_final = (nivel * 1000) + (vidas * 100) - (tiempo_total / 2)
                    guardar_puntaje(jugador, round(puntaje_final, 1), tiempo_total, nivel, vidas)
                    mostrar_puntajes()
                    return
                print("Pasando al siguiente nivel...")
                time.sleep(2)
                break

if __name__ == "__main__":
    main()
