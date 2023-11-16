#include <iostream>
#include <stdio.h>
#include <conio.h>


using namespace std;

struct nodo{
	int dato;
	struct nodo *sig;
}  *inicio=NULL, *ult=NULL, *aux;

void Agregar_Elementos(int num){
	aux=new nodo;
	aux->dato=num;
	if (inicio==NULL){
		inicio=ult=aux;
		aux->sig=NULL;
	}
	else{
		aux->sig=NULL;
		ult->sig=aux;
		ult=aux;
	}
}

void Listado(){
	cout<<"Datos en cola: \n";
	aux=inicio;
	do{
		cout<<aux->dato<<", ";
		aux=aux->sig;
	}while(aux!=NULL);
	
	cout<<"NULL";
}

int main(){
	Agregar_Elementos(5);
	Agregar_Elementos(10);
	Agregar_Elementos(1);
	Agregar_Elementos(20);
	Agregar_Elementos(0);
	Listado();
	//getch();
  return 0;
}

