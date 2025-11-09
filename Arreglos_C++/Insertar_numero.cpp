#include <iostream>
using namespace std;
int main(){
    //arreglo inicial
    int numeros[5] = {30,40,70,50,20};
    for(int i=0;i<5;i++){
        cout<<numeros[i]<<endl;
    }

    //se pide un nuevo numero
    cout<<"ingrese un numero para cambiar"<<endl;
    int nuevo_numero;
    cin>>nuevo_numero;

    //se recorre el arreglo de atras hacia adelante
    for(int i=4;i>0;i--){
        //se mueve el numero a la derecha
        numeros[i]=numeros[i-1];
    }

    //se inserta el nuevo numero en la primera posicion
    numeros[0]=nuevo_numero;
    //se muestra el nuevo arreglo
    for(int i=0;i<5;i++){
        cout<<numeros[i]<<endl;
    }
    return 0;
}