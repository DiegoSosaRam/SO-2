#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// Tamaño de la memoria (número de frames)
//const int memoriaSize = 4;
//const int m=0;

int main() {
	int memoriaSize=0;
	/*
	cout << "Ingrese la cantidad de frames: ";
	cin >> memoriaSize;	
	*/
    int numProcesos=0;
    cout << "Ingrese la cantidad de procesos: ";
    cin >> numProcesos;
    
    memoriaSize=numProcesos;
    
    int llegada=0;
    int tCPU=0;
     
    
    // Lista de procesos
    vector<int> procesos;
    vector<string> nombreProceso;
    
    cout << "Ingrese el nombre y el tamano de cada proceso:"<<endl;
    for (int i = 0; i < numProcesos; i++) {
        string nombreProceso;
        int tamanoProceso;

        cout << "Proceso " << (i + 1) << " (nombre tamaño): ";
        cin >> nombreProceso >> tamanoProceso;

        procesos.push_back(nombreProceso);
        proceso.push_back(procesos); // Cambiamos el nombre del vector
    }
    cout << "\n";
    // Inicializar la memoria como una cola (queue)
    queue<int> memoria;
    
    // Conteo de Page Hits y Page Defaults y los tiempos (m)
    float pageHits=0;
    float pageDefaults=0;
	float m=0;
	
    // Ejecutar el algoritmo FIFO
    for (int tiempo = 0; tiempo < procesos.size(); ++tiempo) {
        int procesoActual = procesos[tiempo];

        // Verificar si el proceso está en la memoria (cola)
        bool pageHit = false;
        queue<int> colaTemporal = memoria;
        while (!colaTemporal.empty()) {
            int procesoEnCola = colaTemporal.front();
            colaTemporal.pop();
            if (procesoEnCola == procesoActual) {
                pageHit = true;
                break;
            }
        }

        if (pageHit) {
            pageHits++;
        } else {
            pageDefaults++;

            // Si la cola está llena, eliminar el proceso más antiguo
            if (memoria.size() >= memoriaSize) {
                memoria.pop(); // Con pop se elimina
            }

            // Agregar el nuevo proceso a la cola (memoria)
            memoria.push(procesoActual);
        }
		m=m+1;
    }
    
    // Mostrar la cola inicial
    cout << "Vector (cola): " << endl;
    for (int i = 0; i < procesos.size(); ++i) {
        cout << procesos[i] << " ";
    }
    
    cout<<"\n";
    cout<<"\n";
    cout<<"Tiempos: " << m <<"\n";
    cout<<"\n";
    cout<<"Frames: " << memoriaSize <<"\n";
    cout<<"\n";
    cout<<"Page Hits: " << pageHits <<endl;
    cout<<"\n";
	cout<<"Page Defaults: " << pageDefaults <<endl;
	cout<<"\n";
	
    cout<<"Procesos en memoria: ";
    queue<int> colaMemoria = memoria;
    while (!colaMemoria.empty()) {
        cout << colaMemoria.front()<<" ";
        colaMemoria.pop();
    }
    cout<<"\n";
	
	float pm=(pageDefaults/m)*100;
	cout<<"Page Miss = ("<< pageDefaults<<"/"<<m<<")*100 = "<< pm;
	cout<<"\n";
	cout<<"\n";
	
	float hr=(pageHits/m)*100;
	cout<<"Hit Ratio = ("<< pageHits<<"/"<<m<<")*100 = "<< hr;
	cout<<"\n";
	
	float tt=pm+hr;
	cout<<"\n";
	cout<<"Total (Page Miss + Hit Ratio): "<<tt<<"%";
	
  return 0;
}

