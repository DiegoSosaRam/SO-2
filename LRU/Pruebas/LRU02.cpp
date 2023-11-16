#include <iostream>
#include <vector>

using namespace std;

int main() {
    int memoriaSize = 0;
    cout << "Ingrese la cantidad de frames: ";
    cin >> memoriaSize;

    int numProcesos = 0;
    cout << "Ingrese la cantidad de procesos: ";
    cin >> numProcesos;

    vector<int> procesos(memoriaSize); // Inicializa el vector con -1 (indicando que no hay procesos en memoria)

    int m=0; // Contador de procesos
    int pageDefaults=0; // Contador de page faults
    int pageHits=0; // Contador de page hits

    for (int i=0; i<numProcesos; i++) {
        int proceso;

        cout << "Ingrese el proceso " << i + 1 << ": ";
        cin >> proceso;

        // Busca el proceso en memoria
        bool found = false;
        for (int j = 0; j < memoriaSize; ++j) {
            if (procesos[j] == proceso) {
                found = true;
                pageHits++;
                break;
            }
        }

        if (!found) {
            // Page fault: el proceso no está en memoria
            if (m >= memoriaSize) {
                // Reemplaza el proceso más antiguo (el primero en el vector)
                procesos.erase(procesos.begin());
            } 

            // Agrega el nuevo proceso al final del vector
            procesos.push_back(proceso);
            pageDefaults++;
        }
        m++;
    }
	cout<<"\n";
    cout<<"Vector (cola): ";
    for (int j=0; j<procesos.size(); j++) {
        cout << procesos[j] << ", ";
    }
    cout<<"\n";
    cout<<"Tiempos: "<<m<<"\n";
    cout<<"\n";
    cout<<"Frames: "<<memoriaSize<<"\n";
    cout<<"\n";
    cout<<"Page Hits: "<<pageHits<<"\n";
    cout<<"\n";
    cout<<"Page Defaults: "<<pageDefaults<<"\n";
	cout<<"\n";
	cout<<"\n";
    float pm=(static_cast<float>(pageDefaults) / m) * 100;
    cout << "Page Miss = (" << pageDefaults << "/" << m << ")*100 = " << pm << "\n";
	cout<<"\n";	
    float hr=(static_cast<float>(pageHits) / m) * 100;
    cout << "Hit Ratio = (" << pageHits << "/" << m << ")*100 = " << hr << "\n";
	cout<<"\n";
    float tt = pm + hr;
    cout << "Total (Page Miss + Hit Ratio): " << tt << "%";
	cout<<"\n";

    return 0;
}

