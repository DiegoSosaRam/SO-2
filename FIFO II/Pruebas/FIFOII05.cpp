#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Proceso {
    string nombre;
    int llegada;
    int tCPU;
    int espera;
    int ejecucion;
    int entrada;
    int fin; // Cambiamos el nombre de sumaTCPU a fin
};

int main() {
    int TR=0, TE=0;
    int numProcesos=0;
    cout<<"Ingrese la cantidad de procesos: ";
    cin>>numProcesos;

    vector<Proceso> procesos;
    cout<<endl;
    for (int i=0; i<numProcesos; i++) {
        Proceso proceso;
        cout<<"Nombre del proceso " << (i + 1) << ": ";
        cin>>proceso.nombre;
        cout<<"Tiempo de llegada del proceso " << proceso.nombre << ": ";
        cin>>proceso.llegada;
        cout<<"Tiempo de CPU del proceso " << proceso.nombre << ": ";
        cin>>proceso.tCPU;
        proceso.espera=0;
        proceso.ejecucion=0;
        proceso.entrada = -1;
        proceso.fin = -1;
        procesos.push_back(proceso);
        cout<<endl;
    }
    cout<<endl;

    queue<Proceso> memoria;
    vector<string> memoriaRepresentacion;

    int tiempo=0;
    int Fn=0;

    while (Fn<numProcesos) { // Cambiamos la condición para que sea cuando Fn alcance el número de procesos
        for (int z=0; z<numProcesos; z++) {
        	//Se verifica si el proceso z ha llegado en o antes del tiempo actual (tiempo)
            if (procesos[z].llegada <= tiempo && procesos[z].ejecucion < procesos[z].tCPU) {
                memoria.push(procesos[z]);
                memoriaRepresentacion.push_back(procesos[z].nombre);

                if (procesos[z].entrada == -1) {
                    procesos[z].entrada = tiempo;
                }

                procesos[z].ejecucion++;
                break;
            }
        }

        if (!memoria.empty()) {
            Proceso procesoActual = memoria.front();
            memoria.pop();

            if (procesoActual.ejecucion == procesoActual.tCPU) {
                procesoActual.fin = tiempo;
                Fn++; // Incrementamos Fn cuando un proceso termina su ejecución
            }

            procesoActual.espera += memoria.size();
            tiempo++;
        } else {
            tiempo++;
        }
    }
    cout << endl;

    cout << "Cola: (";
    for (size_t c=0; c < memoriaRepresentacion.size(); ++c) {
        cout<<memoriaRepresentacion[c];
        if (c<memoriaRepresentacion.size() - 1) {
            cout << ", ";
        }
    }
    cout << ")" << endl;

    // Calculamos Fn sumando los tiempos de finalización de todos los procesos
    int sumaFn = 0;
    for (int k=0; k<numProcesos; k++) {
        sumaFn += procesos[k].fin;
    }

    TR=sumaFn/numProcesos;
    TE=tiempo/numProcesos;
    cout<<"Fn: "<<sumaFn<<" ut"<<endl; // Mostramos Fn en lugar de sumaTCPU
    cout<<"TE: "<<tiempo<<" ut"<<endl;

    for (int i = 0; i < numProcesos; i++) {
        cout << "Proceso " << procesos[i].nombre << ": Inicio: " << procesos[i].entrada << ", Fin: " << procesos[i].fin << endl;
    }

  return 0;
}

