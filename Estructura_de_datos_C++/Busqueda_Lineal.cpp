#include <iostream>
int main(){
    int numeros [4] = {10, 20, 30, 40};
    int encontrar_Numero;
    std::cout << "Ingrese un numero para buscar:";
    std::cin >> encontrar_Numero;
    bool encontrado = false;
    for (int i = 0; i < 4; i++){
        if (numeros[i] == encontrar_Numero){
            encontrado = true;
            std::cout << "Numero encontrado en la posicion: " <<i << std ::endl;
            
            break;
        
        }
        
    }
    if (!encontrado){
            std::cout << "Numero no encontrado" << std::endl;
        }

    return 0;

}