#include <iostream>   // Para entrada y salida de texto (cout, cin)
#include <vector>     // Para usar vectores 2D como laberinto y visibilidad
#include <cstdlib>    // Para funciones aleatorias como rand()
#include <ctime>      // Para inicializar semilla de aleatoriedad con time()
#include <termios.h>  // Para leer teclado sin esperar Enter 
#include <unistd.h>   // Para sleep
using namespace std;

const int TAM = 25;
const char PARED = '*';
const char CAMINO = ' ';
const char JUGADOR = 'P';
const char LLAVE = 'L';
const char TRAMPA = 'T';
const char PUERTA = 'C';
const char SALIDA = 'S';
const char PUERTA_ESPECIAL = 'E';
const int RADIO_VISION = 0;

struct Jugador {
    int x, y;
    int vidas;
    int llaves;
    int puntuacion;
    int nivel;
};

// Leer una tecla sin esperar Enter
char leerTecla() {
    termios oldt, newt;
    char c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

// Generar laberinto aleatorio
void generarLaberinto(vector<vector<char>> &laberinto) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (i == 0 || j == 0 || i == TAM - 1 || j == TAM - 1)
                laberinto[i][j] = PARED;
            else
                laberinto[i][j] = (rand() % 6 == 0) ? PARED : CAMINO;
        }
    }

    // Colocar llaves
    int k = 0;
    while (k < 5) {
        int x = rand() % (TAM - 2) + 1;
        int y = rand() % (TAM - 2) + 1;
        if (laberinto[x][y] == CAMINO) {
            laberinto[x][y] = LLAVE;
            k++;
        }
    }

    // Colocar trampas
    k = 0;
    while (k < 5) {
        int x = rand() % (TAM - 2) + 1;
        int y = rand() % (TAM - 2) + 1;
        if (laberinto[x][y] == CAMINO) {
            laberinto[x][y] = TRAMPA;
            k++;
        }
    }

    // Colocar puertas normales
    k = 0;
    while (k < 3) {
        int x = rand() % (TAM - 2) + 1;
        int y = rand() % (TAM - 2) + 1;
        if (laberinto[x][y] == CAMINO) {
            laberinto[x][y] = PUERTA;
            k++;
        }
    }

    // Colocar puerta especial
    while (true) {
        int x = rand() % (TAM - 4) + 2;
        int y = rand() % (TAM - 4) + 2;
        if (laberinto[x][y] == CAMINO) {
            laberinto[x][y] = PUERTA_ESPECIAL;
            break;
        }
    }

    // Colocar salida
    laberinto[TAM - 2][TAM - 2] = SALIDA;
}

// Mostrar laberinto con visibilidad
void mostrarLaberinto(const vector<vector<char>> &lab, const vector<vector<bool>> &visible, const Jugador &jug) {
    cout << "\033[H"; // Mueve cursor al inicio
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (visible[i][j]) {
                if (i == jug.x && j == jug.y)
                    cout << JUGADOR;
                else
                    cout << lab[i][j];
            } else
                cout << '.';
        }
        cout << '\n';
    }
    cout << "\nNivel: " << jug.nivel
         << " | Vidas: " << jug.vidas
         << " | Llaves: " << jug.llaves
         << " | Puntuación: " << jug.puntuacion << endl;
}

// Actualizar visión
void actualizarVision(vector<vector<bool>> &visible, int x, int y) {
    for (int i = x - RADIO_VISION; i <= x + RADIO_VISION; i++) {
        for (int j = y - RADIO_VISION; j <= y + RADIO_VISION; j++) {
            if (i >= 0 && i < TAM && j >= 0 && j < TAM)
                visible[i][j] = true;
        }
    }
}

// Jugar un nivel
bool jugarNivel(Jugador &jug) {
    vector<vector<char>> lab(TAM, vector<char>(TAM));
    vector<vector<bool>> visible(TAM, vector<bool>(TAM, false));

    generarLaberinto(lab);
    jug.x = 1;
    jug.y = 1;
    lab[jug.x][jug.y] = CAMINO;
    actualizarVision(visible, jug.x, jug.y);

    while (jug.vidas > 0) {
        mostrarLaberinto(lab, visible, jug);
        char tecla = leerTecla();

        int nx = jug.x, ny = jug.y;
        if (tecla == 'w' || tecla == 'W') nx--;
        else if (tecla == 's' || tecla == 'S') nx++;
        else if (tecla == 'a' || tecla == 'A') ny--;
        else if (tecla == 'd' || tecla == 'D') ny++;
        else if (tecla == 'g' || tecla == 'G') return false; // salir juego

        if (lab[nx][ny] != PARED) {
            char celda = lab[nx][ny];

            if (celda == TRAMPA) {
                jug.vidas--;
                jug.puntuacion -= 5;
                cout << "\n¡Caíste en una trampa! Vidas: " << jug.vidas << endl;
                sleep(1);
            }
            else if (celda == LLAVE) {
                jug.llaves++;
                jug.puntuacion += 10;
                lab[nx][ny] = CAMINO;
                cout << "\n¡Recogiste una llave! Llaves: " << jug.llaves << endl;
                sleep(1);
            }
            else if (celda == PUERTA) {
                if (jug.llaves > 0) {
                    jug.llaves--;
                    jug.puntuacion += 20;
                    lab[nx][ny] = CAMINO;
                    cout << "\n¡Abriste una puerta! Llaves restantes: " << jug.llaves << endl;
                    sleep(1);
                } else {
                    continue; // no pasa
                }
            }
            else if (celda == PUERTA_ESPECIAL) {
                jug.puntuacion += 100;
                jug.nivel++;
                cout << "\n¡Puerta especial encontrada! Pasas al siguiente nivel.\n";
                sleep(2);
                return true; // pasar nivel
            }
            else if (celda == SALIDA) {
                jug.puntuacion += 150;
                jug.nivel++;
                cout << "\n¡Llegaste a la salida! Pasas al siguiente nivel.\n";
                sleep(2);
                return true; // pasa al siguiente nivel
            }

            jug.x = nx;
            jug.y = ny;
            actualizarVision(visible, jug.x, jug.y);
        }
    }

    return false;
}

int main() {
    srand(time(0));
    Jugador jug{1, 1, 3, 0, 0, 1};

    system("clear");
    cout << "\033[?25l"; // Oculta cursor

    bool seguir = true;
    while (seguir && jug.vidas > 0) {
        seguir = jugarNivel(jug);
    }

    cout << "\033[?25h"; // Muestra cursor
    cout << "\nJuego terminado. Nivel alcanzado: " << jug.nivel
         << " | Puntuación total: " << jug.puntuacion << endl;

    return 0;
}
