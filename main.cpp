#include <iostream>
using namespace std;

char** crear(int size);
void limpiar(char**,int);
void imprimir(char**,int);

int main(int argc, char const *argv[]) {
    do {

    } while(true);
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
