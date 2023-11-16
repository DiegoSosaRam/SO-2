#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int TR=0, TE=0, tiempo=0;
    int sumFin=0;
    int numProcesos=0;
    cout<<"Ingrese la cantidad de procesos: ";
    cin>>numProcesos;

    vector<string> nombreProceso;
    vector<int> llegadaProceso;
    vector<int> tCPUProceso;
    vector<int> esperaProceso;
    vector<int> ejecucionProceso;
    vector<int> finProceso;

    cout << endl;
    for (int i=0; i<numProcesos; i++) {
        string nombre;
        int llegada, tCPU;

        cout << "Nombre del proceso " << (i+1) << ": ";
        cin >> nombre;
        cout << "Tiempo de llegada del proceso " << nombre << ": ";
        cin >> llegada;
        cout << "Tiempo de CPU del proceso " << nombre << ": ";
        cin >> tCPU;

        nombreProceso.push_back(nombre);
        llegadaProceso.push_back(llegada);
        tCPUProceso.push_back(tCPU);
        esperaProceso.push_back(0);
        ejecucionProceso.push_back(0);
        finProceso.push_back(0);

        cout<<endl;
    }
    cout<<endl;

    int sumaTCPU=0;
    for (int j=0; j<numProcesos; j++) {
        sumaTCPU+=tCPUProceso[j];
    }

    queue<int> memoria;
    vector<string> memoriaV;

    do {
        for (int z=0; z<numProcesos; z++) {
            if (llegadaProceso[z] <= tiempo && ejecucionProceso[z] < tCPUProceso[z]) {
                memoria.push(z);
                memoriaV.push_back(nombreProceso[z]);
                ejecucionProceso[z]++;
                break;
            }
        }

        if (!memoria.empty()) {
            int procesoActualIdx = memoria.front();
            memoria.pop();
            esperaProceso[procesoActualIdx] += memoria.size();
            tiempo++;

            if (ejecucionProceso[procesoActualIdx] == tCPUProceso[procesoActualIdx]) {
                finProceso[procesoActualIdx] = tiempo;
            }
        } else {
            tiempo++;
        }

    } while (tiempo<sumaTCPU);

    cout << "Cola: (";
    for (size_t c=0; c<memoriaV.size(); c++) {
        cout << memoriaV[c];
        if (c < memoriaV.size() - 1) {
            cout << ", ";
        }
    }
    cout << ")" << endl;

    for (int t=0; t<numProcesos; t++) {
        cout << "Proceso: " << nombreProceso[t] << ", ";
        cout << "Fin: " << finProceso[t]-1 << endl;
    }

    for (int f=0; f<numProcesos; f++) {
        sumFin += finProceso[f];
    }

    TR=sumFin/numProcesos;
    TE=tiempo/numProcesos;
    cout << "TR: " << TR << " ut" << endl;
    cout << "TE: " << TE<< " ut" << endl;

    return 0;
}

