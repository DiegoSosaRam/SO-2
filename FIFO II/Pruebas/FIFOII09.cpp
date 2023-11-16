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
    int fin;
};

int main() {
    int TR = 0, TE = 0, tiempo = 0;
    int fini = 0;
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
        proceso.fin = 0;
        procesos.push_back(proceso);
        cout << endl;
    }
    cout << endl;

    queue<Proceso> memoria;
    vector<string> memoriaV;

    while (fini < numProcesos) {
        bool procesoEncontrado = false;

        for (int z = 0; z < numProcesos; z++) {
            if (procesos[z].llegada <= tiempo && procesos[z].ejecucion < procesos[z].tCPU) {
                memoria.push(procesos[z]);
                memoriaV.push_back(procesos[z].nombre);
                procesos[z].ejecucion++;
                procesoEncontrado = true;
            }
        }

        if (procesoEncontrado) {
            Proceso procesoActual = memoria.front();
            memoria.pop();
            procesoActual.espera += memoria.size();
            tiempo++;

            procesoActual.fin = tiempo;

            if (procesoActual.ejecucion == procesoActual.tCPU) {
                fini++;
            }
        } else {
            tiempo++;
        }
    }

    cout << endl;
    cout << "Cola: (";
    for (size_t c = 0; c < memoriaV.size(); ++c) {
        cout << memoriaV[c];
        if (c < memoriaV.size() - 1) {
            cout << ", ";
        }
    }
    cout << ")" << endl;

    TR = TE = 0;
    for (int t = 0; t < numProcesos; t++) {
        TR += procesos[t].fin - procesos[t].llegada;
        TE += procesos[t].espera;
    }
    TR /= numProcesos;
    TE /= numProcesos;

    cout << "TR: " << TR << " ut" << endl;
    cout << "TE: " << TE << " ut" << endl;

    return 0;
}

