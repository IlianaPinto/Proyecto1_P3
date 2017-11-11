#include <iostream>
using namespace std;

char** crear(int size);
void limpiar(char**,int);
void imprimir(char**,int);

int main(int argc, char const *argv[]) {
    char** matriz;
    int size;
    cout<<"-----BIENVENIDO-----"<<endl;
        int resp, resp2;
        cout<<"Elija el tamaño"<<endl
        <<" 1. 4X4"<<endl
        <<" 2. 3X3"<<endl
        <<" 3. 2X2"<<endl;
        cin>>resp;
        while (resp < 1 || resp > 3) {
            cout<<"Opcion invalida, ingrese nuevamente"<<endl;
            cin>>resp;
        }
        cout<<endl;
        cout<<"Elija con quien desea jugar"<<endl
        <<" 1. Multiplayer"<<endl
        <<" 2. Computadora"<<endl;
        cin>>resp2;
        while (resp2 < 1 || resp2 > 2) {
            cout<<"Opcion invalida, ingrese nuevamente"<<endl;
            cin>>resp2;
        }
        cout<<endl;
        if (resp == 1) {
            matriz = crear(4);
            size = 4;
        }else if(resp == 2){
            matriz = crear(3);
            size = 3;
        }else{
            matriz = crear(2);
            size = 2;
        }
        
    limpiar(matriz,size);
    return 0;
}

char** crear(int size){
    char** matriz = new char*[size];
    for (int i = 0; i < size; i++) {
        matriz[i] = new char[size];
    }
    return matriz;
}

void imprimir(char** matriz, int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout<<"["<<matriz[i][j]<<"]";
        }
        cout<<endl;
    }
}

void limpiar(char** matriz, int size){
    for (int i = 0; i < size; i++) {
        delete[] matriz[i];
        matriz[i] = NULL;
    }
    delete[] matriz;
}
