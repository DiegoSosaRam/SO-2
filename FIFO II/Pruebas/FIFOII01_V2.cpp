#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Proceso {
    string nombreProceso; // Cambiamos el nombre de la variable ID a nombreProceso
    int tEntrada;
    int tCPU;
};

int main() {
    int memoriaSize = 0;
    cout << "Ingrese los frames: ";
    cin >> memoriaSize;

    int numProcesos = 0;
    cout << "Ingrese la cantidad de procesos: ";
    cin >> numProcesos;
	
	cout<<endl;
    vector<Proceso> procesos;
    //cout << "Ingrese los procesos (Nombre, Tiempo de Entrada, Tiempo de CPU):" << endl;
    for (int i = 0; i < numProcesos; i++) {
        Proceso proceso;
		cout<<"Nombre del proceso "<< i+1 <<": ";
		cin>> proceso.nombreProceso;
        cout<<"Tiempo de entrada de "<< proceso.nombreProceso <<": ";
        cin>>proceso.tEntrada ;
		cout<<"Tiempo en CPU de "<< proceso.nombreProceso <<": ";
		cin>>proceso.tCPU;
		cout<<endl;
        procesos.push_back(proceso);
    }
    cout << "\n";

    queue<Proceso> memoria;
    float pageHits=0;
    float pageDefaults=0;
    float m=0;

    // FIFO
    for (int tiempo=0; tiempo<procesos.size(); ++tiempo) {
        Proceso procesoActual=procesos[tiempo];

        bool pageHit = false;
        queue<Proceso> colaTemporal = memoria;
        while (!colaTemporal.empty()) {
            Proceso procesoEnCola = colaTemporal.front();
            colaTemporal.pop();
            if (procesoEnCola.nombreProceso == procesoActual.nombreProceso) {
                pageHit=true;
                break;
            }
        }

        if (pageHit) {
            pageHits++;
        } else {
            pageDefaults++;

            if (memoria.size()>=memoriaSize) {
                memoria.pop();
            }

            memoria.push(procesoActual);
        }
        m=m+1;

        cout<<"Tiempo de llegada?: "<<tiempo<<endl;
		cout<<"Proceso: "<<procesoActual.nombreProceso<<endl;
		cout<<"Tiempo en CPU: " << procesoActual.tCPU<<endl;
        procesoActual.tCPU--;
        cout<<endl;

        while (!memoria.empty() && memoria.front().tCPU == 0) {
            memoria.pop();
        }
    }

    cout<<"Frames: "<<memoriaSize<<endl;
    cout<<"PageHits: "<<pageHits<<endl;
    cout<<"PageDefaults: "<<pageDefaults<<endl;

    float pm = (pageDefaults / m) * 100;
    cout << "Page Miss = (" << pageDefaults << "/" << m << ")*100 = " << pm << "%" << endl;

    float hr = (pageHits / m) * 100;
    cout << "Hit Ratio = (" << pageHits << "/" << m << ")*100 = " << hr << "%" << endl;

    float tt = pm + hr;
    cout << "Total (Page Miss + Hit Ratio): " << tt << "%" << endl;

    return 0;
}

