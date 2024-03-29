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
    int entrada;  // Nuevo: tiempo de entrada
    int fin;      // Nuevo: tiempo de finalización
};

int main() {
    int TR = 0, TE = 0;
    int numProcesos = 0;
    cout << "Ingrese la cantidad de procesos: ";
    cin >> numProcesos;

    vector<Proceso> procesos;
    cout << endl;
    for (int i = 0; i < numProcesos; i++) {
        Proceso proceso;
        cout << "Nombre del proceso " << (i + 1) << ": ";
        cin >> proceso.nombre;
        cout << "Tiempo de llegada del proceso " << proceso.nombre << ": ";
        cin >> proceso.llegada;
        cout << "Tiempo de CPU del proceso " << proceso.nombre << ": ";
        cin >> proceso.tCPU;
        proceso.espera = 0;
        proceso.ejecucion = 0;
        proceso.entrada = 0; // Inicializamos tiempo de entrada en 0
        proceso.fin = 0;     // Inicializamos tiempo de finalización en 0
        procesos.push_back(proceso);
        cout << endl;
    }
    cout << endl;

    int sumaTCPU = 0;
    for (int j = 0; j < numProcesos; j++) {
        sumaTCPU += procesos[j].tCPU;
    }

    queue<Proceso> memoria;
    vector<string> memoriaRepresentacion;

    int tiempo = 0;
    while (tiempo < sumaTCPU) {
        for (int z = 0; z < numProcesos; z++) {
            if (procesos[z].llegada <= tiempo && procesos[z].ejecucion < procesos[z].tCPU) {
                memoria.push(procesos[z]);
                memoriaRepresentacion.push_back(procesos[z].nombre);
                procesos[z].ejecucion++;
                procesos[z].entrada = tiempo; // Registramos el tiempo de entrada
                break;
            }
        }

        if (!memoria.empty()) {
            Proceso procesoActual = memoria.front();
            memoria.pop();
            procesoActual.espera += memoria.size();
            tiempo++;
            procesoActual.fin = tiempo; // Registramos el tiempo de finalización
        } else {
            tiempo++;
        }
    }

    cout << "Cola: (";
    for (size_t c = 0; c < memoriaRepresentacion.size(); ++c) {
        cout << memoriaRepresentacion[c];
        if (c < memoriaRepresentacion.size() - 1) {
            cout << ", ";
        }
    }
    cout << ")" << endl;

    TR = sumaTCPU / numProcesos;
    TE = tiempo / numProcesos;
    cout << "TR: " << TR << " ut" << endl;
    cout << "TE: " << TE << " ut" << endl;

    // Imprimimos el tiempo de entrada y finalización para cada proceso
    for (int i = 0; i < numProcesos; i++) {
        cout << "Proceso " << procesos[i].nombre << ", ";
        cout << "Inicio: " << procesos[i].entrada << ", ";
        cout << "Fin: " << procesos[i].fin << endl;
    }

    return 0;
}

