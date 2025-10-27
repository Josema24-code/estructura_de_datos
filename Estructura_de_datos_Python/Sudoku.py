import curses
import random

# Crear 25 tableros vacíos 9x9 (dificultades)
tableros = [[[0 for _ in range(9)] for _ in range(9)] for _ in range(25)]

# Llenar algunos números de ejemplo
for t in range(25):
    for _ in range(20):
        i, j = random.randint(0, 8), random.randint(0, 8)
        tableros[t][i][j] = random.randint(1, 9)

def dibujar_tablero(stdscr, tablero, vidas, nivel):
    stdscr.clear()
    max_y, max_x = stdscr.getmaxyx()

    # Evita error si la ventana es pequeña
    if max_y < 35 or max_x < 40:
        stdscr.addstr(0, 0, "Por favor agranda la ventana de la terminal.")
        stdscr.refresh()
        return

    stdscr.addstr(0, 0, f"Sudoku - Nivel {nivel+1} | Vidas: {vidas}")
    stdscr.addstr(1, 0, "Formato: fila columna número (ej: 1 2 9)")

    for i in range(9):
        if i % 3 == 0:
            stdscr.addstr(2 + i*2, 0, "+-------+-------+-------+\n")
        fila = ""
        for j in range(9):
            if j % 3 == 0:
                fila += "| "
            val = tablero[i][j]
            fila += str(val) if val != 0 else "."
            fila += " "
        fila += "|"
        stdscr.addstr(3 + i*2, 0, fila)
    stdscr.addstr(21, 0, "+-------+-------+-------+\n")
    stdscr.refresh()

def main(stdscr):
    curses.curs_set(0)
    nivel = 0
    tablero = [fila[:] for fila in tableros[nivel]]
    vidas = 3

    while vidas > 0:
        dibujar_tablero(stdscr, tablero, vidas, nivel)
        stdscr.addstr(23, 0, "Ingresa movimiento (o 'salir'): ")
        stdscr.clrtoeol()
        stdscr.refresh()

        try:
            entrada = stdscr.getstr(23, 33, 10).decode().strip()
        except:
            continue

        if entrada.lower() == "salir":
            break

        try:
            fila, col, num = map(int, entrada.split())
            if 0 <= fila < 9 and 0 <= col < 9 and 1 <= num <= 9:
                # Verificación básica (no repetir en fila)
                if num in tablero[fila]:
                    vidas -= 1
                    stdscr.addstr(25, 0, "Número repetido. Pierdes una vida.")
                else:
                    tablero[fila][col] = num
                    stdscr.addstr(25, 0, "Movimiento válido.")
            else:
                stdscr.addstr(25, 0, "Coordenadas fuera de rango.")
        except:
            stdscr.addstr(25, 0, "Entrada inválida. Usa: fila col num")

        stdscr.clrtoeol()
        stdscr.refresh()
        curses.napms(800)

        # Si completó el tablero
        if all(all(c != 0 for c in fila) for fila in tablero):
            stdscr.addstr(27, 0, "Nivel completado. Avanzando...")
            stdscr.refresh()
            curses.napms(1000)
            nivel += 1
            if nivel >= 25:
                stdscr.addstr(28, 0, "Ganaste todos los niveles!")
                stdscr.refresh()
                curses.napms(2000)
                break
            tablero = [fila[:] for fila in tableros[nivel]]

    stdscr.addstr(29, 0, "Fin del juego. Presiona una tecla para salir.")
    stdscr.refresh()
    stdscr.getch()

if __name__ == "__main__":
    curses.wrapper(main)
