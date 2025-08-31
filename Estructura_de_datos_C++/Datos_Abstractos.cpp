#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    string apellido;
    int edad;
};

int main() {
    Persona personas[3] = 
    {
        {"Jose", "Pérez", 30},
        {"Ana", "Valdez", 25},
        {"Ramon", "Ramírez", 40}
    };

    for (int i = 0; i < 3; i++) 
    {
        cout << "Persona " << i+1 << endl;
        cout << "Nombre: " << personas[i].nombre << endl;
        cout << "Apellido: " << personas[i].apellido << endl;
        cout << "Edad: " << personas[i].edad << endl;
        cout << "------------------" << endl;
    }

    return 0;
}
