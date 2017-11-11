#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int** crear(int size);
void limpiar(int**,int);
void imprimir(int**,int);
void multiplayer(int**,int);
int** llenar(int**,int);
void computadora(int**,int);

int main(int argc, char const *argv[]) {
    int** matriz;
    int size;
    cout<<"-----BIENVENIDO-----"<<endl;
        int resp, resp2;
        cout<<"Elija el tamaño"<<endl
        <<" 1. 4X4"<<endl
        <<" 2. 3X3"<<endl
        <<" 3. 2X2"<<endl;
        cin>>resp;
        while (resp < 1 || resp > 3) {
            cout<<endl;
            cout<<"Opcion invalida, ingrese nuevamente"<<endl;
            cin>>resp;
        }
        cout<<endl;
        cout<<"Elija con quien desea jugar"<<endl
        <<" 1. Multiplayer"<<endl
        <<" 2. Computadora"<<endl;
        cin>>resp2;
        while (resp2 < 1 || resp2 > 2) {
            cout<<endl;
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

        if (resp2 == 1) {
            multiplayer(llenar(matriz,size),size);
        }else{
            computadora(llenar(matriz,size),size);
        }

    limpiar(matriz,size);
    return 0;
}

void multiplayer(int** matriz, int size){
    string nombre1, nombre2;
    bool turno = true;
    int x,y,numero,cont=0;
    cout<<"Jugador 1 ingrese su nombre: "<<endl;
    cin>>nombre1;
    cout<<"Jugador 2 ingrese su nombre: "<<endl;
    cin>>nombre2;
    do {
        cout<<endl;
        if(turno){
            cout<<nombre1<<" es tu turno"<<endl;
            turno = false;
        }else{
            cout<<nombre2<<" es tu turno"<<endl;
            turno = true;
        }
        imprimir(matriz,size);
        cout<<"Ingrese numero:"<<endl;
        cin>>numero;
        while (numero < 0 || numero > 9) {
            cout<<endl;
            cout<<"Numero invalido, ingrese nuevamente"<<endl;
            cout<<"Ingrese numero:"<<endl;
            cin>>numero;
        }
        cout<<"Ingrese posicion en x: "<<endl;
        cin>>x;
        cout<<"Ingrese posicion en y:"<<endl;
        cin>>y;
        while(x >= size || y >= size || x < 0 || y < 0 || matriz[x][y] != -1){
            cout<<endl;
            cout<<"La posicion ingresada no es valida, ingrese nuevamente"<<endl;
            cout<<"Ingrese posicion en x: "<<endl;
            cin>>x;
            cout<<"Ingrese posicion en y:"<<endl;
            cin>>y;
        }

        matriz[x][y] = numero;
        imprimir(matriz,size);


        cont ++;
    } while(cont!=5);
}

void computadora(int** matriz, int size){
    string nombre;
    bool turno = true;
    int x,y,numero;
    cout<<"Ingrese su nombre:"<<endl;
    cin>>nombre;
    imprimir(matriz,size);
    do {
        cout<<endl;
        if (turno) {
            cout<<nombre<<" es tu turno"<<endl;
            cout<<"Ingrese numero:"<<endl;
            cin>>numero;
            while (numero > 9 || numero < 0) {
                cout<<endl;
                cout<<"Numero incorrecto, ingrese nuevamente"<<endl;
                cin>>numero;
            }
            cout<<"Ingrese posicion en x:"<<endl;
            cin>>x;
            cout<<"Ingrese posicion en y:"<<endl;
            cin>>y;
            while (x < 0 || x >= size || y < 0 || y >= size || matriz[x][y] != -1) {
                cout<<"Posicion incorrecta, ingrese de nuevo"<<endl;
                cout<<"Ingrese posicion en x:"<<endl;
                cin>>x;
                cout<<"Ingrese posicion en y:"<<endl;
                cin>>y;
            }
            matriz[x][y] = numero;
            imprimir(matriz,size);
            turno = false;
        }else{
            cout<<"Turno de la computadora"<<endl;

            turno = true;

        }


    } while(false);
}

int** llenar(int** matriz, int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matriz[i][j] = -1;
        }
    }
    return matriz;
}

int** crear(int size){
    int** matriz = new int*[size];
    for (int i = 0; i < size; i++) {
        matriz[i] = new int[size];
    }
    return matriz;
}

void imprimir(int** matriz, int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matriz[i][j] == -1) {
                cout<<"[ ]";
            }else{
                cout<<"["<<matriz[i][j]<<"]";
            }
        }
        cout<<endl;
    }
}

void limpiar(int** matriz, int size){
    for (int i = 0; i < size; i++) {
        delete[] matriz[i];
        matriz[i] = NULL;
    }
    delete[] matriz;
}
