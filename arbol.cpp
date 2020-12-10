//LIBRERIAS A INCLUIR
#include<iostream>
#include<stdlib.h>


//Definiciones
using namespace std;
struct Nodo{
	int info;
	Nodo* derecho;
	Nodo* izquierdo;	
};typedef Nodo* Nodoptr;

//prototipos
void menu();
Nodo* crear(int dato);
void PreOrden(Nodo *arbol);
void posOrden(Nodo *arbol);
void insertar(Nodo *&arbol,int dato);
void eliminar();
void buscar();
int getDato();


//funcion principal main
int main(){

   menu();
   return 0;
}

void menu(){

     int opcion;
     Nodoptr arbol = NULL;
    do{
        do{
            cout<<"-------------Menu-------------"<<endl;
            cout<<"\n0)SALIR\n1)CREAR\n2)INSERTAR\n3)ELIMINAR\n4)BUSCAR\n5)Pre-Orden\n6)Pos-Orden\n";
            cout<<"Ingresa una opcion para continuar: "<<endl;
            cin>>opcion;
        }while( (opcion < 0) || (opcion > 6) );
    
        switch(opcion){
            case 1:
                system("cls");
                insertar(arbol,getDato());
                 break;
            case 2:
                system("cls");
                insertar(arbol,getDato());
                break;
            case 3://eliminar
                system("cls");
                break;
            case 4://buscar
                system("cls");
                break;
            case 5:
                system("cls");
                cout<<"Recorrio del arbol en Pre-Orden"<<endl;
                PreOrden(arbol);
                break;
            case 6:
                system("cls");
                cout<<"Recorrio del arbol en Pos-Orden"<<endl;
                posOrden(arbol);
                break;
            default:
                break;
    		

        }	
        system("pause");
        system("cls");	
	}while(opcion != 0);
}

int getDato(){
	int dato =0;
	cout<< "Ingresa un numero entero por favor: "<<endl;
	cin>>dato;
	return dato;
}

Nodo* crear(int dato){
	Nodo* new_elemento = new Nodo();

    new_elemento->info = dato;
    new_elemento->derecho = NULL;
    new_elemento->izquierdo = NULL;

    return new_elemento;
}

void insertar(Nodo *&arbol,int dato){
    
    //Caso 1: Arbol vacio
    if(arbol == NULL){
        Nodo* new_elemento = crear(dato);
        arbol = new_elemento;
    }
    //Caso 2: Arbol no esta vacio
    else{
        int raiz = arbol->info;
        if( dato < raiz )
            insertar(arbol->izquierdo,dato);
        else 
            insertar(arbol->derecho,dato);
    }
}


void posOrden(Nodo *arbol){
    if (arbol == NULL){
        return;
    }
    else{
        posOrden(arbol->izquierdo);
        posOrden(arbol->derecho);
        cout<<arbol->info<<" ";
    }
}

void PreOrden(Nodo *arbol){
	if (arbol == NULL){
        return;
    }
    else{
        cout<<arbol->info<<" ";
        PreOrden(arbol->izquierdo);
        PreOrden(arbol->derecho);
    }
}
