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
void imprimir18Espacios(){
    for (int i = 0; i < 18; ++i) {
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
        if(size1>=i){
            imprimirNivel(temp1);
            temp1=temp1->siguiente;
        //    size1--;
        }else{
            imprimir18Espacios();
        }

        cout<<"                 ";
        if(size2 >=i){
            imprimirNivel(temp2);
            temp2=temp2->siguiente;
            //size2--;
        }else{
            imprimir18Espacios();
        }

        cout<<"                 ";
        if(size3 >= i){
            imprimirNivel(temp3);
            temp3=temp3->siguiente;
        }else{
            imprimir18Espacios();
        }
        cout<<endl;
    }
    imprimirBase();

}
void POP(Nodo * &pila, int torre){

    if (pila != nullptr) {

        Nodo* temp = pila;
        pila = pila->siguiente;
        delete temp; // Liberar la memoria del nodo eliminado
    } else {

    }

}
bool verificarSiGano(Nodo *pila){
    imprimirNodos(pila);
    bool gano=false;
    if(contarRango(pila)==7){
        Nodo *tmp = pila;
        int num=tmp->valor;
        tmp=tmp->siguiente;
        while(tmp!=NULL){
            if(num>tmp->valor){
                gano=false;
                tmp=NULL;
            }else{
                gano=true;
                num=tmp->valor;
                tmp=tmp->siguiente;
            }
        }
    }
    if(gano){
        cout<<"***************************EXCELENTE HAS GANADO***************************"<<endl<<endl;
    }
    //cout<<"verificando si gano "<<gano<<endl;
    return gano;
}


void Menu(Nodo *pila1, Nodo *pila2, Nodo *pila3){
    imprimirTorres(pila1,pila2,pila3);
    bool seguir=true;
    Nodo *PilaGanar= nullptr;
    while(seguir){
        int TorreQuitar;
        int TorrePoner;
        cout<<"Para salir ingrese -1 en cualquier opcion: "<<endl;
        cout<<"Ingrese el numero de Torre a la que quiere quitar: "<<endl;
        cin>>TorreQuitar;
        cout<<"Ingrese el numero de Torre a la que quiere poner: "<<endl;
        cin>>TorrePoner;
        int valor;
        switch (TorreQuitar) {
            case 1:

                if(pila1!= nullptr){//indica que si es numero o un rango de disco
                    valor=pila1->valor;
                    if(TorrePoner==2){
                        if(pila2== nullptr){
                            POP(pila1,1);
                            agregarNodo(pila2,valor);
                        }else{
                            if(pila2->valor < pila1->valor){
                                cout<<"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Movimiento No valido!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                            }else{
                                POP(pila1,1);
                                agregarNodo(pila2,valor);
                                PilaGanar=pila2;
                            }
                        }
                    }else if(TorrePoner==3){
                        if(pila3== nullptr){
                            POP(pila1,1);
                            agregarNodo(pila3,valor);
                        }else{

                            if(pila3->valor < pila1->valor){//evalua que el disco de abajo sea mas grande
                                cout<<"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Movimiento No valido!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                            }else{
                                POP(pila1,1);
                                agregarNodo(pila3,valor);
                                PilaGanar=pila3;
                            }
                        }
                    }
                }
                break;
            case 2:

                if(pila2!= nullptr){//indica que si es numero o un rango de disco
                    valor=pila2->valor;
                    if(TorrePoner==1){
                        if(pila1== nullptr){
                            POP(pila2,2);
                            agregarNodo(pila1,valor);
                        }else{
                            if(pila1->valor < pila2->valor){
                                cout<<"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Movimiento No valido!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                            }else{
                                POP(pila2,2);
                                agregarNodo(pila1,valor);
                                PilaGanar=pila1;
                            }
                        }

                    }else if(TorrePoner==3){
                        if(pila3== nullptr){
                            POP(pila2,2);
                            agregarNodo(pila3,valor);
                        }else{
                            if(pila3->valor < pila2->valor){
                                cout<<"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Movimiento No valido!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                            }else{
                                POP(pila2,2);
                                agregarNodo(pila3,valor);
                                PilaGanar=pila3;
                            }
                        }

                    }
                }
                break;
            case 3:

                if(pila3!= nullptr){//indica que si es numero o un rango de disco
                    valor=pila3->valor;
                    if(TorrePoner==2){
                        if(pila2== nullptr){
                            POP(pila3,3);
                            agregarNodo(pila2,valor);
                        }
                        else{
                            if(pila2->valor < pila3->valor){
                                cout<<"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Movimiento No valido!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                            }else{
                                POP(pila3,3);
                                agregarNodo(pila2,valor);
                                PilaGanar=pila2;
                            }
                        }

                    }else if(TorrePoner==1){
                        if(pila1== nullptr){
                            POP(pila3,3);
                            (pila1,valor);
                        }else{
                            if(pila1->valor < pila3->valor){
                                cout<<"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Movimiento No valido!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                            }else{
                                POP(pila3,3);
                                agregarNodo(pila1,valor);
                                PilaGanar=pila1;
                            }
                        }
                    }
                }
                break;
            default:
                break;
        }

            if(TorrePoner==-1||TorreQuitar==-1){
                seguir=false;
            }else{
                if(PilaGanar!= nullptr){
                    cout<<"la pila no es nula";
                    if(verificarSiGano(PilaGanar)){
                        //imprimirTorres(pila1,pila2,pila3);

                        seguir=false;
                    }
                }

            }
        imprimirTorres(pila1,pila2,pila3);

    }
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
    }
    Menu(pila1,pila2,pila3);

}

