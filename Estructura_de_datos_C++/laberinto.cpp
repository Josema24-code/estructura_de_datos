#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int TAM = 25;
const char PARED = '*';
const char CAMINO = ' ';
const char JUGADOR = 'P';
const char LLAVE = 'L';
const char TRAMPA = 'T';
const char PUERTA = 'C';
const char SALIDA = 'S';
const int RADIO_VISION = 2;

struct Jugador {
    int x, y;
    int vidas;
    int llaves;
};

// Generar laberinto aleatorio
void generarLaberinto(vector<vector<char>> &laberinto) {
    srand(time(0));
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (i == 0 || j == 0 || i == TAM - 1 || j == TAM - 1)
                laberinto[i][j] = PARED;
            else
                laberinto[i][j] = (rand() % 5 == 0) ? PARED : CAMINO;
        }
    }

    // Colocar elementos especiales
    for (int k = 0; k < 5; k++) laberinto[rand() % (TAM - 2) + 1][rand() % (TAM - 2) + 1] = LLAVE;
    for (int k = 0; k < 5; k++) laberinto[rand() % (TAM - 2) + 1][rand() % (TAM - 2) + 1] = TRAMPA;
    for (int k = 0; k < 3; k++) laberinto[rand() % (TAM - 2) + 1][rand() % (TAM - 2) + 1] = PUERTA;

    // Colocar salida
    laberinto[TAM - 2][TAM - 2] = SALIDA;
}

// Mostrar el laberinto con visibilidad limitada
void mostrarLaberinto(const vector<vector<char>> &lab, const vector<vector<bool>> &visible, const Jugador &jug) {
    system("clear"); // Usa "cls" en Windows
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (visible[i][j])
                cout << (i == jug.x && j == jug.y ? JUGADOR : lab[i][j]);
            else
                cout << '.';
        }
        cout << endl;
    }
    cout << "\nVidas: " << jug.vidas << " | Llaves: " << jug.llaves << endl;
}

// Actualizar visibilidad alrededor del jugador
void actualizarVision(vector<vector<bool>> &visible, int x, int y) {
    for (int i = x - RADIO_VISION; i <= x + RADIO_VISION; i++) {
        for (int j = y - RADIO_VISION; j <= y + RADIO_VISION; j++) {
            if (i >= 0 && i < TAM && j >= 0 && j < TAM)
                visible[i][j] = true;
        }
    }
}

int main() {
    vector<vector<char>> lab(TAM, vector<char>(TAM));
    vector<vector<bool>> visible(TAM, vector<bool>(TAM, false));
    Jugador jug{1, 1, 3, 0};

    generarLaberinto(lab);
    lab[jug.x][jug.y] = CAMINO;
    actualizarVision(visible, jug.x, jug.y);

    char tecla;
    while (jug.vidas > 0) {
        mostrarLaberinto(lab, visible, jug);
        cout << "\nUsa W A S D para moverte, Q para salir: ";
        cin >> tecla;

        int nx = jug.x, ny = jug.y;

        if (tecla == 'w' || tecla == 'W') nx--;
        else if (tecla == 's' || tecla == 'S') nx++;
        else if (tecla == 'a' || tecla == 'A') ny--;
        else if (tecla == 'd' || tecla == 'D') ny++;
        else if (tecla == 'q' || tecla == 'Q') break;

        // Validar movimiento
        if (lab[nx][ny] != PARED) {
            char celda = lab[nx][ny];

            if (celda == TRAMPA) {
                jug.vidas--;
                cout << "\n¡Caíste en una trampa! Vidas restantes: " << jug.vidas << endl;
            } 
            else if (celda == LLAVE) {
                jug.llaves++;
                cout << "\nEncontraste una llave. Llaves: " << jug.llaves << endl;
                lab[nx][ny] = CAMINO;
            } 
            else if (celda == PUERTA) {
                if (jug.llaves > 0) {
                    jug.llaves--;
                    cout << "\nUsaste una llave para abrir la puerta." << endl;
                    lab[nx][ny] = CAMINO;
                } else {
                    cout << "\nNecesitas una llave para abrir esta puerta." << endl;
                    continue;
                }
            } 
            else if (celda == SALIDA) {
                cout << "\n¡Felicidades! Escapaste del laberinto " << endl;
                break;
            }

            jug.x = nx;
            jug.y = ny;
            actualizarVision(visible, jug.x, jug.y);
        }
    }

    if (jug.vidas <= 0)
        cout << "\nPerdiste todas tus vidas. Fin del juego \n";

    return 0;
}
