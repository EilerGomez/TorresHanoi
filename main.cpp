#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
bool existeElNumero(int lista[], int size, int numAleatorio){
    bool existe = false;
    for (int i = 0; i < size; ++i) {
        if(lista[i]==numAleatorio){
            existe=true;
            i=size;
        }
    }
    return existe;
}
void generarTamanioDeDiscoAleatorio(int listaNumeros[], int size){
    int lispaPosNumeros[7]={2,4,6,8,10,12,14};
    for (int i = 0; i < size; ++i){
        int num  = 0 + rand() % (8- 1);
        int numDisk=lispaPosNumeros[num];
        while(existeElNumero(listaNumeros,i,numDisk)){
             num  = 0 + rand() % (8- 1);
             numDisk=lispaPosNumeros[num];
        }
        listaNumeros[i]=numDisk;
        //cout<<numDisk<<endl;
    }
}
void imprimirNumerosAleatorios(int lista[], int size){
    for (int i = 0; i < size; ++i) {
        cout<<lista[i]<<endl;
    }
}
struct Nodo{
    int valor;
    Nodo *siguiente;
};

void agregarNodo(Nodo* &lista, int valor){
    Nodo *nuevo = new Nodo();
    nuevo->valor=valor;
    nuevo->siguiente=lista;
    lista=nuevo;
    //cout<<"Agregando nuevo nodo con valor: "<<valor<<endl;

}

void imprimirNodos(Nodo *lista1){
    Nodo *lista = lista1;
    while (lista!=NULL){
        cout<<lista->valor<<endl;
        lista=lista->siguiente;
    }
}
void IniciarvaloresNodos(int listaNumeros[], int size, Nodo *lista){
    for (int i = 0; i < size; ++i) {
        agregarNodo(lista,listaNumeros[i]);
    }
}

void imprimirTorre(Nodo *lista1){
    Nodo *lista =lista1;
    while(lista!=NULL)
    {
        int numEspacios=(18-lista->valor)/2;
        for (int i = 0; i < numEspacios; ++i) {
            cout<<" ";
        }
        for (int i = 0; i < lista->valor; ++i) {
            cout<<"#";
        }
        cout<<endl;
        lista = lista->siguiente;

    }
    cout<<"=================="<<endl<<endl;
}
int contarRango(Nodo *lista){
    int rango=0;
    Nodo *tmp=lista;
    while(tmp!=NULL){
        rango++;
        tmp=tmp->siguiente;
    }
    return rango;
}
void ImprimirEspacios(Nodo *tmp){
    int numEspacios=(18-tmp->valor)/2;
    for (int i = 0; i < numEspacios; ++i) {
        cout<<" ";
    }
}
void imprimirNivel(Nodo *tmp){
    ImprimirEspacios(tmp);
    for (int i = 0; i < tmp->valor; ++i) {
        cout<<"#";
    }
    ImprimirEspacios(tmp);
}

void imprimirBase(){
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 16; ++i) {
            cout<<"_";
            if(i==7){
                cout<<"T"<<j+1;
            }
        }
        cout<<"                 ";
    }
    cout<<endl<<endl;
}
void imprimirTorres(Nodo *lista1, Nodo *lista2, Nodo *lista3){

    Nodo *temp1 =lista1, *temp2=lista2, *temp3=lista3;

    int size1 = contarRango(temp1);
    int size2= contarRango(temp2);
    int size3= contarRango(temp3);
    //cout<<size1<<endl;
    for (int i = 7; i >0 ; --i) {
        if(size1<=i){
            imprimirNivel(temp1);
            temp1=temp1->siguiente;
            size1--;
        }

        cout<<"                 ";
        if(size2 >= i){
            imprimirNivel(temp2);
            temp2=temp2->siguiente;
            //size2--;
        }
        cout<<"                 ";
        if(size3 >= i){
            imprimirNivel(temp3);
            temp3=temp3->siguiente;
        }
        cout<<endl;
    }
    imprimirBase();

}

int main(){
    Nodo *pila1= nullptr, *recorrer= nullptr, *pila2= nullptr, *pila3= nullptr;//IMPORTANTE INICIAILIZAR LOS PUNTEROS CON NULLPTR
    int size=7;
    int listaNumeros[7];
    srand(time(NULL));
    generarTamanioDeDiscoAleatorio(listaNumeros,size);
    //imprimirNumerosAleatorios(listaNumeros,size);
    for (int i = 0; i < size; ++i) {
        agregarNodo(pila1,listaNumeros[i]);
    }/*
    cout<<"va aqui agregando pila 1"<<endl;
    generarTamanioDeDiscoAleatorio(listaNumeros,size);
    for (int i = 0; i < 5; ++i) {
        agregarNodo(pila2,listaNumeros[i]);
    }
    cout<<"va aqui agregando pila 2"<<endl;
    generarTamanioDeDiscoAleatorio(listaNumeros,size);
    for (int i = 0; i < 3; ++i) {
        agregarNodo(pila3,listaNumeros[i]);
    }
    cout<<"va aqui agregando pila 3"<<endl;
    */
    imprimirTorres(pila1,pila2,pila3);

}

