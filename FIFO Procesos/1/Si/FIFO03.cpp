#include <iostream>
#include <cstdlib> // Para generación de números aleatorios
#include <ctime>   // Para obtener una semilla aleatoria
#include <conio.h>

using namespace std;

struct nodo {
    int dato;
    struct nodo* sig;
} *inicio=NULL, *ult=NULL, *aux;

void Agregar_Numero(int num) {
    aux = new nodo;
    aux->dato = num;
    if (inicio == NULL) {
        inicio = ult = aux;
        aux->sig = NULL;
    }
    else {
        aux->sig = NULL;
        ult->sig = aux;
        ult = aux;
    }
    
    cout<<"Agregado: "<<num<<" -- ";
    cout<<"Inicio: "<<inicio->dato<<" -- ";
    cout<<"Ultimo: "<<ult->dato<<" -- ";
    cout<<"Aux: "<<aux->dato<<endl;
    cout<<"\n";
}

void Agregar_Numeros(int n) {
    srand(static_cast<unsigned int>(time(NULL))); // Inicializa la semilla aleatoria
    for (int i = 0; i < n; i++) {
        int numAleatorio = rand() % 10; // Genera números aleatorios entre 0 y 9
        Agregar_Numero(numAleatorio);
    }
}

void Listado() {
    cout << "Datos en cola: \n";
    aux = inicio;
    do {
        cout << aux->dato << ", ";
        aux = aux->sig;
    } while (aux != NULL);

    cout << "NULL";
}

int main() {
    int n;
    cout<<"Ingrese la cantidad de procesos: ";
    cin>>n;
    cout<<"\n";
    Agregar_Numeros(n);
    
    Listado();

    return 0;
}

