#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include <stdlib.h>
using namespace std;

int** crear(int size);
void limpiar(int**,int);
void imprimir(int**,int);
void multiplayer(int**,int);
int** llenar(int**,int);
void computadora(int**,int);
string convert(int);
bool primo(string);
int** number(int**,int,int,int);
int filas(int**,int);
int columnas(int**,int);
int diagonales(int**,int);
bool verificarColumnas(int**,int,int);
bool verificarFilas(int**,int,int);
bool verificarDiagonales(int**,int,int);

int main(int argc, char const *argv[]) {
    int** matriz;
    int size;
    cout<<"----BIENVENIDO----"<<endl;
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

        }else{
            computadora(llenar(matriz,size),size);
        }

    limpiar(matriz,size);
    return 0;
}

string convert(int numero){
    stringstream ss;
    ss << numero;
    return ss.str();
}

bool primo (string numero){
    int num = atoi(numero.c_str());
    int cont;
    for (int i = 1; i < num+1; i++) {
        if(num%i==0){
            cont++;
        }
    }
    if(cont != 2){
        return false;
    }else{
        return true;
    }
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
        cont++;
        bool si = false;
        string algo;
        if(cont == 3){


        }
        if(si){
            cout<<"simon"<<endl;
        }

    } while(cont != 5);
}

void computadora(int** matriz, int size){
    string nombre;
    bool turno = true, ganador = true;
    int x,y,numero,cont = 0;
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
            matriz = number(matriz,size,x,y);
            turno = true;
            imprimir(matriz,size);
        }
        cont++;
        if (filas(matriz,size) != -2) {
            if(verificarFilas(matriz,size,filas(matriz,size))){
                if(!turno){
                    cout<<nombre<<" has ganado!"<<endl;
                }else{
                    cout<<"La computadora ha ganado"<<endl;
                }
                ganador = false;
            }
        }
        if(diagonales(matriz,size) != -2){
            if(verificarDiagonales(matriz,size,diagonales(matriz,size))){
                if(!turno){
                    cout<<nombre<<" has ganado!"<<endl;
                }else{
                    cout<<"La computadora ha ganado"<<endl;
                }
                ganador = false;

            }
        }
        if(columnas(matriz,size) != -2){
            if(verificarColumnas(matriz,size,columnas(matriz,size))){
                if(!turno){
                    cout<<nombre<<" has ganado!"<<endl;
                }else{
                    cout<<"La computadora ha ganado"<<endl;
                }
                ganador = false;
            }
        }
        if(size == 4){
            if(cont == 16){
                ganador = false;
                cout<<"Empate"<<endl;
            }
        }


    } while(ganador);
}

bool verificarDiagonales(int** matriz,int size,int numero){
    string acum = "",back = "";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(numero == 1){
                if((i == 0 && j == size-1) || (i == size-1 && j == 0)){
                    acum += convert(matriz[i][j]);
                }
                if(size == 4){
                    if((i == 1 && j == 2) || (j == 1 && i == 2)){
                        acum += convert(matriz[i][j]);
                    }
                }else if (size == 3){
                    if(i == 1 && j == 1){
                        acum += convert(matriz[i][j]);
                    }
                }
            }else if(numero == 2){
                if(i == j){
                    acum += convert(matriz[i][j]);
                }
            }

        }
    }
    for (int i = acum.size()-1; i >= 0; i--) {
        back += acum.at(i);
    }
    if (primo(back)) {
        return true;
    }else if (primo(acum)){
        return true;
    }else{
        return false;
    }
}

bool verificarFilas (int** matriz, int size, int numero){
    string acum = "",back = "";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(numero == i){
                acum += convert(matriz[i][j]);
            }
        }
    }
    for (int i = acum.size()-1; i >= 0; i--) {
        back += acum.at(i);
    }
    if (primo(back)) {
        return true;
    }else if (primo(acum)){
        return true;
    }else{
        return false;
    }
}

bool verificarColumnas(int** matriz, int size, int numero){
    string acum = "", back = "";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(j == numero){
                acum += convert(matriz[i][j]);
            }
        }
    }
    for (int i = acum.size(); i >= 0; i--) {
        back += acum[i];
    }
    if (primo(back)) {
        return true;
    }else if (primo(acum)){
        return true;
    }else{
        return false;
    }
}

int filas (int** matriz, int size){
    int cont = 0, cont2 = 0, cont3 = 0, cont4 = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matriz[i][j] != -1) {
                if(i == 0){
                    cont++;
                }else if(i == 1){
                    cont2++;
                }else if(i == 2){
                    cont3++;
                }else if(i == 3){
                    cont4++;
                }
            }//end if
        }
    }//end for
    if (cont == size) {
        return 0;
    } else if(cont2 == size){
        return 1;
    }else if(cont3 == size){
        return 2;
    }else if(cont4 == size){
        return 3;
    }else{
        return -2;
    }
}

int columnas(int** matriz, int size){
    int cont = 0, cont2 = 0, cont3 = 0, cont4 = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(matriz[i][j] != -1){
                if(j == 0){
                    cont++;
                }else if(j == 1){
                    cont2++;
                }else if(j == 2){
                    cont3++;
                }else if(j == 3){
                    cont4++;
                }
            }//end if
        }//end segundo for
    }//end primer for
    if(cont == size){
        return 0;
    }else if(cont2 == size){
        return 1;
    }else if (cont3 == size){
        return 2;
    }else if(cont4 == size){
        return 3;
    }else{
        return -2;
    }
}

int diagonales(int** matriz,int size){
    int cont = 0, cont2 = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i == 0 && j == size-1) || (i == size-1 && j == 0)) {
                if(matriz[i][j] != -1){
                    cont++;
                }
            }
            if(size == 4){
                if((i == 1 && j == 2) || (i == 2 && j == 1)){
                    cont++;
                }
            }else if(size == 3){
                if(i == 1 && j == 1){
                    cont++;
                }
            }

            if(matriz[i][j] != -1){
                if(i == j){
                    cont2++;
                }
            }
        }
    }
    if (cont == size) {
        return 1;
    }else if(cont2 == size){
        return 2;
    }else{
        return -2;
    }
}

int** number(int** matriz, int size, int x, int y){
    srand (time(NULL));
    bool ver = true;
    //verifica las casillas disponibles
    if((x+1) < size){
        if(matriz[x+1][y] == -1){
            matriz[x+1][y] = rand() % 10;
            ver = false;
        }else if ((y+1) < size){
            if (matriz[x][y+1] == -1) {
                matriz[x][y+1] = rand() % 10;
                ver = false;
            }else if ((y-1) >= 0){
                if(matriz[x][y-1] == -1){
                    matriz[x][y-1] == rand() % 10;
                    ver = false;
                }
            }
        }
    }else if ((x-1) >= 0){
        if(matriz[x-1][y] == -1){
            matriz[x-1][y] = rand() % 10;
            ver = false;
        }else if ((y+1) < size){
            if (matriz[x][y+1] == -1) {
                matriz[x][y+1] = rand() % 10;
                ver = false;
            }else if ((y-1) >= 0){
                if(matriz[x][y-1] == -1){
                    matriz[x][y-1] == rand() % 10;
                    ver = false;

                }
            }
        }
    }
    bool ver2 = false;
    if(ver){
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(matriz[i][j] == -1){
                    matriz[i][j] = rand() % 10;
                    ver2 = true;
                }
                if(ver2){
                    break;
                }
            }//segundo for
            if(ver2){
                break;
            }
        }//primer for
    }
    return matriz;
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
