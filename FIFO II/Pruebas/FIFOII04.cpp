#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Proceso {
    string nombre;
    int llegada;
    int tCPU;
    int espera;
    int ejecucion;
    int fin; // Variable para registrar el tiempo de finalización
};

int main(){
    int TR=0, TE=0;
    int numProcesos=0;
    cout<<"Ingrese la cantidad de procesos: ";
    cin>>numProcesos;
    cout<<endl;
    
    vector<Proceso> procesos;
    for (int i=0; i<numProcesos; i++) {
        Proceso proceso;
        cout<<"Nombre del proceso " <<(i+1)<< ": ";
        cin>>proceso.nombre;
        cout<<"Tiempo de llegada del proceso " <<proceso.nombre<< ": ";
        cin>>proceso.llegada;
        cout<<"Tiempo de CPU del proceso " <<proceso.nombre<< ": ";
        cin>>proceso.tCPU;
        proceso.espera = 0;
        proceso.ejecucion = 0;
        proceso.fin = 0; // Inicializa el tiempo de finalización en 0
        procesos.push_back(proceso);
        cout<<endl;
    }
    cout<<endl;

    int sumaTCPU=0;
    for (int j=0; j<numProcesos; j++) {
        sumaTCPU += procesos[j].tCPU;
    }

    queue<Proceso> memoria;
    vector<string> memoriaRepresentacion;

    int tiempo=0;
    while (tiempo<sumaTCPU) {
        for (int z=0; z<numProcesos; z++) {
            if (procesos[z].llegada <= tiempo && procesos[z].ejecucion < procesos[z].tCPU) {
                memoria.push(procesos[z]);
                memoriaRepresentacion.push_back(procesos[z].nombre);
                procesos[z].ejecucion++;
                break;
            }
        }

        if (!memoria.empty()) {
            Proceso procesoActual = memoria.front();
            memoria.pop();
            procesoActual.espera += memoria.size();

            // Verificar si el proceso ha terminado
            if (procesoActual.ejecucion == procesoActual.tCPU) { //compara el proceso actual
                procesoActual.fin = tiempo; // Establecer el tiempo de finalización
            }

            tiempo++;
        } else {
            tiempo++;
        }
    }
    cout<<endl;
    cout<<"Cola: (";
    for (size_t c=0; c<memoriaRepresentacion.size(); ++c) {
        cout<<memoriaRepresentacion[c];
        if (c<memoriaRepresentacion.size() - 1) {
            cout<<", ";
        }
    }
    cout<<")"<<endl;
    TR=sumaTCPU/numProcesos;
    TE=tiempo/numProcesos;
    cout<<"TR: "<<sumaTCPU<<" ut"<<endl;
    cout<<"TE: "<<tiempo<<" ut"<<endl;

    // Imprimir el tiempo de finalización de cada proceso
    for (int h=0; h<numProcesos; h++) {
        cout<<"Tiempo de terminado para "<<procesos[h].nombre<<": "<<procesos[h].fin<<endl;
    }

    return 0;
}

