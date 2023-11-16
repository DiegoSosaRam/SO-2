#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main() {
    int memoriaSize=0;
    int numProcesos=0;

    cout << "Ingrese la cantidad de procesos: ";
    cin >> memoriaSize;
    numProcesos=memoriaSize;

    // Vector para almacenar los nombres de los procesos
    vector<string> procesos;

    // Vector para almacenar el tamaño de cada proceso
    vector<int> proceso;

    cout << "Ingrese el nombre y el tamaño de cada proceso:" << endl;
    for (int i = 0; i < numProcesos; i++) {
        string nombreProceso;
        int tamanoProceso;

        cout << "Proceso " << (i + 1) << " (luego su tamano): ";
        cin >> nombreProceso >> tamanoProceso;

        procesos.push_back(nombreProceso);
        proceso.push_back(tamanoProceso); // Cambiamos el nombre del vector
    }
    cout << "\n";

    // Inicializar la memoria como una cola (queue)
    queue<string> memoria;

    // Conteo de Page Hits y Page Defaults
    float pageHits = 0;
    float pageDefaults = 0;
    float m = 0;

    // Ejecutar el algoritmo FIFO
    for (int tiempo = 0; tiempo < procesos.size(); ++tiempo) {
        string procesoActual = procesos[tiempo];
        int tamanoActual = proceso[tiempo]; // Cambiamos el nombre del vector

        // Verificar si el proceso está en la memoria (cola)
        bool pageHit = false;
        queue<string> colaTemporal = memoria;
        while (!colaTemporal.empty()) {
            string procesoEnCola = colaTemporal.front();
            colaTemporal.pop();
            if (procesoEnCola == procesoActual) {
                pageHit = true;
                break;
            }
        }

        if (pageHit) {
            pageHits += tamanoActual;
        } else {
            pageDefaults += tamanoActual;

            // Si la cola está llena, eliminar el proceso más antiguo
            int memoriaUsada = 0;
            queue<string> colaTemporal2 = memoria;
            while (!colaTemporal2.empty()) {
                memoriaUsada += proceso[tiempo]; // Cambiamos el nombre del vector
                colaTemporal2.pop();
            }

            while (memoria.size() >= memoriaSize && memoriaUsada + tamanoActual > memoriaSize) {
                string procesoAntiguo = memoria.front();
                memoria.pop();
                memoriaUsada -= proceso[tiempo]; // Cambiamos el nombre del vector
            }

            // Agregar el nuevo proceso a la cola (memoria)
            memoria.push(procesoActual);
        }
        m = tiempo + 1;
    }

    // Mostrar la cola inicial
    cout << "Vector (cola): " << endl;
    for (int i = 0; i < proceso.size(); ++i) {
        cout << proceso[i] << " ";
    }
    
    for (int i = 0; i < procesos.size(); ++i) {
        cout << procesos[i] << " ";
    }
    cout << "\n";
    cout << "\n";
    cout << "Tiempos: " << m << "\n";
    cout << "\n";
    cout << "Frames: " << memoriaSize << "\n";
    cout << "\n";
    cout << "Page Hits (tamaño total): " << pageHits << endl;
    cout << "\n";
    cout << "Page Defaults (tamaño total): " << pageDefaults << endl;
    cout << "\n";

    // Iterar a través de la cola de memoria para mostrar los procesos
    cout << "Procesos en memoria: ";
    queue<string> colaMemoria = memoria;
    while (!colaMemoria.empty()) {
        cout << colaMemoria.front() << " ";
        colaMemoria.pop();
    }
    cout << "\n";

    float pm = (pageDefaults / m) * 100;
    cout << "Page Miss (porcentaje): " << pm << "%" << endl;
    cout << "\n";

    float hr = (pageHits / m) * 100;
    cout << "Hit Ratio (porcentaje): " << hr << "%" << endl;
    cout << "\n";

    float tt=pm+hr;
    cout << "Total (Page Miss + Hit Ratio): " << tt << "%" << endl;

    return 0;
}

