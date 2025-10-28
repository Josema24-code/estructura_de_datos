import os
import random
import time

# ----- Generar tableros por dificultad -----
def generar_tablero(vacios):
    base = [
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
    tablero = [fila[:] for fila in base]
    for _ in range(vacios):
        i, j = random.randint(0, 8), random.randint(0, 8)
        tablero[i][j] = 0
    return tablero

dificultades = {
    "1": ("Fácil", 30),
    "2": ("Media", 40),
    "3": ("Difícil", 50),
    "4": ("Experto", 60),
    "5": ("Maestro", 65)
}

def limpiar_pantalla():
    os.system("clear" if os.name == "posix" else "cls")

def dibujar_tablero(tablero, nivel, vidas, dificultad):
    limpiar_pantalla()
    print(f"Sudoku - Nivel {nivel+1} ({dificultad}) |  Vidas: {vidas}")
    print("Formato: fila columna número (ej: 3 4 8) | Escribe 'salir' para terminar\n")

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

# ----- Validaciones Sudoku -----
def movimiento_valido(tablero, fila, col, num):
    if num in tablero[fila]:  # Fila
        return False
    for i in range(9):  # Columna
        if tablero[i][col] == num:
            return False
    start_row, start_col = (fila // 3) * 3, (col // 3) * 3
    for i in range(start_row, start_row + 3):
        for j in range(start_col, start_col + 3):
            if tablero[i][j] == num:
                return False
    return True

def tablero_completo(tablero):
    return all(all(c != 0 for c in f) for f in tablero)

# ----- Juego principal -----
def main():
    limpiar_pantalla()
    print("Selecciona dificultad:")
    for k, (nombre, _) in dificultades.items():
        print(f"{k}. {nombre}")
    opcion = input("\nOpción: ").strip()

    if opcion not in dificultades:
        print("Dificultad inválida.")
        return

    dificultad, vacios = dificultades[opcion]
    vidas = 3
    nivel = 0
    max_niveles = 5
    tablero = generar_tablero(vacios)

    while True:
        dibujar_tablero(tablero, nivel, vidas, dificultad)
        entrada = input("\n→ Movimiento: ").strip()
        if entrada.lower() == "salir":
            break

        try:
            fila, col, num = map(int, entrada.split())
            if not (1 <= fila <= 9 and 1 <= col <= 9 and 1 <= num <= 9):
                print(" Coordenadas fuera de rango (1-9).")
                time.sleep(1.5)
                continue
            fila -= 1
            col -= 1
        except:
            print(" Entrada inválida. Usa formato: fila col num")
            time.sleep(1.5)
            continue

        if tablero[fila][col] != 0:
            print(" Esa celda ya tiene un número.")
            time.sleep(1.5)
            continue

        if movimiento_valido(tablero, fila, col, num):
            tablero[fila][col] = num
            print(f" Movimiento correcto ({fila+1},{col+1}) = {num}")
        else:
            vidas -= 1
            print(f" Movimiento inválido ({fila+1},{col+1}) = {num}. Pierdes una vida.  {vidas}")
            if vidas == 0:
                print("\n💀 Te quedaste sin vidas. Fin del juego.")
                break
        time.sleep(1)

        # Si se completó el tablero
        if tablero_completo(tablero):
            print("\n Nivel completado. Avanzando al siguiente...")
            time.sleep(1.5)
            nivel += 1

            if nivel >= max_niveles:
                print("\n ¡Ganaste todos los niveles! Felicidades.")
                break

            if vidas < 4:
                vidas += 1
                print(f" Ganaste una vida extra. Ahora tienes {vidas}.")
                time.sleep(1.5)

            tablero = generar_tablero(vacios)

if __name__ == "__main__":
    main()
