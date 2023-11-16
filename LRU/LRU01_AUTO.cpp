#include <iostream>
#include <queue>
#include <vector>
//#include <cstdlib> // Para generación de números aleatorios
//#include <ctime>   // Para obtener una semilla aleatoria

using namespace std;

int main() {
    int memoriaSize=0;
    cout<<"Ingrese los frames: ";
    cin>>memoriaSize;

    int numProcesos=0;
    cout<<"Ingrese la cantidad de procesos: ";
    cin>>numProcesos;

    vector<int> procesos;
    cout<<"Ingrese los procesos:"<<endl;
    for (int i = 0; i < numProcesos; i++) {
        int proceso;
        cout << "Proceso " << (i + 1) << ": ";
        cin >> proceso;
        procesos.push_back(proceso);
    }
    cout << "\n";

    queue<int> memoria;

    float pageHits=0;
    float pageDefaults=0;
    float m=0;

	//LRU
    for (int tiempo=0; tiempo<procesos.size(); tiempo++) {
        int procesoActual=procesos[tiempo];
		//Identificar Hits y Pages
        bool pageHit=false;
        queue<int> colaTemporal = memoria;
        while (!colaTemporal.empty()) {
            int procesoEnCola = colaTemporal.front();
            colaTemporal.pop();
            if (procesoEnCola == procesoActual) {
                pageHit=true;
                break;
            }
        }
        if (pageHit) {
            pageHits++;
        } else {
            pageDefaults++;

            if (memoria.size() >= memoriaSize) {
                memoria.pop();
            }

            memoria.push(procesoActual);
        }
        m=m+1;
    }

    cout << "Cola: " << endl;
    for (int j=0; j<procesos.size(); j++) {
        cout<<procesos[j] << " ";
    }

    cout << "\n";
    cout << "\n";
    cout << "Tiempos: " << m <<endl;
    cout << "\n";
    cout << "Frames: " << memoriaSize <<endl;
    cout << "\n";
    cout << "Page Hits: " << pageHits <<endl;
    cout << "\n";
    cout << "Page Defaults: " << pageDefaults <<endl;
    cout << "\n";

    float pm=(pageDefaults/m)*100;
    cout << "Page Miss = (" << pageDefaults << "/" << m << ")*100 = " << pm << "\n";
    cout << "\n";

    float hr=(pageHits/m)*100;
    cout<<"Hit Ratio = (" << pageHits << "/" << m << ")*100 = " << hr << "\n";
    cout<<"\n";

    float tt=pm+hr;
    cout<<"Total (Page Miss + Hit Ratio): " << tt << "%" <<endl;

    return 0;
}

